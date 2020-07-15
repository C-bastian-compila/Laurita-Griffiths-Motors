#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "Funciones.h"
#include "Map.h"
#include "MapaEnlazado.h"
#include "ArbolBinario.h"
#include "list.h"

#define abajo 0x50
#define arriba 0x48

// ESTRUCTURAS ----------------------------------------------------------------------------------------------------------------

struct tipoMejora{

    char *nombre;
    char *tipo;
    unsigned long precio;
};

// MENUS ---------------------------------------------------------------------------------------------------------------------

void portada(){

    FILE *menu = fopen ("menu1.txt", "rb");
    if(menu == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        ExitProcess(1);
    }
    char a[1001];
    while (fgets(a,1000,menu) != NULL)
    {
        printf ("%s", a);
    }
    printf("\n");
}

int menu1(){

    int MenuInicio = 1, MenuFin = 4, LineaDeInicio = 6, Menu = 1;
    system("@cls||clear");
    while (1){
        FILE *menu2 = fopen ("menu2.txt", "rb");
        if(menu2 == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO");
            return 1;
        }
        char a[1001];

        while (fgets(a,1000,menu2) != NULL) {
            printf (" %s", a);
        }

        printf("\n");

        int Menu = 1;

        goy(LineaDeInicio);
        printf("   Iniciar Sesion \n");
        printf("   Registrar nueva cuenta \n");
        printf("   Ver autos \n");
        printf("   Salir \n");

        char tecla;

        goy(LineaDeInicio);
        printf("->");

        while(1) {
            tecla = getch();
            if (tecla == arriba) {
                Menu = Menu == MenuInicio ? MenuFin: --Menu;
                printf("\r  ");
                goy(LineaDeInicio + Menu-1);
                printf("->");
            } else if (tecla == abajo) {
                Menu = Menu == MenuFin ? MenuInicio: ++Menu;
                printf("\r  ");
                goy(LineaDeInicio + Menu-1);
                printf("->");
            } else if (tecla == VK_RETURN) {
                break;
            }
        }
        goy(10);
        system("@cls||clear");
        return Menu;
   }

}

int menu2(){

    system("@cls||clear");

    char tecla;
    int MenuInicio = 1, MenuFin = 4, LineaDeInicio = 6, Menu = 1;

    FILE *menu2 = fopen ("menu2.txt", "rb");
        if(menu2 == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO");
            return 1;
        }
        char a[1001];

        while (fgets(a,1000,menu2) != NULL) {
            printf (" %s", a);
        }

    printf("\n");

    goy(LineaDeInicio);

    printf("   Ver autos \n");
    printf("   Mejorar y personalizar carro \n");
    printf("   Ir al carro de compras \n");
    printf("   Salir \n");

    goy(LineaDeInicio);
    printf("->");

    while(1)
    {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);
    return Menu;
}

int menuTipo(){

    int MenuInicio = 1, MenuFin = 6, LineaDeInicio = 2, Menu = 1;
    printf("\t\t MENU TIPO\n");
    goy(LineaDeInicio);
    printf("   Casual \n");
    printf("   Deportivo \n");
    printf("   Deportivo Lujoso \n");
    printf("   Lujoso \n");
    printf("   Todo terreno \n");
    printf("   Volver atras \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);
    system("@cls||clear");
    return Menu;
}

int menuGama(){

    int MenuInicio = 1, MenuFin = 4, LineaDeInicio = 2, Menu = 1;
    printf("\t\t MENU GAMA\n");
    goy(LineaDeInicio);
    printf("   Baja \n");
    printf("   Media \n");
    printf("   Alta \n");
    printf("   Volver atras \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);
    system("@cls||clear");
    return Menu;
}

int menuAutos(){

    int MenuInicio = 1, MenuFin = 4, LineaDeInicio = 2, Menu = 1;
    printf("\t\t MENU AUTOS\n");
    goy(LineaDeInicio);
    printf("   Mostrar lista de Precios \n");
    printf("   Mostrar por tipo \n");
    printf("   Mostrar por gama \n");
    printf("   Volver al menu principal \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);
    system("@cls||clear");
    return Menu;
}

int menuMejora(){

    int MenuInicio = 1, MenuFin = 4, LineaDeInicio = 2, Menu = 1;
    printf("\t\t MENU MEJORA\n");
    goy(LineaDeInicio);
    printf("   Ver mejoras \n");
    printf("   Agregar o quitar mejora \n");
    printf("   Personalizar color \n");
    printf("   Volver atras \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);
    system("@cls||clear");
    return Menu;
}

// FUNCIONES COMPRA ---------------------------------------------------------------------------------------------------------------------

void *menuRecorrer(Mapx *mapa, bool *compra){

    tipoAuto *autoSelec;

    int Menu = 1, MenuInicio = 1, MenuFin = 4, LineaDeInicio3 = 12;
    goy(LineaDeInicio3);

    printf("   Anterior \n");
    printf("   Siguiente \n");
    printf("   Agregar al carro \n");
    printf("   Volver atras \n");

    char tecla;

    goy(LineaDeInicio3);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio3 + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio3 + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }
    goy(10);

    switch(Menu)
    {

        case 1:

            autoSelec = mapxPrevList(mapa);
            break;

        case 2:

            autoSelec = mapxNextList(mapa);
            break;

        case 3:

            autoSelec = mapxCurrent(mapa);
            *compra = true;
            break;

        case 4:

            autoSelec = NULL;
            break;

        default:

            break;

    }

    return autoSelec;
}

void *mostrarAutos(Mapx *mapaTipo, Mapx *mapaGama, BinaryTree *arbolPrecios){

    tipoAuto *autoSelec;
    int opcionMenuAuto;

    do
    {
        opcionMenuAuto = menuAutos();
        switch(opcionMenuAuto)
        {
            case 1: //MOSTRAR LISTA DE PRECIOS.
                mostrarPrecios(arbolPrecios);
                break;

            case 2: // OPCION TIPO
                autoSelec = mostrarTipo(mapaTipo);
                break;

            case 3: //OPCION GAMA
                autoSelec = mostrarGama(mapaGama);
                break;

            case 4:
                return NULL;

            default:
                break;
        }
        if(autoSelec != NULL ) return autoSelec;
        else system("@cls||clear");

    }while(1);
}

void *mostrarTipo(Mapx *mapa){

    int opcion;

    tipoAuto *autoSelec;
    bool compra = false;

    do
    {
        opcion = menuTipo();

        switch(opcion)
        {
            case 1: // CASUAL

                autoSelec = searchMapx(mapa, "Casual");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 2: // DEPORTIVO

                autoSelec = searchMapx(mapa, "Deportivo");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 3: //DEPORTIVO LUJOSO

                autoSelec = searchMapx(mapa, "Deportivo Lujoso");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 4: // LUJOSO

                autoSelec = searchMapx(mapa, "Lujoso");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 5: //TODO TERRENO

                autoSelec = searchMapx(mapa, "Todo terreno");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 6: //VOLVER ATRAS

                return NULL;

            default:
                break;
        }

        system("@cls||clear");

    }while(1);

}

void *mostrarGama(Mapx *mapa){

    int opcion;

    tipoAuto *autoSelec;
    bool compra = false;

    do
    {
        opcion = menuGama();

        switch(opcion)
        {
            case 1: // BAJA

                autoSelec = searchMapx(mapa, "Baja");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 2: // MEDIA

                autoSelec = searchMapx(mapa, "Media");
                do
                {
                    imprimirAuto(autoSelec);
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 3: // ALTA

                autoSelec = searchMapx(mapa, "Alta");
                do
                {
                    imprimirAuto(autoSelec);
                    printf("\n\n");
                    autoSelec = menuRecorrer(mapa, &compra);
                    if(autoSelec == NULL) break;
                    if(compra == true) return autoSelec;

                    system("@cls||clear");

                }while(1);

                break;

            case 4: // VOLVER ATRAS

                return NULL;

            default:
                break;
        }

        system("@cls||clear");

    }while(1);

}

void mostrarPrecios(BinaryTree *arbol){

    int i;
    tipoAuto* dato = firstBinaryTree(arbol);
    if(dato == NULL) return;

    int MenuInicio = 1, MenuFin = 2, LineaDeInicio = 22, Menu = 1;

    char tecla;

    do
    {
        printf("\t\t MENU PRECIO\n");
        goy(LineaDeInicio);
        printf("   Siguientes \n");
        printf("   Volver al menu anterior \n");

        goy(2);

        for(i = 0; i < 5; i++)
        {

            printf(" Nombre: %s\n", dato->nombre);
            printf(" Tipo: %s\n", dato->tipo);
            printf(" Precio: %llu\n\n", dato->precio);
            dato = nextBinaryTree(arbol);

            if(dato == NULL)
            {
                goy(LineaDeInicio);
                printf(" Se han mostrado todos los vehiculos. Presione cualquier tecla para volver al menu anterior...\n");
                printf("\r                                                        ");
                getch();
                return;
            }
        }

        goy(LineaDeInicio);
        printf("->");

        while(1) {
            tecla = getch();
            if (tecla == arriba) {
                Menu = Menu == MenuInicio ? MenuFin: --Menu;
                printf("\r  ");
                goy(LineaDeInicio + Menu-1);
                printf("->");
            } else if (tecla == abajo) {
                Menu = Menu == MenuFin ? MenuInicio: ++Menu;
                printf("\r  ");
                goy(LineaDeInicio + Menu-1);
                printf("->");
            } else if (tecla == VK_RETURN) {
                break;
            }
        }
        goy(10);
        system("@cls||clear");

        switch (Menu){

            case 1:

                break;

            case 2:
                return;

            default:
                break;

        }


    }while(1);







}

void imprimirAuto(tipoAuto *autoSelec){

    printf("\t\tINFO DEL AUTO\n\n");;
    printf(" Modelo: %s\n",autoSelec->nombre);
    printf(" Tipo: %s\n",autoSelec->tipo);
    printf(" Gama: %s\n",autoSelec->gama);
    printf(" Marca: %s\n",autoSelec->marca);
    printf(" Estado: %s\n",autoSelec->estado);
    printf(" Precio: %llu\n",autoSelec->precio);
    if(autoSelec->disponibles > 0) printf(" Auto Disponible\n");
    else printf(" Auto no Disponible\n");
    printf("\n");

}

void imprimirBoleta(tipoAuto *autoSelec){

    printf("\t\tINFO DEL AUTO\n\n");;
    printf(" Modelo: %s\n",autoSelec->nombre);
    printf(" Tipo: %s\n",autoSelec->tipo);
    printf(" Gama: %s\n",autoSelec->gama);
    printf(" Marca: %s\n",autoSelec->marca);
    printf(" Estado: %s\n",autoSelec->estado);
    printf(" Precio: %llu\n",autoSelec->precio);
    printf("\n");
}

void mostrarMejoras(Mapx *mapa, tipoMejora **vecMejoras, char *tipo){

    int opcion;
    int i;
    bool hayMejora;
    unsigned long long suma;

    do
    {
        system("@cls||clear");
        opcion = menuMejora();
        hayMejora = false;

        switch(opcion)
        {
            case 1: // VER MEJORAS
                suma = 0;
                printf("\t MEJORAS AGREGADAS\n\n");
                for(i = 0; i < 7; i++)
                {

                    if(vecMejoras[i] != NULL)
                    {
                        printf(" Nombre: %s\n",vecMejoras[i]->nombre);
                        printf(" Precio: %d\n",vecMejoras[i]->precio);
                        printf("\n");
                        suma += vecMejoras[i]->precio;
                        hayMejora = true;
                    }

                }
                if(hayMejora == false)
                {
                    printf(" No hay mejoras agregadas al auto.\n\n");
                }
                else printf(" TOTAL: %llu\n\n", suma);
                printf(" Presione cualquier tecla para volver atras...\n");
                getch();

                break;

            case 2: // AGREGAR MEJORA

                elegirMejora(mapa,vecMejoras,tipo);
                break;

            case 3: // ELEGIR COLOR

                elegirColor(mapa,vecMejoras);
                break;

            case 4: // VOLVER ATRAS

                return;

            default:

                break;
        }

    }while(1);
}

void elegirMejora(Mapx *mapa, tipoMejora **vecMejoras, char *tipo){

    tipoMejora *mejora = searchMapx(mapa, tipo);
    bool repetido;
    int i;

    int Menu = 1, MenuInicio = 1, MenuFin = 5, LineaDeInicio2 = 7;

    do
    {

        repetido = false;

        system("@cls||clear");

        printf("\t MEJORAS\n\n");
        printf(" Nombre: %s\n",mejora->nombre);
        printf(" Precio: %d\n",mejora->precio);

        Menu = 1;
        goy(LineaDeInicio2);

        printf("   Anterior \n");
        printf("   Siguiente \n");
        printf("   Agregar mejora \n");
        printf("   Quitar mejora \n");
        printf("   Volver atras \n");

        char tecla;

        goy(LineaDeInicio2);
        printf("->");

        while(1) {
            tecla = getch();
            if (tecla == arriba) {
                Menu = Menu == MenuInicio ? MenuFin: --Menu;
                printf("\r  ");
                goy(LineaDeInicio2 + Menu-1);
                printf("->");
            } else if (tecla == abajo) {
                Menu = Menu == MenuFin ? MenuInicio: ++Menu;
                printf("\r  ");
                goy(LineaDeInicio2 + Menu-1);
                printf("->");
            } else if (tecla == VK_RETURN) {
                break;
            }
        }
        goy(10);

        switch(Menu)
        {

            case 1:

                mejora = mapxPrevList(mapa);
                break;

            case 2:

                mejora = mapxNextList(mapa);
                break;

            case 3:

                for(i = 0; i < 6; i++)
                {
                    if(vecMejoras[i] != NULL){
                        if(equalTipoMejora(mejora, vecMejoras[i]) == 1)
                        {
                            repetido = true;
                            break;
                        }
                    }
                }
                if(repetido == true)
                {
                    goy(5);
                    printf(" La mejora ya ha sido agregada anteriormente.");
                    getch();
                    break;
                }

                for(i = 0; i < 6; i++)
                {
                    if(vecMejoras[i] == NULL)
                    {
                        vecMejoras[i] = mejora;
                        goy(5);
                        printf(" Mejora agregada :D\n");
                        getch();
                        break;
                    }
                }
                break;

            case 4:

                for(i = 0; i < 6; i++)
                {
                    if(vecMejoras[i] == NULL)
                    {
                        goy(5);
                        printf(" La mejora que intenta quitar no ha sido agregada anteriormente.\n");
                        getch();
                        break;
                    }
                    if(equalTipoMejora(mejora, vecMejoras[i]) == 1)
                    {
                        vecMejoras[i] = NULL;
                        goy(5);
                        printf(" Mejora quitada correctamente.\n");
                        getch();
                        break;
                    }
                }


                break;


            case 5:

                return;

            default:

                break;

        }
    }while(1);
}

void elegirColor(Mapx *mapa, tipoMejora **vecMejoras){
    tipoMejora *color = searchMapx(mapa, "color");
    bool repetido;
    int i;

    int Menu = 1, MenuInicio = 1, MenuFin = 5, LineaDeInicio2 = 7;

    do
    {

        repetido = false;

        system("@cls||clear");

        printf("\t COLORES\n\n");
        printf(" %s\n",color->nombre);
        printf(" Precio: %d\n",color->precio);

        Menu = 1;
        goy(LineaDeInicio2);

        printf("   Anterior \n");
        printf("   Siguiente \n");
        printf("   Agregar color \n");
        printf("   Quitar color \n");
        printf("   Volver atras \n");

        char tecla;

        goy(LineaDeInicio2);
        printf("->");

        while(1) {
            tecla = getch();
            if (tecla == arriba) {
                Menu = Menu == MenuInicio ? MenuFin: --Menu;
                printf("\r  ");
                goy(LineaDeInicio2 + Menu-1);
                printf("->");
            } else if (tecla == abajo) {
                Menu = Menu == MenuFin ? MenuInicio: ++Menu;
                printf("\r  ");
                goy(LineaDeInicio2 + Menu-1);
                printf("->");
            } else if (tecla == VK_RETURN) {
                break;
            }
        }
        goy(10);

        switch(Menu)
        {

            case 1:

                color = mapxPrevList(mapa);
                break;

            case 2:

                color = mapxNextList(mapa);
                break;

            case 3:

                if(vecMejoras[6] == NULL)
                {
                    vecMejoras[6] = color;
                    goy(5);
                    printf(" Color agregado :D\n");
                    getch();
                    return;
                }
                else
                {
                    vecMejoras[6] = color;
                    goy(5);
                    printf(" Color reemplazado :D\n");
                    getch();
                    return;
                }

                break;

            case 4:

                if(vecMejoras[i] == NULL)
                {
                    goy(5);
                    printf(" El color que intenta quitar no ha sido agregado anteriormente.\n");
                    getch();
                    break;
                }
                if(equalTipoMejora(color, vecMejoras[6]) == 1)
                {
                    vecMejoras[6] = NULL;
                    goy(5);
                    printf(" Color quitado correctamente.\n");
                    getch();
                    break;
                }

                break;


            case 5:

                return;

            default:

                break;

        }
    }while(1);
}

void pagar(tipoUsuario *usuario){

    printf("\e[?25h");
    char dato[101];

    do{
        system("@cls||clear");
        printf("\t\tMENU PAGAR\n\n");
        printf("Ingrese numero de tarjeta: ");
        scanf("%[^\n]100s", dato);
        fflush(stdin);
        printf("\n");
        if(!stringEqual(usuario->numeroTar, dato))
        {
            printf("Numero de tarjeta erroneo.\n");
            printf("Presione cualquier tecla para intentar nuevamente...");
            getch();
            continue;
        }
        printf("Ingrese fecha de vencimiento de la tarjeta: ");
        scanf("%[^\n]100s", dato);
        fflush(stdin);
        printf("\n");
        if(!stringEqual(usuario->vencimientoTar, dato))
        {
            printf("Fecha de vencimiento erronea.\n");
            printf("Presione cualquier tecla para intentar nuevamente...");
            getch();
            continue;
        }
        printf("Ingrese numero verificador: ");
        scanf("%[^\n]100s", dato);
        fflush(stdin);
        printf("\n");
        if(!stringEqual(usuario->cvvTar, dato))
        {
            printf("Numero de verificacion erroneo.\n");
            printf("Presione cualquier tecla para continuar nuevamente...");
            getch();
            continue;
        }
        printf("\t      DATOS CORRECTOS.\n\n");
        printf("Presione cualquier tecla para continuar...");
        getch();
        break;
    }while(1);
    system("@cls||clear");
    return;
}

bool comprar(tipoAuto *autoSelec, tipoMejora **mejoras, tipoUsuario *usuario, unsigned long long *precio){

    int i, LineaDeInicio = 20, MenuInicio = 1, MenuFin = 2, Menu = 1;
    char a[1001];

    unsigned long long total = autoSelec->precio;

    FILE *menu2 = fopen ("menu2.txt", "rb");
    if(menu2 == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        return 1;
    }

    while (fgets(a,1000,menu2) != NULL) {
        printf ("\t   %s", a);
    }

    printf("\n");

    imprimirAuto(autoSelec);

    printf("\t\t   MEJORAS\n\n");

    if(mejoras[0] != NULL || mejoras[6] != NULL)
    {
        for(int i = 0; i < 7 ; i++)
        {
            if(mejoras[i] != NULL)
            {
                printf(" Nombre: %s\n",mejoras[i]->nombre);
                printf(" Precio: %d\n",mejoras[i]->precio);
                printf("\n");
                total += mejoras[i]->precio;
                LineaDeInicio += 3;
            }
        }
    }
    else
    {
        LineaDeInicio += 2;
        printf(" No hay mejoras agregadas al auto.\n\n");
    }

    printf(" PRECIO TOTAL = $%llu\n\n", total);

    if(strcmp(usuario->tipoDeUsuario, "VIP") == 0)
    {
        total -= (unsigned long long)ceil(total * 0.1);
        printf(" Se ha descontado el diez por ciento por ser Usuario VIP.\n\n");
        printf(" PRECIO TOTAL CON DESCUENTO = $%llu\n", total);
        LineaDeInicio += 4;
    }

    *precio = total;

    goy(LineaDeInicio);
    printf("   Pagar \n");
    printf("   Volver \n");

    goy(LineaDeInicio);
    printf("->");
    char tecla;
    while(1) {
        tecla = getch();
        if (tecla == arriba) {
            Menu = Menu == MenuInicio ? MenuFin: --Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == abajo) {
            Menu = Menu == MenuFin ? MenuInicio: ++Menu;
            printf("\r  ");
            goy(LineaDeInicio + Menu-1);
            printf("->");
        } else if (tecla == VK_RETURN) {
            break;
        }
    }

    if(Menu == 1) return true;
    else return false;
}

void boleta(tipoAuto *autoSelec, tipoMejora **mejoras, unsigned long long precio){

    printf("---------------------------------------------\n");
    imprimirBoleta(autoSelec);
    printf("---------------------------------------------\n");
    printf("\t\t   MEJORAS\n\n");
    if(mejoras[0] != NULL || mejoras[6] != NULL ){
        for(int i = 0; i < 7 ; i++)
        {
            if(mejoras[i] != NULL)
            {
                printf(" Nombre: %s\n",mejoras[i]->nombre);
                printf(" Precio: %d\n",mejoras[i]->precio);
                printf("\n");
            }
        }
        printf("---------------------------------------------\n");
        printf(" TOTAL = $%llu\n\n", precio);
        return;
    }
    else
    {
        printf(" No hay mejoras agregadas.\n\n");
        printf("---------------------------------------------\n");
        printf(" TOTAL = $%llu\n\n", precio);
        return;
    }

}

// FUNCIONES PROGRAMA ---------------------------------------------------------------------------------------------------------------------

unsigned long long charANumero(char *charNumero){

    int largo = strlen(charNumero);
    unsigned long long numero = 0;

    for(int i = 0; i < largo; i++) numero = (charNumero[i] - 48) + (numero*10);

    return numero;
}

int stringEqual(const void * key1, const void * key2) {

    const char * A = key1;
    const char * B = key2;

    return strcmp(A, B) == 0;
}

void goy(int y){

    HANDLE hoon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = 0;
    pos.Y = y;
    SetConsoleCursorPosition(hoon,pos);
}

void llenarBD(Map *mapaUsuario, Mapx *mapaTipo, Mapx *mapaGama, Mapx *mapaMejoras, BinaryTree *arbolPrecios){

    FILE *archivo;
    char linea[1001];

    tipoUsuario *datoUsuario;
    tipoAuto *datoAuto;
    tipoMejora *datoMejora;

    //LEER DATOS PARA MAPA DE USUARIOS.

    archivo = fopen("usuarios.txt","r");
    if(archivo == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        ExitProcess(1);
    }

    while(fgets(linea, 1000, archivo) != NULL)
    {
        datoUsuario = crearUsuarioCSV(linea);
        insertMap(mapaUsuario, datoUsuario->rut, datoUsuario);
    }

    fclose(archivo);

    //LEER DATOS PARA MAPA ENLAZADO TIPO Y GAMA.

    archivo = fopen("autos.txt","r");
    if(archivo == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO\n");
        ExitProcess(1);
    }

    while(fgets(linea, 1000, archivo) != NULL)
    {
        datoAuto = crearAutoCSV(linea);

        insertMapx(mapaTipo, datoAuto->tipo, datoAuto);
        insertMapx(mapaGama, datoAuto->gama, datoAuto);
        insertBinaryTree(arbolPrecios, datoAuto->precio, datoAuto);
    }

    fclose(archivo);

    //LEER DATOS MAPA MEJORAS

    archivo = fopen("mejoras.txt","r");
    if(archivo == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO\n");
        ExitProcess(1);
    }

    while(fgets(linea, 1000, archivo) != NULL)
    {
        datoMejora = crearMejoraCSV(linea);
        insertMapx(mapaMejoras, datoMejora->tipo, datoMejora);
    }

    fclose(archivo);

}

void actualizarBD(Mapx *mapaGama, Map *mapaUsuario){

    system("@cls||clear");
    FILE *archivo = fopen("autos.txt","w");
    if(archivo == NULL) ExitProcess(1);

    tipoAuto *recorrer = searchMapx(mapaGama,"Baja");
    tipoAuto *aux = recorrer;

    while(recorrer != NULL)
    {
        fprintf(archivo,"%u;",recorrer->ID);
        fprintf(archivo,"%s;",recorrer->nombre);
        fprintf(archivo,"%s;",recorrer->marca);
        fprintf(archivo,"%s;",recorrer->tipo);
        fprintf(archivo,"%s;",recorrer->gama);
        fprintf(archivo,"%s;",recorrer->estado);
        fprintf(archivo,"%llu;",recorrer->precio);
        fprintf(archivo,"%u\n",recorrer->disponibles);
        recorrer = mapxNextList(mapaGama);
        if(equalTipoAuto(recorrer, aux)) break;
    }

    recorrer = searchMapx(mapaGama,"Media");
    aux = recorrer;

    while(recorrer != NULL)
    {
        fprintf(archivo,"%u;",recorrer->ID);
        fprintf(archivo,"%s;",recorrer->nombre);
        fprintf(archivo,"%s;",recorrer->marca);
        fprintf(archivo,"%s;",recorrer->tipo);
        fprintf(archivo,"%s;",recorrer->gama);
        fprintf(archivo,"%s;",recorrer->estado);
        fprintf(archivo,"%llu;",recorrer->precio);
        fprintf(archivo,"%u\n",recorrer->disponibles);
        recorrer = mapxNextList(mapaGama);
        if(equalTipoAuto(recorrer, aux)) break;
    }

    recorrer = searchMapx(mapaGama,"Alta");
    aux = recorrer;

    while(recorrer != NULL)
    {
        fprintf(archivo,"%u;",recorrer->ID);
        fprintf(archivo,"%s;",recorrer->nombre);
        fprintf(archivo,"%s;",recorrer->marca);
        fprintf(archivo,"%s;",recorrer->tipo);
        fprintf(archivo,"%s;",recorrer->gama);
        fprintf(archivo,"%s;",recorrer->estado);
        fprintf(archivo,"%llu;",recorrer->precio);
        fprintf(archivo,"%u\n",recorrer->disponibles);
        recorrer = mapxNextList(mapaGama);
        if(equalTipoAuto(recorrer, aux)) break;
    }

    fclose(archivo);

    archivo = fopen("usuarios.txt","w");
    if(archivo == NULL) ExitProcess(1);

    tipoUsuario *recorrerUsuario = firstMap(mapaUsuario);

    while(recorrerUsuario != NULL)
    {
        fprintf(archivo,"%s;",recorrerUsuario->rut);
        fprintf(archivo,"%s;",recorrerUsuario->clave);
        fprintf(archivo,"%s;",recorrerUsuario->nombre);
        fprintf(archivo,"%s;",recorrerUsuario->nacimiento);
        fprintf(archivo,"%s;",recorrerUsuario->tipoDeUsuario);
        fprintf(archivo,"%s;",recorrerUsuario->numeroTar);
        fprintf(archivo,"%s;",recorrerUsuario->vencimientoTar);
        fprintf(archivo,"%s\n",recorrerUsuario->cvvTar);
        recorrerUsuario = nextMap(mapaUsuario);
    }

    fclose(archivo);

    return;
}

char * _strdup (const char *s) {

	size_t len = strlen (s) + 1;
    void *new = malloc (len);

	if (new == NULL)
	    return NULL;

	return (char *) memcpy (new, s, len);
}

long long stringHash(const void * key) {

    long long hash = 5381;

    const char * ptr;

    for (ptr = key; *ptr != '\0'; ptr++) {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }

    return hash;
}

void *crearUsuarioCSV(char *linea){

    tipoUsuario *usuario = (tipoUsuario*) malloc (sizeof(tipoUsuario));

    usuario->rut = get_csv_field(linea, 1);
	usuario->clave = get_csv_field(linea, 2);
  	usuario->nombre = get_csv_field(linea, 3);
  	usuario->nacimiento= get_csv_field(linea, 4);
  	usuario->tipoDeUsuario = get_csv_field(linea, 5);
	usuario->numeroTar = get_csv_field(linea, 6);
	usuario->vencimientoTar = get_csv_field(linea, 7);
	usuario->cvvTar= get_csv_field(linea, 8);

	return usuario;
}

void *crearAutoCSV(char *linea){

    tipoAuto *datoAuto = (tipoAuto *) malloc (sizeof(tipoAuto));

    datoAuto->ID = charANumero(get_csv_field(linea, 1));
    datoAuto->nombre = get_csv_field(linea, 2);
    datoAuto->marca = get_csv_field(linea, 3);
    datoAuto->tipo = get_csv_field(linea, 4);
    datoAuto->gama = get_csv_field(linea, 5);
    datoAuto->estado = get_csv_field(linea, 6);
    datoAuto->precio = charANumero(get_csv_field(linea, 7));
    datoAuto->disponibles = charANumero(get_csv_field(linea,8));

    return datoAuto;
}

void *crearMejoraCSV(char *linea){

    tipoMejora *datoMejora = (tipoMejora *) malloc (sizeof(tipoMejora));

    datoMejora->nombre = get_csv_field(linea, 1);
    datoMejora->tipo = get_csv_field(linea, 2);
    datoMejora->precio = charANumero(get_csv_field(linea, 3));

    return datoMejora;
}

const char *get_csv_field (char * tmp, int i) {

    char * line = _strdup (tmp);
    const char * tok;
    for (tok = strtok (line, ";"); tok && *tok; tok = strtok (NULL, ";\n")) {
        if (!--i) {
            return tok;
        }
    }
    return NULL;
}

int equalTipoAuto(void *data1, void *data2){

    tipoAuto *auto1 = (tipoAuto *) data1;
    tipoAuto *auto2 = (tipoAuto *) data2;

    if(auto1->ID == auto2->ID) return 1;
    else return 0;
}

int equalTipoMejora(void * data1, void * data2){

    tipoMejora *A = data1;
    tipoMejora *B = data2;

    if(strcmp(A->nombre,B->nombre) == 0) return 1;
    else return 0;

}

// FUNCIONES MENU PRINCIPAL ---------------------------------------------------------------------------------------------------------------------

tipoUsuario *ingresarUsuario(Map *mapaUsuario){

    char rut[101];
    char clave[1001];
    int cont = 3;

    tipoUsuario *usuario;

    do
    {
        printf("\t\tINICIO DE SESION\n\n");
        printf("Si quiere devolverse al menu principal ingrese 0.\n\n");
        printf("Ingrese su rut: ");
        scanf("%[^\n]100s",rut);
        fflush(stdin);
        printf("\n");

        if(rut[0] == '0') return NULL;

        printf("Ingrese su clave: ");
        scanf("%[^\n]1000s",clave);
        fflush(stdin);
        printf("\n");

        usuario = searchMap(mapaUsuario,rut);

        if(usuario != NULL)
        {
            if(!stringEqual(usuario->clave, clave))
            {
                cont--;
                printf("Su rut o clave es erroneo, tiene %i oportunidad/oportunidades mas\n\n",cont);
                getch();
                system("@cls||clear");
            }
            else return usuario;
        }
        else
        {
            cont--;
            if(cont >= 1) printf("Su rut o clave es erroneo, tiene %i oportunidad/oportunidades mas\n\n",cont);
            getch();
            system("@cls||clear");
        }

        if(cont == 0)
        {
            system("@cls||clear");
            printf("\t\tUSUARIO BLOQUEADO\n\n");
            printf("Presione cualquier tecla para continuar...");
            getch();
            ExitProcess(0);
        }

    }while(1);
}

void *crearChar(){

    char *dato = (char *) malloc(sizeof(char)*101);
    scanf("%100[^\n]s", dato);
    fflush(stdin);
    return dato;
}

void registrarUsuario(Map *mapaUsuarios){

        char *dato;
        int i;
        int largo;

        FILE *archivo = fopen("usuarios.txt","a");
        if(archivo == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO");
            ExitProcess(0);
        }

        tipoUsuario *usuario = (tipoUsuario *) malloc (sizeof(tipoUsuario));

        do
        {

            printf("\t\t REGISTRO DE CUENTA\n\n");
            printf("Datos de la cuenta\n\n");
            printf("RUT (Formato: sin puntos ni digito verificador. Ejemplo: 12345678): ");
            dato = crearChar();
            printf("\n");

            largo = strlen(dato);
            if(largo < 7 || largo > 8)
            {
                printf("Formato del RUT incorrecto, presione cualquier tecla para continuar..\n");
                getch();
                system("@cls||clear");
                free(dato);
                continue;
            }

            for(i = 0; i < largo; i++)
            {
                if(isdigit(dato[i]) == 0)
                {
                    dato[0] = '\0';
                    break;
                }
            }

            if(dato[0] == '\0')
            {
                printf("Formato del RUT incorrecto, presione cualquier tecla para continuar...\n");
                getch();
                system("@cls||clear");
                free(dato);
                continue;
            }

            usuario->rut = dato;

            if(searchMap(mapaUsuarios, dato) != NULL)
            {
                free(dato);
                free(usuario);
                printf("El rut ya esta registrado por favor ingrese con su cuenta.\n\n");
                printf("Presione cualquier tecla para volver al menu principal...\n");
                getch();
                return;
            }

            break;

        }while(1);

        fprintf(archivo,"%s;",dato);

        do
        {
            system("@cls||clear");
            printf("\t\t REGISTRO DE CUENTA\n\n");
            printf("Datos de la cuenta\n\n");
            printf("RUT (Formato: sin puntos ni digito verificador. Ejemplo: 12345678): %s\n\n", usuario->rut);

            printf("Ingrese una clave de usuario: ");
            dato = crearChar();
            printf("\n");

            largo = strlen(dato);
            if(largo < 8 || largo > 24)
            {
                printf("La clave debe contener entre 8 y 24 caracteres y deben ser solo letras y numeros.\n");
                printf("Presione cualquier tecla para reintentarlo.\n");
                getch();
                free(dato);
                continue;
            }

            for(i = 0; i < largo; i++)
            {
                if(isalnum(dato[i]) == 0)
                {
                    dato[0] = '\0';
                    break;
                }
            }
            if(dato[0] == '\0')
            {
                printf("La clave debe contener entre 8 y 24 caracteres y deben ser solo letras y numeros.\n");
                printf("Presione cualquier tecla para reintentarlo.\n");
                getch();
                free(dato);
                continue;
            }

            break;

        }while(1);
        usuario->clave = dato;
        fprintf(archivo,"%s;",dato);

        printf("Datos personales\n\n");

        printf("Ingrese su nombre: ");
        dato = crearChar();
        usuario->nombre = dato;
        fprintf(archivo,"%s;",dato);
        printf("\n");

        printf("Ingrese su fecha de Nacimiento: ");
        dato = crearChar();
        usuario->nacimiento = dato;
        fprintf(archivo,"%s;",dato);
        printf("\n");

        strcpy(dato,"normal");
        fprintf(archivo, "%s;", dato);

        printf("Metodo de pago\n\n");

        printf("Ingrese su numero de tarjeta: ");
        dato = crearChar();
        usuario->numeroTar = dato;
        fprintf(archivo,"%s;",dato);
        printf("\n");

        printf("Ingrese la fecha de Caducidad: ");
        dato = crearChar();
        usuario->vencimientoTar = dato;
        fprintf(archivo,"%s;",dato);
        printf("\n");

        printf("Ingrese el codigo de seguridad(CVV): ");
        dato = crearChar();
        usuario->vencimientoTar = dato;
        fprintf(archivo,"%s\n",dato);
        printf("\n");

        insertMap(mapaUsuarios, usuario->rut, usuario);

        printf("\n");
        printf("USUARIO CREADO EXITOSAMENTE\n");
        getch();

        fclose(archivo);

        return;
}

