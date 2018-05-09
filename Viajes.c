#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ficheros.h"
#include "comun.h"
#include "Vehiculos.h"
#include "Viajes.h"
#define __USE_XOPEN

/*Cabecera: int buscar_viaje(char* id, Viajes* lista, int elementos)
Precondicion: id del viaje a buscar la posición en el array, array y numero de elementos
Poscondicion: Devuelve el número que ha introducido el usuario, si no lo encuentra devuelve -1*/

int buscar_viaje(char *id, Viajes *lista, int elementos) {
    int posicion = -1, exisVia = 0, i = 0;

    while (i < elementos && exisVia == 0) { //Buscamos el id del viaje si existe
        if (!strncmp(id, lista[i].Id_viaje, TAM_ID_VIA)) {
            exisVia = 1; //Si hay una concidencia guardamos y salimos
            posicion = i;
        }
        i++;
    }

    return posicion;
}

/*Cabecera: void publicar_viaje(Viajes* v, int* elementos, char* viaje, char *id)
Precondición: Recibe cadenas de carácteres de un viaje.
Postcondición: Permite al ususario publicar un nuevo viaje.*/

void publicar_viaje(Viajes *v, int *elementos, char *viaje, char *id){
    char *Id_viaje, *Id_mat, *F_inic, *H_inic, *H_fin, *Plazas_libre, *Sentido, *Importe, *Estado;
    int i, n;
    Vehiculos* vh;
    
    for (i = 0; i < n; i++) {
        if (!strcmp(id, vh[i].Id_usuario)) {
            /*Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena*/
            Id_viaje = (char *) malloc(TAM_ID_VIA + 1 * sizeof (char));
            Id_mat = (char *) malloc(TAM_ID_VEI + 1 * sizeof (char));
            F_inic = (char *) malloc(TAM_FIN_VIA + 1 * sizeof (char));
            H_inic = (char *) malloc(TAM_HIN_VIA + 1 * sizeof (char));
            H_fin = (char *) malloc(TAM_HFI_VIA + 1 * sizeof (char));
            Plazas_libre = (char *) malloc(TAM_PLA_VEI + 1 * sizeof (char));
            Sentido = (char *) malloc(TAM_SEN_VIA + 1 * sizeof (char));
            Importe = (char *) malloc(TAM_IMP_VIA + 1 * sizeof (char));
            Estado = (char *) malloc(TAM_EST_VIA + 1 * sizeof (char));

            /*Mostramos informacion que se le solicita al usuario y la recogemos*/
            Id_mat = leer_campo(TAM_ID_VEI, "Inserte la matricula del vehiculo: \n");
            F_inic = leer_campo(TAM_FIN_VIA, "Inserte la fecha en la que se producira el viaje: \n");
            H_inic = leer_campo(TAM_HIN_VIA, "Inserte la hora a la que se iniciara el viaje: \n");
            H_fin = leer_campo(TAM_HFI_VIA, "Inserte la hora a la que finalizará el viaje: \n");
            Plazas_libre = vh[i].Num_plazas;
            Sentido = leer_campo(TAM_SEN_VIA, "Inserte el sentido en el que ira el viaje (ida o vuelta): \n");
            Importe = leer_campo(TAM_IMP_VIA, "Inserte el importe del viaje: \n");
            Estado = "Abierto";

            /*Obtenemos memoria para un nuevo elemento*/
            v = (Viajes *) realloc(v, (*elementos + 1) * sizeof (Viajes));
            
//Variable de control
            
/*if( > fecha.tm_year - actual){
    v[*elementos].F_inic = F_inic;
} else {
    if( <= fecha.tm_year - actual){
        if( > fecha.tm_mon - actual){
            v[*elementos].F_inic = F_inic;
        } else {
            if( <= fecha.tm_mon - actual){
                if( >= fecha.tm_mday - actual){
                    v[*elementos].F_inic = F_inic;
                } else {
                    printf("ERROR: La tiene tiene que ser la actual o una posterior a la actual.");
                    return 0;
                }
            }
        }
    }
}*/
            /*Guardamos la informacionrecogida y generada en el nuevo elemento*/
            sprintf(Id_viaje, "%06d", *elementos + 1);
            v[*elementos].Id_mat = Id_mat;
            v[*elementos].F_inic = F_inic;
            v[*elementos].H_inic = H_inic;
            v[*elementos].H_fin = H_fin;
            v[*elementos].Sentido = Sentido;
            v[*elementos].Importe = Importe;
            v[*elementos].Estado = Estado;
            (*elementos)++;
        } else {
            printf("ERROR: No tiene ningún vehículo dado de alta.");
        }
    }
}

/*Cabecera: void eliminar_viaje(Viajess* lista, int* elemento)
 Precondicion: lista de viajes y numero de elementos 
 Poscondicion: modifica a borrado un viaje*/

void eliminar_viaje(Viajes *lista, int *elementos) {
    char *id;
    int pos;

    printf("\n\nBorrado de un viaje:\n\n");
    
    /*Solicitamos el id del viaje*/
    id = leer_campo(TAM_ID_VIA, "Introduce el id del viaje"); 
    
    pos = buscar_viaje(id, lista, *elementos);
    
    lista[pos].Eliminado = "Si";
    printf("El viaje ha sido eliminado con exito.");
}

/*Cabecera: void modificar_viaje(Viajes* viaje)
Precondición: recibe un puntero a viaje.
Postcondición: Permite al usuario modificar un viaje previamente creado por el mismo.*/

void modificar_viaje(Viajes *viaje){
    Viajes v;
    int o;
        
    do {
        printf("Indique la seccion que desea modificar:\n1.- El id del viaje.\n2.- La matricula del vehiculo.\n3.- La fecha del viaje.\n4.- La hora de inicio del viaje.\n5.- La hora de finalización del viaje.\n6.- El numero de plazas libres del viaje.\n7.- El sentido del viaje.\n8.- El importe del viaje.\n9.- El estado del viaje.\n0.- Salir");
        scanf("%d", &o);
    } while (o<0 || o>9);
    
    switch(o){
        case 1:
            v.Id_viaje = leer_campo(TAM_ID_VIA, "Id del viaje");
            scanf("%s", v.Id_viaje);
            break;
        case 2:
            v.Id_mat = leer_campo(TAM_ID_VEI, "Matricula del vehiculo");
            scanf("%s", v.Id_mat);
            break;
        case 3:
            v.F_inic = leer_campo(TAM_FIN_VIA, "Hora de inicio");
            scanf("%s", v.F_inic);
            break;
        case 4:
            v.H_inic = leer_campo(TAM_HIN_VIA, "Hora de finalizacion");
            scanf("%s", v.H_inic);
            break;
        case 5:
            v.H_fin = leer_campo(TAM_HFI_VIA, "Hora de finalizacion");
            scanf("%s", v.H_fin);
            break;
        case 6:
            v.Plazas_libre = leer_campo(TAM_PLA_VEI, "Plazas libres");
            scanf("%s", v.Plazas_libre);
            break;
        case 7:
            v.Sentido = leer_campo(TAM_SEN_VIA, "Sentido del viaje");
            scanf("%s", v.Sentido);
            break;
        case 8:
            v.Importe = leer_campo(TAM_IMP_VIA, "Importe del viaje");
            scanf("%s", v.Importe);
            break;
        case 9:
            v.Estado = leer_campo(TAM_EST_VIA, "Estado del viaje");
            scanf("%s", v.Estado);
            break;
    }
}
/*Cabecera: void listar_viaje(Viajes* viaje, int* elementos)
Precondición: Recibe un puntero a viaje y un puntero a entero.
Postcondición: Permite al usuario visualizar una lista de todos los viajes que se encuentran en el sistema.*/

void listar_viaje(Viajes *viaje, int elementos, Pasos *lista, int *numPasos) {
    int i;

    printf("Id del viaje - Matricula del vehiculo - Fecha de inicio - Hora de inicio - Hora de finalizacion - Numero de plazas libres - Sentido del viaje - Importe - Estado del viaje");
    for (i = 0; i < elementos; i++) {
        if (strcmp(viaje[i].Eliminado, (char *) "No")) {
            printf("%d: %s - %s - %s - %s - %s - %s - %s - %s - %s", i + 1, viaje[i].Id_viaje, viaje[i].Id_mat, viaje[i].F_inic, viaje[i].H_inic, viaje[i].H_fin, viaje[i].Plazas_libre, viaje[i].Sentido, viaje[i].Importe, viaje[i].Estado);

            listar_paso(lista, numPasos, viaje[i].Id_viaje);
        }
    }
}

void listar_viaje_usuario(Viajes* viaje, int elementos, Usuarios* usuario, char* id){
    int i;
    
    printf("Id del viaje - Matricula del vehiculo - Fecha de inicio - Hora de inicio - Hora de finalizacion - Numero de plazas libres - Sentido del viaje - Importe - Estado del viaje");
    for (i = 0; i < elementos; i++){
        if (strcmp(viaje[i].Eliminado, (char *) "No") && !strcmp(usuario[i].Id_usuario, id)){
            printf("%d: %s - %s - %s - %s - %s - %s - %s - %s - %s", i + 1, viaje[i].Id_viaje, viaje[i].Id_mat, viaje[i].F_inic, viaje[i].H_inic, viaje[i].H_fin, viaje[i].Plazas_libre, viaje[i].Sentido, viaje[i].Importe, viaje[i].Estado);
        }
    }
}

char* conductor_viaje(Viajes* viaje, int elementos, Vehiculos* vehiculo){
    int i;
    
    for (i = 0; i < elementos; i++){
    if (!strcmp(vehiculo[i].Id_mat, viaje[i].Id_mat)){
            return vehiculo[i].Id_usuario;
        }
    }
}

/*Cabecera: void autoFinalizarViajes(Viajes* lista, int elementos)
 Precondición: Recibe un puntero a viaje y un entero
 Postcondición: Finaliza un viaje una vez pasada una hora de su hora de finalización*/

void autoFinalizarViajes(Viajes *lista, int elementos){
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
               printf("\nViajes Finalizado %s\n",lista[indice].Id_viaje);
               lista[indice].Estado = "Finalizado";
            }
        }
    }
}

void publicar_paso(Pasos *lista, int* numPasos, char* idViaje){
    char *poblacion;
    
    poblacion = (char *) malloc(TAM_POB_PAS + 1 * sizeof (char));
        
    poblacion = leer_campo(TAM_POB_PAS,"Población por la que pasa el viaje");
    
    if (! *numPasos) lista = (Pasos *) malloc((*numPasos + 1) * sizeof (Pasos)); //Reserva memoria para el primer elemento
    else lista = (Pasos *) realloc(lista, (*numPasos + 1) * sizeof (Pasos)); //Reserva memoria para los elementos restantes

    lista[*numPasos].Id_viaje = idViaje; //Asiganamos los valores recogidos al elemento
    lista[*numPasos].Poblacion = poblacion;
    (*numPasos)++; //Aumentamos el numero de elementos del array
}

void eliminar_paso(Pasos *lista, int* numPasos, char* idViaje, char* poblacion){
    
    int indice = 0;
    
    if(*numPasos == 1){
        free(lista);
    }
    else{
        while(indice < *numPasos || (!strcmp(idViaje,lista[indice].Id_viaje) && !strcmp(poblacion, lista[indice].Poblacion)))
            indice++;
        
        if(*numPasos-1 != indice){
            lista[indice] = lista[*numPasos-1];
        }
        lista = (Pasos *) realloc(lista, (*numPasos - 1) * sizeof (Pasos));
    }  
}

void listar_paso(Pasos *lista, int* numPasos, char* idViaje){
    int indice;
    
    printf("El viaje pasa por las siguientes localidades:\n\n");
    
    for(indice = 0; indice < *numPasos; indice++){
        if(!strcmp(lista[indice].Id_viaje,idViaje)){
            printf("%s\n",lista[indice].Poblacion);
        }
    }
}

void unirse_viaje (Viajes* viaje, int *elementos, char* id){
    int i;
    char c, *Plazas_libre;
    
    printf("Introduzca el id del viaje al que desea unirse.");
    scanf("%s", &c);
    sprintf(Plazas_libre, "%06d", ((int)viaje[c].Plazas_libre) - 1);
    if (!strcmp(viaje[c].Plazas_libre, "0")){
        viaje[c].Estado = "Cerrado";
    }
    
}