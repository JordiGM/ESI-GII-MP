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
    char *id, *nombre, *localidad, *perfil, *usuario, *login, *estado, *eliminado;

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
        eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, nombre, localidad, perfil, usuario, login, estado,eliminado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Usuarios *) malloc((*n + 1) * sizeof (Usuarios)); //Reserva memoria para el primer elemento
        else alm = (Usuarios *) realloc(alm, (*n + 1) * sizeof (Usuarios)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n", *n,
                TAM_ID_USER, id, TAM_NOM_USER, nombre, TAM_LOC_USER, localidad,
                TAM_PER_USER, perfil, TAM_USE_USER, usuario, TAM_LOG_USER, login,
                TAM_EST_USER, estado,TAM_ELIMINADO, eliminado);

        alm[*n].Id_usuario = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Nomb_usuario = nombre;
        alm[*n].Localidad = localidad;
        alm[*n].Perfil_usuario = perfil;
        alm[*n].User = usuario;
        alm[*n].Login = login;
        alm[*n].Estado = estado;
        alm[*n].Eliminado = eliminado;
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
    char *id, *IdUser, *plazas, *descripcion, *eliminado;

    FILE *fich;
    fich = fopen("Vehiculos.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        IdUser = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        plazas = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));
        descripcion = (char *) malloc(TAM_DES_VEI + 1 * sizeof (char));
        eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdUser, plazas, descripcion,eliminado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Vehiculos *) malloc((*n + 1) * sizeof (Vehiculos)); //Reserva memoria para el primer elemento
        else alm = (Vehiculos *) realloc(alm, (*n + 1) * sizeof (Vehiculos)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n", *n,
                TAM_ID_VEI, id, TAM_ID_USER, IdUser, TAM_PLA_VEI, plazas, TAM_DES_VEI, descripcion, TAM_ELIMINADO, eliminado);

        alm[*n].Id_mat = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_usuario = IdUser;
        alm[*n].Num_plazas = plazas;
        alm[*n].Desc_veh = descripcion;
        alm[*n].Eliminado = eliminado;
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
    char *id, *IdMat, *FecIni, *HorIni, *HorFin, *plazas, *sentido, *importe, *estado, *eliminado;

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
        eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdMat, FecIni, HorIni, HorFin, plazas, sentido, importe, estado,eliminado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Viajes *) malloc((*n + 1) * sizeof (Viajes)); //Reserva memoria para el primer elemento
        else alm = (Viajes *) realloc(alm, (*n + 1) * sizeof (Viajes)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
                   printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n",*n, 
                           TAM_ID_VIA, id,TAM_ID_VEI, IdMat,TAM_FIN_VIA, FecIni,
                           TAM_HIN_VIA, HorIni,TAM_HFI_VIA, HorFin,TAM_PLA_VEI, plazas,
                           TAM_SEN_VIA, sentido, TAM_IMP_VIA, importe, TAM_EST_VIA, estado, TAM_ELIMINADO, eliminado);

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_mat = IdMat;
        alm[*n].F_inic = FecIni;
        alm[*n].H_inic = HorIni;
        alm[*n].H_fin = HorFin;
        alm[*n].Plazas_libre = plazas;
        alm[*n].Sentido = sentido;
        alm[*n].Importe = importe;
        alm[*n].Estado = estado;
        alm[*n].Eliminado = eliminado;
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
    char *id, *poblacion,*eliminado;

    FILE *fich;
    fich = fopen("Pasos.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        poblacion = (char *) malloc(TAM_POB_PAS + 1 * sizeof (char));
        eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));
        
        fscanf(fich, "%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, poblacion,eliminado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Pasos *) malloc((*n + 1) * sizeof (Pasos)); //Reserva memoria para el primer elemento
        else alm = (Pasos *) realloc(alm, (*n + 1) * sizeof (Pasos)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        printf("\nRegistro recuperado: %d - |%*s| - |%*s| - |%-*s| >>> OK\n", *n,
                TAM_ID_VIA, id, TAM_POB_PAS, poblacion, TAM_ELIMINADO, eliminado);

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Poblacion = poblacion;
        alm[*n].Eliminado = eliminado;
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
    char *id, *IdUsReg, *IdUsInc, *descripcion, *estado, *eliminado;

    FILE *fich;
    fich = fopen("Incidencias.txt", "r");
    if (fich == NULL) exit(1); //Comprobamos que se haya podido abrir el fichero

    while (!feof(fich)) { //Mientras no hayamos llegado al final del fichero
        id = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char)); //Reservamos espacio de memoria para las distintas cadenas
        IdUsReg = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        IdUsInc = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
        descripcion = (char *) malloc(TAM_DES_INC + 1 * sizeof (char));
        estado = (char *) malloc(TAM_EST_INC + 1 * sizeof (char));
        eliminado = (char *) malloc(TAM_ELIMINADO + 1 * sizeof (char));

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", //formato para que admita espacios
                id, IdUsReg, IdUsInc, descripcion, estado, eliminado); //Lee cada linea con el formato y lo alamcena en las variables

        if (! *n) alm = (Incidencias *) malloc((*n + 1) * sizeof (Incidencias)); //Reserva memoria para el primer elemento
        else alm = (Incidencias *) realloc(alm, (*n + 1) * sizeof (Incidencias)); //Reserva memoria para los elementos restantes

        //Visualiza cada regisrtro que recupera del fichero
        printf("\nRegistro recuperado: %d - |%*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| - |%-*s| >>> OK\n", *n,
                TAM_ID_VIA, id, TAM_ID_USER, IdUsReg, TAM_ID_USER, IdUsInc,
                TAM_DES_INC, descripcion, TAM_EST_INC, estado, TAM_ELIMINADO, eliminado);

        alm[*n].Id_viaje = id; //Asiganamos los valores recogidos al elemento
        alm[*n].Id_us_registra = IdUsReg;
        alm[*n].Id_us_incidencia = IdUsInc;
        alm[*n].Desc_incidencia = descripcion;
        alm[*n].Est_incidencia = estado;
        alm[*n].Eliminado = eliminado;
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
    FILE *FicheroUsuario = fopen("Usuarios_out.txt", "w"); //Preparamos el fichero para ser escrito
    for (i = 0; i < elementos; i++) { //Vamos accediento a cada elemento
        e = usuarios[i];
        if (i == 0) {
            //Para escribir el primer elemento
            fprintf(FicheroUsuario, "%s-%s-%s-%s-%s-%s-%s-%s", 
                    e.Id_usuario, e.Nomb_usuario, e.Localidad, e.Perfil_usuario, 
                    e.User, e.Login, e.Estado, e.Eliminado);
        } else {
            //Para escribir las demas lineas
            fprintf(FicheroUsuario, "\n%s-%s-%s-%s-%s-%s-%s-%s", 
                    e.Id_usuario, e.Nomb_usuario, e.Localidad, e.Perfil_usuario, 
                    e.User, e.Login, e.Estado, e.Eliminado);
        }

    }
    fclose(FicheroUsuario);
}

// Cabecera: void guardarDatosVehiculos(Vehiculos*,int)
// Precondicion: Recibe un vector con los vehiculos que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector

void guardarDatosVehiculos(Vehiculos* vehiculos, int elementos) {
    int i;
    Vehiculos e;
    FILE *FichVehiculo = fopen("Vehiculos_out.txt", "w"); //Preparamos el fichero para ser escrito
    for (i = 0; i < elementos; i++) { //Vamos accediento a cada elemento
        e = vehiculos[i];
        if (i == 0) {
            //Para escribir el primer elemento
            fprintf(FichVehiculo, "%s-%s-%s-%s-%s", 
                    e.Id_mat, e.Id_usuario, e.Num_plazas, e.Desc_veh, e.Eliminado);
        } else {
            //Para escribir las demas lineas
            fprintf(FichVehiculo, "\n%s-%s-%s-%s-%s", 
                    e.Id_mat, e.Id_usuario, e.Num_plazas, e.Desc_veh, e.Eliminado);
        }

    }
    fclose(FichVehiculo);
}

// Cabecera: void guardarDatosViajes(Viajes*,int)
// Precondicion: Recibe un vector con los viajes que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector

void guardarDatosViajes(Viajes* viajes, int elementos) {
    int i;
    Viajes e;
    FILE *FichViajes = fopen("Viajes_out.txt", "w"); //Preparamos el fichero para ser escrito
    for (i = 0; i < elementos; i++) { //Vamos accediento a cada elemento
        e = viajes[i];
        if (i == 0) {
            //Para escribir el primer elemento
            fprintf(FichViajes, "%s-%s-%s-%s-%s-%s-%s-%s-%s-%s", 
                    e.Id_viaje, e.Id_mat, e.F_inic, e.H_inic, e.H_fin, e.Plazas_libre, 
                    e.Sentido, e.Importe, e.Estado, e.Eliminado);
        } else {
            //Para escribir las demas lineas
            fprintf(FichViajes, "\n%s-%s-%s-%s-%s-%s-%s-%s-%s-%s", 
                    e.Id_viaje, e.Id_mat, e.F_inic, e.H_inic, e.H_fin, e.Plazas_libre, 
                    e.Sentido, e.Importe, e.Estado, e.Eliminado);
        }

    }
    fclose(FichViajes);
}

// Cabecera: void guardarDatosPasos(Pasos*,int)
// Precondicion: Recibe un vector con los pasos que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector

void guardarDatosPasos(Pasos* pasos, int elementos) {
    int i;
    Pasos e;
    FILE *FichPasos = fopen("Pasos_out.txt", "w"); //Preparamos el fichero para ser escrito
    for (i = 0; i < elementos; i++) { //Vamos accediento a cada elemento
        e = pasos[i];
        if (i == 0) {
            //Para escribir el primer elemento
            fprintf(FichPasos, "%s-%s-%s", e.Id_viaje, e.Poblacion, e.Eliminado);
        } else {
            //Para escribir las demas lineas
            fprintf(FichPasos, "\n%s-%s-%s", e.Id_viaje, e.Poblacion, e.Eliminado);
        }

    }
    fclose(FichPasos);
}

// Cabecera: void guardarDatosIncidencias(Incidencias*,int)
// Precondicion: Recibe un vector con las incidencias que deseamos guardar y un int 
// con el tamano del vector
// Poscondicion: Guarda en el fichero el vector

void guardarDatosIncidencias(Incidencias* incidencias, int elementos) {
    int i;
    Incidencias e;
    FILE *FichIncidencias = fopen("Incidencias_out.txt", "w"); //Preparamos el fichero para ser escrito
    for (i = 0; i < elementos; i++) { //Vamos accediento a cada elemento
        e = incidencias[i];
        if (i == 0) {
            //Para escribir el primer elemento
            fprintf(FichIncidencias, "%s-%s-%s-%s-%s-%s",
                    e.Id_viaje, e.Id_us_registra, e.Id_us_incidencia, e.Desc_incidencia, 
                    e.Est_incidencia, e.Eliminado);
        } else {
            //Para escribir las demas lineas
            fprintf(FichIncidencias, "\n%s-%s-%s-%s-%s-%s",
                    e.Id_viaje, e.Id_us_registra, e.Id_us_incidencia, e.Desc_incidencia, 
                    e.Est_incidencia, e.Eliminado);
        }

    }
    fclose(FichIncidencias);
}
