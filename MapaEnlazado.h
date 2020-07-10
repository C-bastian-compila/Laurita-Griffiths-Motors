#ifndef MAPA_ENLAZADO_H_INCLUDED
#define MAPA_ENLAZADO_H_INCLUDED

typedef struct nodeMapx nodeMapx;
typedef struct Mapx Mapx;
typedef struct tipoAuto tipoAuto;

Mapx *createMapx();
void insertMapx(Mapx *, void *, void *);
void *searchMapx(Mapx *, const void *);
void *mapxCurrent(Mapx *);
void *mapxNextList(Mapx *);
void *mapxPrevList(Mapx *);

#endif // MAPA_ENLAZADO_H_INCLUDED
