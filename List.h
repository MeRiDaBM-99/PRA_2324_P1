#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T>
class List{
    public:
        virtual void insert(int pos, T e) = 0;  //Añadir e en pos
        virtual void append(T e) = 0;           //Insertar e al final
        virtual void prepend(T e) = 0;          //Insertar e al principio

        virtual T remove(int pos) = 0;          //Eliminar el elemento en pos (y lo devuelve)
        virtual T get (int pos) = 0;            //Devuelve el elelemento en pos

        virtual int search(T e) = 0;            //Devuelve la posicion de e (sino -1)
        virtual bool empty() = 0;               //Indicar si esta vacio
        virtual int size() = 0;                 //Nº elementos de la lista
	
	virtual ~List(){}
};

#endif
