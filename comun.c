#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"

// Cabecera: void vacia_buffer()
// Precondicion: Ninguna
// Poscondicion: Limpia el buffer de entrada
void vacia_buffer(){
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}

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
     vacia_buffer();
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

// Cabecera: int buscar_usuario(int id)
// Precondicion: id del usuario a buscar la posición en el array, array y numero de elementos
// Poscondicion: devuelve el número que ha introducido el usuario, si no lo encuentra devuelve -1
int buscar_usuario(char *id, Usuarios *lista, int elementos){
    int posicion = -1, exisUser = 0, i = 0;
    
    while (i < elementos && exisUser == 0) { //Buscamos el nombre del usuario si existe
        if (!strncmp(id, lista[i].Id_usuario, TAM_ID_USER)) {
            exisUser = 1; //Si hay una concidencia guardamos y salimos
            posicion = i;
        }
        i++;
    }
    
    return posicion;
}

//Temporal para la función de Adri Ruben
#include "ficheros.h" //Adri y Ruben
#include <time.h> //Ruben

int autoFinalizarViaje(Viajes *lista, int elementos){
    int estadoOp = 1, indice;
    struct tm fecha, hora, *actual;
    time_t tiempo;
    
    tiempo = time(NULL);
    actual = localtime(&tiempo);
    
    for(indice = 0; indice < elementos; indice++){
        strptime(lista[indice].F_inic, "%d/%m/%Y", &fecha);
        strptime(lista[indice].H_fin, "%H:%M", &hora);
        
        if(fecha.tm_year+1900 - actual->tm_year > 0 || 
           fecha.tm_mday - actual->tm_mday > 0 ||
           fecha.tm_mon+1 - actual->tm_mon+1 > 0 ||
           hora.tm_hour+1 - actual->tm_hour >= 0){
            printf("\nViaje Finalizado %s\n",lista[indice].Id_viaje);
            lista[indice].Estado = "Finalizado";
        }
        
            
    }
    
    return estadoOp;
}

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
    sprintf(id, "%04d", *elementos + 1); //Transofrmamos el ultimo id + 1 en una cadena tipo 0001 
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