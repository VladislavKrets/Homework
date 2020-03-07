#include <iostream>
#include "task3.h"
using namespace std;

const int PAIR_COUNT = 3;
const int OBLIGATORY_INDEX = 0;
const int OSAGO_INDEX = 1;
const int HOME_INDEX = 2;


class Passport{
    char * name;
    char * surname;
    char * patronymic;
    char * birthdayDate;
    int serial;
    int number;
    char * orderDate;
    
    public:
        Passport(char * name, char * surname,
            char * patronymic, char *  birthdayDate,
            int serial, int number, char * orderDate):
            name(name), surname(surname),
            patronymic(patronymic),
            birthdayDate(birthdayDate), serial(serial),
            number(number), orderDate(orderDate) {
            
        }
        
        ~Passport(){
            delete [] name;
            delete [] surname;
            delete [] patronymic;
            delete [] birthdayDate;
            delete [] orderDate;
        }

        char * getName(){
            return this->name;
        }
        
        char * getSurname(){
            return this->surname;
        }
        
        char * getPatromic(){
            return this->patronymic;
        }
        
        char * getBirthdayDate(){
            return this->birthdayDate;
        }
        
        int getSerial(){
            return this->serial;
        }
        
        int getNumber(){
            return this->number;
        }
        
        char * getOrderDate(){
            return this->orderDate;
        }
        
};

class Car{
    char * number;
    char * model;
    int capacity;
    int power;
    
    public:
        Car(char * number, char * model,
            int capacity, int power):
            number(number), model(model),
            capacity(capacity), power(power){
            
        }
        
        ~Car(){
            delete [] number;
            delete [] model;
        }

        char * getNumber(){
            return this->number;
        }
        
        char * getModel(){
            return this->model;
        }
        
        int getCapacity(){
            return this->capacity;
        }
        
        int getPower(){
            return this->power;
        }
};

class Home{
    char * address;
    int ownersCount;
    int space;
    
    public:
        Home(char * address, int ownersCount, int space):
            address(address), ownersCount(ownersCount), space(space){
            
        }

        ~Home(){
            delete [] address;
        }
};

class Policy{
    Passport * passport;
    long serialNumber;
    char * startInsuranceDate;
    char * endInsuranceDate;
    char * company;
    char * policyInformation;
    
    public:
        Policy(Passport * passport, long serialNumber,
            char * startInsuranceDate,
            char * endInsuranceDate, char * company, char * policyInformation):
            passport(passport), serialNumber(serialNumber),
            startInsuranceDate(startInsuranceDate),
            company(company),
            endInsuranceDate(endInsuranceDate), policyInformation(policyInformation){
            
        }
        
        ~Policy(){
            delete [] startInsuranceDate;
            delete [] endInsuranceDate;
            delete [] company;
            delete [] policyInformation;
        }

        Passport * getPassport(){
            return this->passport;
        }
        
        long getSerialNumber(){
            return this->serialNumber;
        }
        
        char * getStartInsuranceDate(){
            return this->startInsuranceDate;
        }
        
        char * getEndInsuranceDate(){
            return this->endInsuranceDate;
        }
        
        char * getPolicyInformation(){
            return this->policyInformation;
        }
        
        char * getCompany(){
            return this->company;
        }

        void setCompany(char * company){
            delete [] this->company;
            this->company = company;
        }
        
        void setPolicyInformation(char * policyInformation){
            delete [] this->policyInformation;
            this->policyInformation = policyInformation;
        }
		friend int countPoliciesBySurname(Policy ** policies,
			int policiesCount, char * surname);
    
};

class ObligatoralyPolicy: public Policy{
    public:
        ObligatoralyPolicy(Passport * passport, int serialNumber,
            char * startInsuranceDate,
            char * endInsuranceDate, char * company,
            char * policyInformation) : Policy(passport, serialNumber,
            startInsuranceDate, endInsuranceDate, company, policyInformation){
                
            }

};

class OsagoPolicy: public Policy{
    Car * car;
    public:
        OsagoPolicy(Passport * passport, int serialNumber,
            char * startInsuranceDate,
            char * endInsuranceDate, char * company,
            char * policyInformation, Car * car) : Policy(passport, serialNumber,
            startInsuranceDate, endInsuranceDate,
            company, policyInformation){
                this->car = car;
            }
        
        ~OsagoPolicy(){
            delete car;
        }

        Car * getCar(){
            return this->car;
        }
};

class HomePolicy: public Policy{
    Home * home;
    public:
        HomePolicy(Passport * passport, int serialNumber,
            char * startInsuranceDate,
            char * endInsuranceDate, char * company,
            char * policyInformation, Home * home) : Policy(passport, serialNumber,
            startInsuranceDate, endInsuranceDate,
            company, policyInformation){
                this->home = home;
            }
        ~HomePolicy(){
            delete home;
        }
        Home * getHome(){
            return this->home;
        }
};

int enterPassport(Passport ** passports, int passportsCount){
    char * name = new char[255];
    char * surname = new char[255];
    char * patronymic = new char[255];
    char * birthdayDate = new char[255];
    int serial = 0;
    int number = 0;
    char * orderDate = new char[255];

    cout << "Entering passport data.." << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << endl << "Enter your surname: ";
    cin >> surname;
    cout << endl << "Enter your patronymic: ";
    cin >> patronymic;
    cout << endl << "Enter your birthday date: ";
    cin >> birthdayDate;
    cout << endl << "Enter serial: ";
    cin >> serial;
    cout << endl << "Enter number: ";
    cin >> number;
    cout << endl << "Enter passport ordered day: ";
    cin >> orderDate;
    cout << endl << "Passport has been added" << endl;

    Passport * passport = new Passport(name, surname, patronymic,
     birthdayDate, serial, number, orderDate); 
    passports[passportsCount] = passport;
    return passportsCount + 1;
}

Car * enterCar(){
    char * number = new char[255];
    char * model = new char[255];
    int capacity = 0;
    int power = 0;
    
    cout << "Entering car data.." << endl;
    cout << "Enter car number: ";
    cin >> number;
    cout << endl << "Enter car model: ";
    cin >> model;
    cout << endl << "Enter car capacity: ";
    cin >> capacity;
    cout << endl << "Enter car power: ";
    cin >> power;
    cout << endl << "Car has been entered" << endl;

    Car * car = new Car(number, model, capacity, power);
    return car;
}

Home * enterHome(){
    char * address = new char[255];
    int ownersCount = 0;
    int space = 0;

    cout << "Entering home data.." << endl;
    cout << "Enter home address: ";
    cin >> address;
    cout << endl << "Enter owners count: ";
    cin >> ownersCount;
    cout << endl << "Enter space: ";
    cin >> space;
    cout << endl << "Home has been entered" << endl;
}

Policy * enterPolicy(Passport * passport, int policyType){
    long serialNumber = 0;
    char * startInsuranceData = new char[255];
    char * endInsuranceData = new char[255];
    char * company = new char[255];
    char * policyInformation = new char[255];

    cout << "Entering obligatorily policy data.." << endl;
    cout << "Enter policy serial number: ";
    cin >> serialNumber;
    cout << endl << "Enter start insurance data: ";
    cin >> startInsuranceData;
    cout << endl << "Enter end insurance data: ";
    cin >> endInsuranceData;
    cout << endl << "Enter company: ";
    cin >> company;
    cout << endl << "Enter policy information: ";
    cin >> policyInformation;
    Policy * policy;
    switch (policyType)
    {
    case OBLIGATORY_INDEX:{
        policy = new ObligatoralyPolicy(passport, serialNumber, startInsuranceData,
         endInsuranceData, company, policyInformation);

        return policy;
    }
    case OSAGO_INDEX:{
        cout << endl << "Enter car data:" << endl;
        Car * car = enterCar();
        policy = new OsagoPolicy(passport, serialNumber, startInsuranceData,
         endInsuranceData, company, policyInformation, car);
         return policy;
    }
    case HOME_INDEX:{
        cout << endl << "Enter home data:" << endl;
        Home * home = enterHome();
        policy = new HomePolicy(passport, serialNumber, startInsuranceData,
         endInsuranceData, company, policyInformation, home);
         return policy;
        }
    }
    return 0;

}

void printPassportInfo(int index, Passport * passport){
    cout << "Passport index: " << index << endl;
    cout << "\t" << "Name: " << passport->getName() << endl;
    cout << "\t" << "Surname: " << passport->getSurname() << endl;
    cout << "\t" << "Patromic: " << passport->getPatromic() << endl;
    cout << "\t" << "Birthday date: " << passport->getBirthdayDate() << endl;
    cout << "\t" << "Serial: " << passport->getSerial() << endl;
    cout << "\t" << "Number: " << passport->getNumber() << endl;
    cout << "\t" << "Order date: " << passport->getOrderDate() << endl;
}

void printPassportList(Passport ** passports, int passportsCount){
    for (int i = 0; i < passportsCount; i++){
        printPassportInfo(i, passports[i]);
    }
}

int getLineLength(char * line){
    int count = 0;
    while (line[count] != '\0') count++;
    return count;
}

bool isLineEquals(char * first, char * second){
    int firstLength = getLineLength(first);
    int secondLength = getLineLength(second);
    if (firstLength != secondLength) return false;

    for (int i = 0; i < firstLength; i++){
        if (first[i] != second[i]) return false;
    }
    return true;
}

char * cloneLine(char * line){
    int length = getLineLength(line);
    char * newLine = new char[length + 1];
    for (int i = 0; i < length; i++) newLine[i] = line[i];
    newLine[length] = '\0';
    return newLine;
}

struct Pair
{
    char * key;
    int index;

    Pair(char * key, int index): key(key), index(index){

    }
};

int getIndexByPolicyName(Pair ** pairs, int policyCount, char * command){
    for (int i = 0; i < policyCount; i++){
        if (isLineEquals(command, pairs[i]->key)) return pairs[i]->index;
    }
    return -1;
}

Pair ** initPairs(){
    Pair ** pairs = new Pair*[PAIR_COUNT];
    pairs[OBLIGATORY_INDEX] = new Pair("obl_policy", OBLIGATORY_INDEX);
    pairs[OSAGO_INDEX] = new Pair("os_policy", OSAGO_INDEX);
    pairs[HOME_INDEX] = new Pair("ho_policy", HOME_INDEX);
    return pairs;
}

void printPolicy(int index, Policy * policy){
    cout << "Policy index: " << index << endl;
    cout << "\t" << "Serial number: " << policy->getSerialNumber() << endl;
    cout << "\t" << "Start insurance date: " << policy->getStartInsuranceDate() << endl;
    cout << "\t" << "End insurance date: " << policy->getEndInsuranceDate() << endl;
    cout << "\t" << "Company: " << policy->getCompany() << endl;
    cout << "\t" << "Policy information: " << policy->getPolicyInformation() << endl;
}

void printPolicyList(Policy ** policies, int policiesCount){
    if (policiesCount == 0){
        cout << "There are no policies yet" << endl;
    }
    else {
        for (int i = 0; i < policiesCount; i++){
            printPolicy(i, policies[i]);
        }
    }
}

void editPolicy(Policy ** policies){
    int policyIndex = -1;
    Policy * currPolicy;
    char * command = new char[255];
    cout << "Enter policy index: ";
    cin >> policyIndex;
    currPolicy = policies[policyIndex];
    while(true){
        cout << endl << "Enter command (company, info):" << endl;
        cin >> command;
        if (isLineEquals(command, "company")){
            cout << "Enter company name: ";
            cin >> command;
            currPolicy->setCompany(cloneLine(command));
            cout << endl << "Company name has been changed" << endl;
            break;
        }
        else if (isLineEquals(command, "info")){
            cout << "Enter policy info: ";
            cin >> command;
            currPolicy->setPolicyInformation(cloneLine(command));
            cout << endl << "Policy info has been changed" << endl;
            break;
        }
        else {
            cout << "Wrong command. reenter the command." << endl;
        }
    }
}

int countPoliciesBySurname(Policy ** policies, int policiesCount, char * surname){
    int count = 0;
    for (int i = 0; i < policiesCount; i++){
        if (isLineEquals(surname, policies[i]->getPassport()->getSurname())){
            count++;
        }
    }
    return count;
}

void taskThreeRun(){
	int passportsSize = 0;
	int policiesSize = 0;
	
	cout << "Enter passports count: " << endl;
	cin >> passportsSize;
	cout << "Enter policies count:" << endl;
	cin >>policiesSize;
	
	Passport ** passports = new Passport*[passportsSize];
    Policy ** policies = new Policy*[policiesSize];
    Pair ** pairs = initPairs();
    int passportsCount = 0;
    int policiesCount = 0;
    cout << "Enter passport" << endl;
    passportsCount = enterPassport(passports, passportsCount);
    cout << "All passports info: " << endl;
    printPassportList(passports, passportsCount);
    char * command = new char[255];
    Policy * currPolicy;
    int passportIndex = 0;
    int policyIndex = -1;
    while(true){
        cout << "Enter command (passport_list, policies_list, passport_enter, obl_policy, os_policy, ho_policy, choose_policy, count):" << endl;
        cin >> command;
        policyIndex = getIndexByPolicyName(pairs,  PAIR_COUNT, command);
        if (isLineEquals(command, "passport_list")){
            printPassportList(passports, passportsCount);
        }
        else if (isLineEquals(command, "passport_enter")){
            passportsCount = enterPassport(passports, passportsCount);
        }
        else if (policyIndex != -1){
            cout << "Enter passport index for policy: ";
            cin >> passportIndex;
            cout << endl; 
            currPolicy = enterPolicy(passports[passportIndex], policyIndex);
            policies[policiesCount] = currPolicy;
            policiesCount++;
        }
        else if (isLineEquals(command, "policies_list")){
            printPolicyList(policies, policiesCount);
        }
        else if (isLineEquals(command, "choose_policy")){
            editPolicy(policies);
        }
        else if (isLineEquals(command, "count")){
            cout << "Enter surname to search: " << endl;
            cin >> command;
            cout << "Policies count associated with surname " << command; 
            cout <<" is " << countPoliciesBySurname(policies, policiesCount, command) << endl;
        }
        else{
            cout << "Wrong command. reenter the command." << endl;
        }
        cout << "Do you want to continue? y/n" << endl;
        cin >> command;
        if (!isLineEquals(command, "y")){
            break;
        }
    }
}

