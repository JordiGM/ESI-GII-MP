#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Viajes.h"
#include "ficheros.h"

/*Cabecera: void publicar_viaje(Viaje*)
Precondición: Recibe cadenas de carácteres de un viaje.
Postcondición: Permite al ususario publicar un nuevo viaje.*/

void publicar_viaje(Viaje *viaje){
    Viaje v;
    /*Vehiculo vh;*/
    char c;

	/*if(vh.Id_mat==true){*/
            do{
                printf("Introduzca el id del viaje.");
                scanf("%s", v.Id_viaje);
        
                printf("Introduzca la matricula del vehiculo con el que va a realizar el viaje.");
                scanf("%s", v.Id_mat);
        
                printf("Introduzca la fecha en la que se va a realizar el viaje. (dd/mm/aaaa)");
                scanf("%s", v.F_inic);
        
                printf("Introduzca la hora de inicio del viaje. (XX:YY)");
                scanf("%s", v.H_inic);
        
                printf("Introduzca la hora de finalización del viaje. (XX:YY)");
                scanf("%s", v.H_fin);
        
                printf("Introduzca el numero de plazas libres que hay en el viaje.");
                scanf("%s", v.Plazas_libre);
        
                printf("Introduzca el sentido del viaje. (Ida o vuelta)");
                scanf("%s", v.Sentido);
        
                printf("Introduzca el importe del viaje. (Ej.: 123,25€)");
                scanf("%s", v.Importe);
        
                printf("Introduzca el estado del viaje. (Abierto, cerrado,iniciado, finalizado o anulado)");
                scanf("%s", v.Estado);

                printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", v.Id_viaje, v.Id_mat, v.F_inic, v.H_inic, v.H_fin, v.Plazas_libre, v.Sentido, v.Importe, v.Estado);
                printf("¿Son correctos los datos? s/n\n");
                scanf("%c", &c);
            } while(c!='s');
        /*} else {
            printf("ERROR: No tiene ningún vehiculo dado de alta.");
        }*/
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