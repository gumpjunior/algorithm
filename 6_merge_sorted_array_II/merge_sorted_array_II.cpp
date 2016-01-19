//============================================================================
// Name        : merge_sorted_array_II.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> mergeSortedArrayII(vector<int> &A, vector<int> &B) {

        //if (A == NULL || B == NULL) {
        //    return;
        //}

        vector<int> vecResult (A.size()+B.size(), -1);

        unsigned int m = 0;
        unsigned int n = 0;
        int idx = 0;
        while (m<A.size() && n<B.size()) {
            if (A[m] < B[n]) {
                vecResult[idx] = A[m];
                m++;
            }
            else {
                vecResult[idx] = B[n];
                n++;
            }
            idx++;
        }

        if (m == A.size()) {
            while (n < B.size()) {
                vecResult[idx] = B[n];
                n++;
                idx++;
            }
        }
        else if (n == B.size()) {
            while (m < A.size()) {
                vecResult[idx] = A[m];
                m++;
                idx++;
            }
        }

        return vecResult;
    }

};

int main() {

    cout << "Program starts!" << endl;

    vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 3;

    vector<int> vec3(2);
    vec3[0] = 4;
    vec3[1] = 5;

    vector<int> vec (vec3.size()+vec2.size(), 0);

    Solution cSolution;
    vec = cSolution.mergeSortedArrayII(vec2, vec3);

    for (vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it) {
            cout << *it << "  ";
    }

    cout << "\nProgram ends!" << endl;

    return 0;

}
