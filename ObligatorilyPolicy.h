//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_OBLIGATORILYPOLICY_H
#define HOMEWORK_OBLIGATORILYPOLICY_H
#include "Policy.h"
class ObligatoralyPolicy : public Policy {
public:
    ObligatoralyPolicy(Passport *passport, int serialNumber, char *company,
                       char *policyInformation);
    ObligatoralyPolicy(Passport *passport, int serialNumber,  char *company);
};
#endif //HOMEWORK_OBLIGATORILYPOLICY_H
