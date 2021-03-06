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

// ESTRUCTURAS ---------------------------------------------------------------------------------------------------------------------

struct tipoAuto{

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

// Funciones ---------------------------------------------------------------------------------------------------------------------

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
Funcion que duplica la cadena que es pasada por parametro.
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
Cambia la posici�n del cursor.
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
Imprime un menu que permite ir viendo los autos y agregarlos al carro de compras.
*/
void *menuRecorrer(Mapx *, bool *);

/**
Imprime los datos del auto.
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

/**
Muestra por pantalla las opciones para el menu de las mejoras.

Devuelve un int el cual indica la opcion escogida.
*/
int menuMejora(void);

/**
 Compara si los datos tipo Auto son iguales. Retorna 1 si son iguales y 0 si no.
*/
int equalTipoAuto(void *, void *);

/**
 Compara si los datos tipo Mejora son iguales. Retorna 1 si son iguales y 0 si no.
*/
int equalTipoMejora(void *, void *);

/**
Procesa la opcion otorgada por el menu mejora.
*/
void mostrarMejoras(Mapx *, tipoMejora **, char *);

/**
Muestra por pantalla las mejoras disponibles al tipo de auto,
ademas permite agregar y eliminarlas de la compra.
*/
void elegirMejora(Mapx *, tipoMejora **, char *);

/**
Crea un puntero a un struct tipoMejora y le asigna los valores respectivos.

Recibe un puntero tipo char.

Devuelve un puntero del dato creado.
*/
void *crearMejoraCSV(char *);

/**
Muestra por pantalla el auto y mejoras elegidas, ademas del precio a pagar.

Retorna un bool con el cual se verifica si se desea comprar o no.
*/
bool comprar(tipoAuto *, tipoMejora **, tipoUsuario *, unsigned long long *);

/**
Pide a a los usuarios los datos de su tarjeta y los comprueba con las ingresadas inicialmente.
*/
void pagar(tipoUsuario *);

/**
Entrega por pantalla los datos de los autos y mejoras elegidas, ademas del precio a pagar.
*/
void boleta(tipoAuto *, tipoMejora **, unsigned long long);

/**
Una vez realizada la compra se actualiza la base de datos con los cambios realizados tanto al usuario como a los autos.
*/
void actualizarBD(Mapx *, Map *);

/**
Transforma un caracter en dato numerico.
*/
unsigned long long charANumero(char *charNumero);

/**
Imprime los datos del auto.
*/
void imprimirBoleta(tipoAuto *);

#endif // FUNCIONES_H_INCLUDED
