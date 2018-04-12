#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"
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

// Cabecera: int buscar_usuario(int id)
// Precondicion: id del usuario a buscar la posición en el array, array y numero de elementos
// Poscondicion: devuelve el número que ha introducido el usuario, si no lo encuentra devuelve -1

int buscar_usuario(char *id, Usuarios *lista, int elementos) {
    int posicion = -1, exisUser = 0, i = 0;

    while (i < elementos && exisUser == 0) { //Buscamos el nombre del usuario si existe
        if (!strncmp(id, lista[i].Id_usuario, TAM_ID_USER)) {
            exisUser = 1; //Si hay una concidencia guardamos y salimos
            posicion = i;
        }
        i++;
    }

    return posicion;
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
            scanf("%d", &x);
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
            scanf("%d", &x);
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


//Temporal para la función de Adri Ruben
#include "ficheros.h" //Adri y Ruben
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

char *altaUsuarioInicio(Usuarios *lista, int *elementos, char *usuario) {
    char *id, *localidad, *nombre, *login;

    //Obtenemos espacio en memoria suficiente para la dimension maxima de cada cadena
    id = (char *) malloc(TAM_ID_USER + 1 * sizeof (char));
    nombre = (char *) malloc(TAM_NOM_USER + 1 * sizeof (char));
    localidad = (char *) malloc(TAM_LOC_USER + 1 * sizeof (char));
    login = (char *) malloc(TAM_LOG_USER + 1 * sizeof (char));

    //Mostramos información que se le solicita al usuario y la recogemos
    printf("\n\nHola %s para finalizar tu registro necesitamos algunos datos mas.\n", usuario);
    nombre = leer_campo(TAM_NOM_USER, "Nombre");
    localidad = leer_campo(TAM_LOC_USER, "Ciudad en la que vive");
    login = leer_campo(TAM_LOG_USER, "Contraseña");

    //Obtenemos memoria para un nuevo elemento
    lista = (Usuarios *) realloc(lista, (*elementos + 1) * sizeof (Usuarios));

    //Guardamos la información recogida y generada en el nuevo elemento    
    sprintf(id, "%04d", *elementos + 1); //Transofrmamos el ultimo id + 1 en una cadena tipo 0001 
    lista[*elementos].Id_usuario = id;
    lista[*elementos].Nomb_usuario = nombre;
    lista[*elementos].Localidad = localidad;
    lista[*elementos].Perfil_usuario = "usuario";
    lista[*elementos].User = usuario;
    lista[*elementos].Login = login;
    lista[*elementos].Estado = "activo";
    (*elementos)++;
    return id;
}

void login(Usuarios *L_Usuarios, int *numeroUsuarios) {

    char *user, *login, *perfil, *id;
    int exisUser = 0, passOK = 0, i;

    printf("\n\nINTRODUZCA SU USUARIO Y CONTRASEÑA PARA ACCEDER:\n\n");

    user = leer_campo(TAM_USE_USER, "Introduce nombre de usuario"); //Solicitamos el nombre del usuario

    i = 0;
    while (i < *numeroUsuarios && exisUser == 0) { //Buscamos el nombre del usuario si existe
        if (!strncmp(user, L_Usuarios[i].User, TAM_NOM_USER)) {
            exisUser = 1; //Si hay una concidencia guardamos y salimos
            perfil = L_Usuarios[i].Perfil_usuario;
        }
        i++;
    }

    if (exisUser == 0) { //Si el usuario no existe creamos una cuenta nueva
        printf("\nUsuario indicado no existe, accediendo para crear una cuenta\n");
        perfil = "usuario";
        id = altaUsuarioInicio(L_Usuarios, numeroUsuarios, user); //Función que crea el usuario con el nombre de usuario indicado que no existe que retorna el ID
        if (id != 0) {
            menu_principal(0, id, L_Usuarios, numeroUsuarios); //Se fija valor 0 ya que un usuario creado asi nunca será un administrador
        } else {
            printf("Error al crear el usuario.");
        }
    } else {
        i--;

        if (!strcmp(L_Usuarios[i].Eliminado, (char *) "Si")) { //Nos aseguramos que el nombre de usuario que se quiere utilizar no ha sido de un usuario eliminado
            printf("\nNombre de usuario no permitido.\n");
            printf("Saliendo del sistema\n");
        } else {
            login = leer_campo(TAM_LOG_USER, "Introduce el password"); //Solicitamos la contraseña del usuario

            if (!strcmp(login, L_Usuarios[i].Login)) {
                passOK = 1;
                id = L_Usuarios[i].Id_usuario;
                if (passOK == 1 && exisUser == 1) {
                    menu_principal(!strcmp(perfil, (char *) "administrador"), id, L_Usuarios, numeroUsuarios);
                }
            } else {
                printf("\nError contraseña erronea\n");
                printf("Saliendo del sistema\n");
            }
        }
    }
}