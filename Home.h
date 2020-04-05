//
// Created by lollipop on 05.04.20.
//

#ifndef HOMEWORK_HOME_H
#define HOMEWORK_HOME_H


class Home {
    char *address;
    int ownersCount;
    int space;

public:
    Home(char *address, int ownersCount, int space);

    ~Home();

    char *getAddress() const;

    int getOwnersCount() const;

    int getSpace() const;
};


#endif //HOMEWORK_HOME_H
