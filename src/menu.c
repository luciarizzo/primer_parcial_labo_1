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

void mostrarMenu(char *mensaje, int opcionSalir) {
	eClientes arrayClientes[CANTCLIENTES];
	ePedido arrayPedidos[CANTPEDIDOS];
	int idPedido = CANTPEDIDOS;
	int idCliente = CANTCLIENTES;
	int idPedidoABuscar;
	int flagPrimerEjecucion;
	flagPrimerEjecucion = 0;
	int opcionMenu;
	int opcionSubMenuModificar;
	int idClienteParaPedido;
	int flagHuboCargaCliente = 0;
	int flagHuboCargaPedido = 0;
	int flagPedidoCompleto = 0;
	if (mensaje != NULL) {
		do {
			if (flagPrimerEjecucion == 0) {
				printf("BIENVENIDO. POR FAVOR, ELIJA UNA OPCIÓN:");
				initCliente(arrayClientes, CANTCLIENTES);
				flagPrimerEjecucion = 1;
			}
			if (utn_getNumero(&opcionMenu, mensaje,
					"\n La opción ingresada no está dentro del rango solicitado\n",
					1, opcionSalir, 3) == 0) {
				switch (opcionMenu) {
				case 1: //alta
					if (altaCliente(arrayClientes, CANTCLIENTES, idCliente)
							!= -1) {
						flagHuboCargaCliente++;
						idCliente++;
					}
					while (utn_getCaracterSiNo() == 0) {
						altaCliente(arrayClientes, CANTCLIENTES, idCliente);
						idCliente++;
					}
					fflush(stdin);
					break;
				case 2: //modificar
					if (flagHuboCargaCliente == 0) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un empleado primero.\n");
					} else {
						utn_getNumero(&opcionSubMenuModificar,
								"\nElija qué desea modificar: \n2.1: Dirección \n2.2 Localidad\n",
								"\n La opción ingresada no está dentro del rango solicitado\n",
								1, opcionSalir, 3);
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
					if (flagHuboCargaCliente == 0) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else {
						removeCliente(arrayClientes, CANTCLIENTES);
					}
					break;
				case 4: //crear pedido

					//imprimirPorPantalla
					printClientes(arrayClientes, CANTCLIENTES);

					//buscarId
					idClienteParaPedido = findClienteById(arrayClientes,
							CANTCLIENTES);
					//

					initPedido(arrayPedidos, CANTPEDIDOS);
					if(altaPedido(arrayPedidos, CANTPEDIDOS, idClienteParaPedido) != -1)
					{
						flagHuboCargaPedido++;
						idPedido++;
						printf("\n El nuevo ID de pedido para el cliente con ID %d es: %d.\n",
						idClienteParaPedido, idPedido);
					}

					break;
				case 5: //procesar residuos
					if(flagHuboCargaPedido > 0){
						printPedidos(arrayPedidos, CANTPEDIDOS);
						//buscarId
						idPedidoABuscar = findPedidoById(arrayPedidos, CANTPEDIDOS);
						//ingresar kg de cada plastico y pasa a completado
						if (altaPlasticos(arrayPedidos, CANTPEDIDOS, idPedidoABuscar)
								!= -1) {
							flagPedidoCompleto++;
						} else {
							printf("\nHubo un error en la carga.\n");
						}
					} else {
						printf("\nDebe cargar un pedido para ingresar a esta opción del menú\n");
					}


					//pasar a completado.

					break;
				case 6:
					if (flagHuboCargaCliente == 0) {
						printf(
								"\nError. Para ingresar a esta opción debe cargar un cliente primero.\n");
					} else {
						printClientes(arrayClientes, CANTCLIENTES);
					}
					break;
				}
			} else {
				printf("\n Error, ingrese un número válido para el menú.\n");
			}

		} while (opcionMenu != opcionSalir);
	}

}
