#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include <vector>
using namespace std;

class TriangleTopDown {

public:
    TriangleTopDown(vector<vector<int> >triangle);
    ~TriangleTopDown();

    int min_path_sum();
    void triangle_display();
    
private:
    vector<vector<int> >triangle_;

};      //Required.

#endif



