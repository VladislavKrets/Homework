//
// Created by lollipop on 05.04.20.
//

#include "Car.h"

Car::Car(char *number, char *model, int capacity, int power) :
        number(number), model(model),
        capacity(capacity), power(power) {}
Car::~Car() {
    delete[] number;
    delete[] model;
}
char* Car::getNumber() {
    return this->number;
}
char* Car::getModel() {
    return this->model;
}
int Car::getCapacity() {
    return this->capacity;
}
int Car::getPower() {
    return this->power;
}