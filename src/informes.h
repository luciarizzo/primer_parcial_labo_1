/*
 * informes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef INFORMES_H_
#define INFORMES_H_

void printClientesConCantidadPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedido[], int lenPedido);
void informarPedidosPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
void informarPedidosProcesados(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
void informarPendientesPorLocalidad(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
void informarPromedioPPxCliente(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
void informarClientesConMasPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);
void informarClientesConMasCompletados(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);

#endif /* INFORMES_H_ */
