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
//#include "../binary_tree/binary_tree.h"
#include "../data_structure/binary_tree/binary_tree.h"

void binary_tree_construction(BiTree* tree);
int max_tree_depth(BiTreeNode* node, int curDepth, int maxDepth);

int main(void) {

    printf("Program starts!\n");

    BiTree  biTree;
    BiTree* pBiTree = &biTree;

    //Test binary tree initialization.
    bitree_init(pBiTree, element_destroy);
    test_bitree_init(pBiTree);

    binary_tree_construction(pBiTree);

    int maxDepth = max_tree_depth(pBiTree->root, 0, 0);
    printf("\nThe tree depth is %d\n", maxDepth);

    //Delete whole tree
    //bitree_rem_left(pBiTree, NULL);
    bitree_destroy(pBiTree);

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
//============================================================
// Because curDepth will add 1 inside, so call this func by:
// max_tree_depth(root, 0, 0); setting curDepth = 0 initially.
//============================================================

int max_tree_depth(BiTreeNode* node, int curDepth, int maxDepth) {
    
    if (node == NULL) {
        return maxDepth;
    }

    curDepth++;
    maxDepth = (curDepth > maxDepth) ? curDepth : maxDepth;
    
    //The following two lines are good mistakes. If use ++ to calculate the
    //leftDespth, ++ will change the value of "curDepth" which will cause an
    //extra count in rightDepth calculation in second line. So neither ++curDepth
    //nor curDepth++ is right!! And also, ++curDepth and curDepth++ will lead
    //to two different results!!
    //int leftDepth  = max_tree_depth(node->left,  ++curDepth, maxDepth);       //GOOD mistake.
    //int rightDepth = max_tree_depth(node->right, curDepth++, maxDepth);
    int leftDepth  = max_tree_depth(node->left,  curDepth, maxDepth);
    int rightDepth = max_tree_depth(node->right, curDepth, maxDepth);
    maxDepth = (leftDepth > rightDepth) ? leftDepth : rightDepth;

    return maxDepth;

}
