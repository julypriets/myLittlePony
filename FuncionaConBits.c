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

int main(int argc, char *argv[])
{
	// Variables
	int op;
	int l, p;
	unsigned char *V;
	unsigned char *s;

	// Inicialización
	V = (unsigned char *)calloc(100, sizeof(char));

	/*PRECAUCIÓN: El vector puede que no esté inicializado en su totalidad
 * con 0's por lo que se procederá a rellenarlo hasta la posición 799 (para
 * evitar futuros inconvenientes)*/
	int r;
	for (r = 0; r < 100; r++)
	{
		V[r] = 0;
	}

	s = (unsigned char *)calloc(17, sizeof(char));

	// Mensaje inicial
	printf("PROYECTO 1 - INFRATEC");

	// Loop hasta terminar
	op = 3;
	while (op != 0)
	{
		// Se pregunta al usuario cual opcion desea realizar
		printf(
			"\n\n* Indique la modalidad\n\t0: Terminar\n\t1: Escribir\n\t2: "
			"Leer\n\n");
		printf("Modalidad: ");
		scanf("%d", &op);

		// Escribir
		if (op == 1)
		{
			printf("Acción %d: Escribir\n\n", op);

			// Se reciben los valores de s y p
			printf("Escriba s: ");
			scanf("%s", s);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se escribe s desde el bit p de V
			escribir(V, s, p);
		}
		// Leer
		else if (op == 2)
		{
			printf("Acción %d: Leer\n\n", op);

			// Se reciben los valores de l y p
			printf("Escriba l: ");
			scanf("%d", &l);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se leen l bits de V desde la posición p y se escriben como chars
			// en s
			leer(V, s, p, l);
		}
		// Invalido
		else if (op != 0)
		{
			printf("Opción invalida.\n");
		}
	}

	// Terminar
	printf("\nPrograma terminado.\n");
	return 0;
}

/*
	Procedimiento que escribe s empezando en el bit p de V
*/
void escribir(unsigned char *V, unsigned char *s, int p)
{

	/* PRECAUCIÓN: posiciones incorrectas.
	La posición excede la capacidad del arreglo. */
	if (p > 799)
	{
		printf(
			"\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
		return;
	}
	/*La posición es inválida */
	if (p < 0)
	{
		printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
		return;
	}

	/*RESTRICCIÓN 1:
	La cadena no puede ser mayor a 16 bits.
	Como char tiene solo 1 bit se asume que si la longitud es mayor a 16, es
	mayor a 2 bits. */

	if (strlen(s) > 16)
	{
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
	// Se declara l
	int l = strlen(s);
	if (p + l > 800)
	{
		printf(
			"\nADVERTENCIA: se leerá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");
		l = l - (p + l - 800);
	}

	/* RESTRICCIÓN 3:
	Si la cadena ingresada por el usuario no contiene caracteres válidos */
	char * sch_zero;
	char * sch_one;
	sch_zero = strstr(s, "0");
	sch_one = strstr(s, "1");
	if(sch_one == NULL && sch_zero == NULL){
		printf("La cadena no contiene caracteres validos.\nRecuerde una cadena consta de unos y ceros.\nIntente de nuevo.");
		return;
	}

	int bitte = p / 8;
	int posicion = p % 8;
	//unsigned char bitteModificado= V[bitte];
	unsigned char comp0 = 128; //10000000
	unsigned char comp1 = 127; //01111111
	comp1 = (comp1 >> posicion) | (comp1 << 8 - posicion);
	comp0 = (comp0 >> posicion) | (comp0 << 8 - posicion);
	unsigned char c;
	for (int i = 0; i < l; i++)
	{
		c = s[i];
		if (c == '0')
		{
			V[bitte] = V[bitte] & comp1;
		}
		else
		{
			V[bitte] = V[bitte] | comp0;
		}
		posicion++;
		if (posicion == 8)
		{
			posicion = 0;
			bitte++;
		}
		comp0 = (comp0 >> 1) | (comp0 << 7);
		comp1 = (comp1 >> 1) | (comp1 << 7);
	}

	// Termina el void
	printf("\nSe escribió s desde el bit p de V.\n");
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = ' ';
	}
	return;
}

/*
	Procedimiento que lee l bits de V desde la posición p y los escribe
	como chars en s
*/
void leer(unsigned char *V, unsigned char *s, int p, int l)
{

	/* PRECAUCIÓN: posiciones incorrectas.
		La posición excede la capacidad del arreglo. */

	if (p > 799)
	{
		printf(
			"\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
		return;
	}

	/*La posición es inválida */
	if (p < 0)
	{
		printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
		return;
	}

	/*
	En dado caso que se pida leer una cadena que sumada a la posición supere la
	capacidad del vector.
	*/

	// Posición inicial del vector. Es igual a p
	// Posición inicial de la cadena.

	if (p + l > 800)
	{
		printf(
			"\nADVERTENCIA: se leerá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");
		l = l - (p + l - 800);
	}
	printf("L es: %d\n", l);
	int bitte = p / 8;
	int primerosBits = p % 8;
	unsigned char bitteModificado = V[bitte];
	bitteModificado = (bitteModificado << primerosBits);
	unsigned char comp = 128;
	
	int k = 0;
	int j = 8 - primerosBits;
	//Mientras no terminemos de leer el bit
	while (l-- > 0)
	{
		//Concatena a *s el '1' o el '0' según corresponda
		if (bitteModificado & comp)
		{
			*(s + k) = '1';
		}
		else
		{
			*(s + k) = '0';
		}
		j++;
		if (j == 8)
		{
			bitteModificado = V[++bitte];
			j = 0;
		}
		else
		{
			bitteModificado = (bitteModificado << 1);
		}
		k++;
	}
	printf("Se leyeron los siguientes bits: %s\n", s);
	for (int i = 0; i < strlen(s); i++)
	{
		s[i] = ' ';
	}
}
