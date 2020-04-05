//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_HOMEPOLICY_H
#define HOMEWORK_HOMEPOLICY_H


#include "Home.h"
#include "Policy.h"

class HomePolicy : public Policy {
    Home *home;
public:
    HomePolicy(Passport *passport, int serialNumber,
               char *startInsuranceDate,
               char *endInsuranceDate, char *company,
               char *policyInformation, Home *home);

    ~HomePolicy();

    Home *getHome();
    void print() override;
};


#endif //HOMEWORK_HOMEPOLICY_H
