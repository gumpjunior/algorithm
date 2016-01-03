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

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../binary_tree/binary_tree.h"
//For cpp compilation, the following .c file must be included.
//Otherwise error "undefined function xx referenced ..." reported.
//This is a different point between cpp and c++.
#include "../binary_tree/binary_tree.c"

using namespace std;

void binary_tree_construction(BiTree* tree);
void binary_tree_construction2(BiTree* tree);
void binary_tree_construction3(BiTree* tree);
void binary_tree_construction4(BiTree* tree);
void binary_tree_construction5(BiTree* tree);
BiTreeNode* node_parent_list(stack<BiTreeNode*>& nodeParents, BiTreeNode* node, BiTreeNode* target);
void test_node_parent_list(BiTreeNode* node);
//BiTreeNode* lowest_common_ancestor(BiTreeNode* root, BiTreeNode* node1, BiTreeNode* node2);

int main(void) {

    printf("Program starts!\n");

    BiTree  biTree;
    BiTree* pBiTree = &biTree;

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

    test_node_parent_list(pBiTree->root);

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


    //Delete whole tree
    bitree_rem_left(pBiTree, NULL);

    printf("\nProgram ends!\n");

    return EXIT_SUCCESS;

}

//============================================================
// Return an stack object in c++.
//============================================================

void test_node_parent_list(BiTreeNode* node) {

    stack<BiTreeNode*> nodeParents;
    BiTreeNode* retVar;
    BiTreeNode* it;

    //
    //Test - 1
    //
    //Node should be the root.
    retVar = node_parent_list(nodeParents, node, node);
    if (retVar != NULL) {
        printf("\nnode value is: %d\n\n", *(int*)retVar->data);
        while(!nodeParents.empty()) {
            it = nodeParents.top();
            printf("val = %d\n", *(int*)it->data);
            nodeParents.pop();
        }
    }
    else {
        printf("\nNode does NOT exist\n");
    }

    //
    //Test - 2
    //
    retVar = node_parent_list(nodeParents, node, node->right->right);
    if (retVar != NULL) {
        printf("\nnode value is: %d\n\n", *(int*)retVar->data);
        while(!nodeParents.empty()) {
            it = nodeParents.top();
            printf("val = %d\n", *(int*)it->data);
            nodeParents.pop();
        }
    }
    else {
        printf("\nNode does NOT exist\n");
    }

    //
    //Test - 3
    //
    //Node should not exist.
    retVar = node_parent_list(nodeParents, node, node->right->right->right);
    if (retVar != NULL) {
        printf("\nnode value is: %d\n\n", *(int*)retVar->data);
        while(!nodeParents.empty()) {
            it = nodeParents.top();
            printf("val = %d\n", *(int*)it->data);
            nodeParents.pop();
        }
    }
    else {
        printf("\nNode does NOT exist\n");
    }

    return;

}

//Return NULL means the node does NOT exist.
//Syntax to pass stack object by reference!!
BiTreeNode* node_parent_list(stack<BiTreeNode*>& nodeParents,
        BiTreeNode* node, BiTreeNode* target) {

    BiTreeNode* retVar;
    nodeParents.push(node);
    printf("The nodeParents stack size is: %lu\n", nodeParents.size());

    if (node == NULL || node == target) {
        if (node == NULL)
            nodeParents.pop();
        return node;
    }
    else {
        retVar = node_parent_list(nodeParents, node->left, target);
        if (retVar != NULL) {
            return retVar;
        }
        retVar = node_parent_list(nodeParents, node->right, target);
        if (retVar != NULL) {
            return retVar;
        }
        else {
            nodeParents.pop();
            return NULL;
        }
    }


}


//BiTreeNode* lowest_common_ancestor(BiTreeNode* root, BiTreeNode* node1, BiTreeNode* node2) {
//    
//
//
//}

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

    unsigned int  count = 0;
    int  arr[] = {8, 3, -5, -1, 6, 14, 4, -7, 13};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(arr[0]); ++count) {
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

    unsigned int  count = 0;
    int  arr[] = {-1, 2, -6, 3};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    //for (count=0; count<sizeof(arr)/sizeof(int); ++count) {
    for (count=0; count<sizeof(arr)/sizeof(arr[0]); ++count) {
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

    unsigned int  count = 0;
    int  arr[] = {0};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(arr[0]); ++count) {
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

    unsigned int  count = 0;
    int  arr[] = {1};
    int* pArr[sizeof(arr)/sizeof(arr[0])];                         //Legal
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

    unsigned int  count = 0;
    int  arr[] = {8, 2, -3, 1, -9, 7};
    int* pArr[sizeof(arr)/sizeof(int)];                         //Legal
    for (count=0; count<sizeof(arr)/sizeof(arr[0]); ++count) {
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


