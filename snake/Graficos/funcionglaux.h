/*
 * funciones.h
 *
 *  Created on: 4/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "AUX_RGBImageRec.h"
#include "../IL/il.h"
#include<iostream>
using namespace std;


AUX_RGBImageRec * auxDIBImageLoad(const char * filename) {
	cout << "Cargando la textura " << filename << "\t..........\t";

	if (filename) {
		AUX_RGBImageRec * textura = new AUX_RGBImageRec; //Creamos un nuevo puntero
		unsigned int texturaID = 0;
		ilGenImages(1, &texturaID); // Generamos el nombre de la imagen
		ilBindImage(texturaID); // Vinculamos el nombre de la imagen
		ilLoadImage(filename); ///Cargamos el archivo, openIl se encarga de revisarlo y cargarlo en la memoria
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE); //Convertimos la imagen con el fin que se vea correctamete
		//Obtenemos los valores de il
		textura->sizeX = ilGetInteger(IL_IMAGE_WIDTH);
		textura->sizeY = ilGetInteger(IL_IMAGE_HEIGHT);
		textura->data = ilGetData();
		textura->internalFormat = ilGetInteger(IL_IMAGE_BPP);
		textura->format = ilGetInteger(IL_IMAGE_FORMAT);
		ilBindImage(0); //Desvinculamos el nombre de la imagen, si no se hace esto parece juego de HIPPIES
		cout << "OK" << endl;
		return textura;
	}
	cout << "Error" << endl;
	return NULL;

}

#endif /* FUNCIONES_H_ */
