/*
 * CTexturas.cpp
 *
 *  Created on: 2/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "CTexturas.h"
#include "Graficos/funcionglaux.h"
void texturas::LoadBMP(string Filename, int pos) {
	textura[pos] = auxDIBImageLoad(Filename.c_str());
}


