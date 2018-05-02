#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ficheros.h" 
#include "comun.h"
#include "Usuarios.h"
void modificaAdmin(Usuarios *lista,int *elementos){
    int id,seguir,opcion,otro,modificar;
    do{
    modificar=leer_numero("¿Desea modificar o salir?\n1-Modificar\n2-Salir");
    if(modificar==1){
    listarUsuario;
    id=leer_campo(TAM_ID_USER,"¿Que usuario desea modificar?");
    id=buscar_usuario(id,lista,elementos);//pregunta
    opcion=leer_numero("Que campo desea modificar?\n1-Nombre\n2-Localidad\n3-Nickname\n4-Contraseña\n5-Estado");
    do{
    switch(opcion){
        case 1:lista[id].Nomb_usuario=leer_campo(TAM_NOM_USER,"Modifique el NOMBRE del usuario:\n");
            break;
        case 2:lista[id].Localidad=leer_campo(TAM_LOC_USER,"Modifique la LOCALIDAD del usuario:\n");
            break;
        case 3:lista[id].User=leer_campo(TAM_USE_USER,"Modifique el NICKNAME del usuario:\n");
            break;
        case 4:lista[id].Login=leer_campo(TAM_LOG_USER,"Modifique la CONTRASEÑA del usuario:\n");
            break;
        case 5:lista[id].Estado=leer_campo(TAM_EST_USER,"Modifique el ESTADO del usuario:\n");
            break;    
        }
    seguir=leer_numero("¿Desea seguir modificando los campos de este usuario?\n1-Si\n2-No");
    }while(seguir==1);
    }else
        printf("Saliendo...");
    }while(modificar==1);
}

void modificaUsuario(Usuarios* lista, int* id){
    int opcion;
    switch(opcion){
        case 1:lista[id].Nomb_usuario=leer_campo(TAM_NOM_USER,"Modifique el NOMBRE del usuario:\n");
            break;
        case 2:lista[id].Localidad=leer_campo(TAM_LOC_USER,"Modifique la LOCALIDAD del usuario:\n");
            break;
        case 3:lista[id].User=leer_campo(TAM_USE_USER,"Modifique el NICKNAME del usuario:\n");
            break;
        case 4:lista[id].Login=leer_campo(TAM_LOG_USER,"Modifique la CONTRASEÑA del usuario:\n");
            break;    
        }
}

void mostrarUsuario(Usuarios *lista, int* id){
printf("\nID:%s\nNombre:%s\nNick:%s\nContraseña:%s\nLocalidad:%s\nEstado:%s",lista[id].Id_usuario,lista[id].Nomb_usuario,lista[id].User,lista[id].Login,lista[id].Localidad,lista[id].Estado);   
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

// Cabecera: char* altaUsuarioInicio(Usuarios* lista, int* elemento, char *usuario)
// Precondicion: lista de usuarios , numero de elementos y el nombre de usuarios 
// Poscondicion: retorna el id del usuario tras registrarlo
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

// Cabecera: char* altaUsuario(Usuarios* lista, int* elemento)
// Precondicion: lista de usuarios y numero de elementos 
// Poscondicion: retorna el id del usuario tras registrarlo
char *altaUsuario(Usuarios *lista, int *elementos) {
    char *usuario;

    printf("\n\nRegistro de un nuevo usuario:\n\n");
    
    usuario = leer_campo(TAM_USE_USER, "Introduce nombre de usuario"); //Solicitamos el nombre del usuario
    
    return altaUsuarioInicio(lista, elementos, usuario);
}

// Cabecera: void bajaUsuario(Usuarios* lista, int* elemento)
// Precondicion: lista de usuarios y numero de elementos 
// Poscondicion: modifica a borrado un usuario
void bajaUsuario(Usuarios *lista, int *elementos) {
    char *id;
    int pos;

    printf("\n\nBorrado de un usuario:\n\n");
    
    id = leer_campo(TAM_ID_USER, "Introduce id de usuario"); //Solicitamos el nombre del usuario
    
    pos = buscar_usuario(id, lista, *elementos);
    
    lista[pos].Eliminado = "Si";
}

// Cabecera: void listarUsuario(Usuarios* lista, int* elemento)
// Precondicion: lista de usuarios y numero de elementos 
// Poscondicion: muestra los usuarios disponibles
void listarUsuario(Usuarios *lista, int *elementos) {
    int indice;
    Usuarios e;

    printf("\nID - Nombre - Localidad - Perfil - Usuario - Login - Estado - Eliminado");
    
    for (indice = 0; indice < *elementos; indice++) { //Vamos accediento a cada elemento
        e = lista[indice];
        
        printf("\n%s-%s-%s-%s-%s-%s-%s-%s", 
               e.Id_usuario, e.Nomb_usuario, e.Localidad, e.Perfil_usuario, 
               e.User, e.Login, e.Estado, e.Eliminado);
    }
}

// Cabecera: void login(Usuarios *lista, int *numeroElementos)
// Precondicion: lista de usuarios y el numero de elementos 
// Poscondicion: accede al menu principal según el usuario, en caso contrario o finalizar la funcion sale sin devolver nada
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

/**
// Cabecera: void menu_usuario(Usuarios *lista, int *numeroElementos)
// Precondicion: lista de usuarios y el numero de elementos 
// Poscondicion: accede al menu principal según el usuario, en caso contrario o finalizar la funcion sale sin devolver nada
void menu_usuario(int opc, char *id, Usuarios *ListaUsuarios, int *NumUser) {
    int x = -1, pos = -1;
    char *id_new;
    
    if (opc == 1) {
        do {
            printf("Bienvenido al menu de administración\n"
                    "Introduzca la opcion que desea\n\n "
                    "1: Alta usuario\n "
                    "2: Baja usuario\n "
                    "3: Modificar usuario\n "
                    "4: Mostrar usuarios\n "
                    "0: salir\n");
            x = leer_numero("Indica la opción");
            switch (x) {
                case 0:
                    break;
                case 1:
                    id = altaUsuario(ListaUsuarios,NumUser);
                    printf("\n\tDado de alta usuario nuevo con el id : %s\n", id_new);
                    break;
                case 2:
                    bajaUsuario(ListaUsuarios,NumUser);
                    break;
                case 3:
                    modificaAdmin(ListaUsuarios,NumUser);!!!!!!
                    break;
                case 4:
                    listarUsuario(ListaUsuarios,NumUser);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    } else {
        pos = buscar_usuario(id, ListaUsuarios, *NumUser);
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
                case 1: mostrarUsuario(ListaUsuarios,pos);
                    break;
                case 2: modificaUsuario(ListaUsuarios,pos);
                    break;
                default:
                    printf("Error al elegir la opcion.\t");
                    break;
            }
        } while (x != 0);
    }
}
 **/