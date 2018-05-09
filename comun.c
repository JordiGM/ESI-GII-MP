#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"
#include "comun.h"
#include "Usuarios.h"
#include "Viajes.h"
#include "Vehiculos.h"
#include "Incidencias.h"

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

// Cabecera: int menu_principal(int opc, int id, Usuarios ListaUsuarios, int numUser)
// Precondicion: Valor 1 para administrados, valor <> 1 para usuario
// Poscondicion:  Accede a los distintos menus de la aplicación, no retorna nada

void menu_principal(int opc, char *id, Usuarios *ListaUsuarios, int *numUser) {
    int x, numVehiculos = 0, numViajes = 0, numPasos = 0, numIncidencias = 0, pos;
    int o, i;
    char *id_new, *matricula, c;
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
                        o = leer_numero("Indica la opción");
                        switch (o) {
                            case 0:
                                break;
                            case 1:
                                id = altaUsuario(ListaUsuarios, numUser);
                                printf("\n\tDado de alta usuario nuevo con el id : %s\n", id_new);
                                break;
                            case 2:
                                bajaUsuario(ListaUsuarios, numUser);
                                break;
                            case 3:
                                modificaAdmin(ListaUsuarios, numUser);
                                break;
                            case 4:
                                listarUsuario(ListaUsuarios, numUser);
                                break;
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (o != 0);
                    break;
                case 2:
                    do {
                        printf("Introduzca la opcion que desea\n\n "
                                "1: Alta vehiculo\n "
                                "2: Baja vehiculos\n "
                                "3: Listar vehiculos\n "
                                "4: Modificar vehiculos\n "
                                "5: Listar los viajes de un vehiculo"
                                "0: salir\n");
                        o = leer_numero("Indica la opción");
                        switch (o) {
                            case 0:
                                break;
                            case 1:
                                alta_vehiculo(L_Vehiculos,&numVehiculos,id);
                                break;
                            case 2:
                                baja_vehiculo(L_Vehiculos,numVehiculos);
                                break;
                            case 3:
                                vehiculos_user(id,L_Vehiculos,numVehiculos);
                                break;
                            case 4:
                                vehiculos_user(id,L_Vehiculos,numVehiculos);
                                matricula = leer_campo(TAM_ID_VEI, "Escriba la matricula del vehiculo a modificar");
                                pos = buscar_vehiculo(matricula,L_Vehiculos,numVehiculos);
                                modificar_vehiculo(L_Vehiculos,pos);
                                break;
                            case 5:
                                listar_viajes_coche(L_Viajes,matricula,numVehiculos);
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (o != 0);
                    break;
                case 3:
                    do {
                        printf("Introduzca la opcion que desea:\n1.- Publicar viaje.\n2.- Eliminar viaje.\n3.- Modificar viaje.\n4.- Listar viajes.\n0.- Salir.");
                        scanf("%d", &o);
                        switch (o) {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                publicar_viaje(L_Viajes,&numViajes,id);
                                break;
                            case 2:
                                eliminar_viaje(L_Viajes,&numViajes);
                                break;
                            case 3:
                                modificar_viaje(L_Viajes);
                                break;
                            case 4:
                                listar_viaje(L_Viajes,numViajes,L_Pasos,&numPasos);
                                break;
                            default:
                                printf("ERROR: Opcion invalida.");
                                break;
                        }
                    } while (o != 0);
                    break;
                case 4:
                    do {
                        printf("Introduzca la opcion que desea:\n"
                                "1.- Publicar incidencia.\n"
                                "2.- Eliminar incidencia.\n"
                                "3.- Modificar incidencia.\n"
                                "4.- Listar incidencia.\n"
                                "5.- Validar incidencia.\n"
                                "0.- Salir.");
                        scanf("%d", &o);
                        char *usuario,*conductor,*viaje;
                        
                        if(o == 1 || o == 2 || o == 3){
                            usuario = leer_campo(TAM_ID_USER,"Introduce el id del usuario que realiza la incidencia");
                            viaje = leer_campo(TAM_ID_VIA,"Introduce el id dek viaje de la incidencia");
                            conductor = leer_campo(TAM_ID_USER,"Introduce el id del conductor de la incidencia");
                        }
               
                        switch (o) {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                crearIncidencias(L_Incidencias, &numIncidencias,usuario,viaje,conductor);
                                break;
                            case 2:
                                eliminarIncidencias(L_Incidencias, &numIncidencias,usuario,viaje,conductor);
                                break;
                            case 3:
                                modificarIncidencias(L_Incidencias,numIncidencias,usuario,viaje,conductor);
                                break;
                            case 4:
                                listarIncidencias(L_Incidencias,numIncidencias,"Admin");
                                break;
                            case 5:
                                validarIncidencias(L_Incidencias,numIncidencias);
                                break;
                            default:
                                printf("ERROR: Opcion invalida.");
                                break;
                        }
                    } while (o != 0);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    } else {
        pos = buscar_usuario(id, ListaUsuarios, *numUser);
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
                        o = leer_numero("Indica la opción");
                        switch (o) {
                            case 0:
                                break;
                            case 1:
                                mostrarUsuario(ListaUsuarios, pos);
                                break;
                            case 2:
                                modificaUsuario(ListaUsuarios, pos);
                                break;
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (o != 0);
                    break;
                case 2:
                    do {
                        printf("Bienvenido al menú de la aplicación \n "
                                "Introduzca la opcion que desea\n\n "
                                "1: Alta vehiculo\n "
                                "2: Baja vehiculos\n "
                                "3: Listas vehiculos(propios)\n "
                                "4: Modificar vehiculo\n "
                                "0: salir\n");
                        o = leer_numero("Indica la opción");
                        switch (o) {
                            case 0:
                                break;
                            case 1:
                                alta_vehiculo(L_Vehiculos,&numVehiculos,id);
                                break;
                            case 2:
                                baja_vehiculo(L_Vehiculos,numVehiculos);
                                break;
                            case 3:
                                vehiculos_user(id,L_Vehiculos,numVehiculos);
                                break;
                            case 4:
                                vehiculos_user(id,L_Vehiculos,numVehiculos);
                                matricula = leer_campo(TAM_ID_VEI, "Escriba la matricula del vehiculo a modificar");
                                pos = buscar_vehiculo(matricula,L_Vehiculos,numVehiculos);
                                modificar_vehiculo(L_Vehiculos,pos);
                                break;
                            default:
                                printf("Error al elegir la opcion.\t");
                                break;
                        }
                    } while (x != 0);
                    break;
                case 3:
                    printf("Bienvenido al menú de viajes. Estos son los viajes que hay abiertos actualmente.\n");
                    for (i = 0; i < numViajes; i++) {
                        if (!strcmp(L_Viajes[i].Estado, "Abierto")) {
                            listar_viaje(L_Viajes, numViajes, L_Pasos, &numPasos);
                            if (!strcmp(id, L_Vehiculos[i].Id_usuario) && !strcmp(L_Vehiculos[i].Num_plazas, L_Viajes[i].Plazas_libre)) {
                                printf("¿Desea modificar algún viaje que usted haya publicado? s/n");
                                scanf("%s", &c);
                                if (c == 's') {
                                    modificar_viaje(L_Viajes);
                                }
                            }
                        }
                    }
                    
                    printf("Introduzca la opcion que desea:\n"
                                "1.- Publicar viaje.\n"
                                "2.- Incorporarse a un viaje.\n"
                                "3.- Visualizar viaje.\n"
                                "0.- Salir.");
                    switch(o){
                        case 0:
                            exit(0);
                            break;
                        case 1:
                            publicar_viaje(L_Viajes, &numViajes, id);
                            break;
                        case 2:
                            unirse_viaje(L_Viajes, &numViajes,id);
                            break;
                        case 3:
                            listar_viaje(L_Viajes, numViajes, L_Pasos, &numPasos);
                            break;
                        default:
                            printf("ERROR: Opcion invalida.");
                            break;
                    }
                    break;
                case 4:
                    do {
                        printf("Introduzca la opcion que desea:\n"
                                "1.- Publicar incidencia.\n"
                                "2.- Listar incidencia.\n"
                                "0.- Salir.");
                        scanf("%d", &o);
                        char *conductor,*viaje;
                        switch (o) {
                            case 0:
                                exit(0);
                                break;
                            case 1:
                                viaje = leer_campo(TAM_ID_VIA,"Introduce el id dek viaje de la incidencia");
                                conductor = leer_campo(TAM_ID_USER,"Introduce el id del conductor de la incidencia");
                                crearIncidencias(L_Incidencias, &numIncidencias,id,viaje,conductor);
                                break;
                            case 2:
                                listarIncidencias(L_Incidencias,numIncidencias,id);
                                break;
                            default:
                                printf("ERROR: Opcion invalida.");
                                break;
                        }
                    } while (o != 0);
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
