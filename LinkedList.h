#ifndef HOMEWORK_LINKEDLIST_H
#define HOMEWORK_LINKEDLIST_H
#include <bits/exception.h>
template<class T>
class Node {
public:
    Node *next;
    T t;
    Node(T t) {
        this->next = nullptr;
        this->t = t;
    }
};
template<class T>
class LinkedList {
    Node<T> *firstNode;
    Node<T> *lastNode;
    int size;
public:
    LinkedList() {
        firstNode = nullptr;
        lastNode = nullptr;
        size = 0;
    }
    void add(T t) {
        if (firstNode == nullptr) {
            firstNode = new Node<T>(t);
            lastNode = firstNode;
        } else {
            lastNode->next = new Node<T>(t);
            lastNode = lastNode->next;
        }
        size++;
    }
    bool remove(int index) {
        if (index >= size) return false;
        if (index == size - 1) {
            delete lastNode;
            size--;
            Node<T> *current = firstNode;
            for (int i = 1; i < size; i++) {
                lastNode = current->next;
            }
            return true;
        }
        Node<T> *current = firstNode;
        Node<T> *temp = nullptr;
        int i = 0;
        while (current != nullptr) {
            if (i == index - 1 && current->next != nullptr) {
                temp = current->next;
                current->next = temp->next;
                delete temp;
                size--;
                return true;
            }
            current = current->next;
            i++;
        }
        return false;
    }
    void insert(T t, int index) {
        if (index < 0) throw new std::exception();
        if (index >= size) {
            add(t);
        } else {
            Node<T> *current = firstNode;
            Node<T> *temp = new Node<T>(t);
            int i = 0;
            while (current != nullptr) {
                if (i == index - 1) {
                    temp->next = current->next;
                    current->next = temp;
                    size++;
                    break;
                }
                current = current->next;
                i++;
            }
        }
    }
    T get(int index) {
        if (index >= size || index < 0) throw std::exception();
        Node<T> *current = firstNode;
        for (int i = 0; i < size; i++) {
            if (i == index) return current->t;
            current = current->next;
        }
        throw std::exception();
    }
    int getSize() {
        return size;
    }
};


#endif //HOMEWORK_LINKEDLIST_H
