//
// Created by Patrick Hennis on 9/7/17.
//
#ifndef CLARA_COMPOSITIONCOMPILER_H
#define CLARA_COMPOSITIONCOMPILER_H
#include <regex>
#include <string>
#include <vector>


class CompositionCompiler {
public:
    const std::string ip_string = "([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})";
    std::regex IP(ip_string);

    std::string str_string = "([A-Z|a-z]+[0-9]*)";
    std::regex STR(str_string);

    std::string str2_string = "(%+[0-9]*)*";
    std::regex STR2(str2_string);

    std::string sn_string = IP + STR2 + "_(java|python|cpp):" + STR + ":" + STR;
    std::regex Sn(sn_string);

    std::string rs_string = Sn + "(," + Sn + ")*" + "((\\+&?" + Sn + ")*|(\\+" + Sn + "(," + Sn + ")*)*)";
    std::regex RStmt(rs_string);

    std::string scond_string = Sn + "(==|!=)\"" + STR + "\"";
    std::regex sCond(scond_string);

    std::string ccond_string = sCond + "((&&|!!)" + sCond + ")*";
    std::regex cCond(ccond_string);

    std::string cond_string = "((\\}?if|\\}elseif)\\(" + cCond + "\\)\\{" + RStmt + ")|(\\}else\\{" + RStmt + ")";
    std::regex Cond(cond_string);

    //std::vector<Instruction> instructions;

    std::string myServiceName;

    CompositionCompiler(std::string service) {
        myServiceName = service;
    }

    virtual ~CompositionCompiler() {}

    // throws ClaraException
    void compile(std::string iCode) {

        // reset();

        // use method call 'noBlanks' on iCode
        std::string pCode = noBlanks(iCode);

        std::vector<std::string> pp = preProcess(pCode);


    }

    std::string noBlanks(std::string sCode) {
        // todo : make code not have spaces in it
        return sCode;
    }

    std::vector<std::string> preProcess(std::string pCode) {
        std::vector<std::string> processed;
        // todo
        return processed;
    }

private:


};


#endif //CLARA_COMPOSITIONCOMPILER_H
