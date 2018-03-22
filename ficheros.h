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
    int Id_usuario[4];
    char Nomb_usuario[21];
    char Localidad[21];
    int Perfil_usuario;
    char User[6];
    char Login[9];
    int Estado;    
}Usuarios;

typedef struct{
    
}Vehiculos;

typedef struct{
    int Id_viaje[6];
    char Id_mat[7];
    char F_inic[10];
    char H_inic[5];
    char H_fin[5];
    int Plazas_libre[1];
    char Sentido[6];
    char Importe[7];
    char Estado[10];
}Viajes;

typedef struct{
    
}Pasos;

typedef struct{
    
}Incidencias;

//Funciones

Usuarios* obtenerUsuarios(int *n);
Vehiculos* obtenerVehiculos(int *n);
Viajes* obtenerViajes(int *n);
Pasos* obtenerPasos(int *n);
Incidencias* obtenerIncidencias(int *n);

void guardarDatosUsuarios(Usuarios* usuarios, int elementos);
void guardarDatosVehiculos(Vehiculos* vehiculos, int elementos);
void guardarDatosViajes(Viajes* viajes, int elementos);
void guardarDatosPasos(Pasos* pasos, int elementos);
void guardarDatosIncidencias(Incidencias* incidencias, int elementos);

#endif /* FICHEROS_H */

