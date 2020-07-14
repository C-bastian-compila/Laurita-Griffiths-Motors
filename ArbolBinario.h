#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

typedef struct TreeNode TreeNode;

typedef struct BinaryTree BinaryTree;

/**
Crea un puntero a un arbol binario.
*/
BinaryTree * createBinaryTree();

/**
Crea e incerta un nuevo dato en el sistema a travez de la key, si la key ya existe
se linkea con el dato ya existente.
*/
void insertBinaryTree(BinaryTree *, int, void *);

/**
Entrega un puntero al siguiente dato del arbol siempre y cuando no existan mas valores linkeados.
*/
void * nextBinaryTree(BinaryTree *);




#endif // ARBOLBINARIO_H_INCLUDED
