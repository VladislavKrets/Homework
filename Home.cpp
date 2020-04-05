//
// Created by lollipop on 05.04.20.
//

#include "Home.h"

Home::Home(char *address, int ownersCount, int space) :
        address(address), ownersCount(ownersCount), space(space) {}
Home::~Home() {
    delete[] address;
}

char *Home::getAddress() const {
    return address;
}

int Home::getOwnersCount() const {
    return ownersCount;
}

int Home::getSpace() const {
    return space;
}
