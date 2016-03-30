/*
 * CPuntaje.cpp
 *
 *  Created on: 26/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "CPuntaje.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

CPuntaje::CPuntaje() {
	valor = 0;
	id = 0;
	nombre = "";

}

bool CPuntaje::Guardar() {
	if (id != 0) {
		stringstream archivo;
		archivo<<"points" << id << ".dat";
		string sarchivo = archivo.str();
		ofstream guardar(sarchivo.c_str(), ios::out);
		if (guardar.good()) {
			guardar << id << "\207" << nombre << "\207" << valor << endl; //El caracter 207 es simplemente es para separar el archivo
			guardar.close();
			return true;
		}
	}

	return false;
}

bool CPuntaje::Leer() {

	stringstream directorio;
	directorio <<"points" <<id << ".dat";
	string sarchivo = directorio.str();
	ifstream leer(sarchivo.c_str(), ios::in);
	if (leer.good()) {
		string contenido;
		char auxiliarLectura[200];

		leer.getline(auxiliarLectura, 200);
		contenido.assign(auxiliarLectura);

		int actual = 0;
		stringstream * aux = new stringstream;

		for (unsigned int i = 0; i < contenido.size(); i++) {
			if (contenido[i] != '\207') {
				*aux << contenido[i];
			} else {
				actual++;
				switch (actual) {
				case 1:
					*aux >> id;
					break;
				case 2:
					*aux >> nombre;
					break;
				}
				delete (aux);
				aux = new stringstream;
			}
		}
		*aux >> valor;
		delete (aux);
		leer.close();
		return true;
	}
	return false;

}
int CPuntaje::getId() {
	return id;
}
string CPuntaje::getNombre() {
	return nombre;
}
int CPuntaje::getValor() {
	return valor;
}
void CPuntaje::setId(int key) {
	id = key;
}
void CPuntaje::setNombre(string name) {
	nombre = name;
}
void CPuntaje::setValor(int value) {
	valor = value;
}
