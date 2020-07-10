#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "Map.h"
#include "MapaEnlazado.h"

typedef struct tipoAuto tipoAuto;
typedef struct tipoUsuario tipoUsuario;
typedef struct tipoMejora tipoMejora;

/**
Lee los datos del usuario y busca su existencia en el mapa usuarios.

Retorna un Bool para verificar ingreso exitoso de usuario.

*/
bool ingresarUsuario();

/**
Funcion Hash encargada de otorgar una posicion en los mapas.

Recibe una key que se usara para obtener la posicion.
*/
long long stringHash(const void *);


/**
Funcion encargada de comparar datos.

Recibe dos datos cualquiera que se deseen comparar.

Esta funcion devuelve un 0 en caso de ser diferentes y 1 en caso contrario.
*/
int stringEqual(const void *, const void *);


/**
Lee los archivos para obtener los datos necesarios y los almacena en los TDA.

Recibe como parametros los diferentes mapas a llenar.
*/
void llenarBD(Map *, Mapx *, Mapx *);

/**


*/
char * _strdup (const char *);


/**
Obtiene caracteres de una linea de texto hasta llegar a un ";".

Los parametros que recibe son: la linea de texto y la posicion que se desea obtener;

Entrega un puntero a los caracteres.
*/
const char *get_csv_field (char *, int );

/**
Busca registrar a los nuevos usuarios y ubicarlos dentro del sistema.

Recibe el Mapa donde se ubican todos los usuarios.
*/
void registrarUsuario(Map *);

/**

*/
void *crearChar();

/**
Crea un puntero a un struct tipoAuto y le asigna los valores respectivos.

Recibe un puntero tipo char.

Devuelve un puntero del dato creado.
*/
void *crearAutoCSV(char *);

/**
Crea un puntero a un struct tipoUsuario y le asigna los valores respectivos.

Recibe un puntero tipo char.

Devuelve un puntero del dato creado.
*/
void *crearUsuarioCSV(char *);

/**

*/
void goy(int);

void comprobarMapa(Mapx *); //************************************************

/**

Pregunta al usuario de que forma quiere ver los autos, ya sean tipo, gama o precio.

retorna un puntero.
*/
void *mostrarAutos(Mapx *, Mapx *);

/**
Segun el tipo indicado por parte del usuario se busca y muestran los autos.

retorna un puntero.
*/
void *mostrarTipo(Mapx *);

/**
Segun la gama indicada por parte del usuario se busca y muestran los autos.

retorna un puntero.
*/
void *mostrarGama(Mapx *);

/**

*/
void *menuRecorrer(Mapx *, bool *);

/**

*/
void imprimirAuto(tipoAuto *);

/**
Muestra por pantalla el Menu destinado a la Gama de los autos.

Devuelve un int el cual indica la opcion escogida.
*/
int menuGama();

/**
Muestra por pantalla el Menu destinado al tipo de autos.

Devuelve un int el cual indica la opcion escogida.
*/
int menuTipo();

/**
Muestra por pantalla el Menu principal del programa.

Devuelve un int el cual indica la opcion escogida.
*/
extern int menu1(void);

/**
Muestra por pantalla el inicio de la aplicacion.
*/
void portada(void);

/**
Muestra por pantalla las opciones para mostrar los autos del programa.

Devuelve un int el cual indica la opcion escogida.
*/
int menuAutos(void);

#endif // FUNCIONES_H_INCLUDED
