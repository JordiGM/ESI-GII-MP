/* 
 * File:   main.c
 * Author: Jordi Güeto Matavera
 *
 * Created on 21 de marzo de 2018, 16:42
 * 
 * Fichero main del proyecto,  acceso a la aplicación
 */

#include "ficheros.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    Usuarios L_Usuario[1];
    char user[6], login[9], perfil[15];
    int elementos, exisUser=0, passOK=0, i, id;

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
           "      #            2oo#  knn  mno$    8SnooB    kilBwygBllBmlBB zBiUB1lli    cBBBBBBBsm aB<a gm                     Bm\n"
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
    
    printf("\n\nINTRODUZCA SU USUARIO Y CONTRASEÑA PARA ACCEDER:");
    
    printf("Introduce nombre de usuario:\n");                                   //Solicitamos el nombre del usuario
    fgets (user, 6, stdin);

    i=0;
    while(i<elementos || exisUser==0){                                          //Buscamos el nombre del usuario si existe
        if(strcmp(user,L_Usuario[i].User)){
            exisUser=1;                                                         //Si hay una concidencia guardamos y salimos
            strcpy(L_Usuario[i].Perfil_usuario,perfil);
        }
        i++;
    }
    
    if(exisUser==0){                                                            //Si el usuario no existe creamos una cuenta nueva
        printf("\nUsuario indicado no existe, accediendo para crear una cuenta\n");
        altaUsuarioInicio(L_Usuario,user);
    }
    else{
        i--;
       
        printf("Introduce el password:\n");                                     //Solicitamos la contraseña del usuario
        fgets (login, 9, stdin);

        if(strcmp(login,L_Usuario[i].Login)){
            passOK=1;
            id=L_Usuario[i].Id_usuario;
            if(passOK==1 && exisUser==1){
                menu_principal(strcmp(perfil,"administrador"),id);
            }
        }
        else{
            printf("\nError contraseña erronea\n");
            printf("Saliendo del sistema\n");
        }
    }

    return (0);
}

// Cabecera: void menu_principal(E entero opc, E entero id)
// Precondicion: Valor 1 para administrados, valor <> 1 para usuario
// Poscondicion:  Accede a los distintos menus de la aplicación, no retorna nada
void menu_principal(int opc, int id)
{
    int x;
    
    if(opc=1){
        do
        {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Menú usuarios\n "
                    "2: Menú vehiculos\n "
                    "3: Menú viajes\n "
                    "4: Menú incidencias\n "
                    "0: salir\n");
            scanf("%d",&x);
            switch (x)
            {
            case 0:
                exit(0);
            case 1:
                menu_usuario();
                menu_principal(opc,id);
                break;
            case 2:
                menu_alumno();
                menu_principal(opc,id);
                break;
            case 3:
                menuMaterias();
                menu_principal(opc,id);
                break;
            case 4:
                menuHorarios();
                menu_principal(opc,id);
                break;
            default:
                printf("Error al elegir la opcion.\t");
                break;
            }
        }while(x!=0);
    }
    else{
        do
        {
            printf("Introduzca la opcion que desea\n\n "
                    "1: Perfil\n "
                    "2: Menú vehiculos\n "
                    "3: Menú viajes\n "
                    "4: Menú incidencias\n "
                    "0: salir\n");
            scanf("%d",&x);
            switch (x)
            {
            case 0:
                exit(0);
            case 1:
                menu_usuario();
                menu_principal(opc,id);
                break;
            case 2:
                menu_alumno();
                menu_principal(opc,id);
                break;
            case 3:
                menuMaterias();
                menu_principal(opc,id);
                break;
            case 4:
                menuHorarios();
                menu_principal(opc,id);
                break;
            default:
                printf("Error al elegir la opcion.\t");
                break;
            }
        }while(x!=0);
    }
}