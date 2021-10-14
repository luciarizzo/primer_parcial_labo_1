/*
 * arrayPedidos.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef ARRAYPEDIDOS_H_
#define ARRAYPEDIDOS_H_

typedef struct{
	int idPedido;
	int idCliente;
	char estadoPedido[100];
	float kilosTotalesPedido;
	float cantidadHDPE;
	float cantidadLDPE;
	float cantidadPP;
	int isEmpty;//si es 1, la estructura esta libre par anueva carga, si es 0 esta ocupada
}ePedido;

int initPedido(ePedido lista[], int len);
int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int len);
//int BuscarId(ePedido lista[], int len, int idPedido);
ePedido addPedido(ePedido lista[], int len, int id);
int altaPedido(ePedido lista[], int len, int id);
int findPedidoById(ePedido lista[], int len);
ePedido addTiposPlasticos(ePedido lista[], int len);
int altaPlasticos(ePedido lista[], int len, int id);
void print1Pedido(ePedido pedido);
int printPedidos(ePedido lista[], int len);


#endif /* ARRAYPEDIDOS_H_ */
