#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

int buscar_viaje(char *id, Viajes *lista, int elementos);
void publicar_viaje(Viajes *lista, int *elementos, char *viaje, char *id);
void eliminar_viaje(Viajes *lista, int *elementos);
void modificar_viaje(Viajes *lista);
void listar_viaje(Viajes *lista, int elementos);
void autoFinalizarViaje(Viajes *lista, int elementos);

#endif //VIAJE_H_INCLUDED 