//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_OSAGOPOLICY_H
#define HOMEWORK_OSAGOPOLICY_H


#include "Policy.h"
#include "Car.h"

class OsagoPolicy : public Policy {
    Car *car;
public:
    OsagoPolicy(Passport *passport, int serialNumber,
                char *startInsuranceDate,
                char *endInsuranceDate, char *company,
                char *policyInformation, Car *car);

    ~OsagoPolicy();

    Car *getCar();
    void print() override;
};


#endif //HOMEWORK_OSAGOPOLICY_H
