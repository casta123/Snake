/*
 * CTexturas.h
 *
 *  Created on: 2/11/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CTEXTURAS_H_
#define CTEXTURAS_H_


#include	<stdio.h>
#include "Graficos/AUX_RGBImageRec.h"
#include<string>
using namespace std;

class texturas{
public:
	AUX_RGBImageRec *textura[10];
public:
	//Esta funcion carga la imagen con el nombre dado
	//y la guarda en en el arreglo textura en la posicion dada
	void LoadBMP(string Filename,int pos);
};


#endif /* CTEXTURAS_H_ */
