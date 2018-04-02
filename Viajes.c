#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Viajes.h"
#include "ficheros.h"

/*Cabecera: void publicar_viaje(Viaje*)
Precondición: Recibe cadenas de carácteres de un viaje.
Postcondición: Permite al ususario publicar un nuevo viaje.*/

void publicar_viaje(){
    Viaje v;
    char c;

	if(c);/*La c no va ahí, es una medida provisional para que no de un error momentaneo.*/
		do{
			printf("Introduzca el id del viaje.");
			scanf("%s", v.Id_viaje);
        
			printf("Introduzca la matricula del vehiculo con el que va a realizar el viaje.");
			scanf("%s", v.Id_mat);
        
			printf("Introduzca la fecha en la que se va a realizar el viaje.");
			scanf("%s", v.F_inic);
        
			printf("Introduzca la hora de inicio del viaje.");
			scanf("%s", v.H_inic);
        
			printf("Introduzca la hora de finalización del viaje.");
			scanf("%s", v.H_fin);
        
			printf("Introduzca el numero de plazas libres que hay en el viaje.");
			scanf("%s", v.Plazas_libre);
        
			printf("Introduzca el sentido del viaje (ida o vuelta.");
			scanf("%s", v.Sentido);
        
			printf("Introduzca el importe del viaje.");
			scanf("%s", v.Importe);
        
			printf("Introduzca el estado del viaje (abierto, cerrado,iniciado, finalizado o anulado).");
			scanf("%s", v.Estado);

			printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", v.Id_viaje, v.Id_mat, v.F_inic, v.H_inic, v.H_fin, v.Plazas_libre, v.Sentido, v.Importe, v.Estado);
			printf("¿Son correctos los datos? s/n\n");
			scanf("%c", &c);
		} while(c!='s');
}

/*Cabecera: void eliminar_viaje(Viaje*)
Precondición: Recibe un puntero a viaje y un entero n.
Postcondición: Permite al usuario eliminar un viaje previamente creado por él mismo.*/

void eliminar_viaje(Viaje *viaje, int n){

    int i;
    char id;
    listar_viaje(&viaje, n);
    printf("Introduce el id del viaje a eliminar");
    scanf("%i", id);

    Viaje aux[n];
    id-=1;

    for(i=0;i<n;i++){
        if(i<id){
            aux[i]=viaje[i];
        } else {

    }

/*Cabecera: void modificar_viaje(Viaje*)
Precondición: 
Postcondición: Permite al usuario modificar un viaje previamente creado por el mismo.*/



/*Cabecera: void listar_viaje(Viaje*)
Precondición: 
Postcondición: Permite al usuario visualizar una lista de todos los viajes que se encuentran en el sistema.*/

void listar_viaje(){
    int v, N=;
    
