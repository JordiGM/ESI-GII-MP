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
typedef struct{
    char* Id_usuario;
    char* Nomb_usuario;
    char* Localidad;
    char*Perfil_usuario;
    char* User;
    char* Login;//contra
    char* Estado;
    
}Usuarios;

void mostrar_datos(char*);

#endif /* USUARIOS_H */

