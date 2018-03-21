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
    int Id_usuario[4];
    char Nomb_usuario[21];
    char Localidad[21];
    int Perfil_usuario;
    char User[6];
    char Login[9];
    int Estado;
    
}usuarios;

#endif /* USUARIOS_H */

