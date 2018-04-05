#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabecera: char* leer_campo(entero largo, caracter titulo)
// Precondicion: el tamaño de la cadena que se va a solicitar y  el texto que se quiere mostrar
// Poscondicion: devuelve un puntero de tipo char con la información introducida por el usuario
char *leer_campo( int largo, char *titulo ) {
     char *campo,*p;
     campo = (char *)calloc(largo+1, sizeof(char)) ;
     printf("\n%s (%d caracteres):", titulo, largo);
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
     printf("\n%s (integer):", titulo);
     scanf("%d", &num);
     fflush( stdin );
     return num;
}

//Temporal para la función de Adri
#include "ficheros.h"

char *altaUsuarioInicio(Usuarios *lista,int *elementos,char *usuario){
    char *id,*localidad, *nombre, *login;
    
    //Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena
    id = (char *) malloc( TAM_ID_USER+1*sizeof(char) );
    nombre = (char *) malloc( TAM_NOM_USER+1*sizeof(char) );
    localidad = (char *) malloc( TAM_LOC_USER+1*sizeof(char) );
    login = (char *) malloc( TAM_LOG_USER+1*sizeof(char) );
    
    //Mostramos información que se le solicita al usuario y la recogemos
    printf("\n\nHola %s para finalizar tu registro necesitamos algunos datos mas.\n", usuario);
    nombre = leer_campo(TAM_NOM_USER, "Nombre");
    localidad = leer_campo(TAM_LOC_USER, "Ciudad en la que vive");
    login = leer_campo(TAM_LOG_USER, "Contraseña");
    
    //Obtenemos memoria para un nuevo elemento
    lista = (Usuarios *) realloc( lista, (*elementos+1) * sizeof(Usuarios) );
    
    //Guardamos la información recogida y generada en el nuevo elemento    
    sprintf(id, "%04d", *elementos+1);                                          //Transofrmamos el ultimo id + 1 en una cadena tipo 0001 
    lista[*elementos].Id_usuario = id;
    lista[*elementos].Nomb_usuario = nombre;
    lista[*elementos].Localidad = localidad;
    lista[*elementos].Perfil_usuario = "usuario";
    lista[*elementos].User = usuario;
    lista[*elementos].Login = login;
    lista[*elementos].Estado = "activo";
    (*elementos)++;
    return id;
} 