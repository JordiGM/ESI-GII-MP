#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct{
    char *Id_viaje;
    char *Id_mat;
    char *F_inic;
    char *H_inic;
    char *H_fin;
    char *Plazas_libre;
    char *Sentido;
    char *Importe;
    char *Estado;
}Viaje;

void publicar_viaje(Viaje *lista);
void eliminar_viaje(Viaje *lista);
void modificar_viaje(Viaje *lista);
void listar_viaje(Viaje *lista);
void menu_viaje();

#endif //VIAJE_H_INCLUDED 