//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_CAR_H
#define HOMEWORK_CAR_H


class Car {
    char *number;
    char *model;
    int capacity;
    int power;

public:
    Car(char *number, char *model,
        int capacity, int power);

    ~Car();

    char *getNumber();

    char *getModel();

    int getCapacity();

    int getPower();
};


#endif //HOMEWORK_CAR_H
