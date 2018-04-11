/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "comun.h"
#include"Usuarios.h"
#include<stdio.h>
#include<stdlib.h>

void registrar_usuario(char*,){
    
}
void mostrar_datos(int num_usu ){
    printf("ID:%s\nNombre:%s\nLocalidad:%s\nTipo Perfil:%s\nUsuario:%s\nContraseña:%s\nEstado:%s\n"),usuarios.Id_usuario,usuarios.Localidad),usuarios.Perfil_usuario,usuarios.Nomb_usuario,usuarios.Login,usuarios.Estado;
    
}
//menu pa editar info ya sea usuario o admin
void menu_editar(char* id){
    printf("seleccione que quiere editar:\n1-")
}
//funcion que va a ir dentro del menu

void editar_usuario(char* id, Usuarios *lista, int *nelem){
    int 
    buscar_usuario(id,lista,nelem);
    lista[].User[id]=leercampo(TAM_USE_USER,"insertar nombre usuario");
}