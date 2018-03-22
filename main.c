/* 
 * File:   main.c
 * Author: Jordi Güeto Matavera
 *
 * Created on 21 de marzo de 2018, 16:42
 * 
 * Fichero main del proyecto,  acceso a la aplicación
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    char login[6], pass[9], perfil[15];
    int elementos, exisUser=0, passOK=0, errorPass=0, i, id;

    printf(" \n"
           "                                                                                             BHU##mgmgm#U\n"
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
           "             Am                                                               Y+===+!                @Y$           m\n"
           "            q                                                               B(:|=+=+=     UUH    }+=U=;3            $\n"
           "          m                                               VS               (=+=wgga;  Y''+==:+9  (++===]            #\n"
           "          m                                               iii              E=++m    gm ===|=<+=  c++<wym            m\n"
           "         D                                         VYYY$  zll    8Y1II9    [=|]        sw   c==$ k=+3               #\n"
           "        @m                                     VYliillii  klid  liiilIi3   (+=j          DY!=+=3 k=+j               #\n"
           "        X                    #1nd              clllvslli3 mil3  |vwmglIv   (++j         !;;:|=+3 E=+]               d\n"
           "       @m              BUU$   nod      UH      kll3  piI3  ilv  w  @TlIl   c==]        (==umE=+]  =+)               m\n"
           "       h           8VSvnnnnX  ono   XnnnnvX    EiIv  kiim  cIl   D1iivli$  k=|+      V :|=  #=|)  =+=              @m\n"
           "       $          mvnnnnnnon  2on  hnnoooon$    iIvVYiI3V  Cvi$ Di%vgpil3  m;+=]    F: =|=9H(++=  >==              E\n"
           "       m           nonm moon  Enn$ mom  mnnd    cvlilllliI kll3 CIl   iI3   c=|=)YY(:=$c=+=;<>==  aww              m\n"
           "      #            2oo#  knn  mno$    8Snoo3    kilvwyg%ll3mlI3 zIiUB1lli    c=++==+=sm a=<a gm                   Bm\n"
           "      D            Enod Uvn#   vo3  B1nvqooo    kll3   klI3 %II kiviivzva     w>|=<sy                             m\n"
           "      E            mnoonnnonn$ ooX  1on  kno     ill   CIlj zll  oliam                                           Dm\n"
           "      #             vooowwooo3 2on #nod  Snn$    %viUV1lIim kiim                                                @m\n"
           "      E             ooo    non hnnm nooVSvon3    eIllilllm   m                                                  m\n"
           "      m             kond   nonmmnod p1onnmwm     klllvay                                                       q\n"
           "       $            hnod BSnon  nn3  mwm         muym                                                        Bq\n"
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
    
    do{
        printf("Introduce nombre de usuario:\n");
        fgets (login, 6, stdin);

        /*Conmrpobamos con el array de usuarios la existencia del usuario, en caso contrario error*/
        i=0;
        while(i<elementos || exisUser==0){
            if(strcmp(login,L_Usuario[i].login)){
                exisUser=1;
                strcpy(L_Usuario[i].perfil,perfil);
            }
        }

        if(exisUser==0){
            printf("\nError el alumno no indicado no existe\n");
        }
    }while(exisUser==0);
    
    do{
        printf("Introduce el password:\n");
        fgets (pass, 9, stdin);
        
        /*Conmrpobamos con el array de usuarios si la contraseña, en caso contrario error*/
        i=0;
        while(i<elementos || passOK==0){
            if(strcmp(pass,L_Usuario[i].pass)){
                passOK=1;
                id=L_Usuario[i].id_usuario  ;
            }
        }

        if(passOK==0){
            printf("\nError contraseña erronea\n");
            errorPass++;
            printf("Te quedan %d intentos.\n"3-errorPass);
        }
    }while(passOK==0 && errorPass<3);
    
    if(passOK==1 && exisUser==1){
        menu_principal(strcmp(perfil,"administrador"),id);
    }
    
    
    return (0);
}

