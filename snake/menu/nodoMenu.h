/*
 * nodoMenu.h
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef NODOMENU_H_
#define NODOMENU_H_
#include"stdBoton.h"
class nodoMenu {
public:
	nodoMenu * anterior;
	stdBoton actual;
	nodoMenu * siguiente;
	nodoMenu(nodoMenu * anterior, nodoMenu * siguiente, stdBoton actual);
	nodoMenu();
};

#endif /* NODOMENU_H_ */
