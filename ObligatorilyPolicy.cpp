//
// Created by lollipop on 05.04.20.
//

#include "ObligatorilyPolicy.h"

ObligatoralyPolicy::ObligatoralyPolicy(Passport *passport, int serialNumber, char *startInsuranceDate,
                                       char *endInsuranceDate, char *company, char *policyInformation)
                                       : Policy(passport, serialNumber,
                                               startInsuranceDate, endInsuranceDate, company,
                                               policyInformation) {}
ObligatoralyPolicy::ObligatoralyPolicy(Passport *passport, int serialNumber, char *startInsuranceDate,
                                       char *endInsuranceDate, char *company)
                                       : Policy(passport, serialNumber,
                                               startInsuranceDate, endInsuranceDate, company) {}
