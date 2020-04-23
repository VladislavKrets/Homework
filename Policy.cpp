//
// Created by lollipop on 05.04.20.
//

#include "Policy.h"
Policy::Policy(Passport *passport, long serialNumber, char *company,
               char *policyInformation) :
        passport(passport), serialNumber(serialNumber),
        company(company), policyInformation(policyInformation) {}

Policy::Policy(Passport *passport, long serialNumber,
               char *company) :
        passport(passport), serialNumber(serialNumber),
        company(company), policyInformation("default info") {}
Policy::~Policy() {
    delete[] company;
    delete[] policyInformation;
}
Passport* Policy::getPassport() {
    return this->passport;
}
long Policy::getSerialNumber() {
    return this->serialNumber;
}
char* Policy::getPolicyInformation(){
    return this->policyInformation;
};
char* Policy::getCompany() {
    return this->company;
}
void Policy::setCompany(char *company) {
    delete[] this->company;
    this->company = company;
}
void Policy::setPolicyInformation(char *policyInformation) {
    delete[] this->policyInformation;
    this->policyInformation = policyInformation;
}
void Policy::print() {
    std::cout << "\t" << passport->getSurname() << std::endl;
    std::cout << "\t" << "Serial number: " << getSerialNumber() << std::endl;
    std::cout << "\t" << "Company: " << getCompany() << std::endl;
    std::cout << "\t" << "Policy information: " << getPolicyInformation() << std::endl;
}
int Policy::operator+(int param1){
    return param1 + 1;
}