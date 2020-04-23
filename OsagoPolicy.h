#ifndef HOMEWORK_OSAGOPOLICY_H
#define HOMEWORK_OSAGOPOLICY_H
#include "Policy.h"
class OsagoPolicy : public Policy {
    char *car;
public:
    OsagoPolicy(char *passport, int serialNumber, char *company,
                char *policyInformation, char *car);
    ~OsagoPolicy();
    char *getCar();
    void print() override;
};
#endif //HOMEWORK_OSAGOPOLICY_H
