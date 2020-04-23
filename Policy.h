#ifndef HOMEWORK_POLICY_H
#define HOMEWORK_POLICY_H
#include "iostream"
class Policy {
    char*passport;
    long serialNumber;
    char *company;
    char *policyInformation;
public:
    Policy(char*passport, long serialNumber, char *company, char *policyInformation);
    Policy(char *passport, long serialNumber,char *company);
    ~Policy();
    char *getPassport();
    long getSerialNumber();
    char *getPolicyInformation();
    char *getCompany();
    void setCompany(char *company);
    void setPolicyInformation(char *policyInformation);
    friend int countPoliciesBySurname(Policy **policies,
                                      int policiesCount, char *surname);
    virtual void print();
    int operator+(int param1);
};
#endif //HOMEWORK_POLICY_H
