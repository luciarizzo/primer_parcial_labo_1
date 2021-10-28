/*
 * arrayClientes.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Lucía
 */

#ifndef ARRAYCLIENTES_H_
#define ARRAYCLIENTES_H_

typedef struct{
	int idCliente;
	char nombreCliente[100];
	char direccionCliente[100];
	int idLocalidad;
	char cuitCliente[20];
	int isEmpty;//si es 0, la estructura esta libre par anueva carga, si es 1 esta ocupada
}eClientes;

/**
 * \brief Iniciliza el array de clientes, asigna el campo isEmpty en 1 (ocupado)
 * \param lista[] array de clientes a ser inicialiado
 * \param len longitud del array
 * \return  devuelve -1 si no se pudo hacer o 0 si pudo
 */
int initCliente(eClientes lista[], int len);
/* \brief Busca la primer posicion libre, retorna el índice de esa posición libre
 * \param lista array de clientes
 * \param len longitud del array
 * \return devuelve -1 si no encontró un espacio libre o sino el índice de la posición donde lo encontró
 * */
int BuscarPrimerEspacioLibre(eClientes lista[], int len);
/*\brief Busca la posición del cliente que corresponda al ID ingresado
 * \param lista array de clientes
 * \param len longitud del array
 * \return devuelve -1 si no encontró el id o los isEmpty son 0, o la lista es NULL o el len es mayor a 0, sino devuelve el indice que corresponde
 */
int BuscarId(eClientes lista[], int len, int id);
/*
 * \brief Permite completar los campos de la estructura eClientes
 * \param listaClientes array de clientes
 * \param lenClientes longitud del array
 * \param id numero de id del cliente
 * \return retorna la estructura Cliente
 */
eClientes addCliente(eClientes listaClientes[], int lenClientes, int id);
/*
 * \brief Permite dar de alta un cliente buscando el primer espacio libre donde cargar los datos
 * \param listaClientes array de clientes
 * \param lenClientes longitud del array
 * \param id numero de id del cliente
 * \return retorna la posicion donde carga el cliente: por la fx buscarPrimerEspacioLibre puede devolver -1 si no puede encontrar uno.
 */
int altaCliente(eClientes listaClientes[], int lenClientes, int id);
/*
 * \brief Permite encontrar la posición del cliente por el ID
 * \param lista array de clientes
 * \param len longitud del array
 * \return retorna la posición donde encontró el id o -1 si no lo encontró.
 */
int findClienteById(eClientes lista[], int len);
/*
 * \brief Permite eliminar un cliente ingresando el ID
 * \param lista array de clientes
 * \param len longitud del array
 * \param idCliente id del cliente a eliminar
 * \return retorna 0 si lo pudo eliminar o -1 si no
 */
int removeCliente(eClientes lista[], int len, int idCliente);
/*
 * \brief Permite modificar la dirección de un cliente
 * \param lista array de clientes
 * \param len longitud del array
 * \param idCliente id del cliente a editar dirección
 * \return retorna 0 si lo pudo editar o -1 si no
 */
int modifiedDireccion(eClientes lista[], int len, int idCliente);
/*
 * \brief Permite modificar la localidad de un cliente
 * \param lista array de clientes
 * \param len longitud del array
 * \param idCliente id del cliente a editar localidad
 * \return retorna 0 si lo pudo editar o -1 si no
 */
int modifiedLocalidad(eClientes lista[], int len, int idCliente);
/*
 * \brief Permite imprimir un solo cliente
 * \param unCliente variable de tipo eClientes
 * \return retorna 0 si lo pudo editar o -1 si no
 */
void print1Cliente(eClientes unCliente);
/*
 * \brief Imprime la lista de clientes
 * \param lista array de clientes
 * \param len longitud del array
 * \return retorna 0 si lo pudo editar o -1 si no
 */
int printClientes(eClientes lista[], int len);
/*
 * \brief Imprime el cuit, la dirección y los kg de un cliente
 * \param lista array de clientes
 * \param len longitud del array
 * \param idCliente id del cliente a imprimir
 * \return retorna 0 si lo pudo imprimir o -1 si no
 */
int printCuitDireccionKgClientes(eClientes lista[], int len, int id);
/*
 * \brief Cuenta los clientes y guarda su valor en el puntero cantClientes
 * \param lista array de clientes
 * \param len longitud del array
 * \param cantClientes puntero hacia un entero que es donde se guarda la cantidad de clientes
 * \return retorna 0 si lo pudo imprimir o -1 si no
 */
int contarClientes(eClientes lista[], int len, int *cantClientes);

#endif /* ARRAYCLIENTES_H_ */
