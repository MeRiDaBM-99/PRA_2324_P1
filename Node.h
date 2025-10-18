#ifndef NODE_H
#define NODE_H

#include <ostream>

using namespace std;


template <typename T>
class Node {
    public:
        // miembros públicos
        //ATRIBUTOS
        T data;         //elemento almacenado
        Node<T>* next;  //puntero al siguiente nodo
                        //o nullptr si no hay
       //METODOS                          Asignamos los valores introducidos
        Node(T data, Node<T>* next=nullptr): data(data), next(next){}
        friend ostream& operator<<(ostream &out, const Node<T> &node){
            out << node.data;
            return out;
        }
};

#endif
