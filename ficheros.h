/*
 * Cabecera de estructuras de la aplicación y declaración de funciones del fichero
 * c para leer los archivos de datos.
 */

/* 
 * File:   ficheros.h
 * Author: Jordi Güeto Matavera
 *
 * Created on 21 de marzo de 2018, 16:28
 */

#ifndef FICHEROS_H
#define FICHEROS_H

// TIPOS
typedef struct{
    char* Id_usuario;
    char* Nomb_usuario;
    char* Localidad;
    char* Perfil_usuario;
    char* User;
    char* Login;
    char* Estado;  
    char* Eliminado;
}Usuarios;
//Dimensiones de Usuarios
#define TAM_ID_USER 4
#define TAM_NOM_USER 20
#define TAM_LOC_USER 20
#define TAM_PER_USER 13
#define TAM_USE_USER 5
#define TAM_LOG_USER 8
#define TAM_EST_USER 9
#define TAM_ELIMINADO 2

typedef struct{
    char* Id_mat;
    char* Id_usuario;
    char* Num_plazas;
    char* Desc_veh;
    char* Eliminado;
}Vehiculos;
//Dimensiones vehiculos
#define TAM_ID_VEI 7
#define TAM_PLA_VEI 1
#define TAM_DES_VEI 50

typedef struct{
    char *Id_viaje;
    char *Id_mat;
    char *F_inic;
    char *H_inic;
    char *H_fin;
    char *Plazas_libre;
    char *Sentido;
    char *Importe;
    char *Estado;
    char* Eliminado;
}Viajes;
//Dimensiones viajes
#define TAM_ID_VIA 6
#define TAM_FIN_VIA 10
#define TAM_HIN_VIA 5
#define TAM_HFI_VIA 5
#define TAM_SEN_VIA 6
#define TAM_IMP_VIA 6
#define TAM_EST_VIA 10


typedef struct{
    char *Id_viaje;
    char *Poblacion;
}Pasos;
//Dimensiones pasos
#define TAM_POB_PAS 20

typedef struct{
    char *Id_viaje;
    char *Id_us_registra;
    char *Id_us_incidencia;
    char *Desc_incidencia;
    char *Est_incidencia;
    char* Eliminado;
}Incidencias;
//Dimensiones incidencias
#define TAM_DES_INC 100
#define TAM_EST_INC 8


//Prototipos

Usuarios* obtenerUsuarios(int *);
Vehiculos* obtenerVehiculos(int *);
Viajes* obtenerViajes(int *);
Pasos* obtenerPasos(int *);
Incidencias* obtenerIncidencias(int *);

void guardarDatosUsuarios(Usuarios*, int);
void guardarDatosVehiculos(Vehiculos*, int);
void guardarDatosViajes(Viajes*, int);
void guardarDatosPasos(Pasos*, int);
void guardarDatosIncidencias(Incidencias*, int);

#endif /* FICHEROS_H */

