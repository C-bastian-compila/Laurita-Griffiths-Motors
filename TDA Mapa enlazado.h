#ifndef TDA_MAPA_ENLAZADO_H_INCLUDED
#define TDA_MAPA_ENLAZADO_H_INCLUDED

typedef struct nodeMapx nodeMapx;
typedef struct Mapx Mapx;
typedef struct tipoAuto tipoAuto;

Mapx *createMapx();
nodeMapx *createNodeMapx(const void * , const void * );
int hashMapx(const char * , int);
int equalMapx(const void * , const void * );
int equalTipoAuto(void *, void *);
int  fixCollision(int , int);
void enlargeMapx(Mapx *);
int insertList(nodeMapx *, nodeMapx *);
void insertMapx(Mapx *, void *, void *);
void *searchMapx(Mapx *, const void *);


#endif // TDA_MAPA_ENLAZADO_H_INCLUDED
