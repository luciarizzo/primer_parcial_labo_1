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
#define CANTPEDIDOS 1000


int initPedido(ePedido lista[], int len) {
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


int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int len) {
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

ePedido addPedido(ePedido lista[], int len, int id) {
	ePedido pedido;
	float kilosTotales;
	int flag;
	flag = -1;

	pedido.idCliente = id;

	if(utn_getNumeroFlotante(&kilosTotales, "\nIngrese los kilos totales de plástico del pedido\n",
			"\nError, ingrese un valor válido\n", 1,
			1000, 2) == 0)
	{
		pedido.kilosTotalesPedido = kilosTotales;
		pedido.cantidadHDPE = 0;
		pedido.cantidadLDPE = 0;
		pedido.cantidadPP = 0;
		flag = 0;

	} else {
		printf("\nError, no se pudo ingresar los kilos totales.\n");
	}

	if(flag == 0){
		pedido.isEmpty = 0; //ocupado.
		strcpy(pedido.estadoPedido, "PENDIENTE");
		printf("\n Finalizó la carga del nuevo pedido. El estado es %s\n", pedido.estadoPedido);
	}
	else {
		printf("\nError en la carga del pedido.\n");
	}

	return pedido;
}


int altaPedido(ePedido lista[], int len, int id) {
	int i;
	i = BuscarPrimerEspacioLibrePedidos(lista, len);
	if (i != -1) {
		if (lista != NULL && len > 0) {
			lista[i] = addPedido(lista, len, id);
		}
	}
	return i;
}

int findPedidoById(ePedido lista[], int len) {
	int retorno;
	retorno = -1;
	int i;
	int idIngresado;
	utn_getNumero(&idIngresado,
			"\nIngrese el número de ID del pedido que desea buscar\n",
			"\nError, ingrese un ID válido, debe ser entre 1 y 1000\n", 1, 1000,
			2);
	for (i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0 && lista[i].idPedido == idIngresado) {
			printf("\nEl pedido fue encontrado.\n");
			retorno = idIngresado;
		}
	}
	if (retorno == -1) {
		printf("\nNingun pedido fue encontrado con ese ID.\n");
	}

	return retorno;
}

ePedido addTiposPlasticos(ePedido lista[], int len, int id) {
	ePedido pedido;
	float cantHDPE;
	float cantLDPE;
	float cantPP;

	pedido.idCliente = id;

	if(utn_getNumeroFlotante(&cantHDPE, "\nIngrese los kilos de HDPE del pedido\n",
			"\nError, ingrese un valor válido\n", 1,
			1000, 2) == 0)
	{
		pedido.cantidadHDPE = cantHDPE;

	} else {
		printf("\nError, no se pudo ingresar los kg de HDPE.\n");
	}

	if(utn_getNumeroFlotante(&cantLDPE, "\nIngrese los kilos de LDPE del pedido\n",
			"\nError, ingrese un valor válido\n", 1,
			1000, 2) == 0)
	{
		pedido.cantidadLDPE = cantLDPE;

	} else {
		printf("\nError, no se pudo ingresar los kg de LDPE.\n");
	}

	if(utn_getNumeroFlotante(&cantPP, "\nIngrese los kilos de PP del pedido\n",
			"\nError, ingrese un valor válido\n", 1,
			1000, 2) == 0)
	{
		pedido.cantidadPP = cantPP;

	} else {
		printf("\nError, no se pudo ingresar los kg de LDPE.\n");
	}


	if(cantHDPE > 0 && cantLDPE > 0 && cantPP > 0){
		pedido.isEmpty = 0; //ocupado.
		strcpy(pedido.estadoPedido, "COMPLETADO");
		printf("\n Finalizó la carga del nuevo pedido. El estado es %s\n", pedido.estadoPedido);
	}
	else {
		printf("\nError en la carga del pedido.\n");
	}

	return pedido;
}


int altaPlasticos(ePedido lista[], int len, int id) {
	int i;
	i = BuscarPrimerEspacioLibrePedidos(lista, len);
	if (i != -1) {
		if (lista != NULL && len > 0 && i != -1) {
			lista[i] = addTiposPlasticos(lista, len, id);
		}
	}
	return i;
}

void print1Pedido(ePedido pedido) {
	printf("%2d %12d %20s %20f %20f %20f %12f\t", pedido.idPedido,
			pedido.idCliente, pedido.estadoPedido,
			pedido.kilosTotalesPedido, pedido.cantidadHDPE, pedido.cantidadLDPE, pedido.cantidadPP);
	printf(
			"\n___________________________________________________________________________________\n");
}

int printPedidos(ePedido lista[], int len) {
	int retorno = -1;
	printf("\n_______________________________________________________________________________________________________\n");
	printf("ID\t  ID Cliente\t      Estado\t   KG totales\t    Cantidad HDPE\t    Cantidad LDPE\t     Cantidad PP\t");
	printf("\n________________________________________________________________________________________________________\n");
	for (int i = 0; i < len; i++) {
		if (lista[i].isEmpty == 0) {
			print1Pedido(lista[i]);
			retorno = 0;
		}
	}
	return retorno;
}


