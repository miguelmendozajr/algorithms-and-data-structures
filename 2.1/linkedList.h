#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"  
#include <iostream>

template <class T>
class linkedList {
private:
    node<T> *head;
    int size;

public:
    linkedList();
    ~linkedList();
    void print();
    void addFirst(T);
    T read(int);
    linkedList& update(int, T);
    linkedList& del(int);
};

template <class T>
linkedList<T>::linkedList() {
    size = 0;
    head = nullptr;
}

template <class T>
linkedList<T>::~linkedList() {
    node<T> *node, *next;
    node = head;
    while (node != nullptr) {
        next = node->getNext();
        delete node;
        node = next;
    }
    head = nullptr;
    size = 0;
}

// Como iteramos por toda la lista donde hay n nodos, la complejidad es de
// O(n).
template <class T>
void linkedList<T>::print() {
    node<T> *node;
    node = head;
    while (node != nullptr) {
        std::cout << node->getData() << " ";
        node = node->getNext();
    }
    std::cout << std::endl;
}

// Puede que no existan nodos, o puede que si, pero al estar ya enlazados 
// solo tenemos que indicar la cabeza, por lo que la complejidad es O(1).
template <class T>
void linkedList<T>::addFirst(T data) {
    node<T> *node;
    node = new ::node<T>(data, head);
    head = node;
    size++;
}

// En el mejor caso, cuando el índice es 0, la complejidad sería O(1). 
// Sin embargo, si tenemos un índice mayor tendríamos que iterar hasta 
// llegar a dicho nodo, por lo que la complejidad sería O(n).
template<class T>
T linkedList<T>::read(int index){
    if (index < 0 || index >= size || head == nullptr) {
        std::cout<<"Error: El índice no existe"<<std::endl;
        return T();
    }
    node<T> *current = head;
    int currentIndex = 0;
    while (currentIndex < index) {
        current = current->getNext();
        currentIndex++;
    }
    return current->getData();
}

// En el mejor caso, cuando el índice es 0, la complejidad sería O(1). 
// Sin embargo, si tenemos un índice mayor tendríamos que iterar hasta 
// llegar a dicho nodo, por lo que la complejidad sería O(n).
template<class T>
linkedList<T>& linkedList<T>::update(int index, T data){
    if (index < 0 || index >= size || head == nullptr) {
        std::cout<<"Error: El índice no existe"<<std::endl;
        return *this;
    };

    node<T> *current = head;
    int currentIndex = 0;
    while (currentIndex < index) {
        current = current->getNext();
        currentIndex++;
    }
    current->setData(data);
    return *this;
};

// En el mejor caso, cuando el índice es 0, la complejidad sería O(1). 
// Sin embargo, si tenemos un índice mayor tendríamos que iterar hasta 
// llegar a dicho nodo, por lo que la complejidad sería O(n).
template<class T>
linkedList<T>& linkedList<T>::del(int index){
    if (index < 0 || index >= size || head == nullptr) {
        std::cout<<"Error: El índice no existe"<<std::endl;
        return *this;
    };

    if (index == 0){
        node<T>* aux = head;
        head = head->getNext();
        delete aux;
    } else {
        node<T> *prev = head;
        for (int i = 1; i < index; i++) {
            prev = prev->getNext();
        }
        node<T>* aux = prev->getNext();
        prev->setNext(aux->getNext());
        delete aux;
    }
    size--;
    return *this;
}

#endif
