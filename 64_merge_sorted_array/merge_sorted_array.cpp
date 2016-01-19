//============================================================================
// Name        : string_basics.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    void mergeSortedArray(int A[], int m, int B[], int n) {

        //if (A == NULL || B == NULL || m == 0 || n == 0) {
        if (A == NULL || B == NULL) {
            return;
        }

        int idx = m + n - 1;
        m--;
        n--;

        while (m >= 0 && n >= 0) {
            if (A[m] > B[n]) {
                A[idx] = A[m];
                m--;
            }
            else {
                A[idx] = B[n];
                n--;
            }
            idx--;
        }

        if (m < 0) {        //All A[] array has been copied.
            while (idx >= 0) {
                A[idx] = B[n];
                idx--;
                n--;
            }
        }

        if (n < 0) {
            while (idx >= 0) {
                A[idx] = A[m];
                idx--;
                m--;
            }
        }

        return;
    }

};

int main() {

    cout << "Program starts!" << endl;

    int A[] = {1, 2, 3};
    int m = 3;
    int B[] = {4, 5};
    int n = 2;

    Solution cSolution;
    cSolution.mergeSortedArray(A, m, B, n);

    for (int i=0; i<(m+n); ++i) {
            cout << A[i] << "  ";
    }

    cout << "\nProgram ends!" << endl;

    return 0;

}
