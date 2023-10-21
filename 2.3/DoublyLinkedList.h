//Ximena Lizeth Trejo Lavín A01198557 
 #ifndef DoublyLinkedList_h 
 #define DoublyLinkedList_h 
 #include <iostream> 
 #include "NodeDoublyLinkedList.h" 
  
 using namespace std; 
  
 template<class T> 
 class DoublyLinkedList{ 
 private: 
     NodeDoublyLinkedList<T>* head; 
     NodeDoublyLinkedList<T>* tail; 
     int size; 
 public: 
     DoublyLinkedList(); 
     bool isEmpty(); 
     void addFirst(T data); //Inserta un elemento al principio de la lista 
     void addLast(T data); //Inserta un elemento al final de la lista 
     void insert(T data, int pos); //Inserta un elemento después del indice dado 
     void insertNext(T data, int pos); //Inserta un elemento en el indice dado 
     void deleteData(T data); //Borra el elemento que se encuentre en la lista igual al parámetro de entrada 
     void deleteAt(int pos); //Borra un elemento en una posición dada 
     T getData(int pos); //Lee el valor de un dato de la lista, de acuerdo con la posición recibida como parámetro de entrada. Si la posición es inválida o no se encuentra, se regresa una excepción de out_of_range 
     void updateData(T data, T dataNew); //Actualizar el elemento que sea igual al valor recibido como parámetro de entrada, si no se puede actualizar, se regresa una excepción de out_of_range 
     void updateAt(T data, int pos); //Actualizar el elemento en la posición recibida como parámetro de entrada, si no se puede actualizar, se regresa una excepción de out_of_range 
     int findData(T data); //Buscar un elemento en la lista, si no se encuentra, se regresa un -1 
     T &operator[](int pos); //Leer y/o actualizar un elemento en una posición dada. Si la posición es inválida o no se encuentra, se regresa una excepción de out_of_range 
     void operator=(DoublyLinkedList<T> list); //Actualiza la lista con base en otra lista 
     void clear(); //Borra todos los elementos de la lista 
     void sort(); //Ordena los elementos de la lista 
     void duplicate(); //Duplica los elementos de la lista 
     void removeDuplicates(); //Elimina los elementos duplicados de la lista 
     void print(); //Imprime los elementos de la lista 
 }; 


 template<class T> 
 void DoublyLinkedList<T>::print(){ 
     // Si la lista está vacía, se regresa una excepción de out_of_range 
     if(isEmpty()){ 
         cout << "Lista vacía" << endl; 
     } 
     // Si no, se recorre la lista e imprime los elementos 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         while(aux != nullptr){ 
             cout << aux ->data << " "; 
             aux = aux ->next; 
         } 
         cout << endl; 
     } 
 } 
  
 template<class T> 
 DoublyLinkedList<T>::DoublyLinkedList(){ 
     this ->head = nullptr; 
     this ->tail = nullptr; 
     this ->size = 0; 
 } 
  
 template<class T> 
 bool DoublyLinkedList<T>::isEmpty(){ 
     return this ->head == nullptr; 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::addFirst(T data){ 
     // Crear un nuevo nodo 
     NodeDoublyLinkedList<T>* newNode = new NodeDoublyLinkedList<T>(data); 
     // Si la lista está vacía, el nuevo nodo será la cabeza y la cola 
     if(isEmpty()){ 
         this ->head = newNode; 
         this ->tail = newNode; 
         // Si no está vacía, el nuevo nodo será la cabeza y el siguiente nodo será el que era la cabeza 
     }else{ 
         newNode ->next = this ->head; 
         this ->head ->prev = newNode; 
         this ->head = newNode; 
     } 
     this ->size++; 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::addLast(T data){ 
     // Crear un nuevo nodo 
     NodeDoublyLinkedList<T>* newNode = new NodeDoublyLinkedList<T>(data); 
     // Si la lista está vacía, el nuevo nodo será la cabeza y la cola 
     if(isEmpty()){ 
         this ->head = newNode; 
         this ->tail = newNode; 
     } 
     // Si no está vacía, el nuevo nodo será la cola y el nodo anterior será el que era la cola 
     else{ 
         this ->tail ->next = newNode; 
         newNode ->prev = this ->tail; 
         this ->tail = newNode; 
     } 
     this ->size++; 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::insert(T data, int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range. 
     if(pos < 0 || pos > this ->size){ 
         cout << "Posición inválida" << endl; 
     } 
     //Si la posición es el tamaño de la lista, se agrega al final 
     else if(pos == this ->size){ 
         addLast(data); 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* newNode = new NodeDoublyLinkedList<T>(data); 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos - 1; i++){ 
             aux = aux ->next; 
         } 
         newNode ->next = aux ->next; 
         aux ->next ->prev = newNode; 
         aux ->next = newNode; 
         newNode ->prev = aux; 
         this ->size++; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::insertNext(T data, int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range. 
     if(pos < 0 || pos > this ->size){ 
         cout << "Posición inválida" << endl; 
     } 
     else if(pos == 0){ 
         addFirst(data); 
     } 
     //Si la posición es el tamaño de la lista, se agrega al final 
     else if(pos == this ->size){ 
         addLast(data); 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* newNode = new NodeDoublyLinkedList<T>(data); 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos - 1; i++){ 
             aux = aux ->next; 
         } 
         newNode ->next = aux ->next; 
         aux ->next ->prev = newNode; 
         aux ->next = newNode; 
         newNode ->prev = aux; 
         this ->size++; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::deleteData(T data){ 
     // Si la lista está vacía, se regresa una excepción de out_of_range 
     if(isEmpty()){ 
         throw out_of_range("Lista vacía"); 
     } 
     // Si el dato a borrar es igual al dato de la cabeza, se borra la cabeza 
     else if(this ->head ->data == data){ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         this ->head = this ->head ->next; 
         this ->head ->prev = nullptr; 
         delete aux; 
         this ->size--; 
     } 
     // Si el dato a borrar es igual al dato de la cola, se borra la cola 
     else if(this ->tail ->data == data){ 
         NodeDoublyLinkedList<T>* aux = this ->tail; 
         this ->tail = this ->tail ->prev; 
         this ->tail ->next = nullptr; 
         delete aux; 
         this ->size--; 
     } 
     // Si no, se recorre la lista hasta encontrar el dato 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         while(aux ->next != nullptr){ 
             if(aux ->next ->data == data){ 
                 NodeDoublyLinkedList<T>* temp = aux ->next; 
                 aux ->next = aux ->next ->next; 
                 aux ->next ->prev = aux; 
                 delete temp; 
                 this ->size--; 
                 break; 
             } 
             aux = aux ->next; 
         } 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::deleteAt(int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range 
     if(pos < 0 || pos >= this ->size){ 
         throw out_of_range("Posición inválida"); 
     } 
     // Si la posición es 0, se borra la cabeza 
     else if(pos == 0){ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         this ->head = this ->head ->next; 
         this ->head ->prev = nullptr; 
         delete aux; 
         this ->size--; 
     } 
     // Si la posición es el tamaño de la lista - 1, se borra la cola 
     else if(pos == this ->size - 1){ 
         NodeDoublyLinkedList<T>* aux = this ->tail; 
         this ->tail = this ->tail ->prev; 
         this ->tail ->next = nullptr; 
         delete aux; 
         this ->size--; 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos - 1; i++){ 
             aux = aux ->next; 
         } 
         NodeDoublyLinkedList<T>* temp = aux ->next; 
         aux ->next = aux ->next ->next; 
         aux ->next ->prev = aux; 
         delete temp; 
         this ->size--; 
     } 
 } 
  
 template<class T> 
 T DoublyLinkedList<T>::getData(int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range 
     if(pos < 0 || pos >= this ->size){ 
         throw out_of_range("Posición inválida"); 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos; i++){ 
             aux = aux ->next; 
         } 
         return aux ->data; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::updateData(T data, T dataNew){ 
     // Si la lista está vacía, se regresa una excepción de out_of_range 
     if(isEmpty()){ 
         throw out_of_range("Lista vacía"); 
     } 
     // Si el dato a actualizar es igual al dato de la cabeza, se actualiza la cabeza 
     else if(this ->head ->data == data){ 
         this ->head ->data = dataNew; 
     } 
     // Si el dato a actualizar es igual al dato de la cola, se actualiza la cola 
     else if(this ->tail ->data == data){ 
         this ->tail ->data = dataNew; 
     } 
     // Si no, se recorre la lista hasta encontrar el dato 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         while(aux != nullptr){ 
             if(aux ->data == data){ 
                 aux ->data = dataNew; 
                 break; 
             } 
             aux = aux ->next; 
         } 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::updateAt(T data, int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range 
     if(pos < 0 || pos >= this ->size){ 
         throw out_of_range("Posición inválida"); 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos; i++){ 
             aux = aux ->next; 
         } 
         aux ->data = data; 
     } 
 } 
  
 template<class T> 
 int DoublyLinkedList<T>::findData(T data){ 
     // Si la lista está vacía, se regresa una excepción de out_of_range 
     if(isEmpty()){ 
         cout << "Lista vacía" << endl; 
     } 
     // Si no, se recorre la lista hasta encontrar el dato 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         int pos = 0; 
         while(aux != nullptr){ 
             if(aux ->data == data){ 
                 return pos; 
                 break; 
             } 
             aux = aux ->next; 
             pos++; 
         } 
         // Si no se encuentra, se regresa un -1 
         if(aux == nullptr){ 
             return -1; 
         } 
     } 
 } 
  
 template<class T> 
 T &DoublyLinkedList<T>::operator[](int pos){ 
     // Si la posición es inválida, se regresa una excepción de out_of_range 
     if(pos < 0 || pos >= this ->size){ 
         throw out_of_range("Posición inválida"); 
     } 
     // Si no, se recorre la lista hasta llegar a la posición dada 
     else{ 
         NodeDoublyLinkedList<T>* aux = this ->head; 
         for(int i = 0; i < pos; i++){ 
             aux = aux ->next; 
         } 
         return aux ->data; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list){ 
     // Se borran los elementos de la lista 
     clear(); 
     // Se recorre la lista que se recibe como parámetro de entrada 
     NodeDoublyLinkedList<T>* aux = list.head; 
     while(aux != nullptr){ 
         // Se agregan los elementos de la lista que se recibe como parámetro de entrada a la lista que llama al método 
         addLast(aux ->data); 
         aux = aux ->next; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::clear(){ 
     // Se recorre la lista y se borran los elementos 
     NodeDoublyLinkedList<T>* aux = this ->head; 
     while(aux != nullptr){ 
         NodeDoublyLinkedList<T>* temp = aux; 
         aux = aux ->next; 
         delete temp; 
     } 
     this ->head = nullptr; 
     this ->tail = nullptr; 
     this ->size = 0; 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::sort(){ 
     // Se recorre la lista 
     NodeDoublyLinkedList<T>* aux = this ->head; 
     while(aux != nullptr){ 
         NodeDoublyLinkedList<T>* temp = aux ->next; 
         while(temp != nullptr){ 
             // Si el dato del nodo actual es mayor al dato del nodo siguiente, se intercambian 
             if(aux ->data > temp ->data){ 
                 T data = aux ->data; 
                 aux ->data = temp ->data; 
                 temp ->data = data; 
             } 
             temp = temp ->next; 
         } 
         aux = aux ->next; 
     } 
 } 
  
 template<class T> 
 void DoublyLinkedList<T>::duplicate(){ 
     // Se recorre la lista 
     NodeDoublyLinkedList<T>* aux = this ->head; 
     while(aux != nullptr){ 
         // Se inserta el dato del nodo actual después del nodo actual 
         insertNext(aux ->data, findData(aux ->data)); 
         aux = aux ->next; 
     } 
 } 
  
 //Tras verificar que la lista ordenada tiene valores duplicados, elimina el valor duplicado, dejando solo una copia del valor en la lista. 
 template<class T> 
 void DoublyLinkedList<T>::removeDuplicates(){ 
     // Se recorre la lista 
     NodeDoublyLinkedList<T>* aux = this ->head; 
     while(aux != nullptr){ 
         // Si el dato del nodo actual es igual al dato del nodo siguiente, se borra el nodo siguiente 
         if(aux -> next != nullptr && aux ->data == aux ->next ->data){ 
             NodeDoublyLinkedList<T>* temp = aux ->next; 
             aux ->next = aux ->next ->next; 
             if(aux->next != nullptr){ 
                 aux ->next ->prev = aux; 
             } 
             delete temp; 
             this ->size--; 
         } 
         else{ 
             aux = aux ->next; 
         } 
     } 
 } 
  
 #endif