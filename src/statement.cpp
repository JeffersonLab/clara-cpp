/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* vim: set ts=8 sts=4 et sw=4 tw=80: */
/*
 * Copyright (c) 2016.  Jefferson Lab (JLab). All rights reserved. Permission
 * to use, copy, modify, and distribute  this software and its documentation for
 * educational, research, and not-for-profit purposes, without fee and without a
 * signed licensing agreement.
 *
 * IN NO EVENT SHALL JLAB BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL
 * INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
 * OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF JLAB HAS
 * BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * JLAB SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE. THE CLARA SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY,
 * PROVIDED HEREUNDER IS PROVIDED "AS IS". JLAB HAS NO OBLIGATION TO PROVIDE
 * MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * This software was developed under the United States Government license.
 * For more information contact author at gurjyan@jlab.org
 * Department of Experimental Nuclear Physics, Jefferson Lab.
 */

#include "composition.hpp"

namespace clara {
namespace composition {

    Statement::Statement(const std::string& statement_string,
                         const std::string& service_name) {
        if (statement_string.find(service_name) != std::string::npos) {
            this->statement_string_ = statement_string;
            this->service_name_ = service_name;
            process(statement_string);
        } else {
            throw std::logic_error{"irrelevant statement"};
        }
    }

    std::string Statement::get_service_name() {
        return service_name_;
    }

    std::string Statement::get_statement_string() {
        return statement_string_;
    }

    std::set<std::string> Statement::get_input_links() const {
        return input_links;
    }

    std::set<std::string> Statement::get_output_links() const {
        return output_links;
    }

    std::set<std::string> Statement::get_log_and_inputs() {
        return log_and_inputs;
    };

    void Statement::process(const std::string& statement) {
        input_links.clear();
        output_links.clear();
        log_and_inputs.clear();

        if(statement.find(service_name_) != std::string::npos) {

            std::vector<std::string> statements = tokenize(statement, ";");
            for (const std::string& s : statements) {
                parse_linked(service_name_, s);
            }

            if (is_log_and(service_name_, statement)) {
                for (const std::string& sn : input_links) {
                    log_and_inputs.insert(sn);
                }
            }
        }
    }

    void Statement::parse_linked(const std::string& service_name,
                                 const std::string& statement) {
        std::vector<std::string> element_set;
        std::vector<std::string> st = tokenize(statement, "+");
        for (std::string el : st) {
            el = remove_first(el, '&');
            el = remove_first(el, '{');
            el = remove_first(el, ';');
            element_set.push_back(el);
        }

        int index = -1;
        for (const std::string& s : element_set) {
            index++;
            if (s.find(service_name) != std::string::npos) {
                break;
            }
        }
        if (index == -1) {
            throw std::logic_error{"Routing statement parsing exception. "
                                           "Service name can not be found in the statement."};
        } else {
            if (index == 0) {
                std::string element = element_set[0];
                if (element != "") {
                    if(element.find(',') != std::string::npos) {
                        std::vector<std::string> cs = tokenize(element, ",");
                        for (const std::string& s : cs) {
                            input_links.insert(s);
                        }
                    } else {
                        input_links.insert(element);
                    }
                }
            }

            int nIndex = index + 1;
            if (element_set.size() > nIndex) {
                std::string element = element_set[nIndex];
                output_links.insert(element);
            }
        }
    }

    bool Statement::is_log_and(const std::string& service_name,
                               const std::string& composition) {
        std::string ac = "&" + service_name;

        std::vector<std::string> st = tokenize(composition, "+");
        for (const std::string& s : st) {
            if (s == ac) {
                return true;
            }
        }

        return false;
    }

    bool Statement::operator<(const Statement& lhs) const {
        return this->service_name_ < lhs.service_name_;
    }

    bool Statement::operator==(const Statement& lhs) const {
        if (!(this->service_name_ == lhs.service_name_)) {
            return false;
        }
        if (!(this->statement_string_ == lhs.statement_string_)) {
            return false;
        }
        if (!(this->log_and_inputs == lhs.log_and_inputs)) {
            return false;
        }
        if (!(this->input_links == lhs.input_links)) {
            return false;
        }
        if (!(this->output_links == lhs.output_links)) {
            return false;
        }
        return true;
    }

    int Statement::hash_code() {
        int result = std::hash<std::string>{}(service_name_);
        result = 31 * result + std::hash<std::string>{}(statement_string_);
        //result = 31 * result + std::hash<std::string>{}(log_and_inputs);
        //result = 31 * result + std::hash<std::string>{}(input_links);
        //result = 31 * result + std::hash<std::string>{}(output_links);
        return result;
    }

    std::string Statement::to_string() {
        return "Statement {"
                       "serviceName='" + service_name_ + "'"
//                ", statementString='" + statement_string_ + "'"
//                ", logAndInputs='"
//                ", inputLinks=" + input_links + ""
//                ", outputLinks=" + output_links + ""
                       "}";
    }

}
}
