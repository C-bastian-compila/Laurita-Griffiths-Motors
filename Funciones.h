#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "Map.h"

typedef struct tipoAuto tipoAuto;
typedef struct tipoUsuario tipoUsuario;
typedef struct tipoMejora tipoMejora;

extern int menu1(void);
int portada(void);
int menuAutos(void);
bool ingresarUsuario();
long long stringHash(const void *);
int stringEqual(const void *, const void *);
void llenarBD(Map *);
char * _strdup (const char *);
const char *get_csv_field (char *, int );
void registrarUsuario(Map *);
void *crearChar();
void goy(int);
void comprobarMapa(Map *); //************************************************

#endif // FUNCIONES_H_INCLUDED
