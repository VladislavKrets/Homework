#include "HomePolicy.h"
HomePolicy::HomePolicy(char *passport, int serialNumber,
                       char *company, char *policyInformation, char *home)
        : Policy(passport, serialNumber,
                 company, policyInformation) {
    this->home = home;
}
HomePolicy::~HomePolicy() {
    delete home;
}
char* HomePolicy::getHome() {
    return this->home;
}
void HomePolicy::print() {
    Policy::print();
    std::cout << "\tHome info" << std::endl;
    std::cout << "\tAddress: " << home << std::endl;
}
