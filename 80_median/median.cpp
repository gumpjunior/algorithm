//============================================================================
// Name        : quick_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
    	int medianNum = 0;
    	unsigned int k = (nums.size()+1)/2;
    	priority_queue<int> que;
    	for (unsigned int i=0; i<nums.size(); ++i) {
			if (que.size() == k) {
				if (nums[i] < que.top()) {
					que.pop();
					que.push(nums[i]);
				}
			}
			else {
				que.push(nums[i]);
			}
    	}
    	medianNum = que.top();
    	return medianNum;
    }
};


int main() {
	cout << "Program starts!" << endl;

	//
	// Construct vector"
	//
	// Do not declare class instatiation like this!
	//Solution solution_inst();
	Solution solution_inst;
	vector<int> myVec;
	myVec.push_back(4);
	myVec.push_back(5);
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	//
	// Check the vector generated is correct
	//
	cout << "Check the vector generated is correct" << endl;
	int count = 0;
	vector<int>::iterator iVec;
	for (iVec=myVec.begin(); iVec<myVec.end(); ++iVec) {
		cout << "myVec[" << count << "]" << *iVec << endl;
		++count;
	}

	//
	// Call class method to acquire median
	//
	int idx = solution_inst.median(myVec);
	cout << "median number is " << idx << endl;

	cout << "Program ends!" << endl;
	return 0;
}
