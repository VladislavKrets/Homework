//
// Created by lollipop on 05.04.20.
//

#include "Passport.h"
Passport::Passport(char *surname)  : surname(surname) {
}
Passport::~Passport(){
    delete[] surname;
}
char* Passport::getSurname() {
    return this->surname;
}

