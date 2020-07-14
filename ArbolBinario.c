#include "ArbolBinario.h"
#include <stdlib.h>

typedef struct TreeNode TreeNode;

typedef struct BinaryTree BinaryTree;

struct TreeNode {

    int key;
    void * value;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct BinaryTree {

    TreeNode * root;
    TreeNode * current;
};

TreeNode * createTreeNode(int, void *);

TreeNode * createTreeNode(int key, void * value) {

    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode));
    if (node == NULL) return NULL;
    node->key = key;
    node->value = value;
    node->parent = node->left = node->right = NULL;
    return node;
}

BinaryTree * createBinaryTree() {

    BinaryTree * node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (node == NULL) return NULL;
    node->root = node->current = NULL;
    return node;
}

void insertBinaryTree(BinaryTree * tree, int key, void * value) {

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

void * nextBinaryTree(BinaryTree * tree) {

    if (tree == NULL || tree->root == NULL || tree->current == NULL) return NULL;

    if (tree->current->right != NULL)
    {
        TreeNode * aux = tree->current->right;

        while (aux->left != NULL) {
            aux = aux->left;
        }

        //tree->current = minimum(aux);

        tree->current = aux;

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

    if (aux == NULL) return NULL;

    return (void *)aux->value;
}
