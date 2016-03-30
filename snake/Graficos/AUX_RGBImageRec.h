/*
 * AUX_RGBImageRec.h
 *
 *  Created on: 4/11/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef AUX_RGBIMAGEREC_H_
#define AUX_RGBIMAGEREC_H_

class AUX_RGBImageRec {
public:
	AUX_RGBImageRec();
	int sizeX;
	int sizeY;
	int	internalFormat;
	int format;

	unsigned char * data;

};

#endif /* AUX_RGBIMAGEREC_H_ */
