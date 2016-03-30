/*
 * CPresa.h
 *
 *  Created on: 31/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CPRESA_H_
#define CPRESA_H_
#include "Graficos/CPunto.h"

	class Presa{
	private:
		Punto ubicacion;
		int ubicacion_en_vector;
	public:
		Presa();
		Presa(int x,int y);

		int getx();
		int gety();
		Punto getpunto();
		int ubicacionvect();
		void aleatorizar_presa();
		void dibujar();

	};


#endif /* CPRESA_H_ */
