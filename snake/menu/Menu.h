/*
 * Menu.h
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef MENU_H_
#define MENU_H_
#include "ListaBoton.h"
class Menu {
private:
	ListaBoton botones;
	int PantallaWidth;
	int PantallaHeight;
	int PantallaInicialWidth;
	int PantallaInicialHeight;

	int fondo;

	///Estado de la pantalla
	int xIni, xFin, yIni, yFin;
	//Fondo de Pantalla
	AUX_RGBImageRec * backgr;
public:
	bool enMenu;
	Menu(int PantallaWidth, int PantallaHeight, bool enMenu, int xIni,
			int xFin, int yIni, int yFin, AUX_RGBImageRec * backgr);
	void enClick(double posicionX, double posicionY);
	void enRedimension(int ancho, int alto);
	void insertarBoton(stdBoton boton);
	void dibujar();
};

#endif /* MENU_H_ */
