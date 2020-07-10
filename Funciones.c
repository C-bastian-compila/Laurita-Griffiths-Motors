#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "Map.h"
#include "MapaEnlazado.h"
#include <windows.h>

#define abajo 0x50
#define arriba 0x48

// ESTRUCTURAS ---------------------------------------------------------------------------------------------------------------------

struct tipoAuto{

    unsigned int ID;
    char *nombre;
    char *marca;
    char *tipo;
    char *gama;
    char *estado;
    unsigned long precio;
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

struct tipoMejora{

    char *nombre;
    char *tipo;
    unsigned long precio;
};

// MENUS ---------------------------------------------------------------------------------------------------------------------

int portada(){
    FILE *menu = fopen ("menu1.txt", "rb");
    if(menu == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        return 1;
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
            printf ("%s", a);
        }

        printf("\n");

        int Menu = 1;

        goy(LineaDeInicio);
        printf("   Iniciar Usuario \n");
        printf("   Registrar nueva cuenta \n");
        printf("   Ver autos \n");
        printf("   Salir \n");

        char tecla;

        goy(LineaDeInicio);
        printf("->");

        while(1) {
            tecla = getch();
            //printf("                          %s", tecla);
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
        if (tecla == arriba){
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
    printf("   Volver al menu principal \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba){
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
    printf("   Opcion VIP(Proximamente) \n");
    printf("   Mostrar por tipo \n");
    printf("   Mostrar por gama \n");
    printf("   Volver al menu principal \n");

    char tecla;

    goy(LineaDeInicio);
    printf("->");

    while(1) {
        tecla = getch();
        if (tecla == arriba){
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
        if (tecla == arriba){
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

void *mostrarAutos(Mapx *mapaTipo, Mapx *mapaGama){

    tipoAuto *autoSelec;
    int opcionMenuAuto;

    do
    {
        opcionMenuAuto = menuAutos();
        switch(opcionMenuAuto)
        {
            case 1: // OPCION VIP
                printf("PROXIMAMENTEEEEEE\n");
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

void imprimirAuto(tipoAuto *autoSelec){

    printf("\t\tINFO DEL AUTO\n\n");;
    printf("modelo: %s\n",autoSelec->nombre);
    printf("tipo: %s\n",autoSelec->tipo);
    printf("gama: %s\n",autoSelec->gama);
    printf("marca: %s\n",autoSelec->marca);
    printf("estado: %s\n",autoSelec->estado);
    printf("precio: %s\n",autoSelec->precio); //CAMBIAR**************************************
    if(autoSelec->disponibles > 0) printf("Auto Disponible\n");
    else printf("Auto no Disponible\n");
    printf("\n\n");

}

// FUNCIONES PROGRAMA ---------------------------------------------------------------------------------------------------------------------

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

void llenarBD(Map *mapaUsuario, Mapx *mapaTipo, Mapx *mapaGama){

    FILE *archivo;
    char linea[1001];

    //LEER DATOS PARA MAPA DE USUARIOS.

    tipoUsuario *datoUsuario;

    archivo = fopen("usuarios.txt","r");
    if(archivo == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        ExitProcess(1);
    }

    while(fgets(linea, 1000, archivo)!= NULL)
    {
        datoUsuario = crearUsuarioCSV(linea);
        insertMap(mapaUsuario, datoUsuario->rut, datoUsuario);
    }

    fclose(archivo);

    //LEER DATOS PARA MAPA ENLAZADO TIPO, mas coas

    tipoAuto *datoAuto;

    archivo = fopen("autos.txt","r");
    if(archivo == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO\n");
        ExitProcess(1);
    }

    while(fgets(linea, 1000, archivo)!= NULL)
    {
        datoAuto = crearAutoCSV(linea);

        insertMapx(mapaTipo, datoAuto->tipo, datoAuto);
        insertMapx(mapaGama, datoAuto->gama, datoAuto);
        //ACA SE PONEN LOS OTROS INSERT (precio)
    }

    fclose(archivo);

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

    datoAuto->ID = atoi(get_csv_field(linea, 1));
    datoAuto->nombre = get_csv_field(linea, 2);
    datoAuto->marca = get_csv_field(linea, 3);
    datoAuto->tipo = get_csv_field(linea, 4);
    datoAuto->gama = get_csv_field(linea, 5);
    datoAuto->estado = get_csv_field(linea, 6);
    datoAuto->precio = get_csv_field(linea, 7); // CAMBIAR************************ PONER ATOI CUANDO EL ERICqK LO ARREGLE XD
    datoAuto->disponibles = atoi(get_csv_field(linea,8));

    return datoAuto;
}

void *crearChar(){

    char *dato = (char *) malloc(sizeof(char)*101);
    scanf("%100[^\n]s", dato);
    fflush(stdin);
    return dato;
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

// FUNCIONES MENU PRINCIPAL ---------------------------------------------------------------------------------------------------------------------

bool ingresarUsuario(tipoUsuario *usuario, Map *mapaUsuario){

    char rut[1001];
    char clave[1001];
    int cont = 3;

    do
    {
        printf("\t\tINICIO DE SESION\n\n");
        printf("Si quiere devolverse al menu principal ingrese 0.\n\n");
        printf("Ingrese su rut: ");
        scanf("%[^\n]1000s",rut);
        fflush(stdin);
        printf("\n");

        if(rut[0] == '0')
        {
            return false;
        }

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
            else return true;
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

void registrarUsuario(Map *mapaUsuarios){

        FILE *archivo = fopen("usuarios.txt","a");
        if(archivo == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO");
            ExitProcess(0);
        }

        char *dato;

        tipoUsuario *usuario = (tipoUsuario *) malloc (sizeof(tipoUsuario));

        printf("\t\t REGISTRO DE CUENTA\n\n");

        printf("Datos de la cuenta\n\n");

        printf("Ingrese su RUT: ");
        dato = crearChar();
        usuario->rut = dato;
        printf("\n");

        if(searchMap(mapaUsuarios, usuario->rut) != NULL)
        {
            free(usuario);
            free(dato);
            printf("El rut ya esta registrado por favor ingrese con su cuenta.\n\n");
            printf("Presione cualquier tecla para volver al menu principal...\n");
            getch();
            return;
        }
        fprintf(archivo,"%s;",dato);

        printf("Invente una clave de usuario: ");
        dato = crearChar();
        usuario->clave = dato;
        fprintf(archivo,"%s;",dato);
        printf("\n");

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

// FUNCIONES PARA TESTEOS ---------------------------------------------------------------------------------------------------------------------

void comprobarMapa(Mapx *mapa){

    int aux = 0;
    tipoAuto *current = searchMapx(mapa,"Deportivo");

    do
    {
        printf("%s\n", current->ID);
        printf("%s\n", current->nombre);
        current = mapxNextList(mapa);
        getch();
        aux++;

    }while(aux != 10);

    printf("LISTOOOOO\n");
    getch();

}

