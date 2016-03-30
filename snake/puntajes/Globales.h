/*
 * Globales.h
 *
 *  Created on: 10/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef GLOBALES_H_
#define GLOBALES_H_
#include"CPuntaje.h"
#include"../Graficos/AUX_RGBImageRec.h"
class Globales {
private:
	CPuntaje puntajes[10];
public:
	Globales();
	void dibujarGlobales(AUX_RGBImageRec * textura);
	bool enDibujarGlobales;
	int MasAlto();
	bool esPuntajeAlto(int puntos);
	void insertar(CPuntaje puntajeAlto);
	void cargar();
	void guardar();
};

#endif /* GLOBALES_H_ */
