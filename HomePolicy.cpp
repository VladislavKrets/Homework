//
// Created by lollipop on 05.04.20.
//

#include "HomePolicy.h"

HomePolicy::HomePolicy(Passport *passport, int serialNumber, char *startInsuranceDate, char *endInsuranceDate,
                       char *company, char *policyInformation, Home *home)
        : Policy(passport, serialNumber,
                 startInsuranceDate,
                 endInsuranceDate,
                 company, policyInformation) {
    this->home = home;
}
HomePolicy::~HomePolicy() {
    delete home;
}
Home* HomePolicy::getHome() {
    return this->home;
}