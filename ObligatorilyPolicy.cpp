//
// Created by lollipop on 05.04.20.
//

#include "ObligatorilyPolicy.h"
ObligatoralyPolicy::ObligatoralyPolicy(Passport *passport, int serialNumber, char *company, char *policyInformation)
                                       : Policy(passport, serialNumber, company,
                                               policyInformation) {}
ObligatoralyPolicy::ObligatoralyPolicy(Passport *passport, int serialNumber, char *company)
                                       : Policy(passport, serialNumber, company) {}
