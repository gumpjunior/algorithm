/*
 ============================================================================
 Name        : binary_tree_max_depth.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description : function root_to_leaf_path_sum(...) is GOOD for recursion 
 learning!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../binary_tree/binary_tree.h"

void binary_tree_construction(BiTree* tree);
void binary_tree_construction2(BiTree* tree);
void binary_tree_construction3(BiTree* tree);
void binary_tree_construction4(BiTree* tree);
void binary_tree_construction5(BiTree* tree);
int root_to_leaf_path_sum_wrong(BiTreeNode* node);
int root_to_leaf_path_sum(BiTreeNode* node);

int main(void) {

    printf("Program starts!\n");

    BiTree  biTree;
    BiTree* pBiTree = &biTree;
    int sumRootToLeaf = INT_MIN;

    //Test binary tree initialization.
    bitree_init(pBiTree, element_destroy);
    test_bitree_init(pBiTree);

    //************************************************************//
    //                                                            //
    //-------------------------- Test 1 --------------------------//
    //                                                            //
    //************************************************************//
    
    binary_tree_construction(pBiTree);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(pBiTree, pBiTree->root);
    printf("\n");

    sumRootToLeaf = root_to_leaf_path_sum_wrong(pBiTree->root);
    printf("Wrong version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);
    sumRootToLeaf = root_to_leaf_path_sum(pBiTree->root);
    printf("Right version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);

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


    //============================================================//
    //                                                            //
    //-------------------------- Test 2 --------------------------//
    //                                                            //
    //============================================================//

    binary_tree_construction2(pBiTree);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(pBiTree, pBiTree->root);
    printf("\n\n");

    sumRootToLeaf = root_to_leaf_path_sum_wrong(pBiTree->root);
    printf("Wrong version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);
    sumRootToLeaf = root_to_leaf_path_sum(pBiTree->root);
    printf("Right version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);

    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);

    //============================================================//
    //                                                            //
    //-------------------------- Test 3 --------------------------//
    //                                                            //
    //============================================================//

    binary_tree_construction3(pBiTree);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(pBiTree, pBiTree->root);
    printf("\n\n");

    sumRootToLeaf = root_to_leaf_path_sum_wrong(pBiTree->root);
    printf("Wrong version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);
    sumRootToLeaf = root_to_leaf_path_sum(pBiTree->root);
    printf("Right version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);

    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);

    //============================================================//
    //                                                            //
    //-------------------------- Test 4 --------------------------//
    //                                                            //
    //============================================================//

    binary_tree_construction4(pBiTree);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(pBiTree, pBiTree->root);
    printf("\n\n");

    sumRootToLeaf = root_to_leaf_path_sum_wrong(pBiTree->root);
    printf("Wrong version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);
    sumRootToLeaf = root_to_leaf_path_sum(pBiTree->root);
    printf("Right version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);

    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);

    //============================================================//
    //                                                            //
    //-------------------------- Test 5 --------------------------//
    //                                                            //
    //============================================================//

    binary_tree_construction5(pBiTree);
    printf("\nCall bitree inorder display\n");
    bitree_display_int(pBiTree, pBiTree->root);
    printf("\n\n");

    sumRootToLeaf = root_to_leaf_path_sum_wrong(pBiTree->root);
    printf("Wrong version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);
    sumRootToLeaf = root_to_leaf_path_sum(pBiTree->root);
    printf("Right version result is:");
    printf("\nMax path sum from root to leaf is %d\n", sumRootToLeaf);

    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

//============================================================
// This functions applies to both positive number and negative
// number of node data.
// This version is very GOOD for recursion learning!!
//============================================================

int root_to_leaf_path_sum(BiTreeNode* node) {
    
    int pathSum  = INT_MIN;
    int leftSum  = INT_MIN;
    int rightSum = INT_MIN;

    if (node->left == NULL && node->right == NULL) {
        pathSum = *(int*)node->data;
    }
    else if (node->left != NULL && node->right != NULL) {
        leftSum = root_to_leaf_path_sum(node->left);
        rightSum = root_to_leaf_path_sum(node->right);
        pathSum = (leftSum > rightSum) ? leftSum : rightSum;
        pathSum+= *(int*)node->data;
    }
    else {          //Either node->left or node->right is NULL
        BiTreeNode* nodeExisting = (node->left != NULL) ? node->left : node->right;
        pathSum = root_to_leaf_path_sum(nodeExisting);
        pathSum+= *(int*)node->data;
    }

    return pathSum;

}

//============================================================
// (*)What does this function do:
// Acquire the max path sum from root to leaf.
// (*)Note:
// This is a wrong version. For example, for tree:
//        -1
//        /
//       2
//      / \
//    -6  NIL
//    /
//   3
// It will give out the max path sum (-1)+2 = -1. Coz the 
// following code will recognize "NIL" as a leaf, which is 
// wrong.
// (*)If all data in the tree are greater or equal than 0, 
// then this function works correctly.
//============================================================

int root_to_leaf_path_sum_wrong(BiTreeNode* node) {
    
    if (node == NULL) {
        return 0;
    }

    int pathSum  = INT_MIN;
    int leftSum  = INT_MIN;
    int rightSum = INT_MIN;

    leftSum = root_to_leaf_path_sum_wrong(node->left);
    rightSum = root_to_leaf_path_sum_wrong(node->right);

    pathSum = (leftSum > rightSum) ? leftSum : rightSum;
    pathSum+= *(int*)node->data;

    return pathSum;

}

//============================================================
// Tree construction functions
//============================================================

void binary_tree_construction(BiTree* tree) {
    
    //To construct a tree in following structure
    //         8
    //        / \
    //       3   -5
    //      / \    \
    //     -1  6    14
    //        / \   /
    //       4  -7 13
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {8, 3, -5, -1, 6, 14, 4, -7, 13};
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

    return;

}

void binary_tree_construction2(BiTree* tree) {

    //To construct a tree in following structure
    //        -1
    //        /
    //       2
    //      /
    //    -6
    //    /
    //   3
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {-1, 2, -6, 3};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
        pArr[count] = (int*)malloc(sizeof(int));
        *pArr[count] = arr[count];
    }

    //Insert at root, tree is empty, construct tree level x
    bitree_ins_left(tree, NULL, pArr[0]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root, pArr[1]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left, pArr[2]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left->left, pArr[3]);

    return;

}

void binary_tree_construction3(BiTree* tree) {
    
    //To construct a tree in following structure
    //  root = 0        //Only one node
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {0};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
        pArr[count] = (int*)malloc(sizeof(int));
        *pArr[count] = arr[count];
    }

    //Insert at root, tree is empty, construct tree level x
    bitree_ins_left(tree, NULL, pArr[0]);

    return;

}

void binary_tree_construction4(BiTree* tree) {
    
    //To construct a tree in following structure
    //  root = 1        //Only one node
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {1};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
        pArr[count] = (int*)malloc(sizeof(int));
        *pArr[count] = arr[count];
    }

    //Insert at root, tree is empty, construct tree level x
    bitree_ins_left(tree, NULL, pArr[0]);

    return;

}

void binary_tree_construction5(BiTree* tree) {

    //To construct a tree in following structure
    //         8
    //        /
    //       2
    //        \
    //        -3
    //        /
    //       1
    //        \
    //        -9
    //        /
    //       7
    
    printf("\n//====================================================\n");
    printf("// Construct a binary tree\n");
    printf("//====================================================\n");

    int  count = 0;
    int  arr[] = {8, 2, -3, 1, -9, 7};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
        pArr[count] = (int*)malloc(sizeof(int));
        *pArr[count] = arr[count];
    }

    //Insert at root, tree is empty, construct tree level x
    bitree_ins_left(tree, NULL, pArr[0]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root, pArr[1]);
    //Construct tree level x
    bitree_ins_right(tree, tree->root->left, pArr[2]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left->right, pArr[3]);
    //Construct tree level x
    bitree_ins_right(tree, tree->root->left->right->left, pArr[4]);
    //Construct tree level x
    bitree_ins_left(tree, tree->root->left->right->left->right, pArr[5]);

    return;

}


