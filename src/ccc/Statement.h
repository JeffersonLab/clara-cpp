//
// Created by Patrick Hennis on 9/12/17.
//

#ifndef CLARA_STATEMENT_H
#define CLARA_STATEMENT_H
#include <vector>
#include <string>
#include "../constants.hpp"

inline std::vector<std::string> tokenize(std::string s, std::string delimiter) {
    std::vector<std::string> tv;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tv.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
}


class Statement {
public:
    Statement(std::string statementStringParam, std::string serviceNameParam) {
        if (statementStringParam.find(serviceNameParam) != std::string::npos) {
            statementString = statementStringParam;
            serviceName = serviceNameParam;
            process(statementString);
        } else {
            // todo : throw clara exception "irrelevant statement"
        }
    }

    std::string getServiceName() {
        return serviceName;
    }

    std::string getStatementString() {
        return statementString;
    }

    std::vector<std::string> getInputLinks() {
        return inputLinks;
    }

    std::vector<std::string> getOutputLinks() {
        return outputLinks;
    }

    // todo : change signature when change logAndInputs to correct type
    std::vector<std::string> getLogAndInputs() {
        return logAndInputs;
    }

    void process(std::string statement) {
        inputLinks.clear();
        outputLinks.clear();
        logAndInputs.clear();

        if (statement.find(serviceName) != std::string::npos) {
            parseLinked(serviceName, statement);
            if (isLogAnd(serviceName, statement)) {
                for (std::string sn : inputLinks) {
                    logAndInputs.put(sn, null);
                }
            }
        }
    }

    void parseLinked(std::string serviceNameParam, std::string statementParam) {
        std::vector<std::string> elementSet;

        elementSet = tokenize(statementParam, "+");

        int index = -1;
        for (std::string s : elementSet) {
            index++;
            if (s.find(serviceNameParam) != std::string::npos) {
                break;
            }
        }
        if (index == -1) {
            // todo : throw clara exception "routing statement parsing exception, service name cannot be found in statement
        } else {
            int pIndex = index - 1;
            if (pIndex >= 0) {
                std::string element; // todo : = CompositionParser.getJSetElementAt(elementSet, pIndex)

                elementTokenizer(element, inputLinks);
            }

            int nIndex = index + 1;
            if (elementSet.size() > nIndex) {
                std::string element; // todo : = CompositionParser.getJSetElementAt(elementSet, nIndex)

                elementTokenizer(element, outputLinks);
            }
        }
    }

    void elementTokenizer(std::string element, std::vector<std::string> container) {
        if (element.find(",") != std::string::npos) {
            std::vector<std::string> st1 = tokenize(element, ",");
            while (st1.size() > 0) {
                container.push_back(st1.pop_back());
            }
        } else {
            conainer.push_back(element);
        }
    }

    bool isLagAnd(std::string serviceNname, std::string composition) {
        std::string ac = "&" + serviceNname;

        std::vector<std::string> elementSet;

        std::vector<std::string> st = tokenize(composition, "+");
        while (st.size() > 0) {
            elementSet.push_back(st.pop_back());
        }

        for (std::string s : elementSet) {
            if (s == ac) {
                return true;
            }
        }
        return false;
    }

    std::string toString() {
        return "Statement{" +
                "logAndInputs="         + logAndInputs +
                ", inputLinks="         + inputLinks +
                ", outputLinks="        + outputLinks +
                ", statementString='"   + statementString + "'" +
                ", serviceName='"       + serviceName + "'" +
                "}";
    }

    // todo : fix this implementation
    Statement& operator==(Statement s) {
        if (this == s) {
            return true;
        }

        if (inputLinks != std::string::npos ? !inputLinks == s.inputLinks : statement.inputLinks != std::string::npos) {
            return false;
        }

        if (logAndInputs != std::string::npos ? !logAndInputs == s.logAndInputs : statement.logAndInputs != std::string::npos) {
            return false;
        }

        if (outputLinks != std::string::npos ? !outputLinks == s.outputLinks : statement.outputLinks != std::string::npos) {
            return false;
        }

        if (!serviceName == s.serviceName) {
            return false;
        }

        if (statementString != null ? !statmentString == s.statementString : s.statementString != std::string::npos) {
            return false;
        }

        return true;
    }


    // todo hashcode implementation


private:
    std::vector<std::string> inputLinks;
    std::vector<std::string> outputLinks;
    std::vector<std::string> logAndInputs; // todo : should be map w/ 2nd type engine data
    std::string statementString = clara::constants::udf;
    std::string serviceName = clara::constants::udf;
};

#endif //CLARA_STATEMENT_H
