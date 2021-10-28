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

/**
 * \brief Iniciliza la lista localidad, asigna el campo isEmpty en 1 (ocupado)
 * \param lista[] array de localidades a ser inicialiado
 * \param len longitud del array
 * \return  devuelve -1 si no se pudo hacer o 0 si pudo
 */
int initLocalidad(eLocalidad lista[], int len);
/*
 * \brief Permite encontrar la posición de la localidad por el ID
 * \param lista array de clientes
 * \param len longitud del array
 * \param id id de la localidad
 * \return retorna la posición donde encontró el id o -1 si no lo encontró.
 */
int findLocalidadById(eLocalidad lista[], int len, int id);


#endif /* ARRAYLOCALIDAD_H_ */
