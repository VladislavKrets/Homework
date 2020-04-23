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
    Home(char *address, int space);
    ~Home();
    char *getAddress();
    int getSpace();
};
#endif //HOMEWORK_HOME_H
