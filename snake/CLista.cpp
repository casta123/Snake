/*
 * CLista.cpp
 *
 *  Created on: 30/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "CLista.h"

Cola::Cola() {
	n = 0;
	cursor = NULL;
	primero = NULL;
}

//crea un nuevo nodo y lo inserta en la lista
void Cola::insertar(Punto posicion) {
	Nodo *aux = new Nodo(NULL, NULL, posicion);

	if (primero == NULL) {
		primero = aux;
		cursor = aux;
	} else {
		this->irUltimo();
		cursor->siguiente = aux;
		aux->anterior = cursor;
	}
	n++;
}

//borra el primer elemento

void Cola::borrar() {
	if (primero) {
		if (primero->siguiente) {
			primero = primero->siguiente;
			delete (primero->anterior);
			primero->anterior = NULL;
			n--;
		} else {
			delete (primero);
			this->primero = NULL;
			this->cursor = NULL;
			n--;
		}
	}
}

//retorna el tamaï¿½o actual de la cola
int Cola::tamano() {
	return n;
}

//situa el cursor en el iesimo elemento
void Cola::iesimo(int valor) {
	if (n > valor) {
		this->irPrimero();
		for (int i = 0; i < valor; i++) {
			cursor = cursor->siguiente;
		}
	}
}

//retorna el valor del punto que se encuentra en el cursor
Punto Cola::actual() {
	return cursor->cord;
}

//situa el cursor en el ultimo elemento
void Cola::irUltimo() {
	if (n != 0) {
		while (cursor->siguiente != NULL) {
			cursor = cursor->siguiente;
		}
	}
}

//situa el cursor en el primer elemento
void Cola::irPrimero() {
	cursor = primero;
}

void Cola::irSiguiente() {
	if (cursor->siguiente != NULL)
		cursor = cursor->siguiente;
}

void Cola::irAnterior() {
	if (cursor->anterior != NULL)
		cursor = cursor->anterior;
}

