//============================================================================
// Name        : sort_integers_II_merge_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
    	merge_sort(A, 0, A.size()-1);
    }

    void merge_sort (vector<int>& A, int p, int r) {
    	if (p < r) {
    		// Cannot miss "+1" below. Otherwise dead loop.
    		// Coz "q-1" is used.
    		int q = p+(r-p+1)/2;
    		this->merge_sort(A, p, q-1);
    		this->merge_sort(A, q, r);
    		this->merge(A, p, q, r);
    	}
    }

	void test_merge(vector<int>& A) {
		merge(A, 0, A.size()/2, (A.size()-1));
	}

private:
	// merge函数只是对两个已经排序好的数列进行合并。所以才需要merge_sort函数。
	// Vector A分成了两部分，[p, q)与[q, r]。merge函数对这两部分进行从小到
	// 大的排序，然后将结果更新到原vector A中。
    void merge(vector<int>& A, int p, int q, int r) {
//    	Header file cannot be found.
//    	ASSERT(p<=q, "ERROR:p > q!");
//    	ASSERT(q<=r, "ERROR:q > r!");
    	vector<int> tempVec;
    	int i = p;
		int j = q;
		// 因为原vector A被分成了两部分，因此需要对这两部分
		// 分别进行遍历，所以需要两个变量，即i和j。
    	while (i<q && j<=r) {
			if (A[i] <= A[j]) {		// Push item[i] into the tempVec;
				tempVec.push_back(A[i]);
				++i;
			}
			else {					// Push item[j] into the tempVec;
				tempVec.push_back(A[j]);
				++j;
			}
    	}
    	// Check if any item left in section [p]~[q-1]
    	// If so, append the left items into tempVec;
    	while (i < q) {
    		tempVec.push_back(A[i]);
    		++i;
    	}
    	// Check if any item left in section [q]~[r-1]
		// If so, append the left items into tempVec;
    	while (j <= r) {
    		tempVec.push_back(A[j]);
    		++j;
    	}
    	// Copy result back to vector A.
    	j=0;
    	for (i=p; i<=r; ++i) {
    		A[i] = tempVec[j];
    		j++;
    	}
    }
};

int main() {
	cout << "Program start!" << endl;

	Solution solution_inst;

	// Generate vector.
	vector<int> myVec;
	myVec.push_back(4);
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(5);
	myVec.push_back(3);

	//
	// Check the vector generated is correct
	//
	cout << "check the vector generated" << endl;
	int count = 0;
	vector<int>::iterator iVec;
	for (iVec=myVec.begin(); iVec<myVec.end(); ++iVec) {
		cout << "myVec[" << count << "] = " << *iVec << endl;
		++count;
	}

	//
	// Test merge sub-feature.
	//
	cout << endl << "test merge sub feature" << endl;
	solution_inst.test_merge(myVec);
	cout << endl << "test merge sub feature done" << endl;
	cout << endl << "Before running merge sort" << endl;
	count = 0;
	for (iVec=myVec.begin(); iVec<myVec.end(); ++iVec) {
		cout << "myVec[" << count << "] = " << *iVec << endl;
		++count;
	}
	solution_inst.sortIntegers2(myVec);
	cout << endl << "After running merge sort" << endl;
	count = 0;
	for (iVec=myVec.begin(); iVec<myVec.end(); ++iVec) {
		cout << "myVec[" << count << "] = " << *iVec << endl;
		++count;
	}

	cout << "Program ends!" << endl;
	return 0;
}
