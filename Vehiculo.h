/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: gemac
 *
 * Created on 21 de marzo de 2018, 17:05
 */

#ifndef VEHICULO_H
#define VEHICULO_H

typedef struct{
    char* Id_mat;
    char* Id_usuario;
    char* Num_plazas;
    char* Desc_veh;

} Vehiculo;


void listar_vehiculos(Vehiculos*);

#endif

