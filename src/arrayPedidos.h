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
/**
 * \brief Iniciliza el array de pedidos, asigna el campo isEmpty en 1 (ocupado)
 * \param lista[] array de pedidos a ser inicialiado
 * \param len longitud del array
 * \return  devuelve -1 si no se pudo hacer o 0 si pudo
 */
int initPedido(ePedido lista[], int len);
/* \brief Busca la primer posicion libre, retorna el índice de esa posición libre
 * \param lista array de pedidos
 * \param len longitud del array
 * \return devuelve -1 si no encontró un espacio libre o sino el índice de la posición donde lo encontró
*/
int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int len);
/*
 * \brief Permite completar los campos de la estructura eClientes
 * \param listaPedidos array de pedidos
 * \param len longitud del array
 * \param idCliente numero de id del cliente
 * \param idPedido puntero hacia un entero que es donde se guarda el idPedido
 * \return retorna la estructura ePedido
 */
ePedido addPedido(ePedido lista[], int len, int idCliente, int* idPedido);
/*
 * \brief Permite dar de alta un pedido buscando el primer espacio libre donde cargar los datos
 * \param lista array de pedidos
 * \param len longitud del array
 * \param idCliente numero de id del cliente
 * \param idPedido puntero hacia un entero que es donde se guarda el idPedido
 * \return retorna la posicion donde carga el pedido: por la fx buscarPrimerEspacioLibre puede devolver -1 si no puede encontrar uno.
 */
int altaPedido(ePedido lista[], int len, int idCliente, int* idPedido);
/*
 * \brief Permite encontrar la posición del pedido por el ID
 * \param lista array de pedidos
 * \param len longitud del array
 * \param idCliente numero de id del cliente
 * \return retorna la posición donde encontró el id o -1 si no lo encontró.
 */
int findPedidoById(ePedido lista[], int len, int* idCliente);
/*
 * \brief Permite completar los campos de los tipos de plasticos
 * \param listaPedidos array de pedidos
 * \param len longitud del array
 * \param idPedido numero de id del pedido
 * \return retorna la estructura ePedido
 */
ePedido addTiposPlasticos(ePedido lista[], int len, int idPedido);
/*
 * \brief Permite dar de alta de un tipo de plastico buscando el primer espacio libre donde cargar los datos
 * \param lista array de pedidos
 * \param len longitud del array
 * \param idCliente numero de id del cliente
 * \param idPedido puntero hacia un entero que es donde se guarda el idPedido
 * \return retorna la posicion donde carga el pedido: por la fx buscarPrimerEspacioLibre puede devolver -1 si no puede encontrar uno.
 */
int altaPlasticos(ePedido lista[], int len, int idPedido, int idCliente);
/*
 * \brief Permite imprimir un solo cliente
 * \param pedido variable de tipo eClientes
 * \return retorna 0 si lo pudo imprimir o -1 si no
 */
void print1Pedido(ePedido pedido);
/*
 * \brief Imprime la lista de pedidos
 * \param lista array de pedidos
 * \param len longitud del array
 * \return retorna 0 si lo pudo imprimir o -1 si no
 */
int printPedidos(ePedido lista[], int len);
/*
 * \brief Cuenta los pedidos y guarda su valor en el puntero cantPedidos
 * \param lista array de pedidos
 * \param len longitud del array
 * \param cantPedios puntero hacia un entero que es donde se guarda la cantidad de pedidos
 * \return retorna 0 si lo pudo contar o -1 si no
 */
int contarPedidos(ePedido lista[], int len, int idCliente, int* cantPedidos);
/*
 * \brief Cuenta los pedidos pedientes y guarda su valor en el puntero cantPendientes
 * \param lista array de pedidos
 * \param len longitud del array
 * \param cantPedios puntero hacia un entero que es donde se guarda la cantidad de pedidos
 * \return retorna 0 si lo pudo contar o -1 si no
 */
int contarPedidosPendientes(ePedido lista[], int len, int idCliente, int* cantPendientes);
/*
 * \brief Cuenta los pedidos completados y guarda su valor en el puntero cantCompletados
 * \param lista array de pedidos
 * \param len longitud del array
 * \param cantPedios puntero hacia un entero que es donde se guarda la cantidad de pedidos
 * \return retorna 0 si lo pudo contar o -1 si no
 */
int contarPedidosCompletados(ePedido lista[], int len, int idCliente,
		int *cantCompletados);
/*
 * \brief Cuenta los pedidos completados y guarda su valor en el puntero en cantPP
 * \param lista array de pedidos
 * \param len longitud del array
 * \param cantPP puntero hacia un entero que es donde se guarda la cantidad de plastico tipo PP
 * \return retorna 0 si lo pudo contar o -1 si no
 */
int contarPlasticoTipoPP(ePedido lista[], int len, int *cantPP);
/*
 * \brief Encuentra los pedidos por Id y retorna el índice correspondiente
 * \param lista array de pedidos
 * \param len longitud del array
 * \param idPedido numero de id del pedido
 * \return retorna 0 si lo pudo encontrar o -1 si no
 */
int findPedidosPorIdRetornarIndice(ePedido lista[], int len, int idPedido);

#endif /* ARRAYPEDIDOS_H_ */
