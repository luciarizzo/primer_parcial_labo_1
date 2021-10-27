/*
 * arrayPedidos.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayPedidos.h"
#include "arrayClientes.h"
#include "informes.h"

int initPedido(ePedido lista[], int len) {
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
} //la testeé y funciona.

int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int len) {
	int i;
	int index;
	index = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 0) {
				index = i;
				break;
			}
		}
	}
	return index;
}
/*
 int BuscarId(ePedido lista[], int len, int idPedido) {
 int i;
 int index;
 index = -1;
 if (lista != NULL && len > 0) {
 for (i = 0; i < len; i++) {
 if (lista[i].isEmpty == 0 && lista[i].idPedido == idPedido) {
 index = i;
 break;
 }
 }
 }
 return index;
 }*/

ePedido addPedido(ePedido lista[], int len, int idCliente, int *idPedido) {
	ePedido pedido;
	float kilosTotales;
	int flag;
	flag = -1;
	if (lista != NULL && len > 0) {
		pedido.idCliente = idCliente;
		if (lista != NULL && len > 0) {
			if (utn_getNumeroFlotante(&kilosTotales,
					"\nIngrese los kilos totales de plástico del pedido\n",
					"\nError, ingrese un valor válido\n", 1, 1000, 2) == 0) {
				pedido.kilosTotalesPedido = kilosTotales;
				pedido.cantidadHDPE = 0;
				pedido.cantidadLDPE = 0;
				pedido.cantidadPP = 0;
				flag = 0;

			} else {
				printf("\nError, no se pudo ingresar los kilos totales.\n");
			}

			if (flag == 0) {
				pedido.isEmpty = 1; //ocupado.
				strcpy(pedido.estadoPedido, "PENDIENTE");
				pedido.idPedido = *idPedido;
				(*idPedido)++;
				printf(
						"\n Finalizó la carga del nuevo pedido. El estado es %s con ID pedido %d\n",
						pedido.estadoPedido, pedido.idPedido);
			} else {
				printf("\nError en la carga del pedido.\n");
			}
		}
	}
	return pedido;
}

int altaPedido(ePedido lista[], int len, int idCliente, int *idPedido) {
	int i;
	i = BuscarPrimerEspacioLibrePedidos(lista, len);
	if (i != -1) {
		if (lista != NULL && len > 0) {
			lista[i] = addPedido(lista, len, idCliente, idPedido);
		}
	}
	return i;
}

int findPedidoById(ePedido lista[], int len, int *idCliente) {
	int retorno;
	retorno = -1;
	int i;
	int idIngresado;
	int idDelCliente = 0;
	utn_getNumero(&idIngresado,
			"\nIngrese el número de ID del pedido que desea buscar\n",
			"\nError, ingrese un ID válido, debe ser entre 1000 y 2000\n", 1000,
			2000, 2);
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 1 && lista[i].idPedido == idIngresado) {
			printf("\nEl pedido fue encontrado.\n");
			retorno = idIngresado;
			*idCliente = idDelCliente;
		}
	}
	if (retorno == -1) {
		printf("\nNingun pedido fue encontrado con ese ID.\n");
	}

	return retorno;
}

ePedido addTiposPlasticos(ePedido lista[], int len, int idPedido) {
	ePedido pedido;
	float cantHDPE;
	float cantLDPE;
	float cantPP;
	int i;
	i = findPedidosPorIdRetornarIndice(lista, len, idPedido);
	pedido = lista[i];

	if (lista != NULL && len > 0 && idPedido > 0) {

		printf("Entro al primer if de addplasticos");

		pedido.idPedido = idPedido;

		if (utn_getNumeroFlotante(&cantHDPE,
				"\nIngrese los kilos de HDPE del pedido\n",
				"\nError, ingrese un valor válido\n", 1, 1000, 2) == 0) {
			pedido.cantidadHDPE = cantHDPE;

		} else {
			printf("\nError, no se pudo ingresar los kg de HDPE.\n");
		}

		if (utn_getNumeroFlotante(&cantLDPE,
				"\nIngrese los kilos de LDPE del pedido\n",
				"\nError, ingrese un valor válido\n", 1, 1000, 2) == 0) {
			pedido.cantidadLDPE = cantLDPE;

		} else {
			printf("\nError, no se pudo ingresar los kg de LDPE.\n");
		}

		if (utn_getNumeroFlotante(&cantPP,
				"\nIngrese los kilos de PP del pedido\n",
				"\nError, ingrese un valor válido\n", 1, 1000, 2) == 0) {
			pedido.cantidadPP = cantPP;

		} else {
			printf("\nError, no se pudo ingresar los kg de LDPE.\n");
		}

		if (cantHDPE > 0 && cantLDPE > 0 && cantPP > 0) {
			pedido.isEmpty = 1; //ocupado.
			strcpy(pedido.estadoPedido, "COMPLETADO");
			printf("\n Finalizó la carga del nuevo pedido. El estado es %s\n",
					pedido.estadoPedido);
		} else {
			printf("\nError en la carga del pedido.\n");
		}
	}
	return pedido;
}

int altaPlasticos(ePedido lista[], int len, int idPedido, int idCliente) {
	int i;
	int retorno;
	retorno = -1;
	//i = BuscarPrimerEspacioLibrePedidos(lista, len);
	//buscar entre los pendientes
	i = findPedidosPorIdRetornarIndice(lista, len, idPedido);
	if (lista != NULL && len > 0 && i != -1) {
		//idCliente = lista[i].idCliente;
		lista[i] = addTiposPlasticos(lista, len, idPedido);
		retorno = 0;
	}
	printf("%d", retorno);
	return retorno;
}

void print1Pedido(ePedido pedido) {
	printf("%8d %12d %20s %20.2f %20.2f %20.2f %12.2f\t", pedido.idPedido,
			pedido.idCliente, pedido.estadoPedido, pedido.kilosTotalesPedido,
			pedido.cantidadHDPE, pedido.cantidadLDPE, pedido.cantidadPP);
	printf(
			"\n__________________________________________________________________________________________________________________________\n");
}

int printPedidos(ePedido lista[], int len) {
	int retorno = -1;
	printf(
			"\n__________________________________________________________________________________________________________________________\n");
	printf(
			"	ID\t  ID Cliente\t      Estado\t   		KG totales\t    Cantidad HDPE\t    Cantidad LDPE\t     Cantidad PP\t");
	printf(
			"\n__________________________________________________________________________________________________________________________\n");
	for (int i = 0; i < len; i++) {
		if (lista[i].isEmpty == 1) {
			print1Pedido(lista[i]);
			retorno = 0;
		}
	}
	return retorno;
}

int contarPedidosPendientes(ePedido lista[], int len, int idCliente,
		int *cantPendientes) {
	int i;
	int retorno;
	retorno = -1;
	int contadorPendientes = 0;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (strcmp(lista[i].estadoPedido, "PENDIENTE") == 0
					&& lista[i].idCliente == idCliente) {
				contadorPendientes++;
			}
		}
		*cantPendientes = contadorPendientes;
		/*for(i=0; i<len; i++){
		 printf("contarpedidos");
		 }*/
	}
	return retorno;
}

int contarPedidosCompletados(ePedido lista[], int len, int idCliente,
		int *cantCompletados) {
	int i;
	int retorno;
	retorno = -1;
	int contadorCompletados = 0;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (strcmp(lista[i].estadoPedido, "COMPLETADO") == 0
					&& lista[i].idCliente == idCliente) {
				contadorCompletados++;
			}
		}
		*cantCompletados = contadorCompletados;
		/*for(i=0; i<len; i++){
		 printf("contarpedidos");
		 }*/
	}
	return retorno;
}

int contarPedidos(ePedido lista[], int len, int idCliente, int *cantPedidos) {
	int i;
	int retorno;
	retorno = -1;
	int contadorPedidos = 0;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].isEmpty == 1 && lista[i].idCliente == idCliente) {
				contadorPedidos++;
			}
		}
		*cantPedidos = contadorPedidos;
		/*for(i=0; i<len; i++){
		 printf("contarpedidos");
		 }*/
	}
	return retorno;
}

int buscarPedidoPorIdCliente(ePedido lista[], int len, int idCliente,
		int *idPedido) {
	int i;
	int retorno;
	retorno = -1;
	int auxIdPedido;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].idCliente == idCliente) {
				auxIdPedido = lista[i].idPedido;
				retorno = 0;
			}
		}
		*idPedido = auxIdPedido;
	}
	return retorno;
}

int contarPlasticoTipoPP(ePedido lista[], int len, int *cantPP) {
	int i;
	int acumuladorKgPP = 0;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (strcmp(lista[i].estadoPedido, "COMPLETADO") == 0
					&& lista[i].cantidadPP > 0) {
				acumuladorKgPP = lista[i].cantidadPP;
				retorno = 0;
			}
		}
		*cantPP = acumuladorKgPP;
		printf("La kg de plastico PP es: %d ", acumuladorKgPP);
	} else {
		printf("\nNo se pudo contar el plastico PP.");
	}
	return retorno;
}

int findPedidosPorIdRetornarIndice(ePedido lista[], int len, int idPedido) {
	int i;
	int retorno;
	retorno = -1;
	if (lista != NULL && len > 0 && idPedido > 0) {
		for (i = 0; i < len; i++) {
			if (lista[i].idPedido == idPedido) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

