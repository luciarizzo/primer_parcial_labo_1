/*
 ============================================================================
 Name        : primerParcial_Labo1.c
 Author      : Lucia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);

	mostrarMenu("\nIngrese un n�mero para elegir una opci�n: \n1-Dar alta cliente \n2-Modificar \n3-Dar de baja cliente \n4-Crear Pedido \n5-Procesar Residuos \n6-Imprimir clientes y cantidad de pedidos pendientes \n7-Imprimir pedidos pendientes \n8-Imprimir pedidos procesados \n9-Buscar pendientes por localidad \n10-Promedio de PP reciclado por cliente \n11-Informar clientes con m�s pedidos pendientes \n12-Informar clientes con m�s pedidos procesados \n13-Informar clientes con m�s pedidos \n14-Salir");
	return EXIT_SUCCESS;
}
