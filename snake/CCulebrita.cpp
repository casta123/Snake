/*
 * CCulebrita.cpp
 *
 *  Created on: 30/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "CCulebrita.h"
#include "Graficos/graphic.h"

Culebrita::Culebrita() {
	Punto punto1(3, 3);
	Punto punto2(4, 3);
	Punto punto3(5, 3);
	Punto punto4(6, 3);
	cuerpo.insertar(punto1);
	cuerpo.insertar(punto2);
	cuerpo.insertar(punto3);
	cuerpo.insertar(punto4);
}
void Culebrita::dibujar(int direc,texturas *textur) {
	int tamano = cuerpo.tamano();
	for (int i = 0; i < tamano - 1; i++) {
		cuerpo.iesimo(i);
		crearPunto(cuerpo.actual(), textur);
	}
	cuerpo.iesimo(tamano - 1);
	crearCabeza(cuerpo.actual(), direc, textur);
}

void Culebrita::mover(Punto puntosig) {
	this->crecer(puntosig);
	cuerpo.borrar();
}
void Culebrita::crecer(Punto puntosig) {
	cuerpo.irUltimo();
	cuerpo.insertar(puntosig);
}
bool Culebrita::colisionConCuerpo(Punto punto) {
	cuerpo.irPrimero();
	for(int i = 0; i < cuerpo.tamano(); i++){
		if(punto.getKey() == cuerpo.actual().getKey())
			return true;
	cuerpo.irSiguiente();
	}
	return false;
}
bool Culebrita::colisionConPunto(Punto punto) {
	if(this->cabeza().getKey()==punto.getKey()){
		return true;
	}
	return false;
}
Punto Culebrita::cabeza(){
	cuerpo.irUltimo();
	return cuerpo.actual();
}
void Culebrita::reiniciar() {
	while (cuerpo.tamano() > 0) {
		cuerpo.borrar();
	}
	Punto punto1(3, 3);
	Punto punto2(4, 3);
	Punto punto3(5, 3);
	Punto punto4(6, 3);
	cuerpo.insertar(punto1);
	cuerpo.insertar(punto2);
	cuerpo.insertar(punto3);
	cuerpo.insertar(punto4);
}

