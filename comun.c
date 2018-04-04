#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Cabecera: char* leer_campo(entero largo, caracter titulo)
// Precondicion: el tamaño de la cadena que se va a solicitar y  el texto que se quiere mostrar
// Poscondicion: devuelve un puntero de tipo char con la información introducida por el usuario
char *leer_campo( int largo, char *titulo ) {
     char *campo,*p;
     campo = (char *)calloc(largo+1, sizeof(char)) ;
     printf("%s (%d caracteres):", titulo, largo);
     fgets(campo, largo+1, stdin);
     p = strchr(campo, '\n');                                                   //Eliminamos los saltos de linea
     if (p) *p = '\0';
     fflush( stdin );
     return campo;
}

// Cabecera: int leer_numero(caracter titulo)
// Precondicion: Texto que se le desea mostrar al usuario
// Poscondicion: devuelve el número que ha introducido el usuario
int leer_numero( char *titulo ) {
     int num;
     printf("%s (integer):", titulo);
     scanf("%d", &num);
     fflush( stdin );
     return num;
}
