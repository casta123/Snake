/*
 * main.cpp
 *
 *  Created on: 22/09/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 *
 * GNU/GPL General Public License - http://www.gnu.org/copyleft/gpl.html
 */

#include <iostream>
#include <GL/glut.h>
#include "IL/il.h"
#include "menu/Menu.h"
#include "CCulebrita.h"
#include "CPresa.h"
#include"CNivel.h"
#include "CTexturas.h"
#include "Audio.h"
#include "Direccion/Direccion.h"
#include "puntajes/Globales.h"
using namespace std;

///////////////////////////////////
///// VARIABLES GLOBALES /////////
/////////////////////////////////

CNivel nivel;
GLint velocidad = 150;
Culebrita culebra;
texturas imagenes;
Audio sonido;
Direccion direccion;
Presa presa;
Menu * menu;
Globales puntajesMaximos;
int copia;

unsigned int crecer = 0;
int puntaje = 0;
int punt = 0;
int niv = 1;

bool enJuego = false;
bool enPausa = false;
bool reposo = false;
bool Modo_dos = false;
bool reiniciar = false;
bool salir = false;
bool about = false;

////////////////////////////////////////////////
////           INICIA EL MENU               ///
//////////////////////////////////////////////
void menuInit() {
	menu = new Menu(820, 700, true, -110, 710, -50, 650, imagenes.textura[4]);
	Punto ubicacion(95, 500);
	bool **arbool;
	arbool = new bool*[3];
	*arbool = &enJuego;
	*(arbool + 1) = &enPausa;
	stdBoton boton1("clasico", ubicacion, 400, 40, "Iniciar Juego Clasico",
			arbool, 2, imagenes.textura[5]);
	menu->insertarBoton(boton1);

	bool **listadoBoton3 = new bool*[3];
	*listadoBoton3 = &Modo_dos;
	*(listadoBoton3 + 1) = &enJuego;
	*(listadoBoton3 + 2) = &enPausa;

	ubicacion.set(95, 400);
	stdBoton boton3("arcade", ubicacion, 400, 40, "Juego Arcade",
			listadoBoton3, 3, imagenes.textura[5]);
	menu->insertarBoton(boton3);

	bool ** listado = new bool*[2];
	*listado = &puntajesMaximos.enDibujarGlobales;
	*(listado + 1) = &menu->enMenu;
	ubicacion.set(95, 300);
	stdBoton boton2("puntajes", ubicacion, 400, 40, "Ver Puntajes Maximos",
			listado, 2, imagenes.textura[5]);
	menu->insertarBoton(boton2);

	bool **abot = new bool*;
	*abot = &about;
	ubicacion.set(95, 200);
	stdBoton boton5("acerca", ubicacion, 400, 40, "Acerca de Snake", abot, 1,
			imagenes.textura[5]);
	menu->insertarBoton(boton5);

	bool ** arraySalir = new bool*;
	*arraySalir = &salir;
	ubicacion.set(95, 100);
	stdBoton boton4("salir", ubicacion, 400, 40, "Salir", arraySalir, 1,
			imagenes.textura[5]);
	menu->insertarBoton(boton4);

}
//////////////////////
//FUNCION REINICIAR///
//////////////////////

void Reiniciar() {
	if (Modo_dos == true) {
		niv = 1;
		punt = 0;
	}
	nivel.primero();
	culebra.reiniciar();
	crecer = 0;
	puntaje = 0;
	while (direccion.tamanno() > 0)
		direccion.borrar();
	direccion.insertar(3);
	velocidad = 150;
	sonido.musicaArrancar();
}

void imprimirString(int x, int y, string texto) {
	glRasterPos2f(x, y);
	for (unsigned int i = 0; i < texto.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto[i]);
}
//////////////////////////////////////////////
///FUNCIONES DE PANTALLA/////////////////////
////////////////////////////////////////////

void Juego_Niveles() {
	if (!enJuego && niv <= 6) {
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, imagenes.textura[1]->internalFormat,
				imagenes.textura[1]->sizeX, imagenes.textura[1]->sizeY, 0,
				imagenes.textura[1]->format, GL_UNSIGNED_BYTE,
				imagenes.textura[1]->data);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.0, 0.0, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(600, 0, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(600, 600, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0, 600, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3f(0, 0, 0);
		imprimirString(200, 500, "HAS PERDIDO!!!");
		glColor3f(0, 0.0035294, 0.909803);
		imprimirString(150, 60, "Presione la tecla R para reiniciar");
		imprimirString(150, 20, "Presione ESC para salir al menu");
		glColor3f(1, 1, 1);
	}
	stringstream nive;
	nive << "Nivel: " << niv;
	stringstream pun;
	pun << "Puntos: " << punt;
	glColor3f(1, 1, 0);
	imprimirString(0, 620, nive.str());
	imprimirString(500, 620, pun.str());
	if (punt >= 30 && niv <= 6) {
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, imagenes.textura[1]->internalFormat,
				imagenes.textura[1]->sizeX, imagenes.textura[1]->sizeY, 0,
				imagenes.textura[1]->format, GL_UNSIGNED_BYTE,
				imagenes.textura[1]->data);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.0, 0.0, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(600, 0, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(600, 600, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0, 600, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		if (niv != 6) {
			reposo = true;
			glColor3f(0, 0, 0);
			imprimirString(200, 500, "FELICITACIONES!!!");
			imprimirString(100, 400, "Has completado este nivel");
			glColor3f(0, 0.0035294, 0.909803);
			imprimirString(150, 70, "Presione C para continuar");
			imprimirString(150, 20, "Presione ESC para salir al menu");
			glColor3f(1, 1, 1);
		} else {
			enJuego = false;
			glPushMatrix();
			glColor3f(0, 0, 0);
			imprimirString(200, 500, "FELICITACIONES!!!");
			imprimirString(95, 430, "Has completado el juego");
			glColor3f(0, 0.0035294, 0.909803);
			imprimirString(150, 60, "Presione la tecla R para reiniciar");
			imprimirString(150, 20, "Presione ESC para salir al menu");
			glColor3f(1, 1, 1);
		}
	}
}

void Juego_Normal() {
	stringstream puntuacion;
	puntuacion << "Puntos: " << puntaje;
	stringstream Maximo;
	Maximo << "Puntos: " << copia;
	glColor3f(1, 1, 0);
	imprimirString(550, 620, puntuacion.str());
	if (!enJuego) {
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, imagenes.textura[1]->internalFormat,
				imagenes.textura[1]->sizeX, imagenes.textura[1]->sizeY, 0,
				imagenes.textura[1]->format, GL_UNSIGNED_BYTE,
				imagenes.textura[1]->data);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.0, 0.0, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(600, 0, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(600, 600, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0, 600, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3f(0, 0, 0);
		imprimirString(200, 500, "HAS PERDIDO!!!");
		glRasterPos3f(95, 430, 10);
		imprimirString(95, 430, "Tu puntuacion:");
		glColor3f(1, 0, 0);
		imprimirString(130, 400, puntuacion.str());
		glColor3f(0, 0, 0);
		imprimirString(95, 320, "Maxima puntuacion:");
		glColor3f(1, 0, 0);
		imprimirString(130, 290, Maximo.str());
		glColor3f(0, 0, 0);
		if (puntaje > copia)
			imprimirString(90, 190,
					"Felicitaciones has optenido el puntaje maximo.");
		else
			imprimirString(130, 190, "No has optenido el puntaje maximo.");
		glColor3f(0, 0.0035294, 0.909803);
		imprimirString(150, 60, "Presione la tecla R para reiniciar");
		imprimirString(150, 20, "Presione ESC para salir al menu");
		glColor3f(1, 1, 1);
		glPopMatrix();
	}
}

void display(void) {
	glClearColor(1, 1, 1, 0); //Coloca por defecto el color de pantella en Blanco
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Borra el estado de la pantalla


	if (!menu->enMenu) {
		nivel.DibujarNivel(&imagenes);
		culebra.dibujar(direccion.actual(), &imagenes);
		presa.dibujar();
		if (Modo_dos)
			Juego_Niveles();
		else
			Juego_Normal();
	} else {
		if (about) {
			glTexImage2D(GL_TEXTURE_2D, 0, imagenes.textura[9]->internalFormat,
					imagenes.textura[9]->sizeX, imagenes.textura[9]->sizeY, 0,
					imagenes.textura[9]->format, GL_UNSIGNED_BYTE,
					imagenes.textura[9]->data);

			glEnable(GL_TEXTURE_2D);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0.0, 0.0, 0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(600, 0, 0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(600, 600, 0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, 600, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);

		} else if (puntajesMaximos.enDibujarGlobales) {
			puntajesMaximos.dibujarGlobales(imagenes.textura[4]);
		} else
			menu->dibujar();
	}
	glFlush(); //Forza que se realizan todas las tareas de openGL pendiendentes
	glutSwapBuffers();
}

void init(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-110.0, 710.0, -50.0, 650.0, -50.0, 50.0);
	////////////////////////////////////////////////////////
	//Requerido para la inicializacion de las texturas//////
	////////////////////////////////////////////////////////
	//Pegado sobre el polï¿½gono
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//Filtros
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	////////////////////////////////////
	//Carga de texturas en memoria//////
	////////////////////////////////////
	/*
	 * las imagenes cargadas segun su numero son:
	 * 0) Ladrillos: utilizados para los obstaculos
	 * 1) Loza: Imagen utilizada como fondo del espacio de juego
	 * 2) Hierba1: Utilizado como fondo
	 * 3) Hierba2: Utilizado como fondo
	 * 4) grass: usado como fondo del menu
	 * 5) wood: usado como textura para boton
	 * 6) Escamas: piel de la serpiente
	 * 7) cabeza: textura de la cabeza
	 * 8) ojo: ojos de la serpiente
	 */
	imagenes.LoadBMP("Ladrillos.bmp", 0);
	imagenes.LoadBMP("Loza.bmp", 1);
	imagenes.LoadBMP("Hierba1.bmp", 2);
	imagenes.LoadBMP("Hierba2.bmp", 3);
	imagenes.LoadBMP("grass.jpg", 4);
	imagenes.LoadBMP("wood.jpg", 5);
	imagenes.LoadBMP("Escamas.bmp", 6);
	imagenes.LoadBMP("cabeza.bmp", 7);
	imagenes.LoadBMP("ojo.bmp", 8);
	imagenes.LoadBMP("about.jpg", 9);
}

////////////////////////////////////////////////
///FUNCIONES DE TECLADO////////////////////////
//////////////////////////////////////////////
void mouse(int boton, int estado, int x, int y) {
	if (menu->enMenu)
		if ((estado == GLUT_DOWN))
			if (boton == GLUT_LEFT_BUTTON) {
				menu->enClick(x, y);
			}
}

void PresionarTecla(unsigned char tecla, int MouseX, int MouseY) {
	enPausa = false;
	puntajesMaximos.enDibujarGlobales = false;
	about = false;
	///Si presionan una tecla pause se hace false
	switch (tecla) {
	case 'p':
		enPausa = true;
		break;
	case 'r':
		if (!enJuego && !menu->enMenu) {
			Reiniciar();
			enJuego = true;
			enPausa = true;
		}
		break;
	case 'c':
		if (reposo) {
			culebra.reiniciar();
			crecer = 0;
			puntaje = 0;
			while (direccion.tamanno() > 0)
				direccion.borrar();
			direccion.insertar(3);
			velocidad = 150;
			sonido.musicaArrancar();
			nivel.siguiente();
			punt = 0;
			niv++;
			enPausa = true;
			reposo = false;
		}

	case 27: ///Teclas ESC
		if ((!enJuego || reposo) && !menu->enMenu) {
			menu->enMenu = true;
			enJuego = false;
			reposo = false;
			Reiniciar();
			Modo_dos = false;
		}
		break;
	}
}

void PresionarTeclaEspecial(int tecla, int MouseX, int MouseY) {
	if (!enPausa && enJuego)
		switch (tecla) {
		case GLUT_KEY_UP:
			direccion.insertar(0);
			break;
		case GLUT_KEY_DOWN:
			direccion.insertar(2);
			break;
		case GLUT_KEY_LEFT:
			direccion.insertar(1);
			break;
		case GLUT_KEY_RIGHT:
			direccion.insertar(3);
			break;
		}
	else {

		enPausa = false;
	}
}

/////////////////////////////////////////////////
///FUNCIONES DE MOVIMIENTO//////////////////////
////////////////////////////////////////////////

Punto Siguientepunto(Punto punto, int direccion) {
	Punto s;
	s = punto;
	switch (direccion) {
	case 0:
		s.aumY();
		break;
	case 2:
		s.disY();
		break;
	case 1:
		s.disX();
		break;
	case 3:
		s.aumX();
		break;
	}
	return s;
}

void FuncionMovimiento(int x) {
	if (salir)
		exit(0);
	if (enJuego && !reposo) {
		if (menu->enMenu)
			menu->enMenu = false;
		if (!enPausa) {
			if (direccion.tamanno() > 1)
				direccion.borrar();
			Punto siguiente = Siguientepunto(culebra.cabeza(),
					direccion.actual());
			if (nivel.existeActual(siguiente) || culebra.colisionConCuerpo(
					siguiente)) {
				enJuego = false;
				if (!Modo_dos) {
					copia = puntajesMaximos.MasAlto();
					CPuntaje punt;
					punt.setValor(puntaje);
					puntajesMaximos.insertar(punt);
				}
				sonido.musicaParar();
				sonido.risas();
			} else {
				if (siguiente.getKey() == presa.getpunto().getKey()) {
					crecer = crecer + 2;
					presa.aleatorizar_presa();
					sonido.crack();
					puntaje = puntaje + 10;
					velocidad *= 0.98;
					if (Modo_dos)
						punt++;
				}
				while (nivel.existeActual(presa.getpunto())
						|| culebra.colisionConCuerpo((presa.getpunto()))) {
					presa.aleatorizar_presa();
				}
				if (crecer) {
					culebra.crecer(Siguientepunto(culebra.cabeza(),
							direccion.actual()));
					crecer--;
				} else
					culebra.mover(Siguientepunto(culebra.cabeza(),
							direccion.actual()));
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(velocidad, FuncionMovimiento, 1);//Funcion recursiva
}
void redimensionar(int width, int height) {
	menu->enRedimension(width, height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-110.0, 710.0, -50.0, 650.0, -50.0, 50.0);
}

int main(int argc, char** argv) {
	ilInit();
	sonido.musicaArrancar();
	//Inicia Una nueva ventana
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(820, 700);
	glutInitWindowPosition(100, 20);
	glutCreateWindow("Snake  Theft");
	init();
	menuInit();
	glutKeyboardFunc(PresionarTecla);
	glutSpecialFunc(PresionarTeclaEspecial);
	//Funciones necesarias para el menu
	glutMouseFunc(mouse);
	glutReshapeFunc(redimensionar);
	//Muestra lo declarado funcion display
	glutDisplayFunc(display);
	glutTimerFunc(velocidad, FuncionMovimiento, 1);
	//realiza un ciclo infinito
	glutMainLoop();
	return 0;
}
