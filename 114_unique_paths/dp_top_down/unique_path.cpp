//============================================================================
// Name        : unique_path.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
using namespace std;

class Solution {

public:

    Solution(int row, int column, int** pArr) {
        row_ = row;
        column_ = column;
        pArr_ = pArr;
        cout << "call class Solution constructor\n" << endl;
    }

    ~Solution() {
        cout << "call class Solution de-constructor\n" << endl;
    };

    int unique_path() {

        int uniquePathTotal = 0;

        //Define left upper corner entry
        pArr_[0][0] = 0;

        //Define top row
        for (int i=0; i<column_; ++i) {
            pArr_[0][i] = 1;
        }

        //Define left most column
        for (int i=0; i<row_; ++i) {
            pArr_[i][0] = 1;
        }

        //Print out matrix for verification
        //for (int i=0; i<row_; ++i) {
        //    for (int j=0; j<column_; ++j) {
        //        cout << "pArr[" << i << "][" << j << "] = " << pArr_[i][j] << endl;
        //    }
        //}
        //cout << endl;

        //Calculate path count sum for other array entries
        for (int i=1; i<row_; ++i) {
            for (int j=1; j<column_; ++j) {
                pArr_[i][j] = pArr_[i][j-1] + pArr_[i-1][j];
            }
        }

        uniquePathTotal = pArr_[row_-1][column_-1];

        return uniquePathTotal;

    }

private:

    int row_, column_;                      //Parameters transferred in are array pointer and size.
    int** pArr_;

    //int array[row_][column_];             //illegal
    //vector<vector<int> > array(row_);     //illegal
    //int** pArrRow = new int*[row_];       //illegal in class private section, But works in main function.
    //for (int i=0; i<row_; ++i) {
    //    pArrRow[i] = new int[column];
    //}

};

int main() {

    cout << "Program starts!\n" << endl;

    //int array[3][] = {};      //Not need to declare a real 2D array.
    int row = 3;
    int column = 4;
    int uniquePathTotal = 0;

    //Memory allocation
    int** pArr = new int*[row];
    for (int i=0; i<row; ++i) {
        pArr[i] = new int[column];
    }

    //Initialize all 0s to 2D array
    //Cannot use memset to initialize a 2D array created from allocated memory.
    //But memset works for directly declaration. Refer onenote for more info.
    //memset(pArr, 0, row*column*sizeof(int));

    Solution cSolution(row, column, pArr);
    uniquePathTotal = cSolution.unique_path();
    cout << "Total count of unique paths in a " << row << "x" << column;
    cout << " array is " << uniquePathTotal << endl;

    //Memory recycle
    for (int i=0; i<row; ++i) {
        delete [] pArr[i];
    }
    delete [] pArr;

    cout << "\nProgram ends!\n" << endl;

    return 0;

}

