#ifndef MAPA_ENLAZADO_H_INCLUDED
#define MAPA_ENLAZADO_H_INCLUDED

typedef struct nodeMapx nodeMapx;
typedef struct Mapx Mapx;
typedef struct tipoAuto tipoAuto;

/**
Crea un nuevo puntero de tipo Mapx.

recibe una funcion equal.

Retorna un puntero al mapa creado.
*/
Mapx *createMapx();

/**
Inserta un elemento no existente en el mapa.

recibe el mapa a ser insertado, la clave y el dato respectivamente.
*/
void insertMapx(Mapx *, void *, void *);

/**
Busca el primer elemento dentro del mapa segun la calve.

recibe el mapa y la clave buscada.

retorna un puntero con la direccion del elemento buscado.
*/
void *searchMapx(Mapx *, const void *);

/**
Entrega un puntero a la posicion actual en que se encuentra el mapa.

recibe el mapa a trabajar.

retorna un puntero a la posicion.
*/
void *mapxCurrent(Mapx *);

/**
Entrega un puntero a la posicion siguiente en que se encuentra el mapa,
en caso de llegar al final se dirige al inicio.

recibe el mapa a trabajar.

retorna un puntero a la posicion siguiente.

*/
void *mapxNextList(Mapx *);

/**
Entrega un puntero a la posicion previa en que se encuentra el mapa,
en caso de llegar al inicio se devuelve la misma posicion.

recibe el mapa a trabajar.

retorna un puntero a la posicion siguiente.
*/
void *mapxPrevList(Mapx *);

#endif // MAPA_ENLAZADO_H_INCLUDED
