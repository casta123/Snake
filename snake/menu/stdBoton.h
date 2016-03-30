/*
 * stdBoton.h
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef STDBOTON_H_
#define STDBOTON_H_
#include"../Graficos/AUX_RGBImageRec.h"
#include"../Graficos/CPunto.h"
#include<string>

class stdBoton {
private:
	AUX_RGBImageRec *textura;
	Punto ubicacion;
	unsigned int width;
	unsigned int height;
	string texto;

	string id;
public:
	bool **activador;
	unsigned int numActivadores;

	stdBoton(string id, Punto ubicacion, unsigned int width,
			unsigned int height, string texto, bool **activador,
			unsigned int numActivadores,AUX_RGBImageRec *textura );
stdBoton();
	bool presionado(Punto mouse);
	void activar();
	void dibujar();
};

#endif /* STDBOTON_H_ */
