/*
 * Audio.cpp
 *
 *  Created on: 28/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "Audio.h"
#include<iostream>
using namespace std;
using namespace irrklang;
Audio::Audio() {
	this->arrancarMotor();
	reproduciendo = !true;
	this->Bacgroundmusic = motor->addSoundSourceFromFile("waltz.mp3");
	//Bacgroundmusic->setDefaultVolume(0.1);

	this->risasource = motor->addSoundSourceFromFile("risa.wav");
	this->boneCrack = motor->addSoundSourceFromFile("crack.mp3");

	this->musica = motor->play2D(Bacgroundmusic, true, true, true);
	this->risa = motor->play2D(risasource, false, true, true);
	this->bone = motor->play2D(boneCrack,false,true,true);
}
void Audio::arrancarMotor() {
	motor = createIrrKlangDevice();
}
void Audio::musicaArrancar() {
	if(musica->isFinished()){
		musica->drop();
		this->musica = motor->play2D(Bacgroundmusic, false, true, true);
	}
	musica->setIsPaused(false);
	musica->setPlayPosition(0);
	musica->setPlaybackSpeed(1);
	reproduciendo = true;
}
void Audio::musicaParar() {
	musica->setIsPaused(true);
	reproduciendo = false;

}
void Audio::risas() {
	if (risa->isFinished()) {
		risa->drop();
		this->risa = motor->play2D(risasource, false, true, true);
	}
	risa->setIsPaused(false);
	risa->setPlayPosition(0);
	risa->setPlaybackSpeed(1);
}

void Audio::crack(){
	if (bone->isFinished()) {
			bone->drop();
			this->bone = motor->play2D(boneCrack, false, true, true);
		}
		bone->setIsPaused(false);
		bone->setPlayPosition(0);
		bone->setPlaybackSpeed(1);
}
