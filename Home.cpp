//
// Created by lollipop on 05.04.20.
//

#include "Home.h"

Home::Home(char *address, int space) :
        address(address), space(space) {}
Home::~Home() {
    delete[] address;
}

char *Home::getAddress(){
    return address;
}

int Home::getSpace(){
    return space;
}
