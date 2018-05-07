#include <stdlib.h>
#include <string.h>
#include "ficheros.c"
#include "comun.h"

void publicar_paso(Pasos *lista, int* numPasos, char* idViaje){
    Pasos *alm;
    char *id, *poblacion,*eliminado;
    
    poblacion = (char *) malloc(TAM_POB_PAS + 1 * sizeof (char));
    eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));
        
    poblacion = leer_campo(TAM_POB_PAS,"Población por la que pasa el viaje");
    
    alm = (Pasos *) realloc(alm, (*numPasos + 1) * sizeof (Pasos)); //Reserva memoria para los elementos restantes

    alm[*numPasos].Id_viaje = id; //Asiganamos los valores recogidos al elemento
    alm[*numPasos].Poblacion = poblacion;
    alm[*numPasos].Eliminado = eliminado;
    (*numPasos)++; //Aumentamos el numero de elementos del array
}

void eliminar_paso(Pasos *lista, int* numPasos, char* idViaje){
}

void listar_paso(Pasos *lista, int* numPasos, char* idViaje){
}
