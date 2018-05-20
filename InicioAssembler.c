/*
	PROYECTO 2 FUNDAMENTOS DE INFRAESTRUCTURA TECNOLOGICA
	Nombre Valerie Parra Cortés - 201619703
	Nombre Juliana Prieto Arcila - Codigo Estudiante 2
	Nombre Christian David Florez Pinillos - 201423499
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
	
	/*PRECAUCIÓN: El vector puede que no esté inicializado en su totalidad
 	* con 0's por lo que se procederá a rellenarlo hasta la posición 799 para	
 	* evitar futuros inconvenientes)*/
	int r;
	
	for (r = 0; r < 100; r++)
	{
		V[r] = 0;
	}

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
	unsigned char a = *V;
	unsigned char c = 8;
	unsigned char b, bitte, posicion;
	unsigned char comp0;
	unsigned char comp1;
	
	int longi;
	int l;
	unsigned char prueba1,prueba2, prueba3;
	int i=0;
	
	__asm {
		//Tamaño
		mov ebx, s
		mov edi, 0
		inicio:
		mov ah, [ebx+edi]
		cmp ah, 0
		je fin
		add edi, 1
		jmp inicio
		fin:

		cmp edi, 16 //Restricción 1
		ja salir		

		//Truncar
		mov eax, 0
		mov eax, p
		add eax, edi //Edi no se ha tocado
		cmp eax, 800
		jb cabe
		mov eax, p
		mov esi, 800
		sub esi, eax //800-p
		mov edi, esi // Dejar en edi la nueva longitud
		
		//Escribir como tal
		cabe:
		mov longi, edi //La longitud la guardo en l
		mov eax, 0
		mov eax, p
		cmp eax, 800 //Restricción 2
		ja salir
		div c
		mov bitte, ah 
		mov posicion, al 
		
		mov dh, 127// dh= comp1 =01111111
		mov dl, 128 // dh =comp0 =1000000
		mov cl, bitte // edx =posicion
		
		//Rotaciones
		ror dh, cl
		ror dl, cl //En este punto, edi=l
		
		mov comp1, dh // Guarde comp1
		
			
		mov comp0, dl // Guarde comp1
			
		
		mov esi, s //esi =*s
		mov edi, i // edi=i
		mov al, '0' //al ='0'				
		mov ebx, V //ebx =V		
		mov edx, 0 //edx=0
		mov dl, posicion // dl v[posicion]		
		//mov prueba1, dl	
		
		
		inicioCiclo:
		
		mov ah, [esi+edi] //ah = s[i] edi=i
		mov ecx, [ebx+edx] //En cl se guardo el char que buscaba
		mov al, '0'

		cmp ah, al // ah =0?		
		je escribirCero

		
	
		mov dl, comp0
		or cl, dl	
		mov ebx, V
		mov edx, 0
		mov dl, posicion
		mov [ebx+edx], cl
		mov prueba1, cl
		jmp verificar //Salto a los avances y demás
		
		
		escribirCero:	//Escribir 1		
		mov dl, comp1
		and cl, dl	
		mov ebx, V
		mov edx, 0
		mov dl, posicion
		mov [ebx+edx], cl
		mov prueba1, cl
		
		
		verificar:
		mov eax, 0
		mov ah, bitte
		inc ah 
		mov bitte, ah //Aumento el bitte en el que voy
		cmp ah, 8 
		jne seguir
		
		mov eax, 0 //Esta parte solo se ejecuta si estoy en el bitte 8
		mov al, posicion
		inc al
		mov posicion, al

		seguir:
		mov dl, comp0 //Mover comparadores
		ror dl, 1
		mov prueba1, dl
		mov comp0, dl
		
		mov dl, comp1 //Mover comparadores
		ror dl, 1
		mov prueba2, dl
		mov comp1, dl
		
		mov eax, 0 //Incremento correcto de edi
		mov eax, i
		add eax, 1
		mov i, eax
		mov edi, eax

		mov esi, 0
		mov edi, 0
		mov eax, 0
		mov ebx, 0
		mov edx, 0
		mov ecx, 0

		mov esi, s		
		mov edi, i
		mov al, '0'
		mov ebx, V
		mov edx, 0
		mov dl, posicion
		mov ecx, longi

		cmp edi, ecx 
		jb inicioCiclo
			
		salir:
	

		
	}
	printf("%d %d",V[0],V[1]);
	

	
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
