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

eClientes addCliente(eClientes lista[], int len, int id) {
	char nombreEmpresa[100];
	char direccion[100];
	char localidad[100];
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
			"\n Ingrese el nombre de la Empresa del cliente\n",
			"\nError, ingrese un nombre válido\n", 2);
	strcpy(cliente.nombreCliente, nombreEmpresa);

	utn_getString(direccion, "\n Ingrese la dirección del cliente\n",
			"\nError, ingrese una dirección válida\n", 2);
	strcpy(cliente.direccionCliente, direccion);

	utn_getString(localidad, "\n Ingrese la localidad del cliente\n",
			"\nError, ingrese una localidad válida\n", 2);
	strcpy(cliente.localidadCliente, localidad);

	//usar funcion de getCuit.
	utn_getCUIT(cuit, "\nIngrese el número de cuit del cliente\n",
			"\nError, ingrese un número de cuit del cliente\n", 2);
	strcpy(cliente.cuitCliente, cuit);

	cliente.idCliente = id;
	cliente.isEmpty = 1; //ocupado.
	printf("\n Finalizó la carga del nuevo cliente.\n");

	return cliente;
}

int altaCliente(eClientes lista[], int len, int id) {
	int i;
	i = BuscarPrimerEspacioLibre(lista, len);
	if (i != -1) {
		if (lista != NULL && len > 0 && i != -1) {
			lista[i] = addCliente(lista, len, id);
		}
	}
	return i;
}

int findClienteById(eClientes lista[], int len) {
	int retorno;
	retorno = -1;
	int i;
	int idIngresado;
	if (lista != NULL && len > 0) {
		printClientes(lista, len);
		utn_getNumero(&idIngresado,
				"\nIngrese el número de ID del cliente que desea buscar entre 100 y 200\n",
				"\nError, ingrese un ID válido, debe ser entre 100 y 200\n",
				100, 200, 2);
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == idIngresado) {
				printf("\nEl cliente fue encontrado.\n");
				print1Cliente(lista[i]);
				retorno = idIngresado;
			}
		}
		if (retorno == -1) {
			printf("\nNingun cliente fue encontrado con ese ID.\n");
		}
	}
	return retorno;
}

int removeCliente(eClientes lista[], int len) {
	int i;
	int id;
	id = findClienteById(lista, len);
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == id) {
				printf("\n¿Desea eliminar el cliente con esos datos?\n");
				print1Cliente(lista[i]);
				if (utn_getCaracterSiNo() == 0) {
					lista[i].isEmpty = 0;
					retorno = 0;
					printf("\n Se eliminó el cliente\n");
				}
				break;
			}
		}
	}
	return retorno;
}

int modifiedDireccion(eClientes lista[], int len) {
	int i;
	int clienteAModificar;
	char direccion[100];
	int retorno;
	retorno = -1;
	clienteAModificar = findClienteById(lista, len);
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1
					&& lista[i].idCliente == clienteAModificar) {
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

int modifiedLocalidad(eClientes lista[], int len) {
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
}

void print1Cliente(eClientes unCliente) {
	printf("%2d %12s %20s %20s %12s \t", unCliente.idCliente,
			unCliente.nombreCliente, unCliente.direccionCliente,
			unCliente.localidadCliente, unCliente.cuitCliente);
	printf(
			"\n________________________________________________________________________\n");
}

int printClientes(eClientes lista[], int len) {
	int retorno = -1;
	if (lista != NULL && len > 0) {
		printf(
				"\n____________________________________________________________________\n");
		printf(
				"ID\t  Nombre     Empresa\t     Direccion\t    Localidad\t    CUIT\n");
		printf(
				"\n____________________________________________________________________\n");
		for (int i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1) {
				print1Cliente(lista[i]);
				retorno = 0;
			}
		}
		if (retorno == -1) {
			printf("\nError. No hay clientes para listar\n");
		}
	}

	return retorno;
}

int printCuitDireccionKgClientes(eClientes lista[], int len, int idCliente){
	int retorno = -1;
		if (lista != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				if (lista[i].isEmpty == 1 && lista[i].idCliente == idCliente) {
					printf("\nEl ID es %d, la dirección es %s y el CUIT del cliente es %s\n", lista[i].idCliente,
							lista[i].direccionCliente, lista[i].cuitCliente);
					retorno = 0;
				}
			}
			if (retorno == -1) {
				printf("\nError. No hay clientes para listar\n");
			}
		}

		return retorno;
}



/*
 float totalSalarios(Employee lista[], int len) {
 int i;
 float acumulador;
 acumulador = 0;
 for (i = 0; i < len; i++) {
 if (lista[i].isEmpty == 0) {
 acumulador = acumulador + lista[i].salaryEmployee;
 }
 }
 return acumulador;
 }

 float promedioSalarios(Employee lista[], int len){
 float total;
 int i;
 float promedio;
 int contadorOcupados;
 contadorOcupados = 0;
 total = totalSalarios(lista, len);
 for (i = 0; i < len; i++) {
 if(lista[i].isEmpty == 0){
 contadorOcupados++;
 }
 }
 promedio = total / (float)contadorOcupados;
 return promedio;
 }

 int superanSalarioPromedio(Employee lista[], int len){
 int i;
 float promedio;
 int contadorEmpleadoSalarioSuperior;
 contadorEmpleadoSalarioSuperior = 0;
 promedio = promedioSalarios(lista, len);
 for(i=0; i<len; i++){
 if(lista[i].isEmpty == 0 && lista[i].salaryEmployee > promedio){
 contadorEmpleadoSalarioSuperior++;
 printf("\n%f\n", promedio);
 printf("\n%f\n", lista[i].salaryEmployee);
 }
 }
 return contadorEmpleadoSalarioSuperior;
 }
 */

