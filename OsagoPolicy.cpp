#include "OsagoPolicy.h"
OsagoPolicy::OsagoPolicy(char *passport, int serialNumber,
                         char *company, char *policyInformation, char *car)
        : Policy(passport, serialNumber,
                 company, policyInformation) {
    this->car = car;
}
OsagoPolicy::~OsagoPolicy() {
    delete car;
}
char* OsagoPolicy::getCar() {
    return this->car;
}
void OsagoPolicy::print(){
    Policy::print();
    std::cout << "\tCar info" << std::endl;
    std::cout << "\tNumber: " << car << std::endl;
}