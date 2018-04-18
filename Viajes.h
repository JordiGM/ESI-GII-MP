#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

void publicar_viaje(Viajes *lista);
void eliminar_viaje(Viajes *lista);
void modificar_viaje(Viajes *lista);
void listar_viaje(Viajes *lista);
void autoFinalizarViaje(Viajes *lista, int elementos);
void menu_viaje(Viajes *lista, Vehiculos *lista, int *n, int *m, char *c);

#endif //VIAJE_H_INCLUDED 