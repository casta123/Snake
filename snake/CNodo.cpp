/*
 * CNodo.cpp
 *
 *  Created on: 30/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */



#include "CNodo.h"

Nodo::Nodo(Nodo *anterior, Nodo *siguiente, Punto cord){
	this->anterior=anterior;
	this->siguiente=siguiente;
	this->cord=cord;
}

