/*
 ============================================================================
 Name        : binary_tree.c
 Author      : gumpjunior
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void) {

    printf("Program starts!\n");

    BiTree  biTree;
    BiTree* pBiTree = &biTree;

    //Test binary tree initialization.
    bitree_init(pBiTree, element_destroy);
    test_bitree_init(pBiTree);

    //Test binary tree left insert.
    test_bitree_ins_left_and_tree_destroy(pBiTree);

    printf("\nProgram end!\n");

    return EXIT_SUCCESS;

}
