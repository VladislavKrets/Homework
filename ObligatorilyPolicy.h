#ifndef HOMEWORK_OBLIGATORILYPOLICY_H
#define HOMEWORK_OBLIGATORILYPOLICY_H
#include "Policy.h"
class ObligatoralyPolicy : public Policy {
public:
    ObligatoralyPolicy(char *passport, int serialNumber, char *company,
                       char *policyInformation);
    ObligatoralyPolicy(char *passport, int serialNumber,  char *company);
};
#endif //HOMEWORK_OBLIGATORILYPOLICY_H
