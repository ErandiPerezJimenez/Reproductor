#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#define LONGITUD_1 64
#define LONGITUD_2 64



void leer (char *p1, char * p2)
{
  printf ("\nIngrese el nombre de la cancion a buscar es : ");
  fgets (p1,LONGITUD_1 , stdin);
  p1[strlen (p1) - 1] = '\0';	//strlen sirve para contar el número de letras que tiene una cadena de caracteres

  printf ("\nLa cancion: ");
  fgets (p2,LONGITUD_2, stdin);
  p2[strlen(p2) - 1]='\0' ;
  printf ("\n");
}

void mostrar (char *p1, char* p2)
{
  printf ("\nLa canciona buscar es %s y la cancion es %s\n\n", p1,p2);
}
void comparar(char * p1, char * p2)
{
    /*strcmp sirve para copiar la cadena cadena2 dentro de cadena1
    Devuelve el valor de cadena1*/
	int resultado = strcmp(p1, p2);
	// convertimos el resultado en un valor que es 1, 0 o -1 
	resultado = resultado > 0 ? 1 : (resultado < 0 ? -1 :0);
	switch (resultado) {
		case -1:
			printf("\n%s es menor que %s\n",p1,p2);
			break;
		case 0:
			printf("\n%s es igual que %s\n",p1,p2);
			break;
		case 1:
			printf("\n%s es mayor que %s\n",p1,p2);
			break;
		default:
			break;
	}
	printf("\n");
}


int
main ()
{
    /*
	 Las variables palabra_1 y palabra_2 son cadenas de LONGITUD_1 y LONGITUD_2
	 bytes respectivamente, y se declaran estáticamente.
	*/
	char palabra_1[LONGITUD_1]; 
	char palabra_2[LONGITUD_2];
	/*
	 La variable pcadena señala un bloque de memoria de dimensiones
	 iguales a la suma de dimensiones de palabra_1 y palabra_2.
	 */
	char * pcadena = malloc((LONGITUD_1+LONGITUD_2)*sizeof(char));
	/*
	 Este es el menú que muestra la aplicación
	 */
	char menu[] = "1)Leer 2)Mostrar 3)Comparar Q) Salir";
	/*
	 Esta es la opción que escribe el usuario
	 */
	char opcion;
	/*
	 Esta es la condición de finalización del programa
	 */
	int terminar = 0;
	do {
		printf("%s ", menu);
		scanf("%c%*c",&opcion);
		opcion = toupper(opcion);//toma un carácter y devuelve su versión en mayúscula (si es que existe).
		switch (opcion) {
			case '1':
				printf("\nLectura de cadenas\n");
				leer(palabra_1, palabra_2);
				break;
			case '2':
				printf("\nEscritura de cadenas\n");
				mostrar(palabra_1, palabra_2);
				break;
			case '3':
			    printf("\nComparación de cadenas\n");
				comparar(palabra_1, palabra_2);
				break;
			case 'Q':
				printf("\nTerminación del programa\n");
				terminar = 1;
				break;
			default:
				break;
		}
	} while (!terminar);
    return 0;
}
