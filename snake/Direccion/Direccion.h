/*
 * Direccion.h
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_
#include "ListaDireccion.h"
class Direccion {
private:
	ListaDireccion lista;
public:
	Direccion();
	void insertar(int direccion);
	int actual();
	void borrar();
	int tamanno();

};

#endif /* DIRECCION_H_ */
