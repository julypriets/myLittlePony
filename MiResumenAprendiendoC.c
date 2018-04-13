// Para aprender C hay que saber cómo funciona la memoria de un computador
// Librería que concede la habilidad de imprimir en pantalla
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//-----------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------

/*
El método main retorna un int. El número que retorne la función indica si el
programa está bien o mal hecho.
  *Si retorna 0 está bien hecho.
  *Si retorna un número mayor a 0, el programa falló.
  */
int main(void) {
	printf("Hello World\n");
	printf("\n");

//-----------------------------------------------------------------------
// Tipos de variable
//-----------------------------------------------------------------------

/*
//Enteros                 |                //Enteros que solo pueden ser
positivos
char 1 byte              |                 unsigned char
int 4 bytes               |                 unsigned int
short 2 bytes             |                 unsigned short
long 4 bytes              |                 unsigned long
long long 8 bytes         |                 unsigned long long
*/

// C no tiene boolean entonces hay que definirlo
#define BOOL char
#define FALSE 0
#define TRUE 1

	//-----------------------------------------------------------------------
	// Operaciones con enteros
	//-----------------------------------------------------------------------

	/*The printf() family of functions uses % character as a placeholder. When a
	% is encountered, printf reads the characters following the % to determine
	what to do:

	%s - Take the next argument and print it as a string
	%d - Take the next argument and print it as an int

	*/

	int a = 0, b = 1, c = 2, d = 3, e = 4;
	a = b - c + d * e;
	printf("%d", a); // imprimirá 11.
	printf("\n");

	//-----------------------------------------------------------------------
	// Arreglos
	//-----------------------------------------------------------------------

	// Definir un arreglo normal
	int numbers[10];

	// Definir una matriz
	int matriz[1][2];

	//-----------------------------------------------------------------------
	// Strings
	//-----------------------------------------------------------------------

	// Los strings en C son arreglos de characters. Sin embargo, los pointers
	// pueden usarse en un arreglo de characters para definir Strings simples.
	// String que no puede manipularse
	char *nombre = "John Smith";

	// String que puede manipularse
	// char nombre[] = "John Smith";

	int edad = 27;
	// Imprimir que John Smith tiene 27 años de edad.
	// Imprimimos un salto de línea
	printf("\n");
	printf("%s tiene %d años de edad.\n", nombre, edad);
	printf("\n");

	//-----------------------------------------------------------------------
	// Métodos de strings
	//-----------------------------------------------------------------------

	// strlen = devuelve la longitud de un String
	printf("%d\n", strlen(nombre));
	printf("\n");

	// strncmp = compara dos Strings. Si el resultado es 0, son iguales.
	// Se ingresa String1, String2 y largo máximo de comparación.
	char *str1 = "Paul";
	char *str2 = "John";

	if (strncmp(str1, str2, 4) == 0) {
		printf("Hello, John!\n");
	} else {
		printf("No eres John, ¡acceso denegado!. \n ");
	}
	printf("\n");

	// Para concatenar Strings

	// Se introduce el String de destino, source String, y máximo de caracteres
	// que serán concatenados.
	char dest[20] = "Hello";
	char src[20] = "World";
	strncat(dest, src, 3);
	printf("%s\n", dest);
	// Imrpime Wor World porque con la concat previa se modificó el string a
	// "HelloWor"
	strncat(dest, src, 5);
	printf("%s\n", dest);
	printf("\n");

	//-----------------------------------------------------------------------
	// For loops
	//-----------------------------------------------------------------------
	int i;
	for (i = 0; i < 11; i++) {
		printf("%d\n", i);
	}

	// Para sumar todos los elementos de un arreglo
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 0;
	int j;

	for (j = 0; j < 10; j++) {
		sum += array[j];
	}

	printf("\n");
	printf("La suma de mi arreglo es %d\n", sum);
	printf("\n");

	//-----------------------------------------------------------------------
	// While loops
	//-----------------------------------------------------------------------
	int n = 0;
	while (n < 10) {
		n++;
	}

	n = 0;
	while (1) {
		n++;
		if (n == 10) {
			break;
		}
	}

	n = 0;
	while (n < 10) {
		n++;

		/* check that n is odd */
		if (n % 2 == 1) {
			/* go back to the start of the while block */
			continue;
		}

		/* we reach this code only if n is even */

		printf("The number %d is even.\n", n);
	}

	//-----------------------------------------------------------------------
	// Apuntadores
	//-----------------------------------------------------------------------
	/* Un apuntador es una variable int que guarda una dirección en memoria que
	apunta a algún valor, en lugar de contener dicho valor como tal (solo indica
	dónde está).

	La siguiente línea: */
	char *name = "Mario";
	/* Hace 3 cosas:
		1. Crea una variable llamada name, la cual es un apuntador a un single
	   character.
		2. Hace que el String "Mario" aparezca en alguna parte en la memoria
		   del programa (tras ser compilado y ejecutado).
		3. Inicializa el "name" para que apunte en donde la "M" reside
		  (y la cual está seguida por el resto del String).

		Si tratamos de acceder a la variable "name" como un arreglo, funcionará
	   y se retornará el valor ordinal del caracter "M" puesto que la variable
	   en realidad apunta al comienzo del String.

		Puesto que sabemos que la memoria es secuencial, podemos asumir que si
	   nos movemos adelante en memoria al siguiente caracter, recibiremos la
	   siguiente letra del string hasta que lleguemos al final de dicho string,
	   marcado con un "null terminator" (un caracter cuyo valor ordinal es 0,
	   denotado como
	   \0).

		** Dereferencing **
		Dereferencing es el acto de referirse a donde el apuntador está
	   apuntando, en lugar de la dirección en memoria. El operador [0], por
	   ejemplo, accede al primer item del arreglo. Como los arreglos en realidad
	   son apuntadores, acceder al primer item de un arreglo es lo mismo que
	   deferefencing un pointer. Dereferencing a pointer se hace usando el
	   operador asterisco *.

		Si queremos crear un arreglo que apunte a una variable diferente en
	   unstack, podemos hacer lo siguiente: */

	// Definir la variable local v
	int v = 1;

	// Definir un apuntador que apunte a "v" usando el operador &
	int *pointer_to_v = &v;

	printf("\n");
	printf("El valor de v es %d\n", v);
	printf("El valor de v también es %d\n", *pointer_to_v);

	//-----------------------------------------------------------------------
	// Estructuras
	//-----------------------------------------------------------------------

	/* Las estructuras en C son variables grandes que contienen varias por
	dentro. Las estructuras son los building blocks de los objetos y clases.
	Las estructuras se usan para:
	1. Serialización de datos.
	2. Pasar múltiples arguments in y out de funciones a través de un "single
	argument".
	3. Estructuras de datos tales como las LinkedLists, Binary Trees, entre
	otros.

	El ejemplo más básico de una estructura son los points, lo cuales son una
	entidad sencilla que contiene dos variables, x y y. A continuación se define
	un punto: */

	struct point {
		int x;
		int y;
	};

	/* Si quisiéramos dibujar usando la estructura de point podemos hacer lo
	siguiente:

	struct point p; - creamos nuestra estructura de tipo point
	p.x = 10; - accedemos a las variables de la estructura usando el "."
	p.y = 5;
	draw(p); - dibujamos el punto.


	** Type defs **
	Los typedefs nos permiten definir tipos con nombre distinto (lo cual puede
	ser muy útil a la hora de majear estructuras y puntos). En est caso,
	queremos "deshacernos" de la larga definición de la estructura de un point.
	Por lo tanto podemos usar la siguiente sintaxis para remover el "struct" por
	cada vez que queramos definir un nuevo punto */
	typedef struct {
		int x;
		int y;
	} point;

	// Lo cual nos permitirá definir un punto como de la siguiente manera:

	point p;

	/* Las estructuras también pueden manejar punteros, lo cual les permite
	 * manejar strings, o punteros de estructuras como tal (de ahí su gran
	 * potencial). Por ejemplo, podemos definir una estructura que represente un
	 * carro de la siguiente manera: */

	typedef struct {
		char *marca;
		int modelo;
	} carro;

	/* Como "marca" es un puntero "char", el tipo carro puede contener un string
	 * (el cual, en este caso, idica la marca del vehículo). */

	carro mycar;
	mycar.marca = "Ford";
	mycar.modelo = 2007;

	/* ** Function arguments by reference **

	Los parámetros de funciones son pasados como un valor, lo que quiere decir
	que son copiados dentro y fuera de las funciones, pero, ¿y qué si copiáramos
	punteros asociados a valores en lugar de los valores mismos? Esto nos
	permite darle a las funciones el control sobre las variables y estructuras
	de las funciones padre, y no solo una copia de las mismas.

	Digamos que quermos escribir una función que incremente un numero de a uno,
	llamada "addOne". Lo siguiente no funcionará:

	void addOne( int n ){
	 n++;
	}

	int n; - declaramos nuestro entero en memoria
	addOne(n); - pasamos como parámetro a nuestro número, sin embargo como es
	una copia el método no modifica el valor original
	prinf("Result %d"\n", n); - el método imprimirá 0 (valor por defecto)

	Ahora lo haremos con puntero.

	void addOne( int * n){ - tenemos por parámetro el puntero n.
	  (*n)++;
	}
	 int n;
	 printf("Antes de sumar: %d\n", n);
	 addOne(&n);
	 printf("Después de sumar: %d\n", n);

	La gran diferencia es que en el segundo se recibe un apuntador que conduce a
	la variable y se puede manipular, puesto que sabe en qué sitio de la memoria
	se encuentra.
	Cuando se utiliza la función addOne le pasamos una referencia de la variable
	n y no una copia del valor de dicha variable, para que pueda manipularla.

** Apuntadores a estructuras **

Si queremos crear una función "move" para nuestro point (que hicimos
anteriormente) podemos hacerlo usando solo un apuntador el cual nos dirá en
dónde se encuentra la estructura.
Usamos el operador -> para reemplazar el acto de hacer "(*p).x++; que
significaría obtener el valor de p (la estructura) y con el punto acceder a su
variable. Dicho operador nos lo hace muy sencillo de la siguiente manera: */

	void move(point * p) {
		p->x++;
		p->y++;
	}

	/* **Asignación dinámica **
	La asignación dinámica de memoria nos permite crear estructuras de datos
	complejas como las listas encadenadas. Asginar de manera dinámica la memoria
	nos ayuda a guardar datos sin saber inicialmente el tamaño que ocuparán al
	momento de escribir el programa.
	Para asignar un chunk de memoria dinámicamente, tenemos que tener un
	apuntador listo (el cual guradará la ubicación de "newly allocated memory").
	Podemos acceder a la memoria en la que estaba ubicado antes usando el mismo
	apuntador, y podemos usar el apuntador para liberar espacio en la memoria
	que entemos, al terminar de usarlo.

	Asumamos que queremos guardar de manera dinámica la estructura de una
	persona. La persona se define así: */

	typedef struct {
		char *nombre;
		int edad;
	} persona;

	/* Para guardar una nueva persona en el argumento de "miPersona" usamos la
	 * siguiente sintaxis: */

	persona *miPersona = malloc(sizeof(persona));

	/*Lo anterior le dice al compilador que queremos guardar dinámicamente solo
	lo suficiente para guardar a una persona en memoria, y luego retorna un
	apuntador con el dato recién asignado.

	Sizeof no es una función, pues el compilardor interpreta y lo traduce al
	tamaño real de "persona".
	Para acceder a las variables de la estructura usamos el operador ->.
	MiPersona en realidad es una forma de tomar una Persona sin inicializar,
	tener un apuntador con apenas lo que ocupa en memoria Persona, cambiar sus
	variables y luego enviar un apuntador nuevo que cuente con la nueva memoria
	ocupada. */

	miPersona->nombre = "Pepe";
	miPersona->edad = 10;

	/* Tras haber guardado la estructura de manera dinámica podemos soltarla
	 * usando "free" */
	free(miPersona);

	/*Free no elimina la variable miPersona, simplemente libera los datos a los
	 * que apunta. La variable miPersona todavía apuntará a alguna variable en
	 * memoria, pero después de llamar a miPersona no tenemos acceso al area. No
	 * debemos usar ese apuntador de nuevo hasta que coloquemos nuevos datos
	 * usándolo. */

	//-----------------------------------------------------------------------
	// Arreglos y apuntadores
	//-----------------------------------------------------------------------
	char vowels[] = {'A', 'E', 'I', 'O', 'U'};
	char *pvowels = (char *)&vowels;
	int r;

	// Imprime las direcciones
	printf("\n");
	// Aumentamos r en 1 porque tenemos un arreglo de chars (de a 1byte)
	for (r = 0; r < 5; r++) {
		printf(
			"&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n",
			r,
			&vowels[r], // da la ubicación del r-ésimo elemento del arreglo
			r,
			pvowels + r, // Nos damos cuenta de que tener un apuntador y sumarle
			// los bytes que queremos saltar es igual que hacer
			// &vowlels[r] que quiere decir apuntar a la dirección
			// del elemento r de vowels.
			r,
			vowels + r);
	}

	// Imprime los valores
	for (r = 0; r < 5; r++) {
		printf(
			"vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n",
			r,
			vowels[r],
			r,
			*(pvowels + r),
			r,
			*(vowels + r));
	}

	/*Podemos identificar que el nombre de un arreglo es un apuntador
	(constante) al primer elemento del arreglo. Eso quiere decir que vowels,
	&vowels[0] y vowels+0 apuntan a la misma ubicación.

	** Asignación dinámica de memoria para arreglos **

	Por el momento sabemos que podemos recorrer un arreglo usando apuntadores.
	Ahora sabemos que opdemos asignar dinámicamente memoria contigua usando
	blocks pointers. Esto se ilustra en el siguiente código: */

	// Asignar memoria para guardar cinco caracteres.
	int caracteres = 5;
	char *qvowels = (char *)malloc(caracteres * sizeof(char));
	int w;

	qvowels[0] = 'A';
	qvowels[1] = 'E';
	*(pvowels + 2) = 'I';
	qvowels[3] = 'O';
	*(qvowels + 4) = 'U';

	for (w = 0; w < n; w++) {
		printf("%c ", qvowels[i]);
	}

	printf("\n");

	free(qvowels);

	/* Ahora podemos preguntarnos, ¿para qué usar la asignación de memoria
	dinámica? Hay que tener en cuenta que a la hora de declarar un arreglo, el
	número de elementos que podría contener debería ser conocido. Sin embargo,
	en algunos escenarios el tamaño del arreglo se queda corto o es muy extenso
	para su utilidad. Al usar la asignación dinámica de memoria, es posible
	asignar uanta memoria se requiera para el programa. Además, la memoria sin
	usar puede ser liberada cuando no se requiera invocando la función free().
	Es necesario llamar al método free(), de lo contrario, habrá fallas en
	memoria.

	Para concluir esta parte, vamos a mirar la asignación de memoria dinámica
	para una matriz. Esto puede ser generalizado para arreglos de n-dimensiones
	de una manera similar. A diferencia de los arreglos de una sola dimensión,
	en donde usábamos un apuntador, en este caso requerimos un apuntador a un
	apuntador, como se muestra en el siguiente código: */

	int nrows = 2;
	int ncols = 5;
	int k, l;

	// Allocate memory for nrows pointers
	char **pvowels = (char **)malloc(nrows * sizeof(char *));

	// For each row, allocate memory for ncols elements
	pvowels[0] = (char *)malloc(ncols * sizeof(char));
	pvowels[1] = (char *)malloc(ncols * sizeof(char));

	pvowels[0][0] = 'A';
	pvowels[0][1] = 'E';
	pvowels[0][2] = 'I';
	pvowels[0][3] = 'O';
	pvowels[0][4] = 'U';

	pvowels[1][0] = 'a';
	pvowels[1][1] = 'e';
	pvowels[1][2] = 'i';
	pvowels[1][3] = 'o';
	pvowels[1][4] = 'u';

	for (k = 0; k < nrows; k++) {
		for (l = 0; l < ncols; l++) {
			printf("%c ", pvowels[i][j]);
		}
		printf("\n");
	}

	// Free individual rows
	free(pvowels[0]);
	free(pvowels[1]);

	// Free the top-level pointer
	free(pvowels);

} // Fin del main