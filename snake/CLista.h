/*
 * CLista.h
 *
 *  Created on: 29/09/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CLISTA_H_
#define CLISTA_H_

#include "CNodo.h"

class Cola {
private:
	Nodo *primero;
	Nodo *cursor;
	int n;
public:
	Cola();
	void insertar(Punto posicion);
	void borrar();
	int tamano();
	void iesimo(int valor);
	void irUltimo();
	void irPrimero();
	void irSiguiente();
	void irAnterior();
	Punto actual();
};

#endif /* CLISTA_H_ */
