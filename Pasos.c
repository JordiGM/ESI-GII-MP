#include <stdlib.h>
#include <string.h>
#include "ficheros.c"
#include "comun.h"
#include "Pasos.h"

void publicar_paso(Pasos *lista, int* numPasos, char* idViaje){
    char *poblacion;
    
    poblacion = (char *) malloc(TAM_POB_PAS + 1 * sizeof (char));
        
    poblacion = leer_campo(TAM_POB_PAS,"Población por la que pasa el viaje");
    
    if (! *numPasos) lista = (Pasos *) malloc((*numPasos + 1) * sizeof (Pasos)); //Reserva memoria para el primer elemento
    else lista = (Pasos *) realloc(lista, (*numPasos + 1) * sizeof (Pasos)); //Reserva memoria para los elementos restantes

    lista[*numPasos].Id_viaje = idViaje; //Asiganamos los valores recogidos al elemento
    lista[*numPasos].Poblacion = poblacion;
    lista[*numPasos].Eliminado = "No";
    (*numPasos)++; //Aumentamos el numero de elementos del array
}

void eliminar_paso(Pasos *lista, int* numPasos, char* idViaje, char* poblacion){
    
    int indice = 0;
    
    if(*numPasos == 1){
        free(lista);
    }
    else{
        while(indice < *numPasos || (!strcmp(idViaje,lista[indice].Id_viaje) && !strcmp(poblacion, lista[indice].Poblacion)))
            indice++;
        
        if(*numPasos-1 != indice){
            lista[indice] = lista[*numPasos-1];
        }
        lista = (Pasos *) realloc(lista, (*numPasos - 1) * sizeof (Pasos));
    }  
}

void listar_paso(Pasos *lista, int* numPasos, char* idViaje){
    int indice;
    
    printf("El viaje pasa por las siguientes localidades:\n\n");
    
    for(indice = 0; indice < *numPasos; indice++){
        if(!strcmp(lista[indice].Id_viaje,idViaje)){
            printf("%s\n",lista[indice].Poblacion);
        }
    }
}
