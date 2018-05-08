#include "ficheros.h"
#include "Incidencias.h"
#include "comun.h"
#include <stdio.h>
#include <stdlib.h>

//Cabecera: vacio crearIncidencias(E/S Incidencias lista, E entero numIncidencias, E/S caracter usuario, E/S caracter idViaje, E/S caracter idConductor
//Precondicion: Se facilitara el vactor de incidencias, el numero de elementos del vector, el usuario que pone la incidencia, el id del viaje y su conductor relacionado
//Postcondición: se almacena en el vector de indicencias una nueva incidencia, en estado abierta con los datos facilitados y la descripción indicada por el usuario
void crearIncidencias(Incidencias *lista, int *numIncidencias, char *usuario, char *idViaje, char *idConductor) {
    
    char *descripcion;
    
    descripcion = (char *) malloc(TAM_DES_INC + 1 * sizeof (char));

    
    if (! *numIncidencias) lista = (Incidencias *) malloc((*numIncidencias + 1) * sizeof (Incidencias)); //Reserva memoria para el primer elemento
    else lista = (Incidencias *) realloc(lista, (*numIncidencias + 1) * sizeof (Incidencias)); //Reserva memoria para los elementos restantes
    
    descripcion = leer_campo(TAM_DES_INC,"Indique una descripción de la incidencia");
    
    lista[*numIncidencias].Id_viaje = idViaje; //Asiganamos los valores recogidos al elemento
    lista[*numIncidencias].Id_us_registra = usuario;
    lista[*numIncidencias].Id_us_incidencia = idConductor;
    lista[*numIncidencias].Desc_incidencia = descripcion;
    lista[*numIncidencias].Est_incidencia = "Abierta";
    lista[*numIncidencias].Eliminado = "No";
    (*numIncidencias)++; //Aumentamos el numero de elementos del array
}

void eliminarIncidencias(Incidencias *lista, int *numIncidencias) {

}

void modificarIncidencias(Incidencias *lista, int numIncidencias) {

}

//Cabecera: vacio listaIncidencias(E/S Incidencias lista, E entero numIncidencias, E/S caracter usuario)
//Precondición: vector con la indicencias, entero con el numero de elementos del vector y el id del 
//usuario que se le mostraran sus incidencias
//Postcondicion: se mostraran las incidencias que tiene el usuario y en el caso de ser el admin, se mostraran
//todas las incidencias que haya en el sistema.
void listarIncidencias(Incidencias *lista, int numIncidencias, char *usuario) {
    int indice;
    Incidencias elemento;
    for (indice = 0; indice < numIncidencias; indice++) { //Vamos accediento a cada elemento
        
        
        //REVISAR
        
        if (!strcmp(lista[indice].Id_us_incidencia, usuario) || !strcmp(usuario, (char) "Admin")) { //En el caso que se pase un id de un usuario solo imprimira las incidencias hechas a ese usuario, si es admin imprimira todas las incidencias
            elemento = lista[indice];
            printf("\n%s-%s-%s-%s-%s-%s",
                    elemento.Id_viaje, elemento.Id_us_registra, elemento.Id_us_incidencia, elemento.Desc_incidencia,
                    elemento.Est_incidencia, elemento.Eliminado);
        }
    }
}
