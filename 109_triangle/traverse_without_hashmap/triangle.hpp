//============================================================================
// Name        : triangle_traverse_without_hashmap.hpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================


#include <vector>
using namespace std;        //Required, coz "vector" is in namespace std.

class TraverseWithoutHashMap {

public:
    TraverseWithoutHashMap(vector<vector<int> > &init_triangle);
    ~TraverseWithoutHashMap();
    int MinSum(vector<vector<int> > &triangle);


private:
    vector<vector<int> > triangle_;
    void dfs(int row, int column, int &min_sum, int branch_sum, vector<vector<int> > triangle);

};
