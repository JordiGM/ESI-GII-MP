/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuarios.h
 * Author: Adri
 *
 * Created on 21 de marzo de 2018, 17:02
 */

#ifndef USUARIOS_H
#define USUARIOS_H
void modificaUsuario(Usuarios*,int*);
void modificaAdmin(Usuarios*,int);
void mostrarUsuario(Usuarios*, int*);
//Funciones hechas por Jordi
int buscar_usuario(char*,Usuarios*,int);
char *altaUsuarioInicio(Usuarios *, int *, char *);
char *altaUsuario(Usuarios *, int *); 
void bajaUsuario(Usuarios *, int *);
void listarUsuario(Usuarios *, int *); 
void login(Usuarios *, int *);
void menu_usuario(int, char *, Usuarios *, int *);

#endif /* USUARIOS_H */

