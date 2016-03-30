#include "CPunto.h"
#include<cmath>
#include<sstream>
#include<cstring>
#include<iostream>
using namespace std;
Punto::Punto() {
	x = 0;
	y = 0;
}
Punto::Punto(double lx, double ly) {
	x = lx;
	y = ly;
}
void Punto::setX(double lx) {
	x = lx;
}

void Punto::setY(double ly) {
	y = ly;
}

void Punto::set(double lx, double ly) {
	x = lx;
	y = ly;
}
double Punto::getX() {
	return x;
}
double Punto::getY() {
	return y;
}

void Punto::aumX() {
	x++;
}
void Punto::aumY() {
	y++;
}
void Punto::disX() {
	x--;
}
void Punto::disY() {
	y--;
}
string Punto::getKey(){
	stringstream key;
	if (x <= 9 && x >= 0)
		key << "0" << x;
	else
		key << x;
	if (y <= 9 && y >= 0)
		key << "0" << y;
	else
		key << y;
	return key.str();
}
