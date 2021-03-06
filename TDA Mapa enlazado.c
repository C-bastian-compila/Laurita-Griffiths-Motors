#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "TDA Mapa enlazado.h"

typedef struct nodeMapx nodeMapx;
typedef struct Mapx Mapx;
typedef struct tipoAuto tipoAuto; //********************************

struct tipoAuto{ //Esto se deberia poder quitar

    unsigned int ID;
    char *nombre;
    char *marca;
    char *tipo;
    char *gama;
    char *estado;
    unsigned long precio;
    unsigned int disponibles;
};

struct nodeMapx{

    void *data;
    void *key;
    nodeMapx *next;
};

struct Mapx{

    nodeMapx ** buckets;
    nodeMapx *currNode;
    int currIndex;
    int count; // Cantidad de datos no nulos
    int size; // Tama�o del arreglo
    int loadFactor;

};

Mapx *createMapx() {

    int size = 20;

    Mapx *mapa = (Mapx *) malloc(sizeof(Mapx));
    assert(mapa != NULL);

    mapa->buckets = (nodeMapx **) malloc(sizeof(nodeMapx *) * size);
    memset(mapa->buckets, 0, sizeof(nodeMapx *) * size);

    mapa->currNode = NULL;
    mapa->currIndex = -1;
    mapa->count = 0;
    mapa->size = size;
    mapa->loadFactor = (long)ceil(size * 0.77);

    return mapa;
}

nodeMapx *createNodeMapx(const void * key, const void * data) {

    nodeMapx *node  = (nodeMapx *) malloc(sizeof(nodeMapx));
    assert(node!= NULL);

    node->key = key;
    node->data = data;
    node->next = NULL;

    return node;

}

int hashMapx(const char * key, int size){

    long long hash = 12345;
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

int insertList(nodeMapx *node, nodeMapx *newNode){ // Retorna 1 si se pudo ingresar el dato y 0 si no

    //revisa si el dato se repite desde el primero

    do
    {
        if(equalTipoAuto(node->data, newNode->data)) return 0;
        node = node->next;

    }while(node->next != NULL);

    if(equalTipoAuto(node->data,newNode->data)) return 0;

    node->next = newNode;

    return 1;
}

void insertMapx(Mapx *mapa, void *key, void *data){

    assert(mapa != NULL);

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

    assert(mapa != NULL);

    int index = hashMapx(key, mapa->size);

    do
    {
        if(mapa->buckets[index] != NULL)
        {
            if(equalMapx(mapa->buckets[index]->key, key ))
            {
                return mapa->buckets[index];
            }
            else
            {
                index = fixCollision(index, mapa->size);
            }
        }
        else return NULL;

    }while(1);
}
