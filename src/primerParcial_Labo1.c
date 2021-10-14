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

	mostrarMenu("\nIngrese un número para elegir una opción: \n1-Dar alta cliente \n2-Modificar \n3-Dar de baja empleado \n4-Crear Pedido \n5-Procesar Residuos \n6-Salir\n",
			6);
	return EXIT_SUCCESS;
}
