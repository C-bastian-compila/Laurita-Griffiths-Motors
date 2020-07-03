#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"
#include "Map.h"
#include <windows.h>

int main(){

    system("color 3F");
    int opcion;
    tipoUsuario *usuario;
    bool usuarioReconocido = false;

    Map *mapaUsuario = createMap(stringHash,stringEqual);

    llenarBD(mapaUsuario);

    portada();
    printf("Presione cualquier tecla para continuar...");
    getch();

    while(1)
    {
        opcion = menu1();
        switch(opcion)
        {
            case 1:
                if(ingresarUsuario(usuario, mapaUsuario)) usuarioReconocido = true;
                break;
            case 2:
                registrarUsuario(mapaUsuario);
                break;
            case 3:
                menuAutos();//NO DEBE IR AQUI*************************
                //mostrarCategorias(mapas y tda);
                break;
            case 4:
                portada();
                return 0;
            case 5: //caso de prueba**********************************
                comprobarMapa(mapaUsuario);
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
