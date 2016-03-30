/*
 * stdDireccion.h
 *
 *  Created on: 5/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef STDDIRECCION_H_
#define STDDIRECCION_H_

class stdDireccion {
public:
 stdDireccion * anterior;
 int direccion;
 stdDireccion * siguiente;

public:
	stdDireccion(stdDireccion * anterior, stdDireccion * siguiente, int direccion);
};

#endif /* STDDIRECCION_H_ */
