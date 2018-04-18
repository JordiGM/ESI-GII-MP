#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"
#include "Usuarios.h"
//#include "Viajes.h"

// Cabecera: void vacia_buffer()
// Precondicion: Ninguna
// Poscondicion: Limpia el buffer de entrada

void vacia_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Cabecera: char* leer_campo(entero largo, caracter titulo)
// Precondicion: el tamaño de la cadena que se va a solicitar y  el texto que se quiere mostrar
// Poscondicion: devuelve un puntero de tipo char con la información introducida por el usuario

char *leer_campo(int largo, char *titulo) {
    char *campo, *p;
    campo = (char *) calloc(largo + 1, sizeof (char));
    printf("\n%s (%d caracteres):", titulo, largo);
    fgets(campo, largo + 1, stdin);
    p = strchr(campo, '\n'); //Eliminamos los saltos de linea
    if (p) *p = '\0';
    vacia_buffer();
    fflush(stdin);
    return campo;
}

// Cabecera: int leer_numero(caracter titulo)
// Precondicion: Texto que se le desea mostrar al usuario
// Poscondicion: devuelve el número que ha introducido el usuario

int leer_numero(char *titulo) {
    int num;
    printf("\n%s (integer):", titulo);
    scanf("%d", &num);
    fflush(stdin);
    return num;
}

//TEMPORAL prototipo
void autoFinalizarViaje(Viajes *, int);

// Cabecera: int menu_principal(int opc, int id, Usuarios ListaUsuarios, int NumUser)
// Precondicion: Valor 1 para administrados, valor <> 1 para usuario
// Poscondicion:  Accede a los distintos menus de la aplicación, no retorna nada

void menu_principal(int opc, char *id, Usuarios *ListaUsuarios, int *NumUser) {
    int x, numVehiculos = 0, numViajes = 0, numPasos = 0, numIncidencias = 0, pos;
    Vehiculos* L_Vehiculos;
    Viajes* L_Viajes;
    Pasos* L_Pasos;
    Incidencias* L_Incidencias;

    printf("\nCargando información en el programa.\n");
    L_Vehiculos = obtenerVehiculos(&numVehiculos);
    L_Viajes = obtenerViajes(&numViajes);
    L_Pasos = obtenerPasos(&numPasos);
    L_Incidencias = obtenerIncidencias(&numIncidencias);
    printf("\nInformación cargada.\n");

    printf("\nActualizando información\n");
    autoFinalizarViaje(L_Viajes, numViajes);
    printf("\nInformación actualizada\n");

    if (opc == 1) {
        do {
            printf("Bienvenido al menu de administración\n"
                    "Introduzca la opcion que desea\n\n "
                    "1: Menú usuarios\n "
                    "2: Menú vehiculos\n "
                    "3: Menú viajes\n "
                    "4: Menú incidencias\n "
                    "0: salir\n");
            x = leer_numero("Indica la opción");
            switch (x) {
                case 0:
                    break;
                case 1:
                    menu_usuario(opc, id, ListaUsuarios, NumUser)
                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 2:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 3:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 4:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    } else {
        pos = buscar_usuario(id, ListaUsuarios, *NumUser);
        do {
            printf("Bienvenido al menú de la aplicación %s\n "
                    "Introduzca la opcion que desea\n\n "
                    "1: Perfil\n "
                    "2: Menú vehiculos\n "
                    "3: Menú viajes\n "
                    "4: Menú incidencias\n "
                    "0: salir\n", ListaUsuarios[pos].Nomb_usuario);
            x = leer_numero("Indica la opción");
            switch (x) {
                case 0:
                    break;
                case 1:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 2:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 3:
                    //menu_viaje(L_Viajes, L_Vehiculos, numViajes, numVehiculos, id );
                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                case 4:

                    menu_principal(opc, id, ListaUsuarios, NumUser);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    }

    printf("\nGuardando información del programa.\n");
    guardarDatosVehiculos(L_Vehiculos, numVehiculos);
    guardarDatosViajes(L_Viajes, numViajes);
    guardarDatosPasos(L_Pasos, numPasos);
    guardarDatosIncidencias(L_Incidencias, numIncidencias);
    printf("\nInformación guardada.\n");
}


//Temporal para la función de Ruben
#include "ficheros.h" //Ruben
#define __USE_XOPEN //Ruben
#include <time.h> //Ruben

void autoFinalizarViaje(Viajes *lista, int elementos) {
    int indice;
    struct tm fecha, hora, *actual;
    time_t tiempo;

    tiempo = time(NULL);
    actual = localtime(&tiempo);

    for (indice = 0; indice < elementos; indice++) {
        if (!strcmp(lista[indice].Estado, (char *) "Iniciado") ||
                !strcmp(lista[indice].Estado, (char *) "Cerrado") ||
                !strcmp(lista[indice].Estado, (char *) "Abierto")) {
            strptime(lista[indice].F_inic, "%d/%m/%Y", &fecha);
            strptime(lista[indice].H_fin, "%H:%M", &hora);

            if (fecha.tm_year + 1900 - actual->tm_year > 0 ||
                    fecha.tm_mday - actual->tm_mday > 0 ||
                    fecha.tm_mon + 1 - actual->tm_mon + 1 > 0 ||
                    hora.tm_hour + 1 - actual->tm_hour >= 0) {
                printf("\nViaje Finalizado %s\n", lista[indice].Id_viaje);
                lista[indice].Estado = "Finalizado";
            }
        }
    }
}

