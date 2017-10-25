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

#include "instruction.hpp"

namespace clara {
    namespace instruction {

        Instruction::Instruction(std::string service_name) {
            this->service_name_ = service_name;
        }

        std::string Instruction::get_service_name() {
            return service_name_;
        }

        condition::Condition Instruction::get_if_condition() {
            return if_condition;
        }

        void Instruction::set_if_condition(condition::Condition if_condition) {
            this->if_condition = if_condition;
        }

        void Instruction::set_if_cond_statements(std::vector<statement::Statement> if_cond_statements) {
            this->if_cond_statements = if_cond_statements;
        }

        std::vector<statement::Statement> Instruction::get_if_cond_statements() {
            return if_cond_statements;
        }

        void Instruction::add_if_cond_statement(statement::Statement if_cond_statement) {
            this->if_cond_statements.push_back(if_cond_statement);
        }

        condition::Condition Instruction::get_else_if_condition() {
            return else_if_condition;
        }

        void Instruction::set_else_if_condition(condition::Condition else_if_condition) {
            this->else_if_condition = else_if_condition;
        }

        std::vector<statement::Statement> Instruction::get_else_if_cond_statements() {
            return else_if_cond_statements;
        }

        void Instruction::set_else_if_cond_statements(std::vector<statement::Statement> else_if_cond_statements) {
            this->else_if_cond_statements = else_if_cond_statements;
        }

        void Instruction::add_else_if_cond_statement(statement::Statement else_if_cond_statement) {
            this->else_if_cond_statements.push_back(else_if_cond_statement);
        }

        std::vector<statement::Statement> Instruction::get_else_cond_statements() {
            return else_if_cond_statements;
        }

        void Instruction::set_else_cond_statements(std::vector<statement::Statement> else_cond_statements) {
            this->else_cond_statements = else_cond_statements;
        }

        void Instruction::add_else_cond_statement(statement::Statement else_cond_statement) {
            this->else_cond_statements.push_back(else_cond_statement);
        }

        std::vector<statement::Statement> Instruction::get_un_cond_statements() {
            return un_cond_statements;
        }

        void Instruction::set_un_cond_statements(std::vector<statement::Statement> un_cond_statements) {
            this->un_cond_statements = un_cond_statements;
        }

        void Instruction::add_un_cond_statement(statement::Statement un_cond_statement) {
            this->un_cond_statements.push_back(un_cond_statement);
        }

        std::string Instruction::to_string() {
            return "Instruction{"
//                   "ifCondition=" + if_condition
//                   + ", ifCondStatements=" + if_cond_statements
//                   + ", elseifCondition=" + else_if_condition
//                   + ", elseifCondStatements=" + else_if_cond_statements
//                   + ", elseCondStatements=" + else_cond_statements
//                   + ", unCondStatements=" + un_cond_statements
                   ", serviceName='" + service_name_ + '\''
                   + '}';
        }

        bool Instruction::equals(Instruction i) {
            if (this->service_name_ != i.service_name_) {
                return false;
            }

            if (!(this->if_condition.equals(i.if_condition))) {
                return false;
            }

//            if (this->if_cond_statements != i.if_cond_statements) {
//                return false;
//            }

            if (!(this->else_if_condition.equals(i.else_if_condition))) {
                return false;
            }

//            if (this->else_if_cond_statements != i.else_if_cond_statements) {
//                return false;
//            }
//
//            if (this->else_cond_statements != i.else_cond_statements) {
//                return false;
//            }
//
//            if (this->un_cond_statements != i.un_cond_statements) {
//                return false;
//            }

            return true;
        }

        int Instruction::hash_code() {
            return 0;
        }

    }
}