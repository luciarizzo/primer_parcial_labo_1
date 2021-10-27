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
#include "arrayLocalidad.h"

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

int informarPedidosPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedido) {
	int i;
	int retorno;
	retorno = -1;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedido > 0) {
		for (i = 0; i < lenPedido; i++) {
			if (strcmp(listaPedidos[i].estadoPedido, "PENDIENTE") == 0
					&& listaPedidos[i].isEmpty == 1) {
				printf(
						"\n_____________________________________________________________________________________________________________________________\n");
				printf(
						"ID\t  	ID Cliente\t      Estado\t  	 	KG totales\t    	Cantidad HDPE\t    		Cantidad LDPE\t     		Cantidad PP\t");
				printf(
						"\n______________________________________________________________________________________________________________________________\n");
				print1Pedido(listaPedidos[i]);
				if (BuscarId(listaCliente, lenClientes,
						listaPedidos[i].idCliente) != -1) {
					printf("\nDatos del cliente del pedido con ID %d:\n",
							listaPedidos[i].idPedido);
					printCuitDireccionKgClientes(listaCliente, lenClientes,
							listaPedidos[i].idCliente);
					printf("\nLa cantidad de kg a recolectar es: %.2f\n",
							listaPedidos[i].kilosTotalesPedido);
					retorno = 0;
				}
			} else {
				printf("\nNo se puede mostrar los pedidos\n");
			}
		}
	}
	return retorno;
}

int informarPedidosProcesados(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedido) {
	int i;
	int retorno;
	retorno = -1;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedido > 0) {
		for (i = 0; i < lenPedido; i++) {
			if (strcmp(listaPedidos[i].estadoPedido, "COMPLETADO") == 0
					&& listaPedidos[i].isEmpty == 1) {
				printf(
						"\n__________________________________________________________________________________________________________________________\n");
				printf(
						"ID\t  	ID Cliente\t      Estado\t  	 	KG totales\t    	Cantidad HDPE\t    		Cantidad LDPE\t     		Cantidad PP\t");
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
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int informarPendientesPorLocalidad(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades,
		int lenLocalidades) {
	int i;
	int idLocalidad;
	int retorno;
	retorno = -1;
	int cantidadPedidosPendientes;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedidos > 0) {
		if (utn_getNumero(&idLocalidad, "Ingrese el ID de la localidad",
				"Error, ingrese un ID válido", 1, 5, 2) == 0) {
			for (i = 0; i < lenClientes; i++) {
				if (listaCliente[i].isEmpty == 1
						&& listaCliente[i].idLocalidad == idLocalidad) {
					contarPedidosPendientes(listaPedidos, lenPedidos,
							listaCliente[i].idCliente,
							&cantidadPedidosPendientes);
				}
			}
			printf("\nPara la localidad con ID %d hay %d pedidos pendientes\n",
					idLocalidad, cantidadPedidosPendientes);
			retorno = 0;
		}
	}
	return retorno;
}

int informarPromedioPPxCliente(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos) {
	int cantidadPP;
	int cantidadClientes;
	int promedio;
	int retorno;
	retorno = -1;
	if (listaCliente != NULL && lenClientes > 0 && listaPedidos != NULL
			&& lenPedidos > 0) {
		contarPlasticoTipoPP(listaPedidos, lenPedidos, &cantidadPP);
		contarClientes(listaCliente, lenClientes, &cantidadClientes);
		promedio = cantidadPP / cantidadClientes;
		printf("\nEl promedio de polipropileno reciclado por cliente es %d\n",
				promedio);
		retorno = 0;
	}
	return retorno;
}

int informarClientesConMasPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos) {
	int i;
	int maximoCliente;
	int flag;
	flag = -1;
	int contadorPendientes = 0;
	int idClienteConMaximoPendientes;
	int retorno;
	retorno = -1;
	for (i = 0; i < lenClientes; i++) {
		if (listaCliente[i].isEmpty == 1) {
			contarPedidosPendientes(listaPedidos, lenPedidos,
					listaCliente[i].idCliente, &contadorPendientes);
			if (flag == -1 || contadorPendientes > maximoCliente) {
				flag = 0;
				maximoCliente = contadorPendientes;
				idClienteConMaximoPendientes = listaCliente[i].idCliente;
				retorno = 0;
			}

		}
	}
	printf("El cliente con más pedidos pendientes es el cliente con ID: %d",
			idClienteConMaximoPendientes);
	return retorno;
}

int informarClientesConMasCompletados(eClientes listaCliente[],
		int lenClientes, ePedido listaPedidos[], int lenPedidos) {
	int i;
	int maximoCliente;
	int flag;
	flag = -1;
	int contadorCompletados = 0;
	int idClienteConMaximoCompletados;
	int retorno;
	retorno = -1;
	for (i = 0; i < lenClientes; i++) {
		if (listaCliente[i].isEmpty == 1) {
			contarPedidosCompletados(listaPedidos, lenPedidos,
					listaCliente[i].idCliente, &contadorCompletados);
			if (flag == -1 || contadorCompletados > maximoCliente) {
				flag = 0;
				maximoCliente = contadorCompletados;
				idClienteConMaximoCompletados = listaCliente[i].idCliente;
				retorno = 0;
			}
		}
	}
	printf("El cliente con más pedidos completados es el cliente con ID: %d",
			idClienteConMaximoCompletados);
	return retorno;
}

int informarClientesConMasPedidos(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos) {
	int i;
	int maximoCliente;
	int flag;
	flag = -1;
	int contadorPedidos = 0;
	int idClienteConMasPedidos;
	int retorno;
	retorno = -1;
	for (i = 0; i < lenClientes; i++) {
		if (listaCliente[i].isEmpty == 1) {
			contarPedidos(listaPedidos, lenPedidos, listaCliente[i].idCliente,
					&contadorPedidos);
			if (flag == -1 || contadorPedidos > maximoCliente) {
				flag = 0;
				maximoCliente = contadorPedidos;
				idClienteConMasPedidos = listaCliente[i].idCliente;
				retorno = 0;
			}
		}
	}
	printf("El cliente con más pedidos es el cliente con ID: %d",
			idClienteConMasPedidos);
	return retorno;
}
