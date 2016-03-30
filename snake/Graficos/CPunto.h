/*
 * CPunto.h
 *
 *  Created on: 28/10/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CPUNTO_H_
#define CPUNTO_H_
#define pi 3.1415926535897932384626433832795
#include <string>
using namespace std;
class Punto {
private:
	double x;
	double y;
public:
	Punto();
	Punto(double lx, double ly);
	void setX(double lx);
	void setY(double ly);
	void aumX();
	void aumY();
	void disX();
	void disY();
	void set(double lx, double ly);
	double getX();
	double getY();
	string getKey();
};

#endif /* CPUNTO_H_ */
