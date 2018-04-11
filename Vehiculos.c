/*
 * listar vehiculos :)
 * alta vehiculo    :)
 * baja vehiculo
 * modificar vehiculo
 * mostrar viajes realizados por un vehiculo
 *hacer un menu 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Vehiculo.h"
#include"ficheros.h"
#include"comun.h"
//prototipos
//void listar_vehiculos();
void listar_vehiculos(Vehiculos* );
void menu_vehiculo();


void listar_vehiculos(Vehiculo* vh){
    int i,N=10;
     
    for(i=0; i<N; i++) {
        printf("%i: %s-%s-%s-%s", i+1, vh.Id_mat ,vh.Id_usuario, vh.Desc_veh, vh.Num_plazas );
    }
}



void *alta_vehiculo(Vehiculo *vh,int *elementos,char *usuario){
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
    vh = (Vehiculo *) realloc( vh, (*elementos+1) * sizeof(Vehiculo) );
    
    //Guardamos la información recogida y generada en el nuevo elemento    
    sprintf(id, "%04d", *elementos+1);                                          //Transofrmamos el ultimo id + 1 en una cadena tipo 0001 
    vh[*elementos].Id_mat = id_mat;
    vh[*elementos].Id_usuario = usuario;
    vh[*elementos].Desc_veh = descripcion;
    vh[*elementos].Num_plazas = num_plazas;
    (*elementos)++;
////////////////////////////////////
}





void baja_vehiculo(Vehiculo* vh){
    char matricula[7];
    
    matricula=*leer_campo(7,"inserte matricula del vehiculo a eliminar;\n");
    
   //necesita encontrar el coche en el vector
   //necesita borrar el campo entero y reajustar el vector
    
       
}

void menu_vehiculo() {
    int o;
    Vehiculo *vehiculo;
    
   
    
    do {
        printf("Introduzca la opcion que desea:\n1.- Alta vehiculo.\n2.- Eliminar vehiculo.\n3.- Modificar vehiculo.\n4.- Listar viajes.\n0.- Salir.");
        scanf("%d", &o);
        switch(o) {
            case 0:
                exit(0);
                break;
            case 1:
                publicar_viaje();
                break;
            case 2:
                eliminar_viaje();
                break;
            case 3:
                modificar_viaje();
                break;
            case 4:
                listar_viaje();
                break;
            default:
                printf("ERROR: Opcion invalida.");
                break;
        }
    } while(o!=0);
    fflush(stdin);
    return;
}