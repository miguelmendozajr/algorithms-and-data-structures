#ifndef BST_H
#define BST_H
#include "nodeT.h"

#include "funciones.cpp"

template <typename T>
class BST {
  private:
    nodeT<T> *root; // no espeficicamos el tipo de dato a guardar en el nodo
  public:
    BST();
    ~BST();
    void Delete(nodeT<T>*);
    int search(T);
    void add(T);
    void pop(T);
    void printPreorden();
    void preorden(nodeT<T>*);
    void printInorden();
    void inorden(nodeT<T>*);
    void printPostorden();
    void postorden(nodeT<T>*);
    void printPorNivel();

    void printKey(int key);
    void keySearch(nodeT<T>* r, int key);
};

template <typename T>
BST<T>::BST() {
    root = NULL;
}


template <typename T>
BST<T>::~BST() {
    Delete(root);
}

template <typename T>
void BST<T>::Delete(nodeT<T>* nodo) {
    if (nodo == NULL)
        return;
    Delete(nodo->Left());
    Delete(nodo->Right());
    delete nodo;
}

template <typename T>
int BST<T>::search(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    while (p != NULL) {
        if (p->Data() == data){  
            return p->Data().Key();
        }
        p = p->Data() > data ? p->Left() : p->Right(); // avanzamos a la izquierda o derecha segun el orden entre data y el data del nodo
    }
    return 0; // no se encontro el dato
}


template <typename T>
void BST<T>::add(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL;
    nodeT<T> *nodo;
    if(search(data) != 0){
        data.setKey(search(data) + 1);
        cout << "Ya existe el valor: " << data.getIP() << endl; 
        cout << "Nueva llave: " << data.Key() << endl;   
        pop(data);  
    } // ya esta el dato en nuestro arbol
    nodo = new nodeT<T>(data);
    while (p!= NULL) {
        padre = p;
        p = p->Data() > data ? p->Left() : p->Right();
    }
    if (padre == NULL) {
        root = nodo; // se trata del primer elemento a agregar
    }
    else { // ya existe al menos un elemento en el arbol
        
        if (padre->Data() > data) {
            padre->setLeft(nodo); // agregarlo a izq
        }
        else {
            padre->setRight(nodo);// agregarlo a la derecha
        }
    }
}

template <typename T>
void BST<T>::pop(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL;
    if (search(data) == 0){
        return; // el dato no esta en nuestro arbol
    }
    while (p->Data() != data) {
        padre = p;
        p = p->Data() > data ? p->Left() : p->Right();
    }
    if (p->Left() == NULL && p->Right() == NULL) { // se trata de un nodo hoja
        delete p;
        if (padre == NULL) { // solo quedaba un elemento
            root = NULL; // se vacia el arbol
        }
        else {
            if (padre->Data() > data){
                padre->setLeft(NULL);
            }
            else{
                padre->setRight(NULL);
            }
        }
    }
    else if (p->Left() == NULL || p->Right() == NULL) { // nodo con solo un hijo
        nodeT<T> *subarbol;
        subarbol = p->Left() != NULL ? p->Left() : p->Right();
        delete p;
        if (padre == NULL) { // es equivalente a preguntar p == root o root->Data() == data
            root = subarbol;
        }
        else {
            if (padre->Data() > data){
                padre->setLeft(subarbol);
            }
            else{
                padre->setRight(subarbol);
            }
        }
    }
    else { // nodo con dos hijos
        nodeT<T> *sucesor;
        sucesor = p->Right(); // no es nulo porque el nodo p tiene dos hijos
        padre = p; // valor inicial de padre
        while (sucesor->Left() != NULL) {
            padre = sucesor;
            sucesor = sucesor->Left();
        }
        nodeT<T> *subarbol = sucesor->Right();
        p->setData(sucesor->Data()); // se reemplaza la informacion en p
        delete sucesor; // libera nodo
        if (padre == p) { // no se avanza el padre
            padre->setRight(subarbol);
        }
        else {
            padre->setLeft(subarbol); // subarbol puede ser NULL si el nodo era nodo hoja
        }
    }
}

template <typename T>
void BST<T>::printPreorden(){
    preorden(root);
}

template <typename T>
void BST<T>::preorden(nodeT<T>* r){
    if (r == NULL)
        return;
    std::cout << r->Data().getIP() << " ";
    preorden(r->Left());
    preorden(r->Right());
}

template <typename T>
void BST<T>::printInorden(){
    inorden(root);
}

template <typename T>
void BST<T>::inorden(nodeT<T>* r){
    if (r == NULL)
        return;
    inorden(r->Left());
    std::cout << r->Data().getIP() << " ";
    inorden(r->Right());
}

template <typename T>
void BST<T>::printPostorden(){
    postorden(root);
}

template <typename T>
void BST<T>::postorden(nodeT<T>* r){
    if (r == NULL)
        return;
    postorden(r->Left());
    postorden(r->Right());
    std::cout << r->Data() << " ";
}

//Funcion para imprimir los IPs que tengan cierta cantidad de accesos
//Se utiliza el recorrido preorden
template <typename T>
void BST<T>::printKey(int key){
    keySearch(root, key);
}

template <typename T>
void BST<T>::keySearch(nodeT<T>* r, int key){
    if (r == NULL)
        return;
    if(r->Data().Key() == key){
        std::cout << r->Data().getIP() << endl;
    }
    keySearch(r->Left(), key);
    keySearch(r->Right(), key);
}

/*
template <typename T>
void BST<T>::printPorNivel(){
    queue2<nodeT<T>*> fila;
    nodeT<T> *nodo;
    if (root != NULL) {
        fila.push(root);
    }
    while (!fila.isEmpty()) {
        nodo = fila.front();
        if (nodo->Left() != NULL) { // se agrega hijo izquierdo en caso de existir
            fila.push(nodo->Left());
        }
        if (nodo->Right() != NULL) { // se agrega hijo derecho en caso de existir
            fila.push(nodo->Right());
        }
        fila.pop(); // remueve primer elemento de la fila que ya fue procesado
        std::cout << nodo->Data() << " ";
    }
}
*/
#endif
