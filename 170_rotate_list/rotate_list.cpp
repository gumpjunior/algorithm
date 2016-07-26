//============================================================================
// Name        : rotate_list.cpp
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
    	if (head == NULL) {
    		return NULL;
    	}
    	if (k == 0) {
			return head;
		}
    	// Create a dummy node and put it ahead of the list head.
        ListNode  dummyHead(0);
        ListNode* pDummyHead = &dummyHead;
        pDummyHead->next     = head;
        /* Not allowed. Will run overtime!
    	// If k > list_num, need to do rotation.
    	// This is as same as do moduo to k by list_num.
    	int list_num = 0;
    	ListNode* tempNode = pDummyHead;
    	while (tempNode != NULL) {
    		tempNode->next = tempNode;
    		++list_num;
    	}
    	k = k % list_num;
        */
        // Acquire the pointer of first moving by k steps.
	// If k>list_num, do rotation search.
        ListNode* pMoveFirst  = pDummyHead;
        for (int i=0; i<k; ++i) {
        	if (pMoveFirst->next != NULL) {
        		pMoveFirst = pMoveFirst->next;
        	}
        	else {
        		pMoveFirst = pDummyHead->next;
        	}
        }
        // Move pMoveFirst and pMoveSecond together till pMoveFirst
        // is NULL, then pMoveSecond is the last kth element.
        ListNode* pMoveSecond = pDummyHead;
        ListNode* pBeforeMoveFirst;
        ListNode* pBeforeMoveSecond;
        while (pMoveFirst != NULL) {
        	pBeforeMoveFirst = pMoveFirst;       // Used to record the node before pMoveFirst
        	                                     // for later use after this while loop !!
        	pBeforeMoveSecond = pMoveSecond;
        	pMoveFirst  = pMoveFirst->next;
        	pMoveSecond = pMoveSecond->next;
        }
        // Generate new list.
        pBeforeMoveSecond->next = NULL;
        pBeforeMoveFirst->next = pDummyHead->next;
        return pMoveSecond;
    }
};

int main() {
	cout << "Program starts!" << endl << endl;

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
	pTestNode = solution_inst.rotateRight(&node0, 2);
	cout << "print out the reversed list:" << endl;
	for (int i=0; i<LIST_COUNT; ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}
	cout << endl << endl;

	cout << "Program ends!" << endl << endl;

	return 0;
}
