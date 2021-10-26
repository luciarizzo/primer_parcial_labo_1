/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: Lucía
 */

#ifndef UTN_H_
#define UTN_H_

/* Funcion usada para verificar el ingreso de caracteres.Chequea para que
 solo sean admitidas las letras S o N.
 Se ingresa void y devuelve un entero sin signo
 0 si se ingreso la N
 1 si se ingreso la S
 */
unsigned int verifica(void);

/*
 * brief FACTORIAL
 * param n*: numero entero del que se quiere calcular el factorial
 * return: retorna el factorial del número, o 1 si el param n* era 1
 * */
int factorial(int *n);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
//int esNumerica(char *cadena);
int esNumerica(char* cadena);

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);


void getChar(char* mensaje, char* rta);

int getFloat(float* pResultado);

int getNombre(char* pResultado, int longitud);

int validarTemperaturaF(void);

int validarTemperaturaC(void);

int validarEscalaTemperatura(void);

int convertirTemperaturaFaC(int* temperaturaF);

int convertirTemperaturaCaF(int* temperaturaC);


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */

//void cargarArray(int array[], int tamanio);


int buscarMaximo(int array[], int tamanio);

void cargarArray(int array[], int tamanio);

void mostrarArray(int array[], int tamanio);

void mostrarIndiceMaximo(int array[], int tamanio, int maximo);

/*void contadorNumeros(int *contadorPositivos, int *contadorNegativos,
		int array[], int tamanio);*/

void contadorNumerosPositivosNegativos(int array[], int tamanio);

void contadorPares(int *pPares, int array[], int tamanio);

void contadorImpares(int *pImpares, int array[], int tamanio);

void mostrarContenidoPosicionesImpares(int array[], int tamanio);

void sumarNumerosPares(int *pSumaPares, int array[], int tamanio);

void ordenarDescendente(int array[], int tamanio);

void ordenarAscendente(int array[], int tamanio);

void cargarArrayParalelo(int arrayUno[], int arrayDos[], int arrayTres[], int tamanio);

void ordenarVectores(int arrayUno[],int arrayDos[],int arrayTres[],int tamanio);

void mostrarVectores(int arrayUno[],int arrayDos[],int arrayTres[],int tamanio);

int esTelefonoValido(char* cadena);

int esFlotante(char* cadena, int longitud);

int esNombre(char* cadena,int longitud);

int esSoloLetra(char *pResultado);

int esLetraConEspacio(char *pResultado);

int utn_getCUIT(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);

int esCUIT(char *cadena);

int utn_getTelefono(char *pResultado, char *mensaje, char *mensajeError,
		int minSize, int maxSize, int min, int max, int reintentos);

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos, int longitud);

int utn_getString(char aux[], char *mensaje, char *mensajeError, int reintentos);

int utn_getCaracterSexo(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos);

int utn_getCaracterSiNo(void);

int utn_getCaracterSiNoAgregar(void);

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos);

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos, int longitud);

int esDNI(char *cadena);

int utn_getDNI(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos);

#endif /* UTN_H_ */
