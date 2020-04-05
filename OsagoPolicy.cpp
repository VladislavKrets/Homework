//
// Created by lollipop on 05.04.20.
//

#include "OsagoPolicy.h"

OsagoPolicy::OsagoPolicy(Passport *passport, int serialNumber, char *startInsuranceDate, char *endInsuranceDate,
                         char *company, char *policyInformation, Car *car)
        : Policy(passport, serialNumber,
                 startInsuranceDate, endInsuranceDate,
                 company, policyInformation) {
    this->car = car;
}
OsagoPolicy::~OsagoPolicy() {
    delete car;
}
Car* OsagoPolicy::getCar() {
    return this->car;
}