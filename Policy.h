//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_POLICY_H
#define HOMEWORK_POLICY_H


#include "Passport.h"
#include "iostream"

class Policy {
    Passport *passport;
    long serialNumber;
    char *startInsuranceDate;
    char *endInsuranceDate;
    char *company;
    char *policyInformation;

public:
    Policy(Passport *passport, long serialNumber,
           char *startInsuranceDate,
           char *endInsuranceDate, char *company, char *policyInformation);

    Policy(Passport *passport, long serialNumber,
           char *startInsuranceDate,
           char *endInsuranceDate, char *company);

    ~Policy();

    Passport *getPassport();

    long getSerialNumber();

    char *getStartInsuranceDate();

    char *getEndInsuranceDate();

    char *getPolicyInformation();

    char *getCompany();

    void setCompany(char *company);

    void setPolicyInformation(char *policyInformation);

    friend int countPoliciesBySurname(Policy **policies,
                                      int policiesCount, char *surname);

    virtual void print();

    int operator+(int param1);
};


#endif //HOMEWORK_POLICY_H
