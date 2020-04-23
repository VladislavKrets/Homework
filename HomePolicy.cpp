//
// Created by lollipop on 05.04.20.
//

#include "HomePolicy.h"
HomePolicy::HomePolicy(Passport *passport, int serialNumber,
                       char *company, char *policyInformation, Home *home)
        : Policy(passport, serialNumber,
                 company, policyInformation) {
    this->home = home;
}
HomePolicy::~HomePolicy() {
    delete home;
}
Home* HomePolicy::getHome() {
    return this->home;
}
void HomePolicy::print() {
    Policy::print();
    std::cout << "\tHome info" << std::endl;
    std::cout << "\tAddress: " << home->getAddress() << std::endl;
    std::cout << "\tSpace: " << home->getSpace() << std::endl;
}
