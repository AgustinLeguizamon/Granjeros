/*
 * ArbolHeap.h
 
 
 *FFEEEEEAAA
 *  Created on: 24 jun. 2018
 *      Author: purrevil
 */

#ifndef ARBOLHEAP_H_
#define ARBOLHEAP_H_


#include "Nodo.h"
template<class T>


class ArbolHeap{
private:
	Nodo<T>* primero;
	Nodo<T>* ultimo;
	unsigned int tamanio;

public:
	ArbolHeap();
	void acolar(int prioridad, T dato);
	T desacolar();
	bool estaVacia();
	T obtenerFrente();
	unsigned int obtenerTamanio();

	~Cola();
};


template <class T> T ArbolHeap<T>::obtenerFrente(){
	return this->primero;
}
template <class T> ArbolHeap<T>::Cola(){
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}
template<class T> void ArbolHeap<T>::acolar(int prioridad, T dato){
	Nodo<T>* nuevoNodo = new Nodo<T>(prioridad, dato);
	bool intercambio = false;
	if(estaVacia()){
		this->primero = nuevoNodo;
		this->ultimo = nuevoNodo;
	}
	else if(this->primero->obtenerPrioridad()>prioridad){
		nuevoNodo->cambiarSiguiente(this->primero);
		this->primero = nuevoNodo;
	}
	else if(this->ultimo->obtenerPrioridad() <= prioridad){
		this->ultimo->cambiarSiguiente(nuevoNodo);
		this->ultimo = nuevoNodo;
	}
	else{
		Nodo<T> * nodoActual = this->primero;
		while(nodoActual->obtenerSiguiente() != NULL && !intercambio){
			if((nodoActual->obtenerPrioridad() < prioridad) && (nodoActual->obtenerSiguiente()->obtenerPrioridad()> prioridad)){
				nuevoNodo->cambiarSiguiente(nodoActual->obtenerSiguiente());
				nodoActual->cambiarSiguiente(nuevoNodo);
				intercambio = true;
			}
			nodoActual = nodoActual->obtenerSiguiente();
		}
	}
	this->tamanio ++;
}

template<class T> unsigned int ArbolHeap<T>::obtenerTamanio(){

}

template<class T> bool ArbolHeap<T>::estaVacia(){
	return this->primero==NULL;
}


template<class T> T ArbolHeap<T>::desacolar(){
	T dato;
	Nodo<T>* nodoABorrar;
	if(!this->estaVacia()){
		nodoABorrar = this->primero;
		this->primero = nodoABorrar->obtenerSiguiente();
		dato = nodoABorrar->obtenerDato();
		delete nodoABorrar;
		this->tamanio --;

	}
	return dato;
}

template<class T> ArbolHeap<T>::~ArbolHeap(){
	Nodo<T>* nodoABorrar;
	while(!estaVacia()){
		nodoABorrar = this->primero;
		this->primero = nodoABorrar->obtenerSiguiente();
		delete nodoABorrar;
	}
}


#endif /* ARBOLHEAP_H_ */
