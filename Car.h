//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_CAR_H
#define HOMEWORK_CAR_H
class Car {
    char *number;
    char *model;
public:
    Car(char *number, char *model);
    ~Car();
    char *getNumber();
    char *getModel();
};
#endif //HOMEWORK_CAR_H
