//============================================================================
// Name        : triangle_duplicate.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:

    int acquire_max(vector<int> nums) {
        int maxNum    = INT_MIN;
        int start_max = nums.size();
        int end_max   = nums.size();
        int start, end;
        int subSumArr[start_max][end_max];

        if (nums.size() == 0) {
            return 0;
        }

        for (int i=0; i<start_max; ++i) {
            for (int j=0; j<end_max; ++j) {
                subSumArr[i][j] = INT_MIN;
            }
        }
        //Init subSumArr to all 0s
        //memset
        int subSum    = 0;

        for (start=0; start<start_max; ++start) {
            subSum = 0;
            for (end=start; end<end_max; ++end) {
                subSum += nums.at(end);
                subSumArr[start][end] = subSum;
            }
            for (int i=start; i<start_max; ++i) {
                maxNum = max(maxNum, subSumArr[start][i]);
            }
        }

        //
        //For testing output
        //
        cout << "    ";
        for (int i=0; i<end_max; ++i) {
            cout << i << "   ";
        }
        cout << endl;
        for (int i=0; i<start_max; ++i) {
            cout << i << " : ";
            for (int j=0; j<end_max; ++j) {
                if (subSumArr[i][j] < -500) {
                    cout << "neg" << "   ";
                }
                else {
                    cout << subSumArr[i][j] << "   ";
                }
            }
            cout << endl;
        }

        return maxNum;
    }

};


int main() {

    cout << "Program starts!\n";

    //
    //The following testing sequence is from <Intro to algorithms>
    //
    vector<int> vec(17);
    vec.at(0) = 0;
    vec.at(1) = 13;
    vec.at(2) = -3;
    vec.at(3) = -25;
    vec.at(4) = 20;
    vec.at(5) = -3;
    vec.at(6) = -16;
    vec.at(7) = -23;
    vec.at(8) = 18;
    vec.at(9) = 20;
    vec.at(10) = -7;
    vec.at(11) = 12;
    vec.at(12) = -5;
    vec.at(13) = -22;
    vec.at(14) = 15;
    vec.at(15) = -4;
    vec.at(16) = 7;
    
    Solution cSolution;
    cSolution.acquire_max(vec);

    cout << "\nProgram end!\n";

    return 0;
}
