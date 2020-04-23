#ifndef HOMEWORK_HOMEPOLICY_H
#define HOMEWORK_HOMEPOLICY_H
#include "Policy.h"
class HomePolicy : public Policy {
    char *home;
public:
    HomePolicy(char *passport, int serialNumber,  char *company,
               char *policyInformation, char *home);
    ~HomePolicy();
    char *getHome();
    void print() override;
};
#endif //HOMEWORK_HOMEPOLICY_H
