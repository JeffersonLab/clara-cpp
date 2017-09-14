//
// Created by Patrick Hennis on 9/13/17.
//

#ifndef CLARA_SERVICESTATE_H
#define CLARA_SERVICESTATE_H
#include <vector>
#include <string>
#include "../constants.hpp"

class ServiceState {
public:
    ServiceState(std::string nameP, std::string stateP) {
        name = nameP;
        state = stateP;
    }

    std::string getName() {
        return name;
    }

    std::string getState() {
        return state;
    }

    void setState(String s_state) {
        state = s_state;
    }

   
private:
    std::string name = clara::constants::udf;
    std::string state = clara::constants::udf;
};

#endif //CLARA_SERVICESTATE_H
