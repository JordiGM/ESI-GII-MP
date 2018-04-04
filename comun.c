#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Cabecera: Usuario* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector
char *leer_campo( int largo, char *titulo ) {
//  Seria incorrecto leer string mediante un puntero al que no se le ha reservado memoria
//  scanf toma una palabra como cadena y usa los espacios para separar variables.
     char *campo;
     campo = (char *)calloc(largo+1, sizeof(char)) ;
     printf("%s (%d):", titulo, largo);
     fgets(campo, largo+1, stdin);
     quitar_saltos( campo );
     fflush( stdin );
     return campo;
}

// Cabecera: int* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector
int leer_numero( char *titulo ) {
     int num;
     printf("%s (integer):", titulo);
     scanf("%d", &num);
     fflush( stdin );
     return num;
}


// Cabecera: int* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector
void quitar_saltos( char *cadena ) {
     char *p;
     p = strchr(cadena, '\n');
     if (p) *p = '\0';
}