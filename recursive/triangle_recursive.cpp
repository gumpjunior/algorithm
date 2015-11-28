//============================================================================
// Name        : triangle_recursive_vector_version.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : To find the minimum sum of a triangle path by recursive way.
// Skills:     : (*) multiple dimension vector. (*) recursive programming. (*)
// c++ reference. (*) class application. 
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

#define DEBUG_LOCAL 1

class Solution {

public:

    int minimumTotal(vector<vector<int> > &triangle) {		//When calling this method, directly put the declared vector name here.

        int minTotal= 0;

        for(int i = 0; i<(int)triangle.size();++i)
        {
            minTotal+=triangle[i][0];
        }
        triangleHeight = triangle.size();
        int depth = 1;
        int curSum = 0;

		if (DEBUG_LOCAL)
		{
			cout << "DEBUG_LOCAL >> minTotal = " << minTotal <<endl;
			cout << "DEBUG_LOCAL >> triangleHeight = " << triangleHeight << endl;
		}

		minnum(triangle,minTotal,1,0,curSum);

        return minTotal;

    }

    void minnum(vector<vector<int> > &triangle, int & minTotal, int depth, int loc, int &curSum)
    {

        curSum   += triangle[depth-1][loc];
        if(depth == triangleHeight)
        {
            minTotal = minTotal<curSum ? minTotal : curSum;
			return;
        }

        minnum(triangle, minTotal, depth+1, loc, curSum);
        curSum -= triangle[depth][loc];

        minnum(triangle, minTotal, depth+1, loc+1, curSum);
        curSum -= triangle[depth][loc+1];

    }

    private:
    int triangleHeight;

};

int main() {

	cout << "Program starts!\n" << endl;
	int minTotal = 0;

	//Vector declaration
	//vector<vector<int> > array(4);
	//for(int i=0; i<3; i++)
	//	array[i].resize(3);
	//for(int i=0; i<3; i++)			//Although 'i' has been declared in the for loop above.
	//	for(int j=0; j<3; j++)		//Still need to declare again in this for loop.
	//		array[i][j] = (i+j);
	
	vector<vector<int> > array(3);
	array[0].resize(1);
	array[1].resize(2);
	array[2].resize(3);
	array[3].resize(4);
	array[0][0] = 2;
	array[1][0] = 3;
	array[1][1] = 4;
	array[2][0] = 6;
	array[2][1] = 5;
	array[2][2] = 7;
	array[3][0] = 4;
	array[3][1] = 1;
	array[3][2] = 8;
	array[3][3] = 3;

	//Declare and call class method
	Solution cSolution;
	minTotal = cSolution.minimumTotal(array);
	cout << "minTotal = " << minTotal << endl;
	
	cout << "Program ends!\n" << endl;

	return 0;

}








