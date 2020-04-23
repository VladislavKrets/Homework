#include <iostream>
#include "task3.h"
using namespace std;
#include "HomePolicy.h"
#include "OsagoPolicy.h"
#include "ObligatorilyPolicy.h"
#include "LinkedList.h"
int getLineLength(char *line) {
    int count = 0; while (line[count] != '\0') count++; return count;
}
bool isLineEquals(char *first, char *second) {
    int firstLength = getLineLength(first);
    int secondLength = getLineLength(second);
    if (firstLength != secondLength) return false;
    for (int i = 0; i < firstLength; i++) if (first[i] != second[i]) return false;
    return true;
}
int countPoliciesBySurname(Policy **policies, int policiesCount, char *surname) {
    int count = 0;
    for (int i = 0; i < policiesCount; i++)
        if (isLineEquals(surname, policies[i]->getPassport())) count = *policies[i] + count;
    return count;
}
int countPoliciesBySurname(LinkedList<Policy*> * list, char *surname) {
    int count = 0;
    for (int i = 0; i < list->getSize(); i++)
        if (isLineEquals(surname, list->get(i)->getPassport())) count = *list->get(i) + count;
    return count;
}
void taskThreeRun() {
    char ** surnames = new char*[6]{"aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff"};
    int surname;
    LinkedList<Policy*> * list = new LinkedList<Policy *>();
    for (int i = 0; i < 10000; i++){
        //выбираем рандомом фамилию из списка
        surname = rand() % 6;
        list->add(new ObligatoralyPolicy(surnames[surname], i, "obl"));
    }
    for (int i = 0; i < 6; i++){
        std::cout << surnames[i] << " " << countPoliciesBySurname(list, surnames[i]) << std::endl;
    }
}

