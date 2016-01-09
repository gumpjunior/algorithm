/*
 ============================================================================
 Name        : binary_tree_max_depth.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structure/binary_tree/binary_tree.h"

void binary_tree_construction(BiTree* tree);
//int balanced_binary_tree(BiTreeNode* node);
int balanced_binary_tree(BiTreeNode* node, int curDepth);

int main(void) {

    printf("Program starts!\n");

    BiTree  biTree;
    BiTree* pBiTree = &biTree;

    //Test binary tree initialization.
    bitree_init(pBiTree, element_destroy);
    test_bitree_init(pBiTree);

    binary_tree_construction(pBiTree);


    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);
    //bitree_destroy(pBiTree);

    if (pBiTree->root != NULL) {
        printf("\nError: After removing all elements by bitree_rem_left\n");
        printf("tree->root should be NULL\n");
    }
    if (pBiTree->size != 0) {
        printf("\nError: After removing all elements by bitree_rem_left\n");
        printf("tree->size should be 0\n");
    }
    printf("\nAfter removing the whole tree by bitree_rem_left/right, tree->root ");
    printf("and tree->size still exist. No need to call tree_init before next use.\n");

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

//============================================================
// Return 1 means current tree is balanced.
// The root depth is 1.
//============================================================

int balanced_binary_tree(BiTreeNode* node, int curDepth) {
    
    int balanced   = 1;
    int unBalanced = 0;
    int leftDepth, rightDepth;

    if (node == NULL)
        return curDepth;
    curDepth++;
    leftDepth = balanced;


}
void binary_tree_construction(BiTree* tree) {
    
    //To construct a tree in following structure
    //         8
    //        / \
    //       3   10
    //      / \    \
    //     1   6    14
    //        / \   /
    //       4   7 13
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
        pArr[count] = (int*)malloc(sizeof(int));
        *pArr[count] = arr[count];
    }

    //Insert at root, tree is empty, construct tree level x
    bitree_ins_left(tree, NULL, pArr[0]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root, pArr[1]);
    bitree_ins_right(tree, tree->root, pArr[2]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left, pArr[3]);
    bitree_ins_right(tree, tree->root->left, pArr[4]);
    //Construct tree level x
    bitree_ins_right(tree, tree->root->right, pArr[5]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left->right, pArr[6]);
    bitree_ins_right(tree, tree->root->left->right, pArr[7]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->right->right, pArr[8]);

    printf("\nCall bitree inorder display\n");
    bitree_display_int(tree, tree->root);
    printf("\n");

}
