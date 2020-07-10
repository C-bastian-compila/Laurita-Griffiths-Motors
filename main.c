#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"
#include "Map.h"
#include <windows.h>

int main(){

    system("color 3F");
    int opcion;
    int opcionMenuAuto;
    tipoAuto *autoSelec;
    tipoUsuario *usuario;
    bool usuarioReconocido = false;

    Map *mapaUsuario = createMap(stringHash,stringEqual);
    Mapx *mapaTipo = createMapx();
    Mapx *mapaGama = createMapx();

    llenarBD(mapaUsuario, mapaTipo, mapaGama);

    portada();
    printf("Presione cualquier tecla para continuar...");
    getch();

    while(1)
    {
        printf("\e[?25l"); // ESCONDE EL CURSOR

        opcion = menu1();
        switch(opcion)
        {
            case 1:
                printf("\e[?25h"); // HACE VISIBLE EL CURSOR
                if(ingresarUsuario(usuario, mapaUsuario)) usuarioReconocido = true;
                break;
            case 2:
                printf("\e[?25h"); //HACE VISIBLE EL CURSOR
                registrarUsuario(mapaUsuario);
                break;
            case 3:
                autoSelec = mostrarAutos(mapaTipo, mapaGama);
                if(autoSelec != NULL)
                {
                    printf("Tienes que estar registrado para poder comprar autos.\n");
                    getch();
                }
                break;
            case 4:
                portada();
                return 0;
            case 5: //caso de prueba**********************************
                comprobarMapa(mapaTipo);
            default:
                break;
        }
        if(usuarioReconocido) break;
    }
    printf("AQUI DEBERIA PASAR AL SIGUIENTE MENU\n");//****************************************
    return 0;
    while(1)
    {
        //opcion = menu2();
    }

    return 0;
}
