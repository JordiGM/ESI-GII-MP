#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

int buscar_viaje(char *, Viajes *, int );
void publicar_viaje(Viajes *, int *, char *, char *);
void eliminar_viaje(Viajes *, int *);
void modificar_viaje(Viajes *);
void listar_viaje(Viajes *, int , Pasos *, int *);
void listar_viaje_usuario(Viajes* , int , Usuarios* , char* );
char* conductor_viaje(Viajes* , int , Vehiculos* );
void autoFinalizarViaje(Viajes *, int );
void publicar_paso(Pasos*, int*, char*);
void eliminar_paso(Pasos*, int*, char*,char*);
void listar_paso(Pasos*, int*, char*);
void unirse_viaje (Viajes*, int*, char* id);

#endif //VIAJE_H_INCLUDED 