/*
 * arrayLocalidad.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Lucía
 */

#ifndef ARRAYLOCALIDAD_H_
#define ARRAYLOCALIDAD_H_

typedef struct{
	int idLocalidad;
	char nombreLocalidad[100];
	int isEmpty;//si es 0, la estructura esta libre par anueva carga, si es 1 esta ocupada
}eLocalidad;


int initLocalidad(eLocalidad lista[], int len);
int findLocalidadById(eLocalidad lista[], int len, int id);


#endif /* ARRAYLOCALIDAD_H_ */
