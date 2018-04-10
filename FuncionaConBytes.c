/*
	PROYECTO 1 FUNDAMENTOS DE INFRAESTRUCTURA TECNOL�GICA
	Nombre Estudiante 1 - Codigo Estudiante 1
	Nombre Estudiante 2 - Codigo Estudiante 2
	Juliana Prieto Arcila - 201714463
*/

#include "stdio.h"
#include "stdlib.h"
// Se incluye esta librería para manipular strings.
#include <string.h>

void escribir(unsigned char *V, unsigned char *s, int p);
void leer(unsigned char *V, unsigned char *s, int p, int l);

int main(int argc, char *argv[]) {
	// Variables
	int op;
	int l, p;
	unsigned char *V;
	unsigned char *s;

	// Inicialización
	V = (unsigned char *)calloc(100, sizeof(char));

	/*PRECAUCIÓN II: El vector puede que no esté inicializado en su totalidad
 * con 0's por lo que se procederá a rellenarlo hasta la posición 799 (para
 * evitar futuros inconvenientes)*/
	int r;
	for (r = 0; r < 799; r++) {
		*(V + r) = '0';
	}

	s = (unsigned char *)calloc(17, sizeof(char));

	// Mensaje inicial
	printf("PROYECTO 1 - INFRATEC");

	// Loop hasta terminar
	op = 3;
	while (op != 0) {
		// Se pregunta al usuario cual opcion desea realizar
		printf(
			"\n\n* Indique la modalidad\n\t0: Terminar\n\t1: Escribir\n\t2: "
			"Leer\n\n");
		printf("Modalidad: ");
		scanf("%d", &op);

		// Escribir
		if (op == 1) {
			printf("Acción %d: Escribir\n\n", op);

			// Se reciben los valores de s y p
			printf("Escriba s: ");
			scanf("%s", s);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se escribe s desde el byte p de V
			escribir(V, s, p);
		}
		// Leer
		else if (op == 2) {
			printf("Acción %d: Leer\n\n", op);

			// Se reciben los valores de l y p
			printf("Escriba l: ");
			scanf("%d", &l);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se leen l byte de V desde la posición p y se escriben como chars
			// en s
			leer(V, s, p, l);

		}
		// Invalido
		else if (op != 0) {
			printf("Opción invalida.\n");
		}
	}

	// Terminar
	printf("\nPrograma terminado.\n");
	return 0;
}

/*
	Procedimiento que escribe s empezando en el byte p de V
*/
void escribir(unsigned char *V, unsigned char *s, int p) {
	// TODO: DESARROLLAR COMPLETAMENTE ESTE PROCEDIMIENTO

	/* PRECAUCIÓN: posiciones incorrectas.
	La posición excede la capacidad del arreglo. */
	if (p > 799) {
		printf(
			"\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
		return;
	}
	/*La posición es inválida */
	if (p < 0) {
		printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
		return;
	}

	/*RESTRICCIÓN 1:
	La cadena no puede ser mayor a 16 bytes.
	Como char tiene solo 1 byte se asume que si la longitud es mayor a 16, es
	mayor a 2 bytes. */

	if (strlen(s) > 16) {
		printf(
			"\nLa cadena excede la longitud permitida. Vuelva a "
			"intentarlo.\n");
		return;
	}

	/* RESTRICCIÓN 2:
	Si la cadena excede la capacidad del vector, toca escribir lo que
	alcance.
	Si la longitud de la cadena sumada a la posición es mayor a la
	capacidad del vector,
	entonces cumple la condición. */
	// Se declaran los enteros para los recorridos
	int i = 0;
	int j = 0;
	char a[strlen(s)];
	if (strlen(s) + p > 799) {
		printf(
			"\nADVERTENCIA: se escribirá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");

		// Mientras se esté dentro de la capacidad del vector y...
		while (i < 799 - p) {
			//...mientras se esté recorriendo el String
			while (j < strlen(s)) {
				// Asignar a dicha posición del vector el elemento actual del
				// String
				V[i] = *(s + j);
				// Así se avanzará tanto en el vector como en el String
				i++;
				j++;
				// Hasta que alguno de los dos sobrepase su capacidad.
			}
		}

		// Termina el void
		printf("\nSe escribió s desde el byte p de V.\n");
		return;
	}

	i = p;
	j = 0;

	// Mientras se encuentre dentro del rango establecido y...
	while (i < strlen(s) + p) {
		//...mientras se esté recorriendo el String
		while (j < strlen(s)) {
			// Asignar a dicha posición del vector el elemento actual del String
			*(V + i) = *(s + j);
			// Así se avanzará tanto en el vector como en el String
			i++;
			j++;
			// Hasta que alguno de los dos no cumpla con la condición.
		}
	}
}

/*
	Procedimiento que lee l bytes de V desde la posición p y los escribe
	como chars en s
*/
void leer(unsigned char *V, unsigned char *s, int p, int l) {
	// TODO: DESARROLLAR COMPLETAMENTE ESTE PROCEDIMIENTO

	/* PRECAUCIÓN: posiciones incorrectas.
		La posición excede la capacidad del arreglo. */
	if (p > 799) {
		printf(
			"\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
		return;
	}

	/*La posición es inválida */
	if (p < 0) {
		printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
		return;
	}
	// Posición inicial del vector.
	int i = p;
	// Posición inicial de la cadena.
	int j = 0;

	/*
	En dado caso que se pida leer una cadena que sumada a la posición supere la
	capacidad del vector.
	//FIXME - cuando ingreso de posición 799 y cadena 10, debería devolverme un
	0 porque sí existe la posición 799, pero no lo hace U_U,
	*/
	if (p + l > 799) {
		printf(
			"\nADVERTENCIA: se leerá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");
		// Mientras se esté dentro del rango y la capacidad del vector
		while (i < 800 && i < p + l && j < l) {
			// Se asignará a la cadena el valor del vector en la posición
			// correspondiente.
			*(s + j) = V[i];
			// Se continuará el aumento de posiciones para el arreglo y la
			// cadena
			j++;
			i++;
			// Hasta que alguno de los dos exceda su capacidad.
		}
		printf("Se leyeron los siguientes bytes: %s\n", s);
		return;
	}

	// Mientras la pos no sea mayor a la pos inicial más la longitud de la
	// cadena y...
	while (i < p + l) {
		//... mientras la posición en la cadena no exceda la longitud de la
		// misma,
		while (j < l) {
			// Se asignará a la cadena el valor del vector en la posición
			// correspondiente.
			*(s + j) = V[i];
			// Se continuará el aumento de posiciones para el arreglo y la
			// cadena
			j++;
			i++;
			// Hasta que alguno de los dos exceda su capacidad.
		}
	}
	printf("Se leyeron los siguientes bytes: %s\n", s);
} // End
