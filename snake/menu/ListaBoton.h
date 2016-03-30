/*
 * ListaBoton.h
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef LISTABOTON_H_
#define LISTABOTON_H_
#include"nodoMenu.h"
class ListaBoton {
private:
	nodoMenu * primero;
	nodoMenu * cursor;

public:
	ListaBoton();
	stdBoton actual();
	void insertar(stdBoton);
	void siguiente();
	void anterior();
	void irPrimero();
	bool esUltimo();
	int tamano();
};

#endif /* LISTABOTON_H_ */
