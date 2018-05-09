#include "ficheros.h"
#include "Vehiculos.h"
#include "Viajes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comun.h"

// Cabecera: void *alta_vehiculo(Vehiculos *vh,int *elementos,char *usuario)
// Precondicion: vector vehiculo, nª de elementos del vectoy y usuario
// Poscondicion: añade un elemento mas al vector con informacion nueva de un elemento vehiculo que se pide por teclado

void alta_vehiculo(Vehiculos *vh, int *elementos, char *usuario) {
    char *id_mat, *descripcion, *num_plazas;

    //Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena
    id_mat = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char));
    descripcion = (char *) malloc(TAM_DES_VEI + 1 * sizeof (char));
    num_plazas = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));

    //Mostramos información que se le solicita al usuario y la recogemos
    id_mat = leer_campo(TAM_ID_VEI, "Inserte numero de la matricula:\n");
    descripcion = leer_campo(TAM_DES_VEI, "Inserte descripcion de su vehiculo(MAX 50 caracteres):\n");
            num_plazas = leer_campo(TAM_PLA_VEI, "Inserte numero de plazas disponibles:\n");


            //Obtenemos memoria para un nuevo elemento
            vh = (Vehiculos *) realloc(vh, (*elementos + 1) * sizeof (Vehiculos));

    //Guardamos la información recogida y generada en el nuevo elemento     
    vh[*elementos].Id_mat = id_mat;
    vh[*elementos].Id_usuario = usuario;
    vh[*elementos].Desc_veh = descripcion;
    vh[*elementos].Num_plazas = num_plazas;
    (*elementos)++;
}



// Cabecera: void modificar_vehiculo(Vehiculos *vh, int pos)
// Precondicion: lista de vehiculos y posicion del elemento a modificar 
// Poscondicion: menu que te permite modificar apartados de un elemento vehiculo

void modificar_vehiculo(Vehiculos *vh, int pos) {
    int a;

    do {
        printf("Indique la seccion que desea modificar:\n1.- El numero de la matricula.\n2.- El numero de plazas.\n3.- La descripcion del vehiculo.\n0.- Salir");
        scanf("%d", &a);
    } while (a < 0 || a > 4);

    switch (a) {
        case 1:
            vh[pos].Id_mat = leer_campo(TAM_ID_VEI, "Numero de la matricula actual");
            break;
        case 2:
            vh[pos].Num_plazas = leer_campo(TAM_PLA_VEI, "Numero de plazas");
            break;
        case 3:
            vh[pos].Desc_veh = leer_campo(TAM_DES_VEI, "Descripcion del vehiculo");
            break;
        case 0:
            break;
        default:
            printf("Error al elegir la opcion.\n");
            break;
    }

}



// Cabecera: void baja_vehiculo(Vehiculos *lista, int *elementos)
// Precondicion: lista de vehiculos y numero de elementos 
// Poscondicion: modifica a borrado un vehiculo

void baja_vehiculo(Vehiculos *lista, int elementos) {
    char *matricula;
    int pos;

    printf("\n\nBorrado de un vehiculo:\n\n");

    matricula = leer_campo(TAM_ID_VEI, "Introduce matricula"); //Solicitamos la matricula

    pos = buscar_vehiculo(matricula, lista, elementos);

    lista[pos].Eliminado = "Si";
    printf("El vehiculo ha sido eliminado con exito");
}



// Cabecera: int buscar_vehiculo(char *matricula, Vehiculos *lista, int elementos)
// Precondicion: cracter de matricula lista de vehiculos y numero de elementos 
// Poscondicion: devuelve la posicion de un vehiculo en el vector

int buscar_vehiculo(char *matricula, Vehiculos *lista, int elementos) {
    int pos = -1, exisCoche = 0, i = 0;

    while (i < elementos && exisCoche == 0) { //Buscamos el nombre del usuario si existe
        if (!strncmp(matricula, lista[i].Id_mat, TAM_ID_VEI)) {
            exisCoche = 1; //Si hay una concidencia guardamos y salimos
            pos = i;
        }
        i++;
    }
    return pos;
}




// Cabecera: void vehiculos_user(char *id_usu, Vehiculos *lista, int elementos)
// Precondicion: identificador de usuario, vector vehiculos, numero elementos del vector 
// Poscondicion: busca e imprime vehiculos asociados a un usuario

void vehiculos_user(char *id_usu, Vehiculos *lista, int elementos) {
    int pos = -1, exisUser = 0, i = 0;

    while (i < elementos) { //Buscamos el nombre del vehiculo si existe
        if (!strncmp(id_usu, lista[i].Id_usuario, TAM_ID_USER)) {
            //exisUser = 1; //Si hay una concidencia guardamos y salimos
            printf("Nº ||Id matricula||Usuario||Descripción||Numero plaza");
            printf("\n : %d - %s - %s - %s - %s >>> OK\n",
                    i + 1, lista[i].Id_mat, lista[i].Id_usuario, lista[i].Desc_veh, lista[i].Num_plazas);
            pos = i;
        }
        i++;
    }
}



// Cabecera: void listar_viajes_coche(Viajes* v, char matricula, int elementos)
// Precondicion: lista de viajes, matricula, y numero de elementos 
// Poscondicion: imprime todos los viajes realizados por el vehiculo

void listar_viajes_coche(Viajes* v, char* matricula, int elementos) {
    int pos = -1, exisUser = 0, i = 0;

    while (i < elementos) { //Buscamos el nombre del vehiculo si existe
        if (!strncmp(matricula, v[i].Id_mat, TAM_ID_VEI)) {
            printf("Nº ||Id matricula||Usuario||Descripción||Numero plaza");
            printf("\n : %d - %s - %s - %s - %s - %s - %s >>> OK\n",
                    i + 1, v[i].Id_mat, v[i].Id_viaje, v[i].F_inic, v[i].H_inic, v[i].Sentido, v[i].Importe);
            pos = i;
        }
        i++;
    }

}
