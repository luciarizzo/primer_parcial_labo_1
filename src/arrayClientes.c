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
#define CANTCLIENTES 100


int initCliente(eClientes lista[], int len) {
	int i;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			lista[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
} //la testeé y funciona.

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
			if (lista[i].isEmpty == 0 && lista[i].idCliente == id) {
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
	int cuit;
	eClientes cliente;
	/*el ID es incremental. BORRAR ESTO.
	do{
		utn_getNumero(&id, "\nIngrese el número de ID del empleado\n",
				"\nIngrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
				2);
	}while(BuscarId(lista, len, id) != -1);
	*/
	utn_getString(nombreEmpresa, "\n Ingrese el nombre de la Empresa del cliente\n",
			"\nError, ingrese un nombre válido\n", 2);
	strcpy(cliente.nombreCliente, nombreEmpresa);

	utn_getString(direccion, "\n Ingrese la dirección del cliente\n",
			"\nError, ingrese una dirección válida\n", 2);
	strcpy(cliente.direccionCliente, direccion);

	utn_getString(localidad, "\n Ingrese la localidad del cliente\n",
				"\nError, ingrese una localidad válida\n", 2);
		strcpy(cliente.localidadCliente, localidad);

	//usar funcion de getCuit.
	utn_getNumero(&cuit, "\nIngrese el número de cuit del cliente\n",
			"\nError, ingrese un número de cuit del cliente\n", 1,
			5, 2);
	cliente.cuitCliente = cuit;


	cliente.idCliente = id;
	cliente.isEmpty = 0; //ocupado.
	printf("\n Finalizó la carga del nuevo cliente. \n¿Desea ingresar otro empleado?\n");

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
	utn_getNumero(&idIngresado,
			"\nIngrese el número de ID del cliente que desea buscar\n",
			"\nError, ingrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
			2);
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idCliente == idIngresado) {
			printf("\nEl cliente fue encontrado.\n");
			retorno = idIngresado;
		}
	}
	if (retorno == -1) {
		printf("\nNingun cliente fue encontrado con ese ID.\n");
	}

	return retorno;
}

int removeCliente(eClientes lista[], int len) {
	int i;
	int id;
	id = findClienteById(lista, len);
	int retorno;
	retorno = -1;
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idCliente == id) {
			printf("\n¿Desea eliminar el cliente con esos datos?\n");
			print1Cliente(lista[i]);
			if (utn_getCaracterSiNo() == 0) {
				lista[i].isEmpty = 1;
				retorno = 0;
				printf("\n Se eliminó el cliente\n");
			}
			break;
		}
	}
	return retorno;
}

int modifiedDireccion(eClientes lista[], int len) {
	int i;
	int clienteAModificar;
	char direccion[100];
	int retorno;
	retorno = 0;
	clienteAModificar = findClienteById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idCliente == clienteAModificar) {
			printf("\nEstá a punto de modificar la direccion del cliente con nombre %s\n",
					lista[i].nombreCliente);
			utn_getString(direccion, "\n Ingrese la nueva direccion del cliente\n",
					"\nError, ingrese una direccion válida\n", 2);
			strcpy(lista[i].direccionCliente, direccion);
			printf("\nLa dirección se ha modificado correctamente por: %s\n",
					lista[i].direccionCliente);
			//mostrar todos los datos acá
			retorno = 1;
			break;
		}
	}

	return retorno;

}

int modifiedLocalidad(eClientes lista[], int len) {
	int i;
	int clienteAModificar;
	char localidad[100];
	int retorno;
	retorno = 0;
	clienteAModificar = findClienteById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idCliente == clienteAModificar) {
			printf("\nEstá a punto de modificar la localidad del cliente con nombre: %s\n",
					lista[i].nombreCliente);
			utn_getString(localidad,
					"\n Ingrese la nueva localidad del empleado\n",
					"\nError, ingrese una localidad válida\n", 2);
			strcpy(lista[i].localidadCliente, localidad);
			printf("\nLa localidad se ha modificado correctamente por: %s\n",
					lista[i].localidadCliente);
			retorno = 1;
			break;
		}
	}
	return retorno;
}
/*
int modifiedEmployeeSalary(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	int retorno;
	retorno = 0;
	float salary;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre: %s\n",
					lista[i].nameEmployee);
			utn_getNumeroFlotante(&salary,
					"\nIngrese el salario del empleado\n",
					"\nError. Ingrese un salario válido\n", 1, 100000, 2);
			lista[i].salaryEmployee = salary;
			printf("\nEl salario se ha modificado correctamente por: %f\n",
					lista[i].salaryEmployee);
			retorno = 1;
			break;
		}
	}
	return retorno;
}

int modifiedEmployeeSectorId(Employee lista[], int len) {
	int i;
	int empleadoAModificar;
	int retorno;
	retorno = 0;
	int sectorId;
	empleadoAModificar = findEmployeeById(lista, len);

	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0
				&& lista[i].idEmployee == empleadoAModificar) {
			printf("\nEstá a punto de modificar el empleado con nombre: %s\n",
					lista[i].nameEmployee);
			utn_getNumero(&sectorId,
					"\nIngrese el nuevo número de sector ID del empleado\n",
					"\nError, ingrese un sector ID válido, debe ser entre 1 y 5\n",
					1, 5, 2);
			lista[i].sectorIdEmployee = sectorId;
			printf("\nEl sector se ha modificado correctamente por %d\n",
					lista[i].sectorIdEmployee);
			retorno = 1;
			break;
		}
	}
	return retorno;
}
*/

//ORDENAMIENTO
/*
void sortEmployeesbyLastNameOrSector(Employee lista[], int len) {
	Employee auxEmpleado;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (strcmp(lista[i].lastNameEmployee, lista[j].lastNameEmployee)
					> 0) {
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			} else if (strcmp(lista[i].lastNameEmployee,
					lista[j].lastNameEmployee) == 0) {
				if (lista[i].sectorIdEmployee > lista[j].sectorIdEmployee) {
					auxEmpleado = lista[i];
					lista[i] = lista[j];
					lista[j] = auxEmpleado;
				}
			}
		}
	}
}
*/
void print1Cliente(eClientes unCliente) {
	printf("%2d %12s %20s %20s %12d \t", unCliente.idCliente,
			unCliente.nombreCliente, unCliente.direccionCliente,
			unCliente.localidadCliente, unCliente.cuitCliente);
	printf(
			"\n____________________________________________________________________\n");
}

int printClientes(eClientes lista[], int len) {
	int retorno = -1;
	printf("\n____________________________________________________________________\n");
	printf("ID\t  Nombre Empresa\t   Direccion\t    Localidad\t    CUIT\n");
	printf("\n____________________________________________________________________\n");
	for (int i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0) {
			print1Cliente(lista[i]);
			retorno = 0;
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
