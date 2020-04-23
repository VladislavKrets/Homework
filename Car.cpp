//
// Created by lollipop on 05.04.20.
//

#include "Car.h"
Car::Car(char *number, char *model) :
        number(number), model(model) {}
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