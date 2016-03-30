/*
 * CNivel.h
 *
 *  Created on: 27/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CNIVEL_H_
#define CNIVEL_H_
#include<string>
#include<sstream>
#include"Graficos/CPunto.h"
#include"CTexturas.h"

class CNivel {
private:
int **nivel;
int *actual;
int cursor;
public:
	CNivel();
	void LeerNiveles();
	void Liberar();
	int * Actual();
	void siguiente();
	void anterior();
	void primero();
	bool existeActual(Punto ubicacion);
	void DibujarNivel(texturas *textur);
	void Linea(int a, int b, int c, int d);
};

#endif /* CNIVEL_H_ */
