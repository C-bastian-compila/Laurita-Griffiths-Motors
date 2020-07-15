#include "ArbolBinario.h"
#include <stdlib.h>

typedef struct TreeNode TreeNode;

typedef struct BinaryTree BinaryTree;

struct TreeNode {

    unsigned long long key;
    void * value;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;

    TreeNode * next;

};

struct BinaryTree {

    TreeNode * root;
    TreeNode * current;
    TreeNode * currList;
};

TreeNode * createTreeNode(unsigned long long, void *);
void insertListTree(TreeNode *nodo, TreeNode *nuevo);

TreeNode * createTreeNode(unsigned long long key, void * value) {

    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
    if (node == NULL) return NULL;
    node->key = key;
    node->value = value;

    node->parent = NULL;
    node->left =NULL;
    node->right=NULL;
    node->next=NULL;

    return node;
}

BinaryTree * createBinaryTree() {

    BinaryTree * node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (node == NULL) return NULL;
    node->root = NULL;
    node->current = NULL;
    node->currList = NULL;
    return node;
}

void insertBinaryTree(BinaryTree * tree, unsigned long long key, void * value) {

    if (tree == NULL) return;

    TreeNode * aux = tree->root;
    TreeNode * parent = NULL;

    while (aux != NULL) {
        parent = aux;

        if (key < aux->key) {
            aux = aux->left;
        } else if (key > aux->key) {
            aux = aux->right;
        } else {

            TreeNode* nuevo = createTreeNode(key,value);
            insertListTree(aux,nuevo);
            return;
        }
    }

    TreeNode * new = createTreeNode(key, value);

    new->parent = parent;

    if (parent == NULL) {
        tree->root = new;
    } else if (key < parent->key) {
        parent->left = new;
    } else {
        parent->right = new;
    }
}

void * firstBinaryTree(BinaryTree * tree) {

    if (tree == NULL || tree->root == NULL) return NULL;

    TreeNode * aux = tree->root;

    while (aux->left != NULL) {
        aux = aux->left;
    }

    tree->current = aux;
    tree->currList=tree->current;

    if (tree->current == NULL) return NULL;

    return (void *)tree->current->value;
}

void * nextBinaryTree(BinaryTree * tree) {

    if (tree == NULL || tree->root == NULL || tree->current == NULL) return NULL;

    if(tree->currList != NULL && tree->currList->next != NULL)
    {
        tree->currList=tree->currList->next;
        return tree->currList->value;
    }

    if (tree->current->right != NULL)
    {
        TreeNode * aux = tree->current->right;

        while (aux->left != NULL) {
            aux = aux->left;
        }

        tree->current = aux;
        tree->currList=tree->current;

        if (tree->current == NULL) return NULL;

        return (void *)tree->current->value;
    }

    TreeNode * aux = tree->current->parent;

    while (aux != NULL && tree->current == aux->right)
    {
        tree->current = aux;
        aux = aux->parent;
    }

    tree->current = aux;
    tree->currList=tree->current;

    if (aux == NULL) return NULL;

    return (void *)aux->value;
}

void insertListTree(TreeNode *nodo, TreeNode *nuevo){

    TreeNode* aux= nodo;

    while (aux->next != NULL)
    {
        aux=aux->next;
    }

    aux->next=nuevo;

    return;
}


