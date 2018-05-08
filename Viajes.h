#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

int buscar_viaje(char *id, Viajes *lista, int elementos);
void publicar_viaje(Viajes *lista, int *elementos, char *viaje, char *id);
void eliminar_viaje(Viajes *lista, int *elementos);
void modificar_viaje(Viajes *lista);
void listar_viaje(Viajes *lista, int elementos);
void autoFinalizarViaje(Viajes *lista, int elementos);
void publicar_paso(Pasos*, int*, char*);
void eliminar_paso(Pasos*, int*, char*,char*);
void listar_paso(Pasos*, int*, char*);

#endif //VIAJE_H_INCLUDED 