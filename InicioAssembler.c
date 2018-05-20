/*
	PROYECTO 2 FUNDAMENTOS DE INFRAESTRUCTURA TECNOLOGICA
	Nombre Estudiante 1 - Codigo Estudiante 1
	Nombre Estudiante 2 - Codigo Estudiante 2
	Nombre Estudiante 3 - Codigo Estudiante 3
*/

#include "stdlib.h"
#include "stdio.h"

void escribir(unsigned char *V, unsigned char *s, int p);
void leer(unsigned char *V, unsigned char *s, int p, int l);

int main(int argc, char* argv[])
{
	// Variables
	int op;
	int l, p;
	unsigned char *V;
	unsigned char *s;

	// Inicialización
	V = (unsigned char*) calloc(100, sizeof(char));
	s = (unsigned char*) calloc(17, sizeof(char));

	// Mensaje inicial
	printf("PROYECTO 2 - INFRATEC");

	// Loop hasta terminar
	op = 3;
	while (op != 0)
	{
		// Se pregunta al usuario cual opcion desea realizar
		printf("\n\n* Indique la modalidad\n\t0: Terminar\n\t1: Escribir\n\t2: Leer\n\n");
		printf("Modalidad: ");
		scanf("%d", &op);

		// Escribir
		if (op == 1)
		{
			printf("Acción %d: Escribir\n\n",op);

			// Se reciben los valores de s y p
			printf("Escriba s: ");
			scanf("%s", s);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se escribe s desde el bit p de V
			escribir(V, s, p);
			printf("\nSe escribió s desde el bit p de V.\n");
		}
		// Leer
		else if (op == 2)
		{
			printf("Acción %d: Leer\n\n",op);

			// Se reciben los valores de l y p
			printf("Escriba l: ");
			scanf("%d", &l);
			printf("Escriba p: ");
			scanf("%d", &p);

			// Se leen l bits de V desde la posición p y se escriben como chars en s
			leer(V, s, p, l);
			printf("Se leyeron los siguientes bits: %s\n", s);
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
	Procedimiento que escribe s empezando en el bit p de V.
*/
void escribir(unsigned char *V, unsigned char *s, int p)
{
	unsigned char a = *s;
	unsigned char c = 8;
	unsigned char b, bitte, posicion;
	unsigned comp0=128;
	unsigned comp1=127;
	int l;

	__asm {
		//Tamaño
		mov ebx, s
		mov edi, 1
		inicio:
		mov ah, [ebx+edi]
		cmp ah, 0
		je fin
		add edi, 1
		jmp inicio
		fin:
		//mov b, edi

		//Salir
		cmp edi, 16
		ja salir

		//Truncar
		mov eax, 0
		mov eax, p
		add eax, edi //Edi no se ha tocado
		cmp eax, 800
		jb cabe
		sub eax, edi // eax=p
		//mov bitte, eax
		mov esi, 800
		sub esi, eax //800-p
		mov edi, esi // Dejar en edi la nueva longitud
		
		//Escribir como tal
		cabe:
		mov l, edi
		mov eax, 0
		mov eax, p
		cmp eax, 800 //Si es mayot a 800, salgo
		ja salir
		div c
		mov bitte, ah //Residuo
		mov posicion, al //Cociente
		
		mov dh, 127// dh= cmp1 //01111111
		mov dl, 128 // dh =cmp0 //1000000
		mov cl, posicion // edx =posicion
		
		//Rotaciones
		ror dh, cl
		ror dl, cl //En este punto, edi=l
		
		for:
		
		
				

		//Fin de escribir
		salir:


		
	}
	printf("%d", bitte);
	
}

/*
	Procedimiento que lee l bits de V desde la posición p y los escribe como chars en s.
*/
void leer(unsigned char *V, unsigned char *s, int p, int l)
{
	//TODO: DESARROLLAR COMPLETAMENTE ESTE PROCEDIMIENTO
	// ESCRIBIR EN ENSAMBLADOR, *NO* SE PUEDEN USAR NOMBRES SIMBOLICOS
	__asm {
        
	}
}
