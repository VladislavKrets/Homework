#include "ObligatorilyPolicy.h"
ObligatoralyPolicy::ObligatoralyPolicy(char *passport, int serialNumber, char *company, char *policyInformation)
                                       : Policy(passport, serialNumber, company,
                                               policyInformation) {}
ObligatoralyPolicy::ObligatoralyPolicy(char *passport, int serialNumber, char *company)
                                       : Policy(passport, serialNumber, company) {}
