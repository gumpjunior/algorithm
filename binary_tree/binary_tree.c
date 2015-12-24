#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void bitree_destroy_helper(BiTree* tree, BiTreeNode** node);

//************************************************************
//
// Interface definition.
//
//************************************************************

//============================================================
// 
//============================================================

void element_destroy(void* data) {

    printf("free: data = %d\n", *(int*)data);
    free(data);
    data = NULL;

    return;
}

//============================================================
// Binary tree initialization.
//============================================================

void bitree_init(BiTree* tree, void (*destroy)(void* data)) {

    tree->root = NULL;
    tree->size = 0;
    tree->destroy = destroy;

    return;

}

//============================================================
// 
//============================================================

void bitree_destroy_helper(BiTree* tree, BiTreeNode** node) {

    if (*node == NULL)
        return;

    bitree_destroy_helper(tree, &((*node)->left));
    bitree_destroy_helper(tree, &((*node)->right));
    tree->destroy((*node)->data);
    free(*node);
    *node = NULL;
    tree->size--;

    return;

}

void bitree_destroy(BiTree* tree) {
    
    if (tree == NULL) {
        printf("\nError: Tree does not exist!\n");
        return;
    }
    if (tree->root == NULL || tree->size == 0) {
        printf("\nError: Tree is empty, nothing to remove!\n");
        return;
    }

    bitree_destroy_helper(tree, &(tree->root));

    memset(tree, 0, sizeof(BiTree));
    //memset to all 0s will set tree->root = NULL.

    return;

}

//============================================================
// 
//============================================================

int bitree_ins_left(BiTree* tree, BiTreeNode* node, const void* data) {
    
    //Cannot use the following way to declare a new node, coz the
    //new node will be recycled when exiting from this function.
    //So have to use malloc.
    //BiTreeNode  newNode;
    //BiTreeNode* pNewNode = &newNode;

    //BiTreeNode*  pNewNode = NULL;
    //BiTreeNode** position = NULL;       //GOOD skill
    BiTreeNode*  pNewNode,
              ** position;

    //Illegal case
    if (tree == NULL) {
        printf("\nError: Tree does not exist!\n");
        return EXIT_FAILURE;
    }
    //Move it to else branch below. Coz if node == NULL, will be 
    //dead loop here. Program design is so delicate !!
    //if (node->left != NULL) {
    //    printf("\nNode has already have a left node!\n");
    //    exit(-1);
    //}

    //Use an if-else to set right value for position!!
    if (node == NULL) {
        if (tree->size != 0) {          //Illegal case
            printf("\nError: Node specified wrong!\n");
            return EXIT_FAILURE;
        }
        //Insert node as root
        position = &tree->root;
    }
    else {
        if (node->left != NULL) {
            printf("\nError: Node has already have a left node!\n");
            return EXIT_FAILURE;
        }
        //Insert node as left child
        position = &node->left;
    }

    pNewNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    if (pNewNode == NULL) {
        printf("\nError: Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    pNewNode->data  = (void*)data;
    pNewNode->left  = NULL;
    pNewNode->right = NULL;

    //Have a deep understanding of what is * is the key.
    *position = pNewNode;
    tree->size++;

    return EXIT_SUCCESS;

}

//============================================================
// 
//============================================================

int bitree_rem_left(BiTree* tree, BiTreeNode* node) {

    //Illegal case
    if (tree == NULL) {
        printf("\nError: Tree does not exist!\n");
        return EXIT_FAILURE;
    }
    if(tree->size == 0) {
        printf("\nError: Tree is empty, nothing to remove!\n");
        return EXIT_FAILURE;
    }

    if (node == NULL) {
        //bitree_destroy_helper(tree, &(tree->root));
        bitree_destroy(tree);
    }
    else {
        //node = node->left;
        bitree_destroy_helper(tree, &(node->left));
    }

    return EXIT_SUCCESS;

}

//============================================================
// Display binary tree inorder.
//============================================================

void bitree_display_int(BiTree* tree, BiTreeNode* node) {
    
    if (tree->root == NULL) {
        printf("\nTree is empty, nothing to display!\n");
        return;
    }
    if (node == NULL)
        return;

    bitree_display_int(tree, node->left);
    printf("%d  ", *(int*)node->data);
    bitree_display_int(tree, node->right);

    return;

}

//************************************************************
//
// Test function definition.
//
//************************************************************

int test_bitree_init(BiTree* tree) {

    if (tree->size != 0) {
        printf("Error: Initialized size error.\n");
        return EXIT_FAILURE;
    }
    if (tree->root != NULL) {
        printf("Error: Initialized root pointer error.\n");
        return EXIT_FAILURE;
    }
    if (tree->destroy == NULL) {
        printf("Error: Initialized destroy func pointer error.\n");
        return EXIT_FAILURE;
    }
    printf("\nInitialization test passed\n");

    return EXIT_SUCCESS;

}

int test_bitree_ins_left_and_tree_destroy(BiTree* tree) {
    
    printf("\n//====================================================\n");
    printf("// Testing: insert a node\n");
    printf("//====================================================\n");

    //Insert at root, tree is empty.
    int* pVar = (int*)malloc(sizeof(int)); 
    *pVar = 4;
    bitree_ins_left(tree, NULL, pVar);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

    //Insert a node at root left.
    int* pVar2 = (int*)malloc(sizeof(int)); 
    *pVar2 = 9;
    bitree_ins_left(tree, tree->root, pVar2);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

    //Insert at root, tree is NOT empty.
    printf("\nAn error msg will be following as debug info:\n");
    int* pVar3 = (int*)malloc(sizeof(int)); 
    *pVar3 = 4;
    bitree_ins_left(tree, NULL, pVar2);
    printf("\n");

    //Insert a node.
    int* pVar4 = (int*)malloc(sizeof(int)); 
    *pVar4 = 8;
    bitree_ins_left(tree, tree->root->left, pVar4);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

    printf("\n//====================================================\n");
    printf("// Testing: remove node left child\n");
    printf("//====================================================\n");

    bitree_rem_left(tree, tree->root);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

    bitree_rem_left(tree, NULL);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

    //Remove all nodes upon returning. The tree requires re-init before next use.
    
    //The following test works, but commeted out coz tree has already been 
    //destroyed above.
    //bitree_destroy(tree);
    //printf("\nCall bitree inorder display\n");
    //bitree_display_int(tree, tree->root);
    //printf("\n");

    pVar = NULL;
    pVar2 = NULL;
    pVar3 = NULL;
    pVar4 = NULL;

    return EXIT_SUCCESS;

}
