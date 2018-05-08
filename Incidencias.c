#include "ficheros.h"
#include "Incidencias.h"
#include "comun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: vacio crearIncidencias(E/S Incidencias lista, E entero numIncidencias, E/S caracter usuario, E/S caracter idViaje, E/S caracter idConductor
//Precondicion: Se facilitara el vactor de incidencias, el numero de elementos del vector, el usuario que pone la incidencia, el id del viaje y su conductor relacionado
//Postcondición: se almacena en el vector de indicencias una nueva incidencia, en estado abierta con los datos facilitados y la descripción indicada por el usuario

void crearIncidencias(Incidencias *lista, int *numIncidencias, char *usuario, char *idViaje, char *idConductor) {

    char *descripcion;

    descripcion = (char *) malloc(TAM_DES_INC + 1 * sizeof (char));


    if (! *numIncidencias) lista = (Incidencias *) malloc((*numIncidencias + 1) * sizeof (Incidencias)); //Reserva memoria para el primer elemento
    else lista = (Incidencias *) realloc(lista, (*numIncidencias + 1) * sizeof (Incidencias)); //Reserva memoria para los elementos restantes

    descripcion = leer_campo(TAM_DES_INC, "Indique una descripción de la incidencia");

    lista[*numIncidencias].Id_viaje = idViaje; //Asiganamos los valores recogidos al elemento
    lista[*numIncidencias].Id_us_registra = usuario;
    lista[*numIncidencias].Id_us_incidencia = idConductor;
    lista[*numIncidencias].Desc_incidencia = descripcion;
    lista[*numIncidencias].Est_incidencia = "Abierta";
    lista[*numIncidencias].Eliminado = "No";
    (*numIncidencias)++; //Aumentamos el numero de elementos del array
}

void eliminarIncidencias(Incidencias *lista, int *numIncidencias, char *usuario, char *idViaje, char *idConductor) {
    int indice = 0;

    while (indice < *numIncidencias || !(!strcmp(lista[indice].Id_us_incidencia, idConductor) && !strcmp(lista[indice].Id_us_registra, usuario) && !strcmp(lista[indice].Id_viaje, idViaje)))
        indice++;

    lista[indice].Eliminado = "Si";
}


//Cabecera: vacio modificarIncidencias(E/S Incidencias lista, E entero numIncidencias, E/S caracter usuario, E/S caracter idViaje, E/S caracter idConductor)
//Precondición: Lista de incidencias, numero de elementos del vector, el usuario que pone la incidencia, el viaje que se ha realicado y el conductor asociado.
//Postcondición: Modifica la descripción de la incidencia del viaje indicado

void modificarIncidencias(Incidencias *lista, int numIncidencias, char *usuario, char *idViaje, char *idConductor) {
    int indice = 0, opc;

    while (indice < numIncidencias || !(!strcmp(lista[indice].Id_us_incidencia, idConductor) && !strcmp(lista[indice].Id_us_registra, usuario) && !strcmp(lista[indice].Id_viaje, idViaje)))
        indice++;

    if (!(!strcmp(lista[indice].Id_us_incidencia, idConductor) && !strcmp(lista[indice].Id_us_registra, usuario) && !strcmp(lista[indice].Id_viaje, idViaje))) {
        do {
            printf("Introduzca la opcion que desea:\n"
                    "1.- Modificar estado.\n"
                    "2.- Modificar descripción.\n"
                    "0.- Salir.");
            scanf("%d", &opc);
            switch (opc) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    do {
                        printf("Indique el estado que desea poner:\n"
                                "1.- Validada.\n"
                                "2.- Cerrada.\n"
                                "0.- Salir.");
                        scanf("%d", &opc);
                        switch (opc) {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                lista[indice].Est_incidencia = "Validada";
                                break;
                            case 2:
                                lista[indice].Est_incidencia = "Cerrada";
                                break;
                            default:
                                printf("ERROR: Opcion invalida.");
                                break;
                        }
                    } while (opc != 0);
                    break;
                case 2:
                    lista[indice].Desc_incidencia = leer_campo(TAM_DES_INC, "Introduce la nueva descripcion de la incidencia");
                    break;
                default:
                    printf("ERROR: Opcion invalida.");
                    break;
            }
        } while (opc != 0);
    } else {
        printf("Datos introducidos erroneos, revise la información.\n");
    }
}

//Cabecera: vacio listaIncidencias(E/S Incidencias lista, E entero numIncidencias, E/S caracter usuario)
//Precondición: vector con la indicencias, entero con el numero de elementos del vector y el id del 
//usuario que se le mostraran sus incidencias
//Postcondicion: se mostraran las incidencias que tiene el usuario y en el caso de ser el admin, se mostraran
//todas las incidencias que haya en el sistema.

void listarIncidencias(Incidencias *lista, int numIncidencias, char *usuario) {
    int indice;
    Incidencias elemento;

    if (!strcmp(lista[indice].Id_us_incidencia, usuario))
        printf("Id Viaje - Estado - Descripcion de la incidencia");
    else
        printf("Id Viaje - Estado - Id usuario - Id conductor - Eliminado - Descripcion de la incidencia");

    for (indice = 0; indice < numIncidencias; indice++) { //Vamos accediento a cada elemento
        elemento = lista[indice];
        if (!strcmp(lista[indice].Id_us_incidencia, usuario)) { //En el caso que se pase un id de un usuario solo imprimira las incidencias hechas a ese usuario, si es admin imprimira todas las incidencias
            if (!strcmp(elemento.Eliminado, (char *) "No")) {
                printf("\n%s-%s-%s", elemento.Id_viaje, elemento.Est_incidencia, elemento.Desc_incidencia);
            }
        }

        if (!strcmp(usuario, (char*) "Admin")) {
            printf("\n%s-%s-%s-%s-%s-%s", elemento.Id_viaje, elemento.Est_incidencia, elemento.Id_us_registra,
                    elemento.Id_us_incidencia, elemento.Eliminado, elemento.Desc_incidencia);
        }
    }
}

void validarIncidencias(Incidencias *lista, int numIncidencias) {
    int indice, opc, pendientes = 0;
    Incidencias elemento;
    char *idViaje, *usuario;

    do {
        printf("\n\nIncidencias pendientes de validar\n");
        printf("Id Viaje - Estado - Id usuario - Id conductor - Eliminado - Descripcion de la incidencia");

        for (indice = 0; indice < numIncidencias; indice++) { //Vamos accediento a cada elemento
            elemento = lista[indice];
            if (!strcmp(elemento.Est_incidencia, "Abierta")) {
                printf("\n%s-%s-%s-%s-%s-%s", elemento.Id_viaje, elemento.Est_incidencia, elemento.Id_us_registra,
                        elemento.Id_us_incidencia, elemento.Eliminado, elemento.Desc_incidencia);
                pendientes++;
            }
        }

        if (pendientes > 0) {
            printf("¿Validar alguna incidencia pendiente?:\n"
                    "1.- Si.\n"
                    "0.- No.\n");
            scanf("%d", &opc);
            switch (opc) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    idViaje = leer_campo(TAM_ID_VIA, "Introduce el id del viaje a validar");
                    usuario = leer_campo(TAM_ID_USER, "Introduce el usuario que realiza la queja");
                    indice = 0;
                    while (indice < numIncidencias || (!strcmp(lista[indice].Id_viaje, idViaje) && !strcmp(lista[indice].Id_us_registra, usuario)))
                        indice++;

                    if (!strcmp(lista[indice].Id_viaje, idViaje) && !strcmp(lista[indice].Id_us_registra, usuario))
                        lista[indice].Est_incidencia = "Validada";
                    else
                        printf("Datos introducidos erroneos, revise la información.\n");
                    break;
                default:
                    printf("ERROR: Opcion invalida.");
                    break;
            }
            pendientes = 0;
        } else {
            printf("Todos los viajes estan validados, no hay ninguno pendiente.\n");
        }
    } while (opc != 0);
}