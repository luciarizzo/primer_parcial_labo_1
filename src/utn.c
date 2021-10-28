/*
 * utn.c
 *
 *  Created on: 2 sep. 2021
 *      Author: Lucía
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/* Funcion usada para verificar el ingreso de caracteres. Chequea para que
 solo sean admitidas las letras S o N.
 Se ingresa void y devuelve un entero sin signo
 0 si se ingreso la N
 1 si se ingreso la S
 */
unsigned int verifica(void) {
	char letra;
	printf("\nIngrese opcion...S/N?");
	letra = toupper(getchar());
	while (!((letra == 'S') || (letra == 'N'))) {
		printf(
				"\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
		letra = toupper(getchar());
	}
	return (letra == 'S');
}
/*
 *
 * */
void getChar(char *mensaje, char *rta) {
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", rta);
}
/*
 * brief FACTORIAL
 * param n*: numero entero del que se quiere calcular el factorial
 * return: retorna el factorial del número, o 1 si el param n* era 1
 * */
int factorial(int *n) {
	int resp;
	if (*n == 1)
		return 1;
	resp = *n * factorial(n - 1);
	return (resp);
}

/**
 * \brief MYGETS: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud) {
	int retorno;
	retorno = -1;

	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief ESNUMERICA: Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[0] == '+' || cadena[0] == '-') {
				i++;
				continue; //// vuelve a la linea 85
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int esFlotante(char *cadena, int longitud) {
	int retorno = 1;
	int i;
	int contadorPunto = 0;
	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; i < longitud && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPunto == 0) {
					contadorPunto++;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int esNombre(char *cadena, int longitud) {
	int retorno = 1;

	if (cadena != NULL && longitud > 0) {
		for (int i = 0; i <= longitud && cadena[i] != '\0'; i++) {
			if ((cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] < 'a' || cadena[i] > 'z')
					&& cadena[i] != '.') {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esSoloLetra(char *pResultado) {
	int retorno = 1;
	int i;

	if (pResultado != NULL && strlen(pResultado) > 0) {
		for (i = 0; i < strlen(pResultado); i++) {
			if (isalpha(pResultado[i]) == 0) {
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}
	return retorno;
}

int esLetraConEspacio(char *pResultado) {
	int retorno = 1;
	int i;

	if (pResultado != NULL && strlen(pResultado) > 0) {
		for (i = 0; i < strlen(pResultado); i++) {
			if (isalpha(pResultado[i]) == 0) {
				if (isspace(pResultado[i]) == 0) {
					retorno = 0;
					break;
				}
			}
		}
	} else {
		retorno = 0;
	}
	return retorno;
}

int esTelefonoValido(char *cadena) {
	int retorno = 1;
	int i;
	for (i = 0; cadena[i] != '\0'; i++) {
		if ((cadena[i] < '0' || cadena[i] > '9')
				&& (cadena[i] != '-' || cadena[i] != ' ')) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/**
 * \brief GETINT: Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[5000];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer) == 1) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esFlotante(buffer, sizeof(buffer)) == 1) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
int getNombre(char *pResultado, int longitud) {
	int retorno = -1;
	char buffer[5000];
	if (pResultado != NULL && longitud > 0) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer, sizeof(buffer)) != 0
				&& strnlen(buffer, sizeof(buffer)) <= longitud) {
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief UTN_GETNUMERO: Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInterno;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos > 0) {

		do {
			printf("%s", mensaje);
			if (getInt(&bufferInterno) == 0 && bufferInterno >= minimo
					&& bufferInterno <= maximo) {
				*pResultado = bufferInterno;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);

	}
	return retorno;
}

/*############################################################################################
 * ###############################TEMPERATURAS#######################################*/
/*############################################################################################*/

/*valido fahrenheit */
int validarTemperaturaF(void) {
	int temperaturaF;
	int retorno = -1;
	if (utn_getNumero(&temperaturaF,
			"Ingrese una temperatura Fahrenheit entre 32F y 212F\n",
			"Error, temperatura fuera de rango. Reintente.\n", 32, 212, 2)
			== 0) {
		/*conversion a celsius*/
		printf("Se puede convertir a celsius");
		convertirTemperaturaFaC(&temperaturaF);
		retorno = 0;
	}
	return retorno;

}
/*
 * valido celsius
 * */
int validarTemperaturaC(void) {
	int temperaturaC;
	int retorno = -1;
	if (utn_getNumero(&temperaturaC,
			"Ingrese una temperatura Celsius entre 0C y 100C\n",
			"Error, temperatura fuera de rango. Reintente.\n", 0, 100, 2)
			== 0) {
		/*conversion a celsius*/
		printf("Se puede convertir a Fahrenheit");
		convertirTemperaturaCaF(&temperaturaC);
		retorno = 0;
	}
	return retorno;

}
/*
 * fn chequear si es celsius o fahrenheit
 *
 */
int validarEscalaTemperatura(void) {
	int retorno = -1;
	char respuesta;
	getChar("Ingrese la escala de temperatura 'f' (fahrenheit) o 'c' (celsius)",
			&respuesta);
	fflush(stdin);
	if (respuesta == 'f' || respuesta == 'c') {
		retorno = 0;
		if (respuesta == 'f') {
			printf("La temperatura elegida es Fahrenheit.");
			validarTemperaturaF();
		} else {
			printf("La temperatura elegida es Celsius.");
			validarTemperaturaC();
		}
	}
	return retorno;
}

/*
 * conversion a celsius
 *
 */
int convertirTemperaturaFaC(int *temperaturaF) {
	int resta;
	int multiplicacion;
	resta = *temperaturaF - 32;
	multiplicacion = resta * 5 / 9;
	printf("La temperatura fue convertida a Celsius: %d C", multiplicacion);
	return 0;
}
/*
 * conversion a fahrenheit
 *
 */
int convertirTemperaturaCaF(int *temperaturaC) {
	int suma;
	int multiplicacion;
	multiplicacion = *temperaturaC * 9 / 5;
	suma = multiplicacion + 32;
	printf("La temperatura fue convertida a Fahrenheit: %d F", suma);
	return 0;
}

/*############################################################################################
 *###########################		ARRAYS  CARGA SECUENCIAL   ###############################*/
/*############################################################################################*/

void cargarArray(int array[], int tamanio) {
	int i;
	int numeroIngresado;
	for (i = 0; i < tamanio; i++) {
		utn_getNumero(&numeroIngresado,
				"\nIngrese los elementos del array. Deberán ser 10 números enteros entre -1000 y 1000.\n",
				"\nError. No es entre -1000 y 1000.\n ", -1000, 1000, 2);
		array[i] = numeroIngresado;
	}
}

int buscarMaximo(int array[], int tamanio) {
	int i;
	int maximo;
	for (i = 0; i < tamanio; i++) {
		if (i == 0 || array[i] > maximo) {
			maximo = array[i];
		}
	}
	return maximo;
}

void mostrarArray(int array[], int tamanio) {
	int i;
	for (i = 0; i < tamanio; i++) {
		if (i == 0) {
			printf("Los elementos del array son: %d", array[i]);
		} else
			printf(",%d", array[i]);
	}
}

void mostrarIndiceMaximo(int array[], int tamanio, int maximo) {
	int i;
	for (i = 0; i < tamanio; i++) {
		if (array[i] == maximo) {
			printf("\nIndice del elemento de máximo valor del array: %d\n", i);
		}
	}
}

void contadorNumerosPositivosNegativos(int array[], int tamanio) {
	int i;
	int negativo = 0;
	int positivo = 0;
	for (i = 0; i < tamanio; i++) {
		if (array[i] > 0) {
			positivo++;
		} else {
			negativo++;
		}
	}
	if (negativo == 0) {
		printf("No hay números negativos ingresados");
	}
	if (positivo == 0) {
		printf("No hay números positivos ingresados.");
	}

	printf(
			"\nLa cantidad de POSITIVOS es: %d \n La cantidad de NEGATIVOS es: %d\n",
			positivo, negativo);
}

void contadorPares(int *pPares, int array[], int tamanio) {
	int i;
	int pares = 0;
	for (i = 0; i < tamanio; i++) {
		if (array[i] % 2 == 0) {
			printf("\n%d es par\n", array[i]);
			pares++;
		} else {
			printf("No hay números pares");
		}
		*pPares = pares;
	}
}

void contadorImpares(int *pImpares, int array[], int tamanio) {
	int i;
	int impares = 0;
	int busquedaMaximo;
	for (i = 0; i < tamanio; i++) {
		if (array[i] % 2 == 1) {
			printf("\n%d es impar", array[i]);
			impares++;
			*pImpares = impares;
		} else {
			printf("No hay números impares.");
		}
	}
	if (impares != 0) {
		busquedaMaximo = buscarMaximo(array, tamanio);
		printf("El numero máximo de los impares es: %d\n", busquedaMaximo);
	}
}

void mostrarContenidoPosicionesImpares(int array[], int tamanio) {
	int i = 0;
	int flag = -1;
	for (i = 0; i < tamanio; i++) {
		if (i % 2 == 1) {
			printf("El contenido de esta posición impar %d es %d\n", i,
					array[i]);
			flag = 0;
		}
	}
	if (flag == -1) {
		printf("No hay posiciones impares.");
	}
}

void sumarNumerosPares(int *pSumaPares, int array[], int tamanio) {
	int i;
	int pares = 0;
	for (i = 0; i < tamanio; i++) {
		if (array[i] % 2 == 0) {
			pares = array[i] + pares;
		}

		*pSumaPares = pares;
	}
	if (pares == 0) {
		printf("No hay números pares para sumar.");
	}
}

void ordenarDescendente(int array[], int tamanio) {
	int j;
	int aux;
	int flagNoEstaOrdenado = 1;
	while (flagNoEstaOrdenado == 1) {
		flagNoEstaOrdenado = 0;
		for (j = 1; j < tamanio; j++) {
			if (array[j] < array[j - 1]) {
				aux = array[j];
				array[j] = array[j - 1];
				array[j - 1] = aux;
				flagNoEstaOrdenado = 1;
			}
		}
	}
}

void ordenarAscendente(int array[], int tamanio) {
	int j;
	int aux;
	int flagNoEstaOrdenado = 1;
	while (flagNoEstaOrdenado == 1) {
		flagNoEstaOrdenado = 0;
		for (j = 1; j < tamanio; j++) {
			if (array[j] > array[j - 1]) {
				aux = array[j];
				array[j] = array[j - 1];
				array[j - 1] = aux;
				flagNoEstaOrdenado = 1;
			}
		}
	}
}

//no es un modelo de datos.
void cargarArrayParalelo(int arrayUno[], int arrayDos[], int arrayTres[],
		int tamanio) {
	int i;
	int numeroIngresadoUno;
	int numeroIngresadoDos;

	for (i = 0; i < tamanio; i++) {
		utn_getNumero(&numeroIngresadoUno,
				"\nIngrese el número para el primer Array:",
				"Error, reingrese el número", -1000, 1000, 2);

		arrayUno[i] = numeroIngresadoUno;

		utn_getNumero(&numeroIngresadoDos,
				"\nIngrese el número para el segundo Array:",
				"Error, reingrese el número", -1000, 1000, 2);

		arrayDos[i] = numeroIngresadoDos;

		if (arrayUno[i] > arrayDos[i]) {
			arrayTres[i] = arrayUno[i];
		} else {
			arrayTres[i] = arrayDos[i];
		}
	}

}

void ordenarVectores(int arrayUno[], int arrayDos[], int arrayTres[],
		int tamanio) {
	int i;
	int j;
	int auxiliarArray;

	for (i = 0; i < tamanio - 1; i++) {
		for (j = i + 1; j < tamanio; j++) {
			if (arrayTres[i] > arrayTres[j]) {
				auxiliarArray = arrayTres[i];
				arrayTres[i] = arrayTres[j];
				arrayTres[j] = auxiliarArray;

				auxiliarArray = arrayUno[i];
				arrayUno[i] = arrayUno[j];
				arrayUno[j] = auxiliarArray;

				auxiliarArray = arrayDos[i];
				arrayDos[i] = arrayDos[j];
				arrayDos[j] = auxiliarArray;
			}
		}
	}
}

void mostrarVectores(int arrayUno[], int arrayDos[], int arrayTres[],
		int tamanio) {
	int i;

	printf("\nArray A, B y C:");

	for (i = 0; i < tamanio; i++) {
		printf("\n%d\t%d\t%d", arrayUno[i], arrayDos[i], arrayTres[i]);
	}
}

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	int retorno = -1;
	float bufferInterno;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos > 0) {
		do {
			printf("%s", mensaje);
			if (getFloat(&bufferInterno) == 0 && bufferInterno >= minimo
					&& bufferInterno <= maximo) {
				*pResultado = bufferInterno;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos) {
	int retorno = -1;
	char bufferChar[40];

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferChar);

			if (strlen(bufferChar) < 20) {
				strcpy(pResultado, bufferChar);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracterSexo(char *pResultado, char *mensaje, char *mensajeError,
		char string[][20], int cantidadArray, int reintentos) {
	int retorno = -1;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", &bufferChar);
			if (bufferChar == 'f' || bufferChar == 'm' || bufferChar == 'o') {
				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
int utn_getCaracterSiNo(void) {
	int retorno = -1;
	char c;

	getChar("\nIngrese Si 's' o No 'n'", &c);
	fflush(stdin);

	while (c != 's' && c != 'n') {
		puts("ERROR. OPCION NO VALIDA");
		getChar("Ingrese Si 's' o No 'n'", &c);
		fflush(stdin);

	}
	if (c == 's') {
		retorno = 0;
	}
	return retorno;
}

int utn_getCaracterSiNoAgregar(void) {
	int retorno = -1;
	char c;

	getChar("\n¿Quiere agregar otro? Ingrese Si 's' o No 'n'", &c);
	fflush(stdin);

	while (c != 's' && c != 'n') {
		puts("ERROR. OPCION NO VALIDA");
		getChar("Ingrese Si 's' o No 'n'", &c);
		fflush(stdin);

	}
	if (c == 's') {
		retorno = 0;
	}
	return retorno;
}
int utn_getString(char aux[], char *mensaje, char *mensajeError, int reintentos) {
	int retorno = -1;
	char bufferString[40];

	if (aux != NULL && mensaje != NULL && mensajeError != NULL
			&& reintentos > 0) {
		do {
			printf("%s", mensaje);
			if (myGets(bufferString, 40) == 0) {
				strcpy(aux, bufferString);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos, int longitud) {
	char bufferString[1000];
	int retorno = -1;

	if (mensaje != NULL && mensajeError != NULL && pResultado != NULL
			&& reintentos >= 0 && longitud > 0) {
		do {
			printf("%s", mensaje);
			if (getNombre(bufferString, 1000) == 0) {
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getTelefono(char *pResultado, char *mensaje, char *mensajeError,
		int minSize, int maxSize, int min, int max, int reintentos) {
	int retorno = -1;
	char bufferStr[50];

	if (mensaje != NULL && mensajeError != NULL
			&& minSize
					< maxSize&& min<max && reintentos>=0 && pResultado!=NULL) {
		do {
			printf("%s", mensaje);
			if (myGets(bufferStr, 50) == 0
					&& esTelefonoValido(bufferStr) == 1) {
				strcpy(pResultado, bufferStr);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}
/*
 int esCUIT(char *cadena) // es lo que hay
 {
 int retorno = 1;
 int i;
 char buffer[14];
 int contadorDigito;
 int contadorGuion;
 strncpy(buffer, cadena, 14);

 for (i = 0; buffer[i] != '\0'; i++) {
 if ((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '-')) {
 retorno = 0;
 break;
 } else {
 if (isdigit(cadena[i]) != 0) {
 contadorDigito++;
 } else {
 if (cadena[i] == '-') {
 contadorGuion++;
 } else {
 retorno = 0;
 break;
 }
 }
 }
 }
 if (contadorDigito == 11 && contadorGuion == 2 && buffer[2] == '-'
 && buffer[11] == '-') {
 retorno = 1;
 }
 return retorno;
 }*/

int esCUIT(char *cadena) {
	int i;
	int retorno;
	i = 0;
	retorno = 0;

	if (cadena != NULL && strlen(cadena) == 13) {
		while (cadena[i] != '\0') {
			if ((cadena[i] < '0' || cadena[i] > '9')) {
				if ((i == 2 || i == 11) && cadena[i] == '-') {
					i++;
					continue;
				}
				return retorno;
			}
			i++;
		}
		if (i == strlen(cadena)) {
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getCUIT(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {
	int maxTamanio = 14; //con guiones 13 elementos
	int minTamanio = 11;  // sin puntos
	int retorno = -1;
	char bufferStr[maxTamanio];
	if (mensaje != NULL && mensajeError != NULL
			&& maxTamanio > minTamanio&& reintentos>=0 && pResultado!=NULL) {
		do {
			printf("%s", mensaje);
			if ((myGets(bufferStr, 14) == 0) && (esCUIT(bufferStr) == 1)) {
				strncpy(pResultado, bufferStr, maxTamanio);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

int esDNI(char *cadena) // es lo que hay
{
	int retorno = 1;
	int i;
	char buffer[10];
	int contadorDigito;
	int contadorPunto;
	strncpy(buffer, cadena, 14);

	for (i = 0; buffer[i] != '\0'; i++) {
		if ((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '.')) {
			retorno = 0;
			break;
		} else {
			if (isdigit(cadena[i]) != 0) {
				contadorDigito++;
			} else {
				if (cadena[i] == '.') {
					contadorPunto++;
				} else {
					retorno = 0;
					break;
				}
			}
		}
	}
	if (contadorDigito == 8 && contadorPunto == 2 && buffer[2] == '.'
			&& buffer[6] == '.') {
		retorno = 1;
	}
	return retorno;
}

int utn_getDNI(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {
	int maxTamanio = 10; //con puntos 10 elementos
	int minTamanio = 8;  // sin puntos
	int retorno = -1;
	char bufferStr[maxTamanio];
	if (mensaje != NULL && mensajeError != NULL
			&& maxTamanio > minTamanio&& reintentos>=0 && pResultado!=NULL) {
		do {
			printf("%s", mensaje);
			if ((myGets(bufferStr, 10) == 0) && (esDNI(bufferStr) == 1)) {
				strncpy(pResultado, bufferStr, maxTamanio);
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

/*
 utn_getNumero
 utn_getNumeroConSigno
 utn_getNumeroConDecimales
 utn_getTelefono
 utn_getDNI ---> falta
 utn_getCUIT
 utn_getEmail --> falta
 utn_getTexto --> falta
 */
