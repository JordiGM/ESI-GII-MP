#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct{
    int Id_viaje[6];
    char Id_mat[7];
    char F_inic[10];
    char H_inic[5];
    char H_fin[5];
    int Plazas_libre[1];
    char Sentido[6];
    char Importe[7];
    char Estado[10];
}Viaje;

void publicar_viaje(Viaje *lista);
void eliminar_viaje(Viaje *lista);
void modificar_viaje(Viaje *lista);
void listar_viaje(Viaje *lista);

#endif //VIAJE_H_INCLUDED