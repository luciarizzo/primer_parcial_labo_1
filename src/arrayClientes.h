/*
 * arrayClientes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef ARRAYCLIENTES_H_
#define ARRAYCLIENTES_H_

typedef struct{
	int idCliente;
	char nombreCliente[100];
	char direccionCliente[100];
	char localidadCliente[100];
	char cuitCliente[20];
	int isEmpty;//si es 1, la estructura esta libre par anueva carga, si es 0 esta ocupada
}eClientes;


int initCliente(eClientes lista[], int len);
int BuscarPrimerEspacioLibre(eClientes lista[], int len);
int BuscarId(eClientes lista[], int len, int id);
eClientes addCliente(eClientes lista[], int len, int id);
int altaCliente(eClientes lista[], int len, int id);
int findClienteById(eClientes lista[], int len);
int removeCliente(eClientes lista[], int len);
int modifiedDireccion(eClientes lista[], int len);
int modifiedLocalidad(eClientes lista[], int len);
void print1Cliente(eClientes unCliente);
int printClientes(eClientes lista[], int len);

#endif /* ARRAYCLIENTES_H_ */
