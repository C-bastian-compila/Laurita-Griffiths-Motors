#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "Map.h"
#include "MapaEnlazado.h"
#include "ArbolBinario.h"
#include "list.h"

typedef struct tipoAuto tipoAuto;
typedef struct tipoUsuario tipoUsuario;
typedef struct tipoMejora tipoMejora;

/**
Lee los datos del usuario y busca su existencia en el mapa usuarios.

Retorna un Bool para verificar ingreso exitoso de usuario.

*/
tipoUsuario *ingresarUsuario();

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
void llenarBD(Map *, Mapx *, Mapx *, Mapx *, BinaryTree *);

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
Crea un dato tipo char, reserva memoria y devuelve un puntero a esta.
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
Cambia la posición del cursor.
*/
void goy(int);

/**

Pregunta al usuario de que forma quiere ver los autos, ya sean tipo, gama o precio.

retorna un puntero.
*/
void *mostrarAutos(Mapx *, Mapx *, BinaryTree *);

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
int menu1(void);

/**
Muestra por pantalla el Menu de usuario registrado.

Devuelve un int el cual indica la opcion escogida.
*/
int menu2(void);

/**
Muestra por pantalla el inicio de la aplicacion.
*/
void portada(void);

/**
Muestra por pantalla las opciones para mostrar los autos del programa.

Devuelve un int el cual indica la opcion escogida.
*/
int menuAutos(void);

//FALTA DOCUMENTAR **********************************************************************************************************
int menuMejora(void);

/**
 Compara si los datos tipo Auto son iguales. Retorna 1 si son iguales y 0 si no.
*/
int equalTipoAuto(void *, void *);

/**
 Compara si los datos tipo Mejora son iguales. Retorna 1 si son iguales y 0 si no.
*/

//FALTA DOCUMENTAR **********************************************************************************************************
int equalTipoMejora(void *, void *);

//FALTA DOCUMENTAR **********************************************************************************************************
void mostrarMejoras(Mapx *, tipoMejora **, char *);

//FALTA DOCUMENTAR **********************************************************************************************************
void elegirMejora(Mapx *, tipoMejora **, char *);

//FALTA DOCUMENTAR **********************************************************************************************************
void *crearMejoraCSV(char *);

//FALTA DOCUMENTAR **********************************************************************************************************
bool comprar(tipoAuto *, tipoMejora **, tipoUsuario *, unsigned long long *);

//FALTA DOCUMENTAR **********************************************************************************************************
void pagar(tipoUsuario *);

//FALTA DOCUMENTAR **********************************************************************************************************
void boleta(tipoAuto *, tipoMejora **, unsigned long long);

//FALTA DOCUMENTAR **********************************************************************************************************
void actualizarBD(Mapx *, Map *);

//FALTA DOCUMENTAR **********************************************************************************************************
unsigned long long charANumero(char *charNumero);

//FALTA DOCUMENTAR **********************************************************************************************************
void imprimirBoleta(tipoAuto *);

#endif // FUNCIONES_H_INCLUDED
