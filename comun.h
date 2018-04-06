/*
 * Funciones comunes a los modulos
 */

/* 
 * File:   comun.h
 * Author: Jordi Güeto Matavera
 *
 * Created on 4 de abril de 2018, 16:27
 */

#ifndef COMUN_H
#define COMUN_H

//Temporal para la funcion de Adri
char *altaUsuarioInicio(Usuarios *, int *, char *);

//Prototipos
char *leer_campo( int, char * );
int leer_numero( char * );
int buscar_usuario(char*,Usuarios*,int);
void vacia_buffer();

#endif /* COMUN_H */

