/*
 * nodoMenu.cpp
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include"stdBoton.h"
#include "nodoMenu.h"

nodoMenu::nodoMenu(nodoMenu * anterior, nodoMenu * siguiente, stdBoton actual) {
this->anterior = anterior;
this->siguiente = siguiente;
this->actual = actual;
}
nodoMenu::nodoMenu(){
	this->anterior = NULL;
	this->siguiente = NULL;
}
