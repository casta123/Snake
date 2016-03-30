/*
 * Audio.h
 *
 *  Created on: 28/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef AUDIO_H_
#define AUDIO_H_
#include<irrKlang/irrKlang.h>
using namespace irrklang;
class Audio {
private:
	ISoundSource *Bacgroundmusic;
	ISoundSource *risasource;
	ISoundSource *boneCrack;
	ISoundEngine * motor;
	ISound * musica;
	ISound * risa;
	ISound * bone;

public:
	Audio();
	void arrancarMotor();
	void musicaArrancar();
	void musicaParar();
	bool reproduciendo;
	void risas();
	void crack();
};

#endif /* AUDIO_H_ */
