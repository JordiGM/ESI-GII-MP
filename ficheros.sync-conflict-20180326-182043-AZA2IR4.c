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

//####################################
//##### Funciones de estructuras #####
//####################################

// Cabecera: Usuarios obtenerUsuario(char *)
// Precondicion: Se obtiene una linea del fichero
// Poscondicion: Crea un objeto de tipo Usuarios con la linea de texto y lo 
// devuelve
Usuarios obtenerUsuario(char *cadena){

    Usuarios u;

    char* texto;
    texto = strtok(cadena,"-");
    u.Id_usuario = atoi(texto);                                                 //La función atoi nos hace la conversion de char* a int
    texto = strtok(NULL, "-");
    strcpy(u.Nomb_usuario,texto);
    texto = strtok(NULL, "-");
    strcpy(u.Localidad,texto);
    //printf("%s",u.nombre);
    texto = strtok(NULL, "-");
    strcpy(u.Perfil_usuario,texto);
    texto = strtok(NULL, "-");
    strcpy(u.User,texto);
    texto = strtok(NULL, "-");
    strcpy(u.Login,texto);
    texto = strtok(NULL, "-");
    strcpy(u.Estado,texto);

    return u;
}

// Cabecera: Vehiculos obtenerVehiculo(char *)
// Precondicion: Se obtiene una linea del fichero
// Poscondicion: Crea un objeto de tipo Vehiculos con la linea de texto y lo 
// devuelve
Vehiculos obtenerVehiculo(char *cadena){

    Vehiculos v;
    char* texto;

    texto = strtok(cadena,"-");
    //strcpy(v.id_alumno,texto);
    texto = strtok(NULL, "-");
    //strcpy(v.nombre,texto);

    return v;
}

// Cabecera: Viajes obtenerViaje(char *)
// Precondicion: Se obtiene una linea del fichero
// Poscondicion: Crea un objeto de tipo Viajes con la linea de texto y lo 
// devuelve
Viajes obtenerViaje(char *cadena){

    Viajes v;
    char* texto;

    texto = strtok(cadena,"-");
    strcpy(v.Id_viaje,texto);
    texto = strtok(NULL, "-");
    strcpy(v.Id_mat,texto);
    texto = strtok(NULL, "-");
    strcpy(v.F_inic,texto);
    texto = strtok(NULL, "-");
    strcpy(v.H_inic,texto);
    texto = strtok(NULL, "-");
    strcpy(v.H_fin,texto);
    texto = strtok(NULL, "-");
    strcpy(v.Plazas_libre,texto);
    texto = strtok(NULL, "-");
    strcpy(v.Sentido,texto);
    texto = strtok(NULL, "-");
    strcpy(v.Importe,texto);
    texto = strtok(NULL, "-");
    strcpy(v.Estado,texto);

    return v;
}

// Cabecera: Pasos obtenerPaso(char *)
// Precondicion: Se obtiene una linea del fichero
// Poscondicion: Crea un objeto de tipo Pasos con la linea de texto y lo 
// devuelve
Pasos obtenerPaso(char *cadena){

    Pasos p;
    char* texto;

    texto = strtok(cadena,"-");
    //strcpy(p.id_alumno,texto);
    texto = strtok(NULL, "-");
    //strcpy(p.nombre,texto);

    return p;
}

// Cabecera: Incidencias obtenerIncidencia(char *)
// Precondicion: Se obtiene una linea del fichero
// Poscondicion: Crea un objeto de tipo Incidencias con la linea de texto y lo 
// devuelve
Incidencias obtenerIncidencia(char *cadena){

    Incidencias i;
    char* texto;

    texto = strtok(cadena,"-");
    //strcpy(i.id_alumno,texto);
    texto = strtok(NULL, "-");
    //strcpy(i.nombre,texto);

    return i;
}

//############################################
//##### Funciones de lectura de ficheros #####
//############################################

// Cabecera: Usuario* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector
Usuarios* obtenerUsuarios(int *n){
    FILE *FICHERO_USUARIO;
    *n=0;
    Usuarios *e = (Usuarios*) calloc(1,sizeof(Usuarios));

    if(FICHERO_USUARIO = fopen("Usuarios.txt", "r")){
        char *contenido = NULL;
        int ftam=0;
        fseek(FICHERO_USUARIO, 0, SEEK_END);
        ftam = ftell(FICHERO_USUARIO);
        rewind(FICHERO_USUARIO);

        contenido = (char*) calloc(ftam,sizeof(char*));
        fread(contenido, 1, ftam, FICHERO_USUARIO);

        //AUX ALMACENA TODAS LAS LINEAS
        char** aux = (char**) calloc(1,sizeof(char**));
        //Guard almacena una linea
        char* guard;

        guard=strtok(contenido,"\n");
        aux[*n] = (char*) malloc(sizeof(char**) * 20000);
        strcpy(aux[*n],guard);
        ++*n;
        e = (Usuarios*) realloc(e, *n*sizeof(Usuarios));

        while(guard!=NULL){
            guard=strtok(NULL,"\n");
            if(guard!=NULL){
                aux[*n] = (char*) malloc(sizeof(char**) * 20000);
                strcpy(aux[*n],guard);
                printf("%s\n",aux[*n]*);
                ++*n;
            }
        }
        
        int i;
        for(i=0;i<*n;i++){
            e = (Usuarios*) realloc(e, *n*2000*sizeof(Usuarios));
            e[i] = obtenerUsuario(aux[i]);
        }
        fclose(FICHERO_USUARIO);
    }

    return e;
}

//##############################################
//##### Funciones de escritura de ficheros #####
//##############################################

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
