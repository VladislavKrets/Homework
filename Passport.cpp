//
// Created by lollipop on 05.04.20.
//

#include "Passport.h"

Passport::Passport(char *name, char *surname,
                    char *patronymic, char *birthdayDate,
                    int serial, int number, char *orderDate)  :
        name(name), surname(surname),
        patronymic(patronymic),
        birthdayDate(birthdayDate), serial(serial),
        number(number), orderDate(orderDate) {
}
Passport::~Passport(){
    delete[] name;
    delete[] surname;
    delete[] patronymic;
    delete[] birthdayDate;
    delete[] orderDate;
}
char* Passport::getName() {
    return this->name;
}
char* Passport::getSurname() {
    return this->surname;
}
char* Passport::getPatromic() {
    return this->patronymic;
}
char* Passport::getBirthdayDate() {
    return this->birthdayDate;
}
int Passport::getSerial() {
    return this->serial;
}
int Passport::getNumber() {
    return this->number;
}
char* Passport::getOrderDate() {
    return this->orderDate;
}
