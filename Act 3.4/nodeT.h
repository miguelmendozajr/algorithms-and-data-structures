#ifndef NODET_H
#define NODET_H

template <typename T>
class nodeT {
  private:
    T data;
    nodeT<T> *left,*right;
    int key;
  public:
    nodeT();
    nodeT(T);
    T Data() {return data;}
    int Key() {return key;}
    nodeT<T>* Left() {return left;}
    nodeT<T>* Right() {return right;}
    void setData(T _data) {data = _data;}
    void setLeft(nodeT<T>* p) {left = p;}
    void setRight(nodeT<T>* p) {right = p;}
    void incKey();
};

template <typename T>
nodeT<T>::nodeT() {
    left = right = NULL;
    key = 1;
}

template <typename T>
nodeT<T>::nodeT(T data) {
    this->data = data; // ocurre enmascaramiento de la variable data
    left = right = NULL;
    key = 1;
}

template <typename T>
void nodeT<T>::incKey(){
    key++; // se incrementa el valor de la llave por 1
}

#endif