/*
 * menu.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Lucía
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayClientes.h"
#include "arrayPedidos.h"
#include "informes.h"
#define CANTCLIENTES 100
#define CANTPEDIDOS 1000

void mostrarMenu(char *mensaje) {
	eClientes arrayClientes[CANTCLIENTES] = { { 100, "LAVA", "Pineiro 358",
			"Lanus", "201234567", 1 }, { 101, "CODERS", "Manuel OCampo 1269",
			"Temperley", "245125470", 1 } };

	ePedido arrayPedidos[CANTPEDIDOS];

	int idPedido = CANTPEDIDOS;
	int idCliente = CANTCLIENTES;
	int idPedidoABuscar;
	int flagPrimerEjecucion;
	flagPrimerEjecucion = 0;
	int opcionMenu;
	int opcionSubMenuModificar;
	int idClienteParaPedido;
	int flagHuboCargaCliente = 1; // CAMBIAR A 0 SI NO HAY CLIENTES HARDCODEADOS(!!!!)
	int flagHuboCargaPedido = -1; // Se cambia a 0 cuando hubo carga de pedido.
	int flagPedidoCompleto = -1;
	initPedido(arrayPedidos, CANTPEDIDOS);

	if (mensaje != NULL) {
		do {
			if (flagPrimerEjecucion == 0) {
				printf("BIENVENIDO. POR FAVOR, ELIJA UNA OPCIÓN:");
				//initCliente(arrayClientes, CANTCLIENTES);
				flagPrimerEjecucion = 1;
			}
			if (utn_getNumero(&opcionMenu, mensaje,
					"\n La opción ingresada no está dentro del rango solicitado\n",
					1, 14, 3) == 0) {

				switch (opcionMenu) {

				case 1: //alta
					if (altaCliente(arrayClientes, CANTCLIENTES, idCliente)
							!= -1) {
						flagHuboCargaCliente++;
						idCliente++;
					}
					while (utn_getCaracterSiNoAgregar() == 0) {
						altaCliente(arrayClientes, CANTCLIENTES, idCliente);
						idCliente++;
					}
					fflush(stdin);
					break;

				case 2: //modificar
					if (flagHuboCargaCliente == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un empleado primero.\n");
					} else {
						//SUBMENU PARA MODIFICAR
						utn_getNumero(&opcionSubMenuModificar,
								"\nElija qué desea modificar: \n1: Dirección \n2: Localidad\n",
								"\n La opción ingresada no está dentro del rango solicitado\n",
								1, 2, 3);
						switch (opcionSubMenuModificar) {
						case 1:
							modifiedDireccion(arrayClientes, CANTCLIENTES);
							break;
						case 2:
							modifiedLocalidad(arrayClientes,
							CANTCLIENTES);
							break;
						}
					}
					break;

				case 3: //baja
					if (flagHuboCargaCliente == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else {
						removeCliente(arrayClientes, CANTCLIENTES);
					}
					break;

				case 4: //crear pedido
					//imprimirPorPantalla
					if (flagHuboCargaCliente == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else {
						if (printClientes(arrayClientes, CANTCLIENTES) == 0) {
							//buscarId
							idClienteParaPedido = findClienteById(arrayClientes,
							CANTCLIENTES);
							if (idClienteParaPedido != -1
									&& altaPedido(arrayPedidos, CANTPEDIDOS,
											idClienteParaPedido, &idPedido)
											!= -1) {
								flagHuboCargaPedido = 0;
							}
						}
					}
					break;

				case 5: //procesar residuos
					if (flagHuboCargaCliente == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else if (flagHuboCargaPedido == 0) {
						printPedidos(arrayPedidos, CANTPEDIDOS);
						//buscarId
						idPedidoABuscar = findPedidoById(arrayPedidos,
						CANTPEDIDOS);
						//ingresar kg de cada plastico y pasa a completado
						if (altaPlasticos(arrayPedidos, CANTPEDIDOS, idPedido)
								!= -1) {
							flagPedidoCompleto = 0;
							printf(
									"Se cargaron los kg de plasticos correctamente");
						} else {
							printf(
									"\nHubo un error en la carga de tipos de plasticos.\n");
						}
					} else {
						printf(
								"\nDebe cargar un pedido para ingresar a esta opción del menú\n");
					}
					break;

				case 6: // imprimir clientes
					if (flagHuboCargaPedido == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else {
						printClientesConCantidadPendientes(arrayClientes,
						CANTCLIENTES, arrayPedidos, CANTPEDIDOS);
					}
					break;

				case 7:
					//imprimir pedidos pendientes
					if (flagHuboCargaPedido == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un pedido primero.\n");
					} else {
						informarPedidosPendientes(arrayClientes, CANTCLIENTES,
								arrayPedidos, CANTPEDIDOS);
					}
					break;
				case 8:
					//imprimir pedidos procesados
					if (flagHuboCargaPedido == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un pedido primero.\n");
					} else {
						informarPedidosProcesados(arrayClientes, CANTCLIENTES,
								arrayPedidos, CANTPEDIDOS);
					}
					break;
				case 9:
					//buscar pendientes ingresando localidad
					if (flagHuboCargaPedido == -1) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un pedido primero.\n");
					} else {
						informarPendientesPorLocalidad(arrayClientes, CANTCLIENTES, arrayPedidos, CANTPEDIDOS);
					}
					break;
				case 10:
					//promedio
					break;
				case 11:
					//clientes con mas pedidos pendientes
					break;
				case 12:
					//clientes con mas pedidos completados
					break;
				case 13:
					//clientes con mas pedidos
					break;
				}
			} else {
				printf("\n Error, ingrese un número válido para el menú.\n");
			}

		} while (opcionMenu != 14);
	}
}
