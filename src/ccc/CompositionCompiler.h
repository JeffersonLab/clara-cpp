//
// Created by Patrick Hennis on 9/7/17.
//

#ifndef CLARA_COMPOSITIONCOMPILER_H
#define CLARA_COMPOSITIONCOMPILER_H


class CompositionCompiler {
public:
    auto IP = "([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})";
    auto STR = "([A-Z|a-z]+[0-9]*)";
    auto STR2 = "(%+[0-9]*)*";
    auto Sn = IP + STR2 + "_(java|python|cpp):" + STR + ":" + STR;
    auto RStmt = Sn + "(," + Sn + ")*" + "((\\+&?" + Sn + ")*|(\\+" + Sn + "(," + Sn + ")*)*)";
    auto sCond = Sn + "(==|!=)\"" + STR + "\"";
    auto cCond = sCond + "((&&|!!)" + sCond + ")*";
    auto Cond = "((\\}?if|\\}elseif)\\(" + cCond + "\\)\\{" + RStmt + ")|(\\}else\\{" + RStmt + ")";

    // vector containing instructions (java linked hash set)

    std::string myServiceName;

    CompositionCompiler(std::string service) {
        myServiceName = service;
    }

    virtual ~CompositionCompiler() {}

    // throws ClaraException
    void compile(std::string iCode) {

        // reset();

        // use method call 'noBlanks' on iCode
        std::string pCode = iCode;


    }

private:


};


#endif //CLARA_COMPOSITIONCOMPILER_H
