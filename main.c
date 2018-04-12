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
#include "ficheros.h"
#include "comun.h"

int main() {

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

    login(L_Usuarios, &numeroUsuarios);

    guardarDatosUsuarios(L_Usuarios, numeroUsuarios);
    printf("\n\nHASTA PRONTO Y BUEN VIAJE\n\n");
    return (0);
}