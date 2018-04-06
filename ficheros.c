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

// Cabecera: Usuarios* obtenerUsuarios(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los usuarios y en el parametro almacena 
// el tamano del vector

Usuarios* obtenerUsuarios(int *n) {
    Usuarios *alm;
    char *id, *nombre, *localidad, *perfil, *usuario, *login, *estado;

    FILE *fich;
    fich = fopen("Usuarios.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_USER + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        nombre = (char *) malloc(TAM_NOM_USER + 1 * sizeof (char));
        localidad = (char *) malloc(TAM_LOC_USER + 1 * sizeof (char));
        perfil = (char *) malloc(TAM_PER_USER + 1 * sizeof (char));
        usuario = (char *) malloc(TAM_USE_USER + 1 * sizeof (char));
        login = (char *) malloc(TAM_LOG_USER + 1 * sizeof (char));
        estado = (char *) malloc(TAM_EST_USER + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, nombre, localidad, perfil, usuario, login, estado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Usuarios *) malloc((*n + 1) * sizeof (Usuarios)); //Reserva memoria para el primer elemento
        else alm = (Usuarios *) realloc(alm, (*n + 1) * sizeof (Usuarios)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        /*
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_USER, id,TAM_NOM_USER, nombre,TAM_LOC_USER, localidad,
                           TAM_PER_USER, perfil,TAM_USE_USER, usuario,TAM_LOG_USER, login,
                           TAM_EST_USER, estado);
         */

        alm[*n].Id_usuario = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Nomb_usuario = nombre;
        alm[*n].Localidad = localidad;
        alm[*n].Perfil_usuario = perfil;
        alm[*n].User = usuario;
        alm[*n].Login = login;
        alm[*n].Estado = estado;
        (*n)++; //Aumentamos el numero de elementos del array
    }

    fclose(fich);
    return alm;
}


// Cabecera: Vehiculos* obtenerVehiculos(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los vehiculos y en el parametro almacena 
// el tamano del vector

Vehiculos* obtenerVehiculos(int *n) {
    Vehiculos *alm;
    char *id, *IdUser, *plazas, *descripcion;

    FILE *fich;
    fich = fopen("Vehiculos.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        IdUser = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        plazas = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));
        descripcion = (char *) malloc(TAM_DES_VEI + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdUser, plazas, descripcion); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Vehiculos *) malloc((*n + 1) * sizeof (Vehiculos)); //Reserva memoria para el primer elemento
        else alm = (Vehiculos *) realloc(alm, (*n + 1) * sizeof (Vehiculos)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        /*
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_VEI, id,TAM_ID_USER, IdUser,TAM_PLA_VEI, plazas,TAM_DES_VEI, descripcion);
         */

        alm[*n].Id_mat = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_usuario = IdUser;
        alm[*n].Num_plazas = plazas;
        alm[*n].Desc_veh = descripcion;
        (*n)++; //Aumentamos el numero de elementos del array
    }

    fclose(fich);
    return alm;
}

// Cabecera: Viajes* obtenerViajes(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los viajes y en el parametro almacena 
// el tamano del vector

Viajes* obtenerViajes(int *n) {
    Viajes *alm;
    char *id, *IdMat, *FecIni, *HorIni, *HorFin, *plazas, *sentido, *importe, *estado;

    FILE *fich;
    fich = fopen("Viajes.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        IdMat = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char));
        FecIni = (char *) malloc(TAM_FIN_VIA + 1 * sizeof (char));
        HorIni = (char *) malloc(TAM_HIN_VIA + 1 * sizeof (char));
        HorFin = (char *) malloc(TAM_HFI_VIA + 1 * sizeof (char));
        plazas = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));
        sentido = (char *) malloc(TAM_SEN_VIA + 1 * sizeof (char));
        importe = (char *) malloc(TAM_IMP_VIA + 1 * sizeof (char));
        estado = (char *) malloc(TAM_EST_VIA + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdMat, FecIni, HorIni, HorFin, plazas, sentido, importe, estado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Viajes *) malloc((*n + 1) * sizeof (Viajes)); //Reserva memoria para el primer elemento
        else alm = (Viajes *) realloc(alm, (*n + 1) * sizeof (Viajes)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        /*
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_USER, id,TAM_NOM_USER, nombre,TAM_LOC_USER, localidad,
                           TAM_PER_USER, perfil,TAM_USE_USER, usuario,TAM_LOG_USER, login,
                           TAM_EST_USER, estado);
         */

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_mat = IdMat;
        alm[*n].F_inic = FecIni;
        alm[*n].H_inic = HorIni;
        alm[*n].H_fin = HorFin;
        alm[*n].Plazas_libre = plazas;
        alm[*n].Sentido = sentido;
        alm[*n].Importe = importe;
        alm[*n].Estado = estado;
        (*n)++; //Aumentamos el numero de elementos del array
    }

    fclose(fich);
    return alm;
}

// Cabecera: Pasos* obtenerPasos(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los pasos y en el parametro almacena 
// el tamano del vector

Pasos* obtenerPasos(int *n) {
    Pasos *alm;
    char *id, *poblacion;

    FILE *fich;
    fich = fopen("Pasos.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        poblacion = (char *) malloc(TAM_POB_PAS + 1 * sizeof (char));
        
        fscanf(fich, "%[^-]-%[^\n]\n", //formato para que admita espacios
                id, poblacion); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Pasos *) malloc((*n + 1) * sizeof (Pasos)); //Reserva memoria para el primer elemento
        else alm = (Pasos *) realloc(alm, (*n + 1) * sizeof (Pasos)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        /*
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_USER, id,TAM_NOM_USER, nombre,TAM_LOC_USER, localidad,
                           TAM_PER_USER, perfil,TAM_USE_USER, usuario,TAM_LOG_USER, login,
                           TAM_EST_USER, estado);
         */

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Poblacion = poblacion;
        (*n)++; //Aumentamos el numero de elementos del array
    }

    fclose(fich);
    return alm;
}

// Cabecera: Incidencias* obtenerViajes(int*)
// Precondicion: el int que recibe debe estar declarado ya que almacenará el 
// numero de elementos del vector dinamico
// Poscondicion: devuelve el vector de los incidencias y en el parametro almacena 
// el tamano del vector

Incidencias* obtenerIncidencias(int *n) {
    Incidencias *alm;
    char *id, *IdUsReg, *IdUsInc, *descripcion, *estado;

    FILE *fich;
    fich = fopen("Incidencia.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        IdUsReg = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        IdUsInc = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        descripcion = (char *) malloc(TAM_DES_INC + 1 * sizeof (char));
        estado = (char *) malloc(TAM_EST_INC + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdUsReg, IdUsInc, descripcion, estado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Incidencias *) malloc((*n + 1) * sizeof (Incidencias)); //Reserva memoria para el primer elemento
        else alm = (Incidencias *) realloc(alm, (*n + 1) * sizeof (Incidencias)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        /*
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_USER, id,TAM_NOM_USER, nombre,TAM_LOC_USER, localidad,
                           TAM_PER_USER, perfil,TAM_USE_USER, usuario,TAM_LOG_USER, login,
                           TAM_EST_USER, estado);
         */

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_us_registra = IdUsReg;
        alm[*n].Id_us_incidencia = IdUsInc;
        alm[*n].Desc_incidencia = descripcion;
        alm[*n].Est_incidencia = estado;
        (*n)++; //Aumentamos el numero de elementos del array
    }

    fclose(fich);
    return alm;
}


//##############################################
//##### Funciones de escritura de ficheros #####
//##############################################

// Cabecera: void guardarDatosUsuario(Usuarios*,int)
// Precondicion: Recibe un vector con los usuarios que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector

void guardarDatosUsuarios(Usuarios* usuarios, int elementos) {
    int i;
    Usuarios e;
    FILE *FICHERO_ALUMNO = fopen("Usuarios.txt", "w");
    for (i = 0; i < elementos; i++) {
        e = usuarios[i];
        if (i == 0) {
            fprintf(FICHERO_ALUMNO, "%s-%s-%s-%s-%s-%s-%s", e.Id_usuario, e.Nomb_usuario, e.Localidad, e.Perfil_usuario, e.User, e.Login, e.Estado);
        } else {
            fprintf(FICHERO_ALUMNO, "\n%s-%s-%s-%s-%s-%s-%s", e.Id_usuario, e.Nomb_usuario, e.Localidad, e.Perfil_usuario, e.User, e.Login, e.Estado);
        }

    }
    fclose(FICHERO_ALUMNO);
}


