#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

typedef struct TreeNode TreeNode;

typedef struct BinaryTree BinaryTree;

BinaryTree * createBinaryTree();
void insertBinaryTree(BinaryTree *, int, void *);
void * searchBinaryTree(BinaryTree *, int);
void * nextBinaryTree(BinaryTree *);



#endif // ARBOLBINARIO_H_INCLUDED
