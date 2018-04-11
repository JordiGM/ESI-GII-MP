#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Viajes.h"
#include "ficheros.h"
#define __USE_XOPEN

/*Cabecera: void publicar_viaje(Viaje*)
Precondición: Recibe cadenas de carácteres de un viaje.
Postcondición: Permite al ususario publicar un nuevo viaje.*/

void *publicar_viaje(Viaje *v, int *elementos, char *viaje){
    char *Id_viaje, *Id_mat, *F_inic, *H_inic, *H_fin, *Plazas_libre, *Sentido, *Importe, *Estado;
        
    /*Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena*/
    Id_viaje = (char *) malloc (TAM_ID_VIA +1*sizeof(char));
    Id_mat = (char *) malloc (TAM_ID_VEI +1*sizeof(char));
    F_inic = (char *) malloc (TAM_FIN_VIA +1*sizeof(char));
    H_inic = (char *) malloc (TAM_HIN_VIA +1*sizeof(char));
    H_fin = (char *) malloc (TAM_HFI_VIA +1*sizeof(char));
    Plazas_libre = (char *) malloc (TAM_PLA_VEI +1*sizeof(char));
    Sentido = (char *) malloc (TAM_SEN_VIA +1*sizeof(char));
    Importe = (char *) malloc (TAM_IMP_VIA +1*sizeof(char));
    Estado = (char *) malloc (TAM_EST_VIA +1*sizeof(char));
        
    /*Mostramos informacion que se le solicita al usuario y la recogemos*/
    Id_mat = leer_campo(TAM_ID_VEI, "Inserte la matricula del vehiculo: \n");
    F_inic = leer_campo(TAM_FIN_VIA, "Inserte la fecha en la que se producira el viaje: \n");
    H_inic = leer_campo(TAM_HIN_VIA, "Inserte la hora a la que se iniciara el viaje: \n");
    H_fin = leer_campo(TAM_HFI_VIA, "Inserte la hora a la que finalizará el viaje: \n");
    Sentido = leer_campo(TAM_SEN_VIA, "Inserte el sentido en el que ira el viaje (ida o vuelta): \n");
    Importe = leer_campo(TAM_IMP_VIA, "Inserte el importe del viaje: \n");
    Estado = leer_campo(TAM_EST_VIA, "Inserte el estado del viaje (abierto, cerrado, iniciado, finalizado o anulado): \n");
        
    /*Obtenemos memoria para un nuevo elemento*/
    v = (Viaje *) realloc(v, (*elementos+1) * sizeof(Viaje));
        
    /*Guardamos la informacionrecogida y generada en el nuevo elemento*/
    sprintf(Id_viaje, "%06d", *elementos+1);
    v[*elementos].Id_mat = Id_mat;
    v[*elementos].F_inic = F_inic;
    v[*elementos].H_inic = H_inic;
    v[*elementos].H_fin = H_fin;
    v[*elementos].Sentido = Sentido;
    v[*elementos].Importe = Importe;
    v[*elementos].Estado = Estado;
    (*elementos)++;
}

/*Cabecera: void eliminar_viaje(Viaje*)
Precondición: Recibe un puntero a viaje y un entero n.
Postcondición: Permite al usuario eliminar un viaje previamente creado por él mismo.*/

void eliminar_viaje(Viaje *viaje, int n){
    int N=10, a, i, j;
    Viaje x, y, z[N];
    char c;
    
    do {
    listar_viaje(&viaje);
    printf("Introduzca el id del viaje que desea eliminar.");
    scanf("%s", y.Id_viaje);
    
        for(i=0; i<N; i++) {
            if(x.Id_viaje==y.Id_viaje) {
                for(j=i; j<N; j++) {
                    z[j]=z[j+1];
                    a=1;
                }
            } else {
                printf("Error al introducir el id del viaje.\n");
                a=0;
                printf("¿Desea salir? s/n\n");
                scanf("%c", &c);
                if(c=='s'){
                    a=1;
                }
            }
        }
    } while(a!=1);
}

/*Cabecera: void modificar_viaje(Viaje*)
Precondición: 
Postcondición: Permite al usuario modificar un viaje previamente creado por el mismo.*/

void modificar_viaje(Viaje *viaje){
    Viaje v;
    int o;
        
    do {
        printf("Indique la seccion que desea modificar:\n1.- El id del viaje.\n2.- La matricula del vehiculo.\n3.- La fecha del viaje.\n4.- La hora de inicio del viaje.\n5.- La hora de finalización del viaje.\n6.- El numero de plazas libres del viaje.\n7.- El sentido del viaje.\n8.- El importe del viaje.\n9.- El estado del viaje.\n0.- Salir");
        scanf("%d", &o);
    } while (o<0 || o>9);
    
    switch(o){
        case 1:
            v.Id_viaje leer_campo(TAM_ID_VIA, "Id del viaje");
            scanf("%s", v.Id_viaje);
            break;
        case 2:
            v.Id_mat leer_campo(TAM_ID_VEI, "Matricula del vehiculo");
            scanf("%s", v.Id_mat);
            break;
        case 3:
            v.F_inic leer_campo(TAM_FIN_VIA, "Hora de inicio");
            scanf("%s", v.F_inic);
            break;
        case 4:
            v.H_inic leer_campo(TAM_HIN_VIA, "Hora de finalizacion");
            scanf("%s", v.H_inic);
            break;
        case 5:
            v.H_fin leer_campo(TAM_HFI_VIA, "Hora de finalizacion");
            scanf("%s", v.H_fin);
            break;
        case 6:
            v.Plazas_libre leer_campo(TAM_PLA_VEI, "Plazas libres");
            scanf("%s", v.Plazas_libre);
            break;
        case 7:
            v.Sentido leer_campo(TAM_SEN_VIA, "Sentido del viaje");
            scanf("%s", v.Sentido);
            break;
        case 8:
            v.Importe leer_campo(TAM_IMP_VIA, "Importe del viaje");
            scanf("%s", v.Importe);
            break;
        case 9:
            v.Estado leer_campo(TAM_EST_VIA, "Estado del viaje");
            scanf("%s", v.Estado);
            break;
    }
}

/*Cabecera: void listar_viaje(Viaje*)
Precondición: 
Postcondición: Permite al usuario visualizar una lista de todos los viajes que se encuentran en el sistema.*/

void listar_viaje(Viaje* viaje){
    int i, N=10;
    Viaje v;
    
    for(i=0; i<N; i++) {
        printf("%i: %s-%s-%s-%s-%s-%s-%s-%s-%s", i+1, v.Id_viaje, v.Id_mat, v.F_inic, v.H_inic, v.H_fin, v.Plazas_libre, v.Sentido, v.Importe, v.Estado);
    }
}

void autoFinalizarViaje(Viajes *lista, int elementos){
    int indice;
    struct tm fecha, hora, *actual;
    time_t tiempo;
    
    tiempo = time(NULL);
    actual = localtime(&tiempo);
    
    for(indice = 0; indice < elementos; indice++){
        if(!strcmp(lista[indice].Estado,(char *)"Iniciado") || !strcmp(lista[indice].Estado,(char *)"Cerrado") || !strcmp(lista[indice].Estado,(char *)"Abierto")){
            strptime(lista[indice].F_inic, "%d/%m/%Y", &fecha);
            strptime(lista[indice].H_fin, "%H:%M", &hora);

            if(fecha.tm_year+1900 - actual->tm_year > 0 || fecha.tm_mday - actual->tm_mday > 0 || fecha.tm_mon+1 - actual->tm_mon+1 > 0 || hora.tm_hour+1 - actual->tm_hour >= 0){
               printf("\nViaje Finalizado %s\n",lista[indice].Id_viaje);
               lista[indice].Estado = "Finalizado";
            }
        }
    }
}

void menu_viaje() {
    int o, n;
    Viaje*viaje;
    
    do {
        printf("Introduzca la opcion que desea:\n1.- Publicar viaje.\n2.- Eliminar viaje.\n3.- Modificar viaje.\n4.- Listar viajes.\n0.- Salir.");
        scanf("%d", &o);
        switch(o) {
            case 0:
                exit(0);
                break;
            case 1:
                publicar_viaje(viaje);
                break;
            case 2:
                eliminar_viaje(viaje, n);
                break;
            case 3:
                modificar_viaje(viaje);
                break;
            case 4:
                listar_viaje(viaje);
                break;
            default:
                printf("ERROR: Opcion invalida.");
                break;
        }
    } while(o!=0);
    fflush(stdin);
    return;
}