//============================================================================
// Name        : main.cpp
// Author      : Dongyue Jiao
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "binary_tree.h"
//using namespace std;

//Interface definition
//b-tree init
//b-tree add
//b-tree deletion
//b-tree find via key value

int main(void)
{
    std::cout << "======= program start =======\n";

    /*traverse style*/
    std::cout << "\n======= preorder_walk output: =======\n";

    sTreeNode* root = NULL;
    root = binary_tree_construction();
    preorder_walk(root);
    std::cout << std::endl;

    std::cout << "\n======= postorder_walk output: =======\n";
    postorder_walk(root);
    std::cout << std::endl;

    std::cout << "\n======= inorder_walk output: =======\n";
    inorder_walk(root);
    std::cout << std::endl;

    /*divide conquer style*/
    //refer pdf "Binary Tree Preorder Traversal" in onenote.
    //The data structure used for conquer should be linked list.
    //Coz I am still at the beginning stage of algorithm, leave
    //this algorithm implementation later.

    /*non-recursion*/
    //Coz stack is involved, C++ is used.
    std::cout << "\n======= non-recursion preorder_walk output version_1: =======\n";
    nonrecursion_preorder_walk_v1(root);

    std::cout << "\n======= non-recursion preorder_walk output version_2: =======\n";
    nonrecursion_preorder_walk_v2(root);
    std::cout << std::endl;

    std::cout << "\n======= non-recursion ineorder_walk output: =======\n";
    nonrecursion_inorder_walk(root);
    std::cout << std::endl;

    std::cout << "\n======= max tree depth: =======\n";
    std::cout << "maxDepth = " << max_depth(root) << std::endl;

    std::cout << "\n======= balanced tree or not: =======\n";
    std::cout << "Returning value 0 means tree is unbalanced" << std::endl;
    std::cout << "Returning value is: " << tree_balanced(root) << std::endl;

    std::cout << "\n======= search for lowest common ancestor: =======\n";
    sTreeNode* node1 = root->lchild->lchild;
    sTreeNode* node2 = root->rchild->rchild->lchild;
    sTreeNode* tmp = lowest_common_ancestor(node1, node2, root);
    std::cout << "key value of LCA is " << tmp->key << std::endl;

    std::cout<<"\n======= program end =======\n";

    return 0;
}

