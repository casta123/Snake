/*
 * ListaDireccion.cpp
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include "stdDireccion.h"
#include<iostream>
using namespace std;
#include "ListaDireccion.h"

ListaDireccion::ListaDireccion() {
	this->cursor = NULL;
	this->primero = NULL;
}

void ListaDireccion::insertar(int direccion) {
	stdDireccion * insertando = new stdDireccion(NULL, NULL, direccion);
	if (!this->primero) {//No existe primero
		this->primero = insertando;
		this->cursor = primero;
	} else {
		this->irUltimo();
		cursor->siguiente = insertando;
		insertando->anterior = cursor;
		cursor = insertando;
	}
}
void ListaDireccion::borrar() {
	if (primero) {
		this->irPrimero();

		if (cursor->siguiente == 0) {//La cola queda vacÃ­a
			delete (cursor);
			cursor = 0;
			primero = 0;
		} else {
			cursor = cursor->siguiente;
			delete (cursor->anterior);
			cursor->anterior = 0;
			primero = cursor;
		}
	}

}
int ListaDireccion::tamano() {
	if (primero) {
		cursor = primero;
		int contador = 1;
		while (cursor->siguiente) {
			contador++;
			cursor = cursor->siguiente;
		}
		return contador;
	}
	return 0;
}

void ListaDireccion::iesimo(int valor) {
	if (primero) {
		cursor = primero;
		int contador = 1;
		while (cursor->siguiente && valor < contador) {
			contador++;
			cursor = cursor->siguiente;
		}

	}

}

void ListaDireccion::irUltimo() {
	if(cursor)
	while (cursor->siguiente)
		cursor = cursor->siguiente;

}
void ListaDireccion::irPrimero() {
if(this->primero)
	this->cursor = this->primero;
}
int ListaDireccion::actual() {
	if(cursor){
	return cursor->direccion;
	}
}
