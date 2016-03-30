/*
 * CPuntaje.h
 *
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CPUNTAJE_H_
#define CPUNTAJE_H_
#include <string>


using namespace std;
class CPuntaje {
	private:
	int id;
	string nombre;
	int valor;

public:
	CPuntaje();
	bool Guardar();
	bool Leer();

	int getId();
	string getNombre();
	int getValor();

	void setId(int key);
	void setNombre(string name);
	void setValor(int value);


};

#endif /* CPUNTAJE_H_ */
