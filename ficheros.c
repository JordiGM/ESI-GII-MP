/*
 * Códifgo encargado de leer los datos de los ficheros subiendolos a memoria y 
 * de escribir los ficheros
 * una vez se cierre la aplicación.
 * El funcionamieno del mismos es obtener cada linea del fichero e ir obteniendo
 *  los distintos datos del registro, almacenando los mismos en una estructura.
 */

/*
 *  * File:   ficheros.c
 * Author: Jordi Güeto Matavera
 *
 * Created on 21 de marzo de 2018, 16:42
 * 
 */

#include "ficheros.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//############################################
//##### Funciones de lectura de ficheros #####
//############################################

// Cabecera: Usuario* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector
Usuarios* obtenerUsuarios(int *n){
    Usuarios *alm;
    char *id, *nombre, *localidad, *perfil, *usuario, *login, *estado;

     FILE *fich;
     fich = fopen("Usuarios.txt", "r");
     if (fich==NULL) exit(1);

     while ( !feof(fich) ) {
           id = (char *) malloc( TAM_ID_USER+1*sizeof(char) );
           nombre = (char *) malloc( TAM_NOM_USER+1*sizeof(char) );
           localidad = (char *) malloc( TAM_LOC_USER+1*sizeof(char) );
           perfil = (char *) malloc( TAM_PER_USER+1*sizeof(char) );
           usuario = (char *) malloc( TAM_USE_USER+1*sizeof(char) );
           login = (char *) malloc( TAM_LOG_USER+1*sizeof(char) );
           estado = (char *) malloc( TAM_EST_USER+1*sizeof(char) );
           
           fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",
                   id, nombre, localidad, perfil, usuario, login, estado); // formato para que admita espacios

           if (! *n) alm = (Usuarios *) malloc( (*n+1) * sizeof(Usuarios) );
           else alm = (Usuarios *) realloc( alm, (*n+1) * sizeof(Usuarios) );
           printf("Registro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                   TAM_ID_USER, id,TAM_NOM_USER, nombre,TAM_LOC_USER, localidad,
                   TAM_PER_USER, perfil,TAM_USE_USER, usuario,TAM_LOG_USER, login,
                   TAM_EST_USER, estado);
           
           alm[*n].Id_usuario = id;
           alm[*n].Nomb_usuario = nombre;
           alm[*n].Localidad = localidad;
           alm[*n].Perfil_usuario = perfil;
           alm[*n].User = usuario;
           alm[*n].Login = login;
           alm[*n].Estado = estado;
           (*n)++;
     }

     fclose(fich);
     return alm;
}

//######################################
//##### Funciones de escritura de ficheros #####
//######################################

// Cabecera: void guardarDatosUsuario(Usuarios*,int)
// Precondicion: Recibe un vector con los usuarios que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector
void guardarDatosUsuarios(Usuarios* usuarios, int elementos){
    int i;
    Usuarios e;
    FILE *FICHERO_ALUMNO = fopen("Usuarios.txt", "w");
    for(i = 0; i < elementos; i++){
        e = usuarios[i];
        if(i == 0){
            fprintf(FICHERO_ALUMNO, "%s-%s-%s-%s-%s-%s-%s", e.Id_usuario, e.Nomb_usuario,e.Localidad,e.Perfil_usuario,e.User,e.Login,e.Estado);
        }else{
            fprintf(FICHERO_ALUMNO, "\n%s-%s-%s-%s-%s-%s-%s", e.Id_usuario, e.Nomb_usuario,e.Localidad,e.Perfil_usuario,e.User,e.Login,e.Estado);
        }

    }
    fclose(FICHERO_ALUMNO);
}


