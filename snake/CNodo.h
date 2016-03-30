/*
 * CNodo.h
 *
 *  Created on: 30/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "Graficos/CPunto.h"

class Nodo{
public:
	Nodo *siguiente;
	Nodo *anterior;
	Punto cord;
public:
	Nodo(Nodo *anterior,Nodo *siguiente, Punto cord);
};

