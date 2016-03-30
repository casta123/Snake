/*
 * ListaBoton.cpp
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include <iostream>
using namespace std;
#include"nodoMenu.h"
#include "ListaBoton.h"

ListaBoton::ListaBoton() {
	cursor = NULL;
	primero = NULL;

}
stdBoton ListaBoton::actual() {
	if (cursor)
		return cursor->actual;
}
void ListaBoton::insertar(stdBoton boton) {
	nodoMenu * nuevo = new nodoMenu(NULL, NULL, boton);
	if (primero) {
		while (cursor->siguiente != NULL)
			cursor = cursor->siguiente;

		nuevo->anterior = cursor;
		cursor->siguiente = nuevo;
	} else {
		primero = nuevo;
		cursor = nuevo;
	}

}
void ListaBoton::siguiente() {
	if (primero) ///La lista no esta vacia
		if (cursor->siguiente)
			cursor = cursor->siguiente;
}
void ListaBoton::anterior() {
	if (cursor)
		if (cursor->anterior)
			cursor = cursor->anterior;
}
bool ListaBoton::esUltimo() {
	if (cursor)
		if (cursor->siguiente)
			return false;
	return true;
}
void ListaBoton::irPrimero() {
	cursor = primero;
}
int ListaBoton::tamano() {
	if (cursor) {
		this->irPrimero();
		int i = 1;
			while (cursor->siguiente != NULL) {
				cursor = cursor->siguiente ;
			i++;
		}

		return i;
	}
	return 0;
}
