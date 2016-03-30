/*
 * stdDireccion.cpp
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "stdDireccion.h"

stdDireccion::stdDireccion(stdDireccion * anterior, stdDireccion * siguiente, int direccion){
this->anterior = anterior;
this->siguiente = siguiente;
this->direccion = direccion;

}
