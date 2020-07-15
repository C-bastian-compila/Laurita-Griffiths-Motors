#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Funciones.h"
#include "MapaEnlazado.h"
#include "ArbolBinario.h"
#include "Map.h"
#include "list.h"

struct tipoAuto{ //******************************************************************

    unsigned int ID;
    char *nombre;
    char *marca;
    char *tipo;
    char *gama;
    char *estado;
    unsigned long long precio;
    unsigned int disponibles;
};

struct tipoUsuario{

    char *rut;
    char *clave;
    char *nombre;
    char *nacimiento;
    char *tipoDeUsuario;
    char *numeroTar;
    char *vencimientoTar;
    char *cvvTar;
};

int main(){

    system("color 0D");
    printf("\e[?25l");

    int opcion;
    char tecla;
    bool usuarioReconocido;
    tipoAuto *autoSelec;
    tipoAuto *aux;
    tipoUsuario *usuario;

    Map *mapaUsuario = createMap(stringHash,stringEqual);
    Mapx *mapaTipo = createMapx(equalTipoAuto);
    Mapx *mapaGama = createMapx(equalTipoAuto);
    Mapx *mapaMejoras = createMapx(equalTipoMejora);
    BinaryTree *arbolPrecios = createBinaryTree();

    llenarBD(mapaUsuario, mapaTipo, mapaGama, mapaMejoras, arbolPrecios);

    inicio:

    usuarioReconocido = false;
    autoSelec = NULL;
    aux = NULL;
    usuario = NULL;

    tipoMejora **vecMejoras = (tipoMejora **) calloc (7, sizeof(tipoMejora *));
    if(vecMejoras == NULL) return 1;

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
                usuario = ingresarUsuario(mapaUsuario);
                if(usuario != NULL) usuarioReconocido = true;
                break;

            case 2:

                printf("\e[?25h"); //HACE VISIBLE EL CURSOR
                registrarUsuario(mapaUsuario);
                break;

            case 3:

                autoSelec = mostrarAutos(mapaTipo, mapaGama, arbolPrecios);
                if(autoSelec != NULL)
                {
                    printf(" Tienes que estar registrado para poder comprar autos.\n");
                    getch();
                }
                break;

            case 4:
                portada();
                return 0;

            default:
                break;
        }
        if(usuarioReconocido) break;
    }

    printf("\e[?25l"); // ESCONDE EL CURSOR

    while(1)
    {
        system("@cls||clear");
        printf("\e[?25l");
        opcion = menu2();
        switch(opcion)
        {
            case 1: // Ver autos

                system("@cls||clear");
                aux = autoSelec;
                autoSelec = mostrarAutos(mapaTipo, mapaGama, arbolPrecios);
                if(autoSelec == NULL){
                    autoSelec = aux;
                    break;
                }
                else
                {
                    if(autoSelec->disponibles == 0)
                    {
                        autoSelec = NULL;
                        printf("El auto seleccionado actualmente no esta disponible, pruebe con otro.");
                        getch();
                        break;
                    }

                    printf(" El auto %s ha sido agregado al carro de compras. ", autoSelec->nombre);
                    printf("Presione cualquier tecla para continuar...\n");
                    getch();
                }
                for(int i = 0 ; i < 7 ; i++) vecMejoras[i] = NULL;

                break;

            case 2: // Mejorar y personalizar auto

                if(autoSelec != NULL)
                {
                    system("@cls||clear");
                    mostrarMejoras(mapaMejoras, vecMejoras, autoSelec->tipo);
                }
                else
                {
                    printf("\n Debes haber agregado un auto al carro de compras para poder personalizarlo.\n");
                    getch();
                    system("@cls||clear");
                }
                break;

            case 3: //Ir al carro de compras.

                if(autoSelec == NULL)
                {
                    printf("\n Debe agregar un auto al carro de compras. Presione cualquier tecla para volver continuar.\n");
                    getch();
                    system("@cls||clear");
                    break;
                }
                system("@cls||clear");
                if(comprar(autoSelec, vecMejoras, usuario))
                {
                    strcpy(usuario->tipoDeUsuario,"VIP");
                    pagar(usuario);
                    printf("\n");
                    printf(" BOLETA:\n");
                    boleta(autoSelec, vecMejoras);
                    printf(" Presione escape para salir o enter para continuar usando el programa...");
                    tecla = getch();
                    autoSelec->disponibles--;
                    actualizarBD(mapaGama, mapaUsuario);

                    if(tecla == VK_RETURN)
                    {
                        system("@cls||clear");
                        free(vecMejoras);
                        goto inicio;
                    }
                    if(tecla == VK_ESCAPE)
                    {
                        system("@cls||clear");
                        portada();
                        ExitProcess(1);
                    }
                }

                break;

            case 4: //Salir

                system("@cls||clear");
                portada();
                return 0;

            default:
                break;
        }
    }
    return 0;
}


/**
mejorar interfaz
Documentar funciones
quitar struct del main
PONER MAS LUJOSOS
*/
