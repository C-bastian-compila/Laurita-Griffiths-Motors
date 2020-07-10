#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "MapaEnlazado.h"
#include "Funciones.h"

struct nodeMapx{

    void *data;
    void *key;
    nodeMapx *prev;
    nodeMapx *next;
};

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

struct Mapx{

    nodeMapx ** buckets;
    nodeMapx *currNode;
    int currIndex;
    int count; // Cantidad de datos no nulos
    int size; // Tamaño del arreglo
    int loadFactor;

};

int hashMapx(const char * , int);
int equalMapx(const void * , const void *);
int equalTipoAuto(void *, void *);
int  fixCollision(int , int);
void enlargeMapx(Mapx *);
int insertList(nodeMapx *, nodeMapx *);
nodeMapx *createNodeMapx(const void * , const void * );

Mapx *createMapx() {

    int size = 80;

    Mapx *mapa = (Mapx *) malloc(sizeof(Mapx));
    assert(mapa != NULL);

    mapa->buckets = (nodeMapx **) malloc(sizeof(nodeMapx *) * size);
    memset(mapa->buckets, 0, sizeof(nodeMapx *) * size);

    mapa->currNode = NULL;
    mapa->count = 0;
    mapa->currIndex = -1;
    mapa->size = size;
    mapa->loadFactor = (long)ceil(size * 0.77);

    return mapa;
}

nodeMapx *createNodeMapx(const void * key, const void * data) {

    nodeMapx *node  = (nodeMapx *) malloc(sizeof(nodeMapx));
    assert(node!= NULL);

    node->key = key;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;

}

int hashMapx(const char * key, int size){

    long long hash = 5381;
    int aux;

    int largo = strlen(key);

    for (int i = 0; i < largo; i++)
    {
        hash = (key[i] * 13) % 100000;
    }

    aux = hash % size;

    return aux;
}

int equalMapx(const void * key1, const void * key2){ // retorna 1 si las claves son iguales

    const char *A = key1;
    const char *B = key2;

    if(strcmp(A,B) == 0) return 1;
    else return 0;

}

int equalTipoAuto(void *node1, void *node2){ //retorna 1 si los tipoAuto son el mismo auto y 0 si no son el mismo.

    tipoAuto *auto1 = (tipoAuto *) node1;
    tipoAuto *auto2 = (tipoAuto *) node2;

    if(auto1->ID == auto2->ID) return 1;
    else return 0;
}

int  fixCollision(int index, int size){

    long long aux = index;
    aux = ((aux * 7) + 13579) % 100000;

    index = aux % size;
    return index;
}

void enlargeMapx(Mapx *mapa){

    nodeMapx **oldBucket = mapa->buckets;
    long oldSize = mapa->size;
    long newSize = mapa->size * 2;

    mapa->buckets = (nodeMapx **) malloc(sizeof(nodeMapx *) * newSize);
    memset(mapa->buckets, 0, newSize * sizeof(nodeMapx *)); // DUDA: no se como funciona esta wea pero deberia limpiar el vector********************************************
    mapa->count = 0;
    mapa->size = newSize;
    mapa->loadFactor = (long)ceil(newSize * 0.77);

    for (int i = 0; i < oldSize; i++)
    {
        if(oldBucket[i] != NULL)
        {
            if (oldBucket[i]->data != NULL)
            {
                insertMapx(mapa, oldBucket[i]->key, oldBucket[i]->data);
            }
            else
            {
                free(oldBucket[i]);
            }
        }
    }

    free(oldBucket);

    return;
}

int insertList(nodeMapx *node, nodeMapx *newNode){ // Retorna 1 si se pudo ingresar el dato y 0 si no.

    nodeMapx* aux=node;

    while(aux->next != NULL)
    {
        if(equalTipoAuto(aux->data, newNode->data)) return 0;
        aux = aux->next;

    }

    if(equalTipoAuto(node->data,newNode->data)) return 0;

    newNode->prev = aux;
    aux->next = newNode;

    return 1;
}

void insertMapx(Mapx *mapa, void *key, void *data){

    if(mapa == NULL) return NULL;

    if((mapa->count + 1) > mapa->loadFactor) enlargeMapx(mapa);

    int index = hashMapx(key, mapa->size);

    do
    {
        if(mapa->buckets[index] == NULL)
        {
            mapa->buckets[index] = createNodeMapx(key, data);
            mapa->count++;

            return;
        }
        else
        {

            if(equalMapx(mapa->buckets[index]->key ,key))
            {
                if(mapa->buckets[index]->data == NULL)
                {
                    mapa->buckets[index]->data = data;
                    mapa->count++;
                    return;

                }

                else
                {
                    nodeMapx *newNode = createNodeMapx(key, data);
                    if(insertList(mapa->buckets[index], newNode)) mapa->count++; //suma uno al cont si se pudo ingresar el nodo.
                    return;
                }

            }
            else index = fixCollision(index, mapa->size);

        }

    }while(1);
}

void *searchMapx(Mapx *mapa, const void *key){

    if(mapa == NULL) return NULL;

    int index = hashMapx(key, mapa->size);

    do
    {
        if(mapa->buckets[index] != NULL)
        {
            if(equalMapx(mapa->buckets[index]->key, key ))
            {
                mapa->currIndex = index;
                mapa->currNode = mapa->buckets[index]; // ***************************************************
                return mapa->buckets[index]->data;

            }
            else
            {
                index = fixCollision(index, mapa->size);
            }
        }
        else return NULL;

    }while(1);
}

void *mapxNextList(Mapx *mapa){

    if(mapa == NULL) return NULL;

    if(mapa->currNode->next)
    {
        mapa->currNode = mapa->currNode->next;
        return mapa->currNode->data;
    }
    else
    {
        mapa->currNode = mapa->buckets[mapa->currIndex];
        return mapa->currNode->data;
    }
}

void *mapxPrevList(Mapx *mapa){

    if(mapa == NULL) return NULL;

    if(mapa->currNode->prev != NULL)
    {
        mapa->currNode = mapa->currNode->prev;
        return mapa->currNode->data;
    }
    else return mapa->currNode->data;
}

void *mapxCurrent(Mapx *mapa){

    if(mapa == NULL) return NULL;

    return mapa->currNode->data;

}
