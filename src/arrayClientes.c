/*
 * arrayClientes.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayClientes.h"
#include "arrayLocalidad.h"

int initCliente(eClientes lista[], int len) {
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

int BuscarPrimerEspacioLibre(eClientes lista[], int len) {
	int i;
	int index;
	index = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				index = i;
				break;
			}
		}
	}
	return index;
}

int BuscarId(eClientes lista[], int len, int id) {
	int i;
	int index;
	index = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == id) {
				index = i;
				break;
			}
		}
	}
	return index;
}

eClientes addCliente(eClientes listaClientes[], int lenClientes, int id) {
	char nombreEmpresa[100];
	char direccion[100];
	int idLocalidad;
	char cuit[20];
	eClientes cliente;
	/*el ID es incremental. BORRAR ESTO.
	 do{
	 utn_getNumero(&id, "\nIngrese el número de ID del empleado\n",
	 "\nIngrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
	 2);
	 }while(BuscarId(lista, len, id) != -1);
	 */

	utn_getString(nombreEmpresa,
			"\nIngrese el nombre de la Empresa del cliente\n",
			"\nError, ingrese un nombre válido\n", 2);
	strcpy(cliente.nombreCliente, nombreEmpresa);

	utn_getString(direccion, "\nIngrese la dirección del cliente\n",
			"\nError, ingrese una dirección válida\n", 2);
	strcpy(cliente.direccionCliente, direccion);

	/*utn_getString(localidad, "\n Ingrese la localidad del cliente\n",
			"\nError, ingrese una localidad válida\n", 2);
	strcpy(cliente.localidadCliente, localidad);*/

	utn_getNumero(&idLocalidad, "\nIngrese el numero de ID de la localidad correspondiente\n", "\nError, ingrese el ID nuevamente\n",
			1, 5, 2);
	cliente.idLocalidad = idLocalidad;

	//usar funcion de getCuit.
	utn_getCUIT(cuit, "\nIngrese el número de cuit del cliente\n",
			"\nError, ingrese un número de cuit del cliente\n", 2);
	strcpy(cliente.cuitCliente, cuit);

	cliente.idCliente = id;
	cliente.isEmpty = 1; //ocupado.
	printf("\n Finalizó la carga del nuevo cliente.\n");

	return cliente;
}

int altaCliente(eClientes listaClientes[], int lenClientes, int id) {
	int i;
	i = BuscarPrimerEspacioLibre(listaClientes, lenClientes);
	if (i != -1) {
		if (listaClientes != NULL && lenClientes > 0 && i != -1) {
			listaClientes[i] = addCliente(listaClientes, lenClientes, id);
		}
	}
	return i;
}

int findClienteById(eClientes lista[], int len) {
	int retorno;
	retorno = -1;
	int i;
	//int idIngresado;
	if (lista != NULL && len > 0) {
		printClientes(lista, len);
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				printf("\nEl cliente fue encontrado.\n");
				print1Cliente(lista[i]);
				retorno = i;
			}
		}
		if (retorno == -1) {
			printf("\nNingun cliente fue encontrado con ese ID.\n");
		}
	}
	return retorno;
}

int removeCliente(eClientes lista[], int len, int idCliente) {
	int i;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				printf("\n¿Desea eliminar el cliente con esos datos?\n");
				print1Cliente(lista[i]);
				if (utn_getCaracterSiNo() == 0) {
					lista[i].isEmpty = 0;
					retorno = idCliente;
					printf("\n Se eliminó el cliente\n");
				}
				break;
			}
		}
	}
	return retorno;
}

int modifiedDireccion(eClientes lista[], int len, int idCliente) {
	int i;
	char direccion[100];
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1
					&& lista[i].idCliente == idCliente) {
				print1Cliente(lista[i]);
				printf(
						"\nEstá a punto de modificar la direccion del cliente con nombre %s\n",
						lista[i].nombreCliente);
				utn_getString(direccion,
						"\n Ingrese la nueva direccion del cliente\n",
						"\nError, ingrese una direccion válida\n", 2);
				strcpy(lista[i].direccionCliente, direccion);
				printf(
						"\nLa dirección se ha modificado correctamente por: %s\n",
						lista[i].direccionCliente);
				print1Cliente(lista[i]);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int modifiedLocalidad(eClientes lista[], int len, int idCliente) {
	int i;
	//int clienteAModificar;
	int idLocalidad;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == idCliente) {
				print1Cliente(lista[i]);
				printf(
						"\nEstá a punto de modificar la localidad del cliente con nombre: %s\n",
						lista[i].nombreCliente);
				utn_getNumero(&idLocalidad,
						"\n Ingrese el ID de la  nueva localidad del cliente\n",
						"\nError, ingrese una localidad válida\n", 1, 5, 2);

				printf(
						"\nLa localidad se ha modificado correctamente por la de ID: %d\n",
						lista[i].idLocalidad);
				print1Cliente(lista[i]);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void print1Cliente(eClientes unCliente) {
	printf("%2d %12s %20s %20d %12s \t", unCliente.idCliente,
			unCliente.nombreCliente, unCliente.direccionCliente,
			unCliente.idLocalidad, unCliente.cuitCliente);
	printf(
			"\n________________________________________________________________________\n");
}

int printClientes(eClientes lista[], int len) {
	int retorno = -1;
	int i;

	printf(
			"\n____________________________________________________________________\n");
	printf(
			"ID\t  Nombre     Empresa\t     Direccion\t   ID Localidad\t    CUIT\n");
	printf(
			"\n____________________________________________________________________\n");

	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				print1Cliente(lista[i]);
			}
		}
		retorno = 0;
	} else {
		printf("\nError. No hay clientes para listar\n");
	}
	return retorno;
}

int printCuitDireccionKgClientes(eClientes lista[], int len, int idCliente) {
	int retorno = -1;
	if (lista != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == idCliente) {
				printf(
						"\nEl ID es %d, la dirección es %s y el CUIT del cliente es %s\n",
						lista[i].idCliente, lista[i].direccionCliente,
						lista[i].cuitCliente);
				retorno = 0;
			}
		}
		if (retorno == -1) {
			printf("\nError. No hay clientes para listar\n");
		}
	}

	return retorno;
}

int contarClientes(eClientes lista[], int len, int *cantClientes) {
	int i;
	int contadorClientes = 0;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				contadorClientes++;
				retorno = 0;
			}
		}
		*cantClientes = contadorClientes;
		printf("La cantidad de clientes es: %d ", contadorClientes);

	} else {
		printf("\nNo se pudo contar los clientes.");
	}
	return retorno;
}



