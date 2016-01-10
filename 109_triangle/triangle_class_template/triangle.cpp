//============================================================================
// Name        : triangle.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <vector>
#include <iostream>
#include "triangle.hpp"
#include <limits.h>

using namespace std;

TriangleTopDown::TriangleTopDown(vector<vector<int> > triangle) {
    triangle_ = triangle;
}

TriangleTopDown::~TriangleTopDown() {}

int TriangleTopDown::min_path_sum() {

    int min_path_sum = INT_MAX;

    cout << "calling function" << endl;

    return min_path_sum;

}

void TriangleTopDown::triangle_display() {

    int row, column;
    int rowTotal = triangle_.size();
    int columnTotal;

    cout << endl;
    for (row=0; row<rowTotal; ++row) {
        columnTotal = triangle_[row].size();
        for (column=0; column<columnTotal; ++column) {
            cout << "triangle_[" << row << "][" << column << "] = ";
            cout << triangle_[row][column] << endl;
        }
    }
    cout << endl;



}
