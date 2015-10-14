#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "binary_tree.h"
#include <stack>

int tree_node_init(sTreeNode* treeNode) {
    treeNode->key = -1;
    treeNode->parent = NULL;
    treeNode->lchild = NULL;
    treeNode->rchild = NULL;
    treeNode->value = -1;
    return 0;
}

/*
 * To construct a tree in following structure for test purpose
 *          8
 *         / \
 *        3   10
 *       / \    \
 *      1   6    14
 *         / \   /
 *        4   7 13
 */

sTreeNode* binary_tree_construction(void) {
    //node root
    sTreeNode* root = NULL;

    sTreeNode* node8 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node8);
    node8->key = 8;

    //node 3
    sTreeNode* node3 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node3);
    node3->parent = node8;
    node3->key = 3;
    node8->lchild = node3;

    //node 1
    sTreeNode* node1 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node1);
    node1->parent = node3;
    node1->key = 1;
    node3->lchild = node1;

    //node 6
    sTreeNode* node6 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node6);
    node6->parent = node3;
    node6->key = 6;
    node3->rchild = node6;

    //node 4
    sTreeNode* node4 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node4);
    node4->parent = node6;
    node4->key = 4;
    node6->lchild = node4;

    //node 7
    sTreeNode* node7 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node7);
    node7->parent = node6;
    node7->key = 7;
    node6->rchild = node7;

    //node 10
    sTreeNode* node10 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node10);
    node10->parent = node8;
    node10->key = 10;
    node8->rchild = node10;

    //node 14
    sTreeNode* node14 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node14);
    node14->parent = node10;
    node14->key = 14;
    node10->rchild = node14;

    //node 13
    sTreeNode* node13 = (sTreeNode*) malloc(sizeof(sTreeNode));
    tree_node_init(node13);
    node13->parent = node14;
    node13->key = 13;
    node14->lchild = node13;

    root = node8;
    node8 = NULL;
    node3 = NULL;
    node1 = NULL;
    node6 = NULL;
    node7 = NULL;
    node4 = NULL;
    node10 = NULL;
    node14 = NULL;
    node13 = NULL;

    return root;
}

/*
 * Tree walks:
 * (*) preorder
 * (*) inorder
 * (*) postorder
 * Use two ways to solve the above issues.
 * Recursion style and non-recursion style.
 */

int preorder_walk(sTreeNode* root) {
    if (root != NULL) {
        printf("%d  ", root->key);
        preorder_walk(root->lchild);
        preorder_walk(root->rchild);
    }
    return 0;
}

int postorder_walk(sTreeNode* root) {
    if (root != NULL) {
        postorder_walk(root->lchild);
        postorder_walk(root->rchild);
        printf("%d  ", root->key);
    }
    return 0;
}

int inorder_walk(sTreeNode* root) {
    if (root != NULL) {
        postorder_walk(root->lchild);
        printf("%d  ", root->key);
        postorder_walk(root->rchild);
    }
    return 0;
}

//my own idea
int nonrecursion_preorder_walk_v1(sTreeNode* root) {
    std::stack<sTreeNode*> preOrder;
    preOrder.push(root);
    sTreeNode* node = NULL;

    //while( !preOrder.empty() || (node != NULL) )
    while (!preOrder.empty())
    //Usually, node!=NULL is set to run the last node.
    //coz stack is empty then. But for preorder walk,
    //it can be ignored.
    {
        node = preOrder.top();
        preOrder.pop();
        if (node != NULL) {
            std::cout << node->key << "  ";
            preOrder.push(node->rchild);
            preOrder.push(node->lchild);
        }
    }
    std::cout << std::endl;

    return 0;
}

//the version found online
int nonrecursion_preorder_walk_v2(sTreeNode* root) {
    std::stack<sTreeNode*> preOrder;
    sTreeNode* node = root;

    while ((node != NULL) || (!preOrder.empty()))
    //check preOrder is not empty is necessary. When node
    //points to an empty child of a leaf, it is NULL, but
    //the stack is not empty, so the program should go on.
    {
        while ((node != NULL)) {
            std::cout << node->key << "  ";
            preOrder.push(node);
            node = node->lchild;
        }

        if (!preOrder.empty()) {
            node = preOrder.top();
            preOrder.pop();
            node = node->rchild;
        }
    }

    return 0;
}

int nonrecursion_inorder_walk(sTreeNode* root) {
    std::stack<sTreeNode*> inOrder;
    sTreeNode* node = root;

    while ((node != NULL) || (!inOrder.empty())) {
        while (node != NULL) {
            inOrder.push(node);
            node = node->lchild;
        }

        if (!inOrder.empty()) {
            node = inOrder.top();
            std::cout << node->key << "  ";
            inOrder.pop();
            node = node->rchild;
        }
    }

    return 0;
}

//non-recursive postorder walk ignore first. Coz it is not
//quite possible to show up in interview.

//Other tree properties
/*
 * Maximum Depth of Binary Tree
 */

int max_depth(sTreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = max_depth(root->lchild);
    int right = max_depth(root->rchild);

    return (std::max(left, right) + 1);
}

/*
 * Balanced Binary Tree
 * If tree is NOT balanced, return 0.
 * Otherwise return the height of the tree.
 */

int tree_balanced(sTreeNode* node) {
    //int balanced   = 1;
    int unbalanced = 0;
    int left = 0;
    int right = 0;

    if (node == NULL) {
        return 0;
    }

    left = tree_balanced(node->lchild);
    right = tree_balanced(node->rchild);

    if ((left - right <= 1) || (right - left <= 1)) {
        //return balanced;
        return std::max(left, right) + 1;
    } else {
        return unbalanced;
    }
}

/*
 * Lowest Common Ancestor
 */

sTreeNode* lowest_common_ancestor(sTreeNode* node1, sTreeNode* node2,
        sTreeNode* root) {
    std::stack<sTreeNode*> node1Parents;
    std::stack<sTreeNode*> node2Parents;

    while (node1 != NULL) {
        node1Parents.push(node1);
        node1 = node1->parent;
    }
    while (node2 != NULL) {
        node2Parents.push(node2);
        node2 = node2->parent;
    }

    int size1 = node1Parents.size();    //return 0 if stack is just initialized.
    int size2 = node2Parents.size();
    int size = (size1 < size2) ? size1 : size2;
    for (int tmp = 0; tmp < size; tmp++) {
        node1 = node1Parents.top();
        node1Parents.pop();
        node2 = node2Parents.top();
        node2Parents.pop();
        if (node1 != node2) {
            return node1->parent;
        }
    }

    if (node1 == node2)
    //In the above for loop, if node1 == node2 when tmp=size-1,
    //means one node is on the path from root to the other node.
            {
        return node1;
    } else {
        return NULL;
    }
}

