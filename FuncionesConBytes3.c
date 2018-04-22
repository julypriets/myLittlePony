/*
	PROYECTO 1 FUNDAMENTOS DE INFRAESTRUCTURA TECNOL�GICA
	Christian David Florez Pinillos - 2014...
	Valerie Parra Cortés - 201619703
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

	/*PRECAUCIÓN: El vector puede que no esté inicializado en su totalidad
 * con 0's por lo que se procederá a rellenarlo hasta la posición 799 (para
 * evitar futuros inconvenientes)*/
	int r;
	for (r = 0; r <= 799; r++) {
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
    //La condición es 99 porque esta en Bytes y no en bits
	if (p > 99) {
		printf( "\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
			for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		return;
	}
	if (p < 0) { printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
	        for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		return;
	}
	if (strlen(s) > 16) {
		printf( "\nLa cadena excede la longitud permitida. Vuelva a "
			"intentarlo.\n");
			for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		return;
	}
	int longitud= strlen(s);
	if (longitud + p > 99) {
		printf(
			"\nADVERTENCIA: se escribirá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");
        //Recalcular la longitud
        longitud= longitud-((p+longitud)-99);
	}
	int i = p;
	int j = 0;
    	while (longitud-- > 0) {
			// Asignar a dicha posición del vector el elemento actual del String
	    	*(V + i) = *(s + j);
			// Así se avanzará tanto en el vector como en el String
    		i++;
    		j++;
    }
	printf("\nSe escribió s desde el byte p de V.\n");
	for(int i=0; i<16;i++){
	    s[i]=' ';
	}
	return;
}
void leer(unsigned char *V, unsigned char *s, int p, int l) {
	if (p > 799) {
		printf(
			"\nLa posición excede la capacidad del vector. Inténtelo de "
			"nuevo.\n");
			for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		return;
	}
	if (p < 0) {
		printf("\nLa posición es inválida. Inténtelo de nuevo.\n");
		for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		return;
	}
	int i = p;
	int j = 0;
	if (p + l > 799) {
		printf(
			"\nADVERTENCIA: se leerá hasta lo que pueda contener "
			"el vector puesto que la cadena y la posición dadas superan "
			"su capacidad.\n");
			for(int i=0; i<16;i++){
	            s[i]=' ';
			}
		  l= l-((p+l)-800);
		return;
	}
    
    	while (l-- > 0) {
			// Escribir en S
			*(s + j) = V[i];
			// Así se avanzará tanto en el vector como en el String
    		i++;
    		j++;
    }
	printf("Se leyeron los siguientes bytes: %s\n", s);
    for(int i=0; i<16;i++){
	    s[i]=' ';
	}
	
	return;
} 