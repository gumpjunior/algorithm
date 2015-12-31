#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdlib.h>

//============================================================
// Define data structure for binary tree.
//============================================================

typedef struct BiTreeNode_ {
    void*               data;
    struct BiTreeNode_* left;
    struct BiTreeNode_* right;
} BiTreeNode;

typedef struct BiTree_ {
    int size;
    void (*destroy)(void* data);
    //int  (*match)(const void* key1, const void* key2);
    BiTreeNode* root;
} BiTree;

//============================================================
// Define interface for binary tree.
//============================================================
void element_destroy(void* data);
void bitree_init(BiTree* tree, void (*destroy)(void* data));
void bitree_destroy(BiTree* tree);
int bitree_ins_left(BiTree* tree, BiTreeNode* node, const void* data);
int bitree_ins_right(BiTree* tree, BiTreeNode* node, const void* data);
void bitree_rem_left(BiTree* tree, BiTreeNode* node);
void bitree_rem_right(BiTree* tree, BiTreeNode* node);
//int bitree_merge(...);
void bitree_display_int(BiTree* tree, BiTreeNode* node);

//#define bitree_size(BiTree* tree) tree->size;     //GOOD mistake
#define bitree_size(tree) (tree)->size
#define bitree_root(tree) (tree)->root
#define bitree_is_eob(node) ((node) == NULL)        //end of branch
//#define bitree_is_leaf(node) 
#define bitree_data(node) (node)->data
#define bitree_left(node) (node)->left
#define bitree_right(node) (node)->right

//============================================================
// Define interface for binary tree test functions.
//============================================================

int test_bitree_init(BiTree* tree);
int test_bitree_ins_left_and_rem_left(BiTree* tree);
int test_bitree_ins_right_and_rem_right(BiTree* tree);

#endif
