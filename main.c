/* 
 * File:   main.c
 * Author: Jordi Güeto Matavera
 *
 * Created on 21 de marzo de 2018, 16:42
 * 
 * Fichero main del proyecto,  acceso a la aplicación
 */

#include "ficheros.h"
#include "comun.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
void menu_principal(int opc, int id, Usuarios *ListaUsuarios, int *NumUser);

/*
 * 
 */
int main() {

    char *user, *login, *perfil, *id;
    int exisUser = 0, passOK = 0, i, valor = 0;
    int numeroUsuarios;
    Usuarios* L_Usuarios;

    printf("                                                                                             BHU##mgmgm#U\n"
            "                                                                                     BHUUmmgm            mm$\n"
            "                                                                             BHV#mggmm                     mm$\n"
            "                                                                     HHU#mqmmm                               m#\n"
            "                                                             BHU#mggm                                         mU\n"
            "                                                     HHV#mgmm                                                   Z\n"
            "                                             HUUZmgmmm                                                           $\n"
            "                                    BB8UZmgmm                                                                    m\n"
            "                            BHHAmmgmm                                                                             d\n"
            "                    BHU##mgmm                                                                                     m\n"
            "                 Umm                                                                                               d\n"
            "              @$m                                                                 $                                #\n"
            "             Am                                                               YBBBBB!                @Y$           m\n"
            "            q                                                               BBB|BBBBB     UUH    BBBUBBB            $\n"
            "          m                                               VS               BBBBwggaB  Y''BBBBB9  çBBBBBB            #\n"
            "          m                                               iii              EBBBm    gm BBB|B<BB  cBB<wym            m\n"
            "         D                                         VYYY$  zll    8Y1BB9    BB|B        sw   cBB$ kBBB               #\n"
            "        @m                                     VYliillii  klid  liiilBiB   BBBj          DY!BBBB kBBj               #\n"
            "        X                    #1nd              clllBslliB milB  |BwmglBB   BBBj         !BBB|BBB EBBB               d\n"
            "       @m              BUU$   nod      UH      kllB  piBB  ilB  w  @TlBl   cBBB        BBBumEBBB  BBB               m\n"
            "       h           8VSBnnnnX  ono   XnnnnBX    EiBB  kiim  cBl   D1iiBli$  kB|B      V B|B  #B|B  BBB              @m\n"
            "       $          mBnnnnnnon  2on  hnnoooon$    iBBVYiBBV  CBi$ DiBBgpilB  m;BBB    FB B|B9HBBBB  >BB              E\n"
            "       m           nonm moon  Enn$ mom  mnnd    cBlilllliB kllB CBl   iBB   cB|BBYYBBB$cBBB;<>BB  aww              m\n"
            "      #            2oo#  knn  mno$    8SnooB    kilBwygBllBmlBB zBiUB1lli    cBBBBBBBsm aB<a gm                    Bm\n"
            "      D            Enod UBn#   BoB  B1nBqooo    kllB   klBB BBB kiBiiBzBa     w>|B<sy                             m\n"
            "      E            mnoonnnonn$ ooX  1on  kno     ill   CBlj zll  oliam                                           Dm\n"
            "      #             BooowwoooB 2on #nod  Snn$    BBiUV1lBim kiim                                                @m\n"
            "      E             ooo    non hnnm nooVSBonB    eBllilllm   m                                                  m\n"
            "      m             kond   nonmmnod p1onnmwm     klllBay                                                       q\n"
            "       $            hnod BSnon  nnB  mwm         muym                                                        Bq\n"
            "       #            moooonnnn   wmm                                                                        @G\n"
            "       Z             noonnog                                                                             8Gm\n"
            "        $            owmm                                                                          8HH#mm\n"
            "        Z                                                                                    H#mqmm\n"
            "         $                                                                                   Z\n"
            "         Z                                                                BBUU#mqgU          m\n"
            "          d                                                        UHUZmgmm        gU         d\n"
            "           d                                              BU8U#mgmm                  mZ       #\n"
            "            Z                                     BUH#mqgmm                            mZ     m\n"
            "             Z                            BUH#mqmm                                       mm$   #\n"
            "              mZ                  B8U#mmgm                                                  pH E\n"
            "                mpU$      BUH#mqmmm                                                           mZ$\n"
            "                    mgmgmm                                                                      m\n\n");
    printf("\n\nBIENVENIDO A LA APLICACIÓN");

    L_Usuarios = obtenerUsuarios(&numeroUsuarios);

    printf("\n\nINTRODUZCA SU USUARIO Y CONTRASEÑA PARA ACCEDER:\n\n");

    user = leer_campo(TAM_USE_USER, "Introduce nombre de usuario"); //Solicitamos el nombre del usuario

    i = 0;
    while (i < numeroUsuarios && exisUser == 0) { //Buscamos el nombre del usuario si existe
        valor = strncmp(user, L_Usuarios[i].User, TAM_NOM_USER);
        if (!strncmp(user, L_Usuarios[i].User, TAM_NOM_USER)) {
            exisUser = 1; //Si hay una concidencia guardamos y salimos
            perfil = L_Usuarios[i].Perfil_usuario;
        }
        i++;
    }

    if (exisUser == 0) { //Si el usuario no existe creamos una cuenta nueva
        printf("\nUsuario indicado no existe, accediendo para crear una cuenta\n");
        perfil = "usuario";
        id = altaUsuarioInicio(L_Usuarios, &numeroUsuarios, user); //Función que crea el usuario con el nombre de usuario indicado que no existe que retorna el ID
        if (id != 0) {
            menu_principal(0, (int) *id, L_Usuarios, &numeroUsuarios); //Se fija valor 0 ya que un usuario creado asi nunca será un administrador
        } else {
            printf("Error al crear el usuario.");
        }
    } else {
        i--;

        login = leer_campo(TAM_LOG_USER, "Introduce el password"); //Solicitamos la contraseña del usuario

        if (strcmp(login, L_Usuarios[i].Login)) {
            passOK = 1;
            id = L_Usuarios[i].Id_usuario;
            if (passOK == 1 && exisUser == 1) {
                menu_principal(!strcmp(perfil, (char *) "administrador"), (int) *id, L_Usuarios, &numeroUsuarios);
            }
        } else {
            printf("\nError contraseña erronea\n");
            printf("Saliendo del sistema\n");
        }
    }

    guardarDatosUsuarios(L_Usuarios, numeroUsuarios);
    printf("\n\nHASTA PRONTO Y BUEN VIAJE\n\n");
    return (0);
}

// Cabecera: int menu_principal(int opc, int id, Usuarios ListaUsuarios, int NumUser)
// Precondicion: Valor 1 para administrados, valor <> 1 para usuario
// Poscondicion:  Accede a los distintos menus de la aplicación, no retorna nada

void menu_principal(int opc, int id, Usuarios *ListaUsuarios, int *NumUser) {
    int x;

    if (opc = 1) {
        do {
            printf("Introduzca la opcion que desea\n\n "
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
        do {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Perfil\n "
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
    }
}