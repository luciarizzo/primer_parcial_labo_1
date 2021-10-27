/*
 * informes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef INFORMES_H_
#define INFORMES_H_

void printClientesConCantidadPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedido[], int lenPedido);
int informarPedidosPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
int informarPedidosProcesados(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
int informarPendientesPorLocalidad(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
int informarPromedioPPxCliente(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
int informarClientesConMasPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);
int informarClientesConMasCompletados(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);
int informarClientesConMasPedidos(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);

#endif /* INFORMES_H_ */
