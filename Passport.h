//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_PASSPORT_H
#define HOMEWORK_PASSPORT_H


class Passport {
    char *name;
    char *surname;
    char *patronymic;
    char *birthdayDate;
    int serial;
    int number;
    char *orderDate;

public:
    Passport(char *name, char *surname,
             char *patronymic, char *birthdayDate,
             int serial, int number, char *orderDate);

    ~Passport();

    char *getName();

    char *getSurname();

    char *getPatromic();

    char *getBirthdayDate();

    int getSerial();

    int getNumber();

    char *getOrderDate();
};


#endif //HOMEWORK_PASSPORT_H
