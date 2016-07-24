//============================================================================
// Name        : reverse_linked_list.cpp
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
     * @return: The new head of reversed linked list.
     */

    ListNode* newHeadNode;
    ListNode* tempNode;

    ListNode *reverse(ListNode *head) {

    	//
    	// Error checking.
    	//
        if (head == NULL) {
            //cout << "ERROR:head is NULL." << endl;
            return NULL;
        }

        newHeadNode = NULL;			// For first round of while loop.
        while (head != NULL) {
            // Remove node from old linked list.
            tempNode = head;
            head     = head->next;

            // Add new node into the new linked list.
            tempNode->next = newHeadNode;       //DO NOT write "newNode->next" here !!
            // This is a very good point! Do not write "newNode->next".
            // newNode->next  = tempNode;
            newHeadNode  = tempNode;
        }

        return newHeadNode;
    }
};

int main() {
	cout << "Program starts" << endl;

	ListNode* pTestNode = NULL;

	//
	// Construct a linked list.
	//
	ListNode node0(3);
	ListNode node1(4);
	ListNode node2(7);
	ListNode node3(9);
	node0.next = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;

	//
	// Testing
	// Check the linked list by printing out the values.
	//
	pTestNode = &node0;
	for (int i=0; i<4; ++i) {
		cout << "node" << i << "_value = " << pTestNode->val << endl;
		pTestNode = pTestNode->next;
	}

	//
	// Did not write any code or testing about linked list reverse.
	// Coz the above class "Solution" has passed on Lintcode.
	//

	cout << "Program sends" << endl;

	return 0;
}
