//============================================================================
// Name        : merge_two_sorted_lists.cpp
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    	if (l1 == NULL && l2 == NULL) {
			return NULL;
		}

        ListNode  dummyHead(0);
        ListNode* pDummyHead = &dummyHead;
        pDummyHead->next = NULL;
        ListNode  l1DummyHead(0);
		ListNode* pL1DummyHead = &l1DummyHead;
		pL1DummyHead->next = l1;
		ListNode  l2DummyHead(0);
		ListNode* pL2DummyHead = &l2DummyHead;
		pL2DummyHead->next = l2;

        ListNode* dummyTail = pDummyHead;
        ListNode* l2PreNode = pL2DummyHead;
        ListNode* l2CurNode = l2PreNode->next;
        ListNode* l1PreNode = pL1DummyHead;
        ListNode* l1CurNode = l1PreNode->next;

        while (l1CurNode != NULL && l2CurNode != NULL) {

        	// Detach l2 current node and append it to new list.
        	if (l1CurNode->val > l2CurNode->val) {
        		l2PreNode->next = l2CurNode->next;
        		l2CurNode->next = NULL;
        		dummyTail->next = l2CurNode;
        		dummyTail       = dummyTail->next;
        		// Do not need to update pre node. Coz current node
        		// has been removed, and pre node points to next node.
        		// Only need to update l2CurNode;
        		// l2PreNode = l2PreNode->next;
        		// Wrong way to update l2CurNode! Coz l2CurNode has been updated.
        		// l2CurNode = l2CurNode->next;
        		l2CurNode = l2PreNode->next;
        	}
        	// Detach l1 current node and append it to new list.
        	else {
        		l1PreNode->next = l1CurNode->next;
        		l1CurNode->next = NULL;
        		dummyTail->next = l1CurNode;
        		dummyTail       = dummyTail->next;
        		l1CurNode = l1PreNode->next;
        	}

        }

        // Append remaining l1 list to the newly merged list.
        if (l1CurNode != NULL) {
        	dummyTail->next = l1CurNode;
        }

        // Append remaining l2 list to the newly merged list.
        if (l2CurNode != NULL) {
        	dummyTail->next = l2CurNode;
        }

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
	ListNode node0(1);
	ListNode node1(2);
	ListNode node2(3);
	ListNode node3(4);
	ListNode node4(7);
	ListNode node5(9);
	int LIST1_COUNT = 6;
	node0.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;

	//
	// Construct another linked list.
	//
	ListNode node20(3);
	ListNode node21(4);
	ListNode node22(6);
	ListNode node23(8);
	int LIST2_COUNT = 4;
	node20.next = &node21;
	node21.next = &node22;
	node22.next = &node23;
	node23.next = NULL;

	//
	// Testing
	// Check the linked list construction by printing out the values.
	//
	pTestNode = &node0;
	cout << "print out the list-1 in order:" << endl;
	for (int i=0; i<LIST1_COUNT; ++i) {
			cout << "node" << i << "_value = " << pTestNode->val << endl;
			pTestNode = pTestNode->next;
	}
	cout << endl;
	pTestNode = &node20;
	cout << "print out the list-2 in order:" << endl;
	for (int i=0; i<LIST2_COUNT; ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}
	cout << endl << endl;

	// Run testing
	pTestNode = solution_inst.mergeTwoLists(&node0, &node20);
	cout << "print out the reversed list:" << endl;
	for (int i=0; i<(LIST1_COUNT+LIST2_COUNT); ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}
	cout << endl << endl;

	cout << "Program ends!" << endl;
	return 0;
}
