#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
        //ATRIBUTOS
        Node<T>* first;     //Primer nodo
        int n;              //Nº elementos

    public:
        //METODOS
        ListLinked(): first(nullptr), n(0) {}
        ~ListLinked(){
            Node<T>* aux;
            while (first != nullptr) {
                aux = first->next;      
                delete first;           
                first = aux;            
            }
            
        }

        T operator[](int pos){
            if(pos < 0 || pos >= n){
                throw out_of_range("Posicion invalida");
            }

            Node<T>* aux = first;

            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }

            return aux->data;
        }


        friend ostream& operator<< <>(ostream &out, const ListLinked<T> &list);


        //METODOS HEREDADOS
        void insert(int pos, T e) override{
            if(pos < 0 || pos > n){
                throw out_of_range("Posicion invalida");
            }

            Node<T>* aux = new Node<T>(e);

            if(pos == 0){
                aux->next = first;
                first = aux;
            }else{
                Node<T>* prev = first;

                for(int i = 0; i < pos - 1; i++){
                    prev = prev->next;
                }

                aux->next = prev->next;
                prev->next = aux;
            }
            //RECORDAR SIEMPRE AÑADIR EL NUEVO NODO AL CONTADOR
            n++;

        }


        void append(T e) override{
            insert(n, e);
        }

        void prepend(T e) override{
            insert(0, e);
        }

        T remove(int pos) override{
            if(pos < 0 || pos >= n){
                throw out_of_range("Posicion invalida");
            }
            
            Node<T>* aux;
            T valor;

            if(pos == 0){
                aux = first;
                valor = aux->data;
                first = first->next;
            }else{
                Node<T>* prev = first;
                for(int i = 0; i < pos - 1; i++){
                    prev = prev->next;
                }

                aux = prev->next;
                valor = aux->data;
                prev->next = aux->next; 
            }
            delete aux;
            n--;
            return valor;
        }


        T get(int pos) override{
            if(pos < 0 || pos >= n){
                throw out_of_range("Posicion invalida");
            }

            Node<T>* prev = first;
            for(int i = 0; i < pos; i++){
                prev = prev->next;
            }

            return prev->data;
        }

        int search(T e) override{
            Node<T>* aux = first;
            int pos = 0;

            while(aux != nullptr){
                if(aux->data == e){
                    return pos;
                }

                aux = aux->next;
                pos++;
            }

            return -1;
        }


        bool empty() override{
            return n == 0;
        }

        int size() override{
            return n;
        }

};


template <typename T>
ostream& operator<<(ostream &out, const ListLinked<T> &list){
    out << "[";
    Node<T>* aux = list.first;

    while (aux != nullptr) {
        out << aux->data;
        if (aux->next != nullptr) {
            out << ", ";
        }
        aux = aux->next;
    }

    out << "]";
    return out;
}

#endif
