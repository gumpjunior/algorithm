//============================================================================
// Name        : partition_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */

    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return NULL;
        }

        // Vars required for old/original list.
        // Do not need pDummyTail. But pCurNode and pPreNode are
        // required. Pls think about why.
        ListNode  dummyHead_inst(0);
        ListNode* pDummyHead = &dummyHead_inst;
        pDummyHead->next = head;
        ListNode* pPreNode = pDummyHead;
        ListNode* pCurNode = pDummyHead->next;

        // Vars required for newly generated list.
        // pNewDummyHead and pNewDummyTail are required.
        ListNode  newDummyHead_inst(0);
        ListNode* pNewDummyHead = &newDummyHead_inst;
        // pNewDummyTail与pNewDummyHead指向了同一个节点。下面在
        // 进行正序插入的时候，使用Tail进行尾端控制。所以，最终
        // pNewDummyHead->next即是新list的head。妙。
        ListNode* pNewDummyTail = pNewDummyHead;

        while (pCurNode != NULL) {
            if (pCurNode->val >= x) {
                // Remove tempNode from List by concatianting
                // the list nodes before and after tempNode.
                pPreNode->next = pCurNode->next;
                // Insert current node in the new list.
                pCurNode->next = NULL;
                // 这里的tail pointer及其初始化使用的很妙。
                pNewDummyTail->next = pCurNode;
                pNewDummyTail = pNewDummyTail->next;
                pCurNode      = pPreNode->next;
            }
            else {
            	pCurNode = pCurNode->next;
            	pPreNode = pPreNode->next;
            }

        }
        // Append the new to the new partitioned orignal List.
        pPreNode->next = pNewDummyHead->next;
        // Dummy head node will be deallocated automatically.

        return pDummyHead->next;
    }
};

int main() {

	cout << "Program starts!" << endl;

	Solution solution_inst;
	ListNode* pTestNode;

	//
	// Construct a linked list.
	//
	ListNode node0(3);
	ListNode node1(4);
	ListNode node2(7);
	ListNode node3(9);
	ListNode node4(2);
	ListNode node5(1);
	int LIST_COUNT = 6;
	node0.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;

	//
	// Testing
	// Check the linked list construction by printing out the values.
	//
	pTestNode = &node0;
	cout << "print out the list in order:" << endl;
	for (int i=0; i<LIST_COUNT; ++i) {
			cout << "node" << i << "_value = " << pTestNode->val << endl;
			pTestNode = pTestNode->next;
	}
	cout << endl << endl;

	// Run testing
	pTestNode = solution_inst.partition(&node0, 4);
	cout << "print out the partitioned list:" << endl;
	for (int i=0; i<LIST_COUNT; ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}

	cout << endl << endl;
	cout << "Program ends!" << endl << endl;

	return 0;
}
