/*
 * ListaDireccion.h
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef LISTADIRECCION_H_
#define LISTADIRECCION_H_
#include "stdDireccion.h"
class ListaDireccion {
private:

	stdDireccion *primero;
	stdDireccion *cursor;

	public:
		ListaDireccion();
		void insertar(int direccion);
		void borrar();
		int tamano();
		void iesimo(int valor);
		void irUltimo();
		void irPrimero();
		int actual();
};

#endif /* LISTADIRECCION_H_ */
