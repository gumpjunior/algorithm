//============================================================================
// Name        : reverse_linked_list_II.cpp
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
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */

    // Pre-requisite condition:
    // 1 <= m <= n <= length
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int i = 0;
		ListNode* mMinusOneNode;
		ListNode* tempNode;
		ListNode* oldMthNode;

		// Declare a dummy node and insert it
		// ahead of the List head node.
		ListNode dummyHead_inst(0);
		ListNode* dummyHead;
		dummyHead = &dummyHead_inst;
		dummyHead->next = head;

		if ( head == NULL ) {
			return NULL;
		}

		// m == n, no reverse operation.
		if (m==n) {
			return head;
		}

		// Initialize.
		// All shifting nodes will inserted after mMinusOneNode.
		// oldMthNode is the one hold the position of mth node in old List.
		for (i=0; i<m; ++i) {
			if (i == 0) {
				mMinusOneNode = dummyHead;
				oldMthNode    = head;
			}
			else {
				mMinusOneNode = mMinusOneNode->next;
				oldMthNode    = oldMthNode->next;
			}
		}

		// Insertion operation should run (n-m+1)-1 times.
		for (i=0; i<(n-m); ++i) {
			// Acquire the one which is gonna move.
			tempNode = oldMthNode->next;
			// Remove the acquired node above from the List.
			oldMthNode->next =oldMthNode->next->next;
			// Insert the acquired node above between mMinusOneNode
			// new mth node in new List.
			tempNode->next = mMinusOneNode->next;
			mMinusOneNode->next = tempNode;
		}

		return dummyHead->next;
	}

	// Nothing but only a test function.
    ListNode* test_reverseBetween(ListNode *head, int m, int n) {
        return reverseBetween(head, m, n);
    }

};



int main() {

	cout << "Program starts!" << endl << endl;

	Solution solution_inst;
	int m = 3;
	int n = 5;

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
	pTestNode = solution_inst.test_reverseBetween(&node0, m, n);
	cout << "print out the reversed list:" << endl;
	for (int i=0; i<LIST_COUNT; ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}
	cout << endl << endl;

	cout << "Program ends!" << endl << endl;

	return 0;
}
