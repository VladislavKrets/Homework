//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_PASSPORT_H
#define HOMEWORK_PASSPORT_H
class Passport {
    char *surname;
public:
    Passport( char *surname);
    ~Passport();
    char *getSurname();
};
#endif //HOMEWORK_PASSPORT_H
