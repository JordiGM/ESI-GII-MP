#ifndef VEHICULOS_H
#define VEHICULOS_H

void alta_vehiculo(Vehiculos*, int*, char*);
void baja_vehiculo(Vehiculos* ,int);
void modificar_vehiculo(Vehiculos*,int);
int buscar_vehiculo(char*, Vehiculos*, int);
void vehiculos_user(char*, Vehiculos*, int);
void listar_viajes_coche(Viajes* , char*, int );

#endif

