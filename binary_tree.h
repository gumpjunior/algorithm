/*
 * binary_tree.h
 *
 *  Created on: Oct 4, 2015
 *      Author: djiao
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode {
    int key;                        /*< integer key as index >**/
    struct _treeNode* parent;
    struct _treeNode* lchild;       /*< ptr to left child >**/
    struct _treeNode* rchild;       /*< ptr to right child >**/
    int value;                      /*< use integer as the stored value type >**/
} sTreeNode;

//tree construction
int tree_node_init(sTreeNode* treeNode);

sTreeNode* binary_tree_construction(void);

//tree traverse - recursive version
int preorder_walk(sTreeNode* root);

int postorder_walk(sTreeNode* root);

int inorder_walk(sTreeNode* root);

//tree traverse - non-recursive version

int nonrecursion_preorder_walk_v1(sTreeNode* root);

int nonrecursion_preorder_walk_v2(sTreeNode* root);

int nonrecursion_inorder_walk(sTreeNode* root);

//other tree properties

int max_depth(sTreeNode* root);

int tree_balanced(sTreeNode* node);

sTreeNode* lowest_common_ancestor(sTreeNode* node1,
        sTreeNode* node2, sTreeNode* root);

#endif /* BINARY_TREE_H_ */
