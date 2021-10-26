/*
 * informes.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayClientes.h"
#include "arrayPedidos.h"

void printClientesConCantidadPendientes(eClientes listaCliente[],
		int lenClientes, ePedido listaPedidos[], int lenPedido) {
	int i;
	int cantidadPedidosPendientes;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedido > 0) {
		for (i = 0; i < lenClientes; i++) {
			if (listaCliente[i].isEmpty == 1) {
				contarPedidosPendientes(listaPedidos, lenPedido,
						listaCliente[i].idCliente, &cantidadPedidosPendientes);
				printf(
						"\n El cliente con ID %d Tiene %d pedido/s pendiente/s\n",
						listaCliente[i].idCliente, cantidadPedidosPendientes);
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				printf(
						"ID\t  ID Cliente\t      Estado\t   KG totales\t    Cantidad HDPE\t    Cantidad LDPE\t     Cantidad PP\t");
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				print1Cliente(listaCliente[i]);

			}
		}
	}
}

void informarPedidosPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedido) {
	int i;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedido > 0) {
		for (i = 0; i < lenPedido; i++) {
			if (strcmp(listaPedidos[i].estadoPedido, "PENDIENTE") == 0
					&& listaPedidos[i].isEmpty == 1) {
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				printf(
						"ID\t  ID Cliente\t      Estado\t   KG totales\t    Cantidad HDPE\t    Cantidad LDPE\t     Cantidad PP\t");
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				print1Pedido(listaPedidos[i]);
				if (BuscarId(listaCliente, lenClientes,
						listaPedidos[i].idCliente) != -1) {
					printf("\nDatos del cliente del pedido con ID %d:\n",
							listaPedidos[i].idPedido);
					printCuitDireccionKgClientes(listaCliente, lenClientes,
							listaPedidos[i].idCliente);
					printf("\nLa cantidad de kg a recolectar es: %.2f\n",
							listaPedidos[i].kilosTotalesPedido);
				}
			}
		}
	}
}

void informarPedidosProcesados(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedido) {
	int i;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedido > 0) {
		for (i = 0; i < lenPedido; i++) {
			if (strcmp(listaPedidos[i].estadoPedido, "COMPLETADO") == 0
					&& listaPedidos[i].isEmpty == 1) {
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				printf(
						"ID\t  ID Cliente\t      Estado\t   KG totales\t    Cantidad HDPE\t    Cantidad LDPE\t     Cantidad PP\t");
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				print1Pedido(listaPedidos[i]);
				if (BuscarId(listaCliente, lenClientes,
						listaPedidos[i].idCliente) != -1) {
					printf("\nDatos del cliente del pedido con ID %d:\n",
							listaPedidos[i].idPedido);
					printCuitDireccionKgClientes(listaCliente, lenClientes,
							listaPedidos[i].idCliente);
					printf(
							"\nLa cantidad de kg de HDPE reciclados es: %.2f, la de LDPE es %.2f, y la de PP es %.2f\n",
							listaPedidos[i].cantidadHDPE,
							listaPedidos[i].cantidadLDPE,
							listaPedidos[i].cantidadPP);
				}
			}
		}
	}
}

void informarPendientesPorLocalidad(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos) {
	int i;
	char localidad[100];
	int cantidadPedidosPendientes;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedidos > 0) {
		if (utn_getString(localidad, "Ingrese el nombre de la localidad",
				"Error, ingrese un nombre válido", 2) == 0) {
			for (i = 0; i < lenClientes; i++) {
				if ((stricmp(listaCliente[i].localidadCliente, localidad) == 0) && listaCliente[i].isEmpty == 1){
					contarPedidosPendientes(listaPedidos, lenPedidos, listaCliente[i].idCliente, &cantidadPedidosPendientes);
					printf("\nPara la localidad %s hay %d pedidos pendientes\n", localidad, cantidadPedidosPendientes);
					}
				}
			}
		}

}
