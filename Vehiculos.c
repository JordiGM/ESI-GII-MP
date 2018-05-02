/*
 * listar vehiculos  :)   mostrar viajes realizados por un vehiculo ?¿?¿? es lo mismo?
 * alta vehiculo    :)
 * baja vehiculo
 * modificar vehiculo + buscar vehiculo(contemplar la opcion de mas de un vehiculopor usuario)
 *hacer un menu :)
 * listar los viajes de un coche
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Vehiculo.h"
#include"ficheros.h"
#include"comun.h"
#include"Viajes.h"

//prototipos
void listar_vehiculo(Vehiculos* , int );
void menu_vehiculo();
void alta_vehiculo(Vehiculos*, int, char);
void baja_vehiculo(Vehiculos* ,int*);
void modificar_vehiculo(Vehiculos*,int);
int buscar_vehiculo(char *id, Vehiculos *lista, int elementos);

void listar_vehiculo(Vehiculos* vh, int elementos){
    int i;
     
    for(i=0; i<elementos; i++) {
        if(!strcmp(vh[i].Eliminado, (char *) "No")==0){
        //Visualiza cada regisrtro del fichero no eliminado
            printf("Nº ||Id matricula||Usuario||Descripción||Numero plaza");
            printf("\n : %d - |%*s| - |%*s| - |%*s| - |%*s| >>> OK\n", 
                 i+1, vh[i].Id_mat ,vh[i].Id_usuario, vh[i].Desc_veh, vh[i].Num_plazas );
    }
    }
}   

void *alta_vehiculo(Vehiculos *vh,int *elementos,char *usuario){
    char *id_mat,*id_usu, *descripcion, *num_plazas;
    
    //Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena
    id_mat = (char *) malloc( TAM_ID_VEI +1*sizeof(char) );
    id_usu = (char *) malloc( TAM_ID_USER+1*sizeof(char) );
    descripcion = (char *) malloc( TAM_DES_VEI+1*sizeof(char) );
    num_plazas = (char *) malloc( TAM_PLA_VEI+1*sizeof(char) );
    
        //Mostramos información que se le solicita al usuario y la recogemos
    id_mat=leer_campo(TAM_ID_VEI,"Inserte numero de la matricula:\n");
    descripcion=leer_campo(TAM_DES_VEI, "Inserte descripcion de su vehiculo(MAX 50 caracteres):\n")
    num_plazas=leer_campo(TAM_PLA_VEI,"Inserte numero de plazas disponibles:\n")
    
        
    //Obtenemos memoria para un nuevo elemento
    vh = (Vehiculos *) realloc( vh, (*elementos+1) * sizeof(Vehiculos) );
    
    //Guardamos la información recogida y generada en el nuevo elemento     
    vh[*elementos].Id_mat = id_mat;
    vh[*elementos].Id_usuario = usuario;
    vh[*elementos].Desc_veh = descripcion;
    vh[*elementos].Num_plazas = num_plazas;
    (*elementos)++;
////////////////////////////////////
}



void modificar_vehiculo(Vehiculos *vh, int pos){
    int a;
        
    do {
        printf("Indique la seccion que desea modificar:\n1.- El numero de la matricula.\n2.- El numero de plazas.\n3.- La descripcion del vehiculo.\n0.- Salir");
        scanf("%d", &a);
    } while (a<0 || a>4);
    
    switch(a){
        case 1:
            vh[pos].Id_mat=leer_campo(TAM_ID_VEI, "Numero de la matricula actual");
            break;
        case 2:
            vh[pos].Num_plazas= leer_campo(TAM_PLA_VEI, "Numero de plazas");
            break;
        case 3:
            vh[pos].Desc_veh= leer_campo(TAM_DES_VEI, "Descripcion del vehiculo");
            break;
        case 0:
             break;
        default:
            printf("Error al elegir la opcion.\n");
            break;
    }
    
}



// Cabecera: void bajaUsuario(Usuarios* lista, int* elemento)
// Precondicion: lista de usuarios y numero de elementos 
// Poscondicion: modifica a borrado un usuario
void baja_vehiculo(Vehiculos *lista, int *elementos) {
    char *matricula;
    int pos;

    printf("\n\nBorrado de un vehiculo:\n\n");
    
    matricula = leer_campo(TAM_ID_VEI, "Introduce matricula"); //Solicitamos la matricula
    
    pos = buscar_vehiculo(matricula, lista, *elementos);
    
    lista[pos].Eliminado = "Si";
    printf("El vehiculo ha sido eliminado con exito");
}



//le damos una matricula y busca el coche
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



//le damos un usuario y busca sus coches asociados
void vehiculos_user(char *id_usu, Vehiculos *lista, int elementos) {
    int pos = -1, exisUser = 0, i = 0;

    while (i < elementos) { //Buscamos el nombre del vehiculo si existe
        if (!strncmp(id_usu, lista[i].Id_usuario, TAM_ID_USER)) {
            //exisUser = 1; //Si hay una concidencia guardamos y salimos
            printf("Nº ||Id matricula||Usuario||Descripción||Numero plaza");
            printf("\n : %d - |%*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n", 
                 i+1, lista[i].Id_mat ,lista[i].Id_usuario, lista[i].Desc_veh, lista[i].Num_plazas );
            pos = i;
        }
        i++;
    }
}




void listar_viajes_coche(Viajes* v, char matricula, int elementos){
    int pos = -1, exisUser = 0, i = 0;

    while (i < elementos) { //Buscamos el nombre del vehiculo si existe
        if (!strncmp(matricula, v[i].Id_mat, TAM_ID_VEI)) {
            //exisUser = 1; //Si hay una concidencia guardamos y salimos
            printf("Nº ||Id matricula||Usuario||Descripción||Numero plaza");
            printf("\n : %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",
                 i+1, v[i].Id_mat ,v[i].Id_viaje,v[i].F_inic v[i].H_inic, v[i].Sentido, v[i].Importe );
            pos = i;
        }
        i++;
    }

}




void menu_vehiculo(int opc, char *id,Viajes *via, Usuarios *ListaUsuarios, int *NumUser, Vehiculos* vh, int elementos) {
    int x, pos;
    char matricula;
   
    if (opc == 1) {
        do {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Alta vehiculo\n "
                    "2: Baja vehiculos\n "
                    "3: Listar vehiculos\n "
                    "4: Modificar vehiculos\n "
                    "5: Listar los viajes de un vehiculo"
                    "0: salir\n");
            x = leer_numero("Indica la opción");
            switch (x) {
                case 0:
                    break;
                case 1:                    
                    alta_vehiculo(Vehiculos* vh, int*elementos, char* NumUser);
                    break;
                case 2:
                    baja_vehiculo(Vehiculos*vh, int*elementos);
                    break;
                case 3:
                    vehiculos_user(char* id, Vehiculos* vh, int elementos);
                    break;
                case 4:
                    vehiculos_user(char*id, Vehiculos* vh, int elementos);
                    matricula=leer_campo(TAM_ID_VEI,"Escriba la matricula del vehiculo a modificar");
                    pos=buscar_vehiculo(char matricula, Vehiculos* vh, int elementos);
                    modificar_vehiculo(Vehiculos* vh,int pos);
                    break;
                case 5:
                    listar_viajes_coche(Viajes* via, char matricula, int elementos);
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    } else {
        
        do {
            printf("Bienvenido al menú de la aplicación %s\n "
                    "Introduzca la opcion que desea\n\n "
                    "1: Alta vehiculo\n "
                    "2: Baja vehiculos\n "
                    "3: Listas vehiculos(propios)\n "
                    "4: Modificar vehiculo\n "
                    "0: salir\n");
            x = leer_numero("Indica la opción");
            switch (x) {
                case 0:
                    break;
                case 1:
                     alta_vehiculo(Vehiculos* vh, int*elementos, char* NumUser);
                    break;
                case 2:
                    baja_vehiculo(Vehiculos*vh, int*elementos);
                    break;
                case 3:
                    vehiculos_user(char* id, Vehiculos* vh, int elementos);
                    break;
                case 4:
                    vehiculos_user(char*id, Vehiculos* vh, int elementos);
                    matricula=leer_campo(TAM_ID_VEI,"Escriba la matricula del vehiculo a modificar");
                    pos=buscar_vehiculo(char matricula, Vehiculos* vh, int elementos);
                    modificar_vehiculo(Vehiculos* vh,int pos);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    }
}


