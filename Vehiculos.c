/*
 * listar vehiculos :)
 * alta vehiculo
 * baja vehiculo
 * modificar vehiculo
 * mostrar viajes realizados por un vehiculo
 * 
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










void listar_vehiculos(Vehiculo* vh){
    int i,N=10;
     
    for(i=0; i<N; i++) {
        printf("%i: %s-%s-%s-%s", i+1, vh.Id_mat ,vh.Id_usuario, vh.Desc_veh, vh.Num_plazas );
    }
}


void alta_vehiculo(Vehiculo* vh){
    vh.Id_mat=*leercampo(TAM_ID_VEI,"Inserte numero de la matricula:");




}