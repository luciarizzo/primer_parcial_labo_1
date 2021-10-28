/*
 * informes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/*
 * \brief imprime los clientes junto con su cantidad de pedidos pendientes
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return void
 */
void printClientesConCantidadPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedido[], int lenPedido);
/*
 * \brief informa los pedidos pendientes
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarPedidosPendientes(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
/*
 * \brief informa los pedidos procesados
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarPedidosProcesados(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedido);
/*
 * \brief informa los pedidos pendientes por localidad
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarPendientesPorLocalidad(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
/*
 * \brief informa el promedio de pedidos pendientes por cliente
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarPromedioPPxCliente(eClientes listaCliente[], int lenClientes, ePedido listaPedidos[], int lenPedidos);
/*
 * \brief informa los clientes con más pedidos pendientes
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarClientesConMasPendientes(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);
/*
 * \brief informa los clientes con más pedidos completados
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarClientesConMasCompletados(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);
/*
 * \brief informa los clientes con más pedidos
 * \param listaCliente array de clientes
 * \param lenClientes longitud del array Clientes
 * \param listaPedido array de pedidos
 * \param lenPedido longitud del array Pedido
 * \return retorna 0 si pudo informar o -1 sino
 */
int informarClientesConMasPedidos(eClientes listaCliente[], int lenClientes,
		ePedido listaPedidos[], int lenPedidos);

#endif /* INFORMES_H_ */
