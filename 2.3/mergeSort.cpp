# include "Node.h"

# include <iostream>
using namespace std;

template <typename T>
Node<T>* merge(Node<T>* left, Node<T>* right) {
    Node<T>* result = nullptr;
    
    if (left == nullptr) {
        return right;
    }
    
    if (right == nullptr) {
        return left;
    }
    
    if (left->data.getIp().getInt() > right->data.getIp().getInt()) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    
    return result;
}

template <typename T>
Node<T>* mergeSort(Node<T>* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node<T>* middle = findMiddle(head);
    Node<T>* nextToMiddle = middle->next;
    middle->next = nullptr;
    
    Node<T>* left = mergeSort(head);
    Node<T>* right = mergeSort(nextToMiddle);
    
    return merge(left, right);
}

template <typename T>
Node<T>* findMiddle(Node<T>* head) {
    if (head == nullptr) {
        return head;
    }
    
    Node<T>* slow = head;
    Node<T>* fast = head;
    
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
