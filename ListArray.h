#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
        T* arr;                         // Puntero al inicio del array
        int max;                        // Tamaño actual del array
        int n;                          // Nº elementos en la lista
        static const int MINSIZE = 2;   // Tamaño minimo del array


        //Ajustar el tamaño de un array
        void resize(int new_size){
            //Crear nuevo array dinamico
            T* new_arr = new T[new_size];
            
            //Copiar contenido del array antiguo
            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[i];
            }
            
            //Liberar memoria del array antiguo
            delete[] arr;
            
            //Actualizar puntero arr
            arr = new_arr;
            
            //Actualizar max
            max = new_size;
        }

    public:
        // miembros públicos, incluidos los heredados de List<T>

        //Constructor sin argumentos, reserva memoria para un array de MINSIZE elementos.
        ListArray(){
            arr = new T[MINSIZE];
            max = MINSIZE;
            n = 0;
        }


        //Destructor
        ~ListArray(){
            delete[] arr;
        } 


        //Sobrecarga operador []
        T operator[](int pos) {
            if (pos < 0 || pos > size()-1) {
                throw out_of_range("Posicion invalida");
            }
            return arr[pos];
        }


        //Sobrecarga operador <<
        friend ostream& operator<<(ostream &out, const ListArray<T> &list) {
            out << "[";
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i];
                if (i < list.n - 1) {
                    out << ", ";
                }
            }
            out << "]";
            return out;
        }


        //Metodos heredados
        void insert(int pos, T e) override{
            if(pos < 0 || pos > n){
                throw out_of_range("Posicion invalida");
            }

            //Redimensionar si el array esta completo
            if(n == max){
                resize(max + 3);
            }

            //Desplazar todo a la derecha
            for(int i = n; i > pos; i--){  //Como la posicion n esta vacia
                arr[i] = arr[i - 1];       //podemos hacerlo asi
            }

            //Insertar el elemento nuevo
            arr[pos] = e;
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
            
            //Guardamos el elemento a eliminar
            T elem = arr[pos];

            //Movemos todo a la izquierda
            for(int i = pos; i < n-1; i++){
                arr[i] = arr[i + 1];
            }

            //Disminuimos el tamaño de elementos
            n--;

            //***EXTRA***
            //Vaciar si el array esta muy vacio
            if (n > 0 && n <= max / 4 && max > MINSIZE) {
                resize(max / 2);
            }
            
            return elem;

        }


        T get(int pos) override{
            if(pos < 0 || pos >= n){
                throw out_of_range("Posicion invalida");
            }

            return arr[pos];
        }


        int search(T e) override{
            for(int i = 0; i < n; i++){
                if(arr[i] == e){
                    return i;
                }
            }
            return -1;
        }


        bool empty() override{
            if(n == 0){
                return true;
            }else{
                return false;
            }
        }

        int size() override{
            return n;
        }
    
};

#endif
