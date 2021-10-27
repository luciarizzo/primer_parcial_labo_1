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
	int isEmpty;//si es 0, la estructura esta libre par anueva carga, si es 1 esta ocupada
}ePedido;

int initPedido(ePedido lista[], int len);
int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int len);
//int BuscarId(ePedido lista[], int len, int idPedido);
ePedido addPedido(ePedido lista[], int len, int idCliente, int* idPedido);
int altaPedido(ePedido lista[], int len, int idCliente, int* idPedido);
int findPedidoById(ePedido lista[], int len, int* idCliente);
ePedido addTiposPlasticos(ePedido lista[], int len, int idPedido);
int altaPlasticos(ePedido lista[], int len, int idPedido, int idCliente);
void print1Pedido(ePedido pedido);
int printPedidos(ePedido lista[], int len);
int contarPedidos(ePedido lista[], int len, int idCliente, int* cantPedidos);
int contarPedidosPendientes(ePedido lista[], int len, int idCliente, int* cantPendientes);
int contarPedidosCompletados(ePedido lista[], int len, int idCliente,
		int *cantCompletados);
int contarPlasticoTipoPP(ePedido lista[], int len, int *cantPP);
int findPedidosPorIdRetornarIndice(ePedido lista[], int len, int idPedido);

#endif /* ARRAYPEDIDOS_H_ */
