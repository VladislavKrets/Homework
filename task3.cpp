#include <iostream>
#include "task3.h"
using namespace std;
#include "HomePolicy.h"
#include "OsagoPolicy.h"
#include "ObligatorilyPolicy.h"
#include "LinkedList.h"
const int PAIR_COUNT = 3; const int OBLIGATORY_INDEX = 0;
const int OSAGO_INDEX = 1; const int HOME_INDEX = 2;
int enterPassport(Passport **passports, int passportsCount) {
    char *name = new char[255]; char *surname = new char[255];
    int serial = 0; int number = 0;
    cout << "Entering passport data.." << endl;
    cout << endl << "Enter your surname: "; cin >> surname;
    Passport *passport = new Passport(surname);
    passports[passportsCount] = passport;
    return passportsCount + 1;
}
Car *enterCar() {
    char *number = new char[255]; char *model = new char[255];
    cout << "Entering car data.." << endl;
    cout << "Enter car number: "; cin >> number;
    cout << endl << "Enter car model: "; cin >> model;
    cout << endl << "Car has been entered" << endl;
    Car *car = new Car(number, model); return car;
}
Home *enterHome() {
    char *address = new char[255]; int space = 0;
    cout << "Entering home data.." << endl;
    cout << "Enter home address: "; cin >> address;
    cout << endl << "Enter space: "; cin >> space;
    cout << endl << "Home has been entered" << endl;
    return new Home(address, space);
}
Policy *enterPolicy(Passport *passport, int policyType) {
    int serialNumber = 0; char *company = new char[255];
    char *policyInformation = new char[255];
    cout << "Entering policy data.." << endl;
    cout << "Enter policy serial number: "; cin >> serialNumber;
    cout << endl << "Enter company: "; cin >> company;
    cout << endl << "Enter policy information: "; cin >> policyInformation;
    Policy *policy;
    switch (policyType) {
        case OBLIGATORY_INDEX: {
            policy = new ObligatoralyPolicy(passport, serialNumber, company, policyInformation);
            return policy;
        }
        case OSAGO_INDEX: {
            cout << endl << "Enter car data:" << endl;
            Car *car = enterCar();
            policy = new OsagoPolicy(passport, serialNumber, company, policyInformation, car);
            return policy;
        }
        case HOME_INDEX: {
            cout << endl << "Enter home data:" << endl;
            Home *home = enterHome();
            policy = new HomePolicy(passport, serialNumber, company, policyInformation, home);
            return policy;
        }
    }
    return 0;
}
void printPassportInfo(int index, Passport *passport) {
    cout << "Passport index: " << index << endl;
    cout << "\t" << "Surname: " << passport->getSurname() << endl;
}
void printPassportList(Passport **passports, int passportsCount) {
    for (int i = 0; i < passportsCount; i++) printPassportInfo(i, passports[i]);

}
int getLineLength(char *line) {
    int count = 0; while (line[count] != '\0') count++; return count;
}
bool isLineEquals(char *first, char *second) {
    int firstLength = getLineLength(first);
    int secondLength = getLineLength(second);
    if (firstLength != secondLength) return false;
    for (int i = 0; i < firstLength; i++) if (first[i] != second[i]) return false;
    return true;
}
char *cloneLine(char *line) {
    int length = getLineLength(line);
    char *newLine = new char[length + 1];
    for (int i = 0; i < length; i++) newLine[i] = line[i];
    newLine[length] = '\0';
    return newLine;
}
struct Pair {
    char *key;
    int index;
    Pair(char *key, int index) : key(key), index(index) {}
};
int getIndexByPolicyName(Pair **pairs, int policyCount, char *command) {
    for (int i = 0; i < policyCount; i++) if (isLineEquals(command, pairs[i]->key)) return pairs[i]->index;
    return -1;
}
Pair **initPairs() {
    Pair **pairs = new Pair *[PAIR_COUNT];
    pairs[OBLIGATORY_INDEX] = new Pair("obl_policy", OBLIGATORY_INDEX);
    pairs[OSAGO_INDEX] = new Pair("os_policy", OSAGO_INDEX);
    pairs[HOME_INDEX] = new Pair("ho_policy", HOME_INDEX);
    return pairs;
}
void printPolicy(int index, Policy *policy) {
    cout << "Policy index: " << index << endl;
    policy->print();
}
void printPolicyList(Policy **policies, int policiesCount) {
    if (policiesCount == 0) cout << "There are no policies yet" << endl;
    else for (int i = 0; i < policiesCount; i++) printPolicy(i, policies[i]);
}
void editPolicy(Policy **policies) {
    int policyIndex = -1; Policy *currPolicy;
    char *command = new char[255];
    cout << "Enter policy index: "; cin >> policyIndex;
    currPolicy = policies[policyIndex];
    while (true) {
        cout << endl << "Enter command (company, info):" << endl;
        cin >> command;
        if (isLineEquals(command, "company")) {
            cout << "Enter company name: "; cin >> command;
            currPolicy->setCompany(cloneLine(command));
            cout << endl << "Company name has been changed" << endl;
            break;
        } else if (isLineEquals(command, "info")) {
            cout << "Enter policy info: "; cin >> command;
            currPolicy->setPolicyInformation(cloneLine(command));
            cout << endl << "Policy info has been changed" << endl;
            break;
        } else cout << "Wrong command. reenter the command." << endl;
    }
}
int countPoliciesBySurname(Policy **policies, int policiesCount, char *surname) {
    int count = 0;
    for (int i = 0; i < policiesCount; i++)
        if (isLineEquals(surname, policies[i]->getPassport()->getSurname())) count = *policies[i] + count;
    return count;
}
int countPoliciesBySurname(LinkedList<Policy*> * list, char *surname) {
    int count = 0;
    for (int i = 0; i < list->getSize(); i++)
        if (isLineEquals(surname, list->get(i)->getPassport()->getSurname())) count = *list->get(i) + count;
    return count;
}
void taskThreeRun() {
    char ** surnames = new char*[6]{"aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff"};
    int surname;
    LinkedList<Policy*> * list = new LinkedList<Policy *>();
    for (int i = 0; i < 10000; i++){
        surname = rand() % 6;
        list->add(new ObligatoralyPolicy(new Passport(surnames[surname]), i, "obl"));
    }
    for (int i = 0; i < 6; i++){
        std::cout << surnames[i] << " " << countPoliciesBySurname(list, surnames[i]) << std::endl;
    }
}

