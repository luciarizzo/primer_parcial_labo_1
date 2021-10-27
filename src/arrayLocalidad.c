/*
 * arrayLocalidad.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Lucía
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayPedidos.h"
#include "arrayClientes.h"
#include "arrayLocalidad.h"
#include "informes.h"


int initLocalidad(eLocalidad lista[], int len) {
	int i;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			lista[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}

int findLocalidadById(eLocalidad lista[], int len, int id){
	int indice;
	int i;
	indice = -1;
	if(lista != NULL && len > 0){
		for(i = 0; i<len; i++){
			if(lista[i].isEmpty == 1 && lista[i].idLocalidad == id){
				indice = i;
				break;
			}
		}
	}
	return indice;
}
/*
int modifiedLocalidad(eLocalidad lista[], int len) {
	int i;
	int clienteAModificar;
	char localidad[100];
	int retorno;
	retorno = -1;
	clienteAModificar = findClienteById(lista, len);
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1
					&& lista[i].idCliente == clienteAModificar) {
				print1Cliente(lista[i]);
				printf(
						"\nEstá a punto de modificar la localidad del cliente con nombre: %s\n",
						lista[i].nombreCliente);
				utn_getString(localidad,
						"\n Ingrese la nueva localidad del empleado\n",
						"\nError, ingrese una localidad válida\n", 2);
				strcpy(lista[i].localidadCliente, localidad);
				printf(
						"\nLa localidad se ha modificado correctamente por: %s\n",
						lista[i].localidadCliente);
				print1Cliente(lista[i]);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}*/
