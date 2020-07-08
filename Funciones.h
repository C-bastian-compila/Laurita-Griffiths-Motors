#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "Map.h"
#include "MapaEnlazado.h"

typedef struct tipoAuto tipoAuto;
typedef struct tipoUsuario tipoUsuario;
typedef struct tipoMejora tipoMejora;

extern int menu1(void);
int portada(void);
int menuAutos(void);
bool ingresarUsuario();
long long stringHash(const void *);
int stringEqual(const void *, const void *);
void llenarBD(Map *, Mapx *);
char * _strdup (const char *);
const char *get_csv_field (char *, int );
void registrarUsuario(Map *);
void *crearChar();
void *crearAutoCSV(char *);
void *crearUsuarioCSV(char *);
void goy(int);
void comprobarMapa(Mapx *); //************************************************

#endif // FUNCIONES_H_INCLUDED
