//Ximena Lizeth Trejo Lavín A01198557 
 #pragma once 
  
 template<class T> 
 struct NodeDoublyLinkedList{ 
     T data; 
     NodeDoublyLinkedList<T>* next; 
     NodeDoublyLinkedList(T data); 
     NodeDoublyLinkedList(T data, NodeDoublyLinkedList<T> *next, NodeDoublyLinkedList<T> *prev); 
     //Crear un prev 
     NodeDoublyLinkedList<T>* prev; 
 }; 
  
 template<class T> 
 NodeDoublyLinkedList<T>::NodeDoublyLinkedList(T data){ 
     this ->data = data; 
     this ->next = nullptr; 
     // Es nullptr porque no se ha agregado a la lista 
     this ->prev = nullptr; 
 } 
  
 template<class T> 
 NodeDoublyLinkedList<T>::NodeDoublyLinkedList(T data, NodeDoublyLinkedList<T>* next, NodeDoublyLinkedList<T>* prev){ 
     this ->data = data; 
     this ->next = next; 
     this ->prev = prev; 
 }