#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"
#include "Usuarios.h"
#include "Viajes.h"

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
    int u, o;
    char *id_new;
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
                    do {
                        printf("Bienvenido al menu de administración\n"
                                "Introduzca la opcion que desea\n\n "
                                "1: Alta usuario\n "
                                "2: Baja usuario\n "
                                "3: Modificar usuario\n "
                                "4: Mostrar usuarios\n "
                                "0: salir\n");
                        u = leer_numero("Indica la opción");
                        switch (u) {
                            case 0:
                                break;
                            case 1:
                                id = altaUsuario(ListaUsuarios, NumUser);
                                printf("\n\tDado de alta usuario nuevo con el id : %s\n", id_new);
                                break;
                            case 2:
                                bajaUsuario(ListaUsuarios, NumUser);
                                break;
                            case 3:

                                break;
                            case 4:
                                listarUsuario(ListaUsuarios, NumUser);
                                break;
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (u != 0);
                    break;
                case 2:

                    break;
                case 3:
                    do {
                        printf("Introduzca la opcion que desea:\n1.- Publicar viaje.\n2.- Eliminar viaje.\n3.- Modificar viaje.\n4.- Listar viajes.\n0.- Salir.");
                        scanf("%d", &o);
                        switch(o) {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                //ublicar_viaje(viaje);
                                break;
                            case 2:
                                //eliminar_viaje(viaje, n);
                                break;
                            case 3:
                                //modificar_viaje(viaje);
                                break;
                            case 4:
                                //listar_viaje(viaje);
                                break;
                            default:
                                printf("ERROR: Opcion invalida.");
                                break;
                        }
                    } while(o!=0);
                    break;
                case 4:

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
                    do {
                        printf("Bienvenido al menú del usuario, administra tu cuenta %s\n "
                                "Introduzca la opcion que desea\n\n "
                                "1: Mostrar datos\n "
                                "2: Modificar datos\n "
                                "0: salir\n", ListaUsuarios[pos].Nomb_usuario);
                        x = leer_numero("Indica la opción");
                        switch (x) {
                            case 0:
                                break;
                            case 1:

                                break;
                            case 2:

                                break;
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (x != 0);
                    break;
                case 2:

                    break;
                case 3:
                    //menu_viaje(L_Viajes, L_Vehiculos, numViajes, numVehiculos, id );
                    break;
                case 4:

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