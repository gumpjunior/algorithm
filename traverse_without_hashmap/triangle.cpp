//============================================================================
// Name        : triangle_traverse_without_hashmap.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <vector>
#include <iostream>
#include <limits.h>
#include "triangle.hpp"
using namespace std;


TraverseWithoutHashMap::TraverseWithoutHashMap(vector<vector<int> > &init_triangle) {
    triangle_ = init_triangle;
}

TraverseWithoutHashMap::~TraverseWithoutHashMap() {}

int TraverseWithoutHashMap::MinSum(vector<vector<int> > &triangle) {

    int min_sum = INT_MAX;

    if (triangle.empty()) {
        return -1;
    }

    dfs(0, 0, min_sum, 0, triangle);

    return min_sum;

}

void TraverseWithoutHashMap::dfs(int row, int column, int &min_sum, int branch_sum, vector<vector<int> > triangle) {

    const int triangle_height = triangle.size();

    if (row == triangle_height-1) {
        branch_sum += triangle[row][column];
        min_sum = min(min_sum, branch_sum);
        return;
    }

    dfs(row+1, column, min_sum, (branch_sum+triangle[row][column]), triangle);
    dfs(row+1, column+1, min_sum, (branch_sum+triangle[row][column]), triangle);

}
