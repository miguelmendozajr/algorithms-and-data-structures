#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include "mergeSort.cpp"

template <typename T>
class DoublyLinkedList {
private:
    Node<T> * head;

public:
    DoublyLinkedList();
    void append(T data);
    void prepend(T data);
    void deleteNode(T data);
    void display();
    void sortByIp();
    void filterByIp(long long ip1, long long ip2);
    void writeDataToFile();
    ~DoublyLinkedList();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
};

template <typename T>
void DoublyLinkedList<T>::append(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

template <typename T>
void DoublyLinkedList<T>::prepend(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(T data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::display() {
    if (head == nullptr) {
        return;
    }
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data.getIp().getAddress() << " <-> ";
        current = current->next;
    }
    cout << "Null" << endl;
}

template <typename T>
void DoublyLinkedList<T>::sortByIp() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    head = mergeSort(head);
}

template <typename T>
void DoublyLinkedList<T>::filterByIp(long long ip1, long long ip2) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node<T> * current = head;
    while (current != nullptr) {
        long long currentIp = current->data.getIp().getInt();
        if (currentIp > ip1) {
            Node<T> *temp = current;
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }
            current = current->next;
            delete temp;
        }
        else {
            if(current->next->data.getIp().getInt() < ip2){
                while (current->next != nullptr) {
                    Node<T> *temp = current->next;
                    current->next = temp->next;
                    if (current->next != nullptr) {
                        current->next->prev = current;
                    }
                    delete temp;
                }              
            return;
            } else {
                current = current->next;
            }
        }
    }
}


template <typename T>
void DoublyLinkedList<T>::writeDataToFile() {
    if (head == nullptr) {
        return;
    }
    ofstream outFile("output.txt");
    Node<T>* current = head;
    while (current != nullptr) {
        outFile << current->data.getMonth() << " "
                << current->data.getDay() << " "
                << current->data.getTime() << " "
                << current->data.getIp().getAddress() << " "
                << current->data.getText() <<endl;
        current = current->next;
    }

    outFile.close();
}


template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

#endif