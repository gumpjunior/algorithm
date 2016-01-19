//============================================================================
// Name        : recover_rotated_sorted_array.cpp
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

    void recoverRotatedSortedArray(vector<int> &nums) {

        int edgePoint;
        unsigned int i;
        edgePoint = 0;

        for (i=0; i<nums.size(); ++i) {
            if (nums.at(i) < nums.at(edgePoint)) {
                edgePoint = i;
            }
        }

        reverseVector(nums, 0, edgePoint);
        reverseVector(nums, edgePoint+1, nums.size()-1);
        reverseVector(nums, 0, nums.size()-1);

        for (i=0; i<nums.size(); ++i) {
            cout << nums.at(i) << "  ";
        }

        return;
    }

//private:
    void reverseVector(vector<int> &nums, int start, int end) {

        int temp;

        if (end-start <= 1 || nums.size() == 0) {
            return;
        }
        for (; start<end; ++start, --end) {
            temp           = nums.at(start);
            nums.at(start) = nums.at(end);
            nums.at(end)  = temp;
        }

        return;
    }

};


int main() {

    cout << "Program starts!\n";

    vector<int> vec(5);
    vec.at(0) = 4;
    vec.at(1) = 5;
    vec.at(2) = 1;
    vec.at(3) = 2;
    vec.at(4) = 3;
    
    Solution cSolution;
    //cSolution.maxSubArray(vec);
    cSolution.recoverRotatedSortedArray(vec);

    cout << "\nProgram end!\n";

    return 0;
}
