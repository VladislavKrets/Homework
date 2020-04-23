//
// Created by lollipop on 05.04.20.
//

#include "OsagoPolicy.h"
OsagoPolicy::OsagoPolicy(Passport *passport, int serialNumber,
                         char *company, char *policyInformation, Car *car)
        : Policy(passport, serialNumber,
                 company, policyInformation) {
    this->car = car;
}
OsagoPolicy::~OsagoPolicy() {
    delete car;
}
Car* OsagoPolicy::getCar() {
    return this->car;
}
void OsagoPolicy::print(){
    Policy::print();
    std::cout << "\tCar info" << std::endl;
    std::cout << "\tNumber: " << car->getNumber() << std::endl;
    std::cout << "\tModel: " << car->getModel() << std::endl;
}