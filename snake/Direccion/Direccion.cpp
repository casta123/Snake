/*
 * Direccion.cpp
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include "ListaDireccion.h"
#include "Direccion.h"

Direccion::Direccion() {
	this->insertar(3);
}
void Direccion::insertar(int direccion) {

	if (this->lista.tamano()) {
		this->lista.irUltimo();
		if (this->lista.actual() == 0 || this->lista.actual() == 2) {
			if (direccion == 1 || direccion == 3) {
				this->lista.insertar(direccion);
			}
		} else {
			if (direccion == 0 || direccion == 2) {
				this->lista.insertar(direccion);
			}
		}

	}else
		this->lista.insertar(direccion);

}
int Direccion::actual() {
	this->lista.irPrimero();
	return this->lista.actual();
}

void Direccion::borrar() {
	this->lista.borrar();
}
int Direccion::tamanno() {
	return this->lista.tamano();
}
