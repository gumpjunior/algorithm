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

using namespace std;

int main() {

    cout << "Program starts!\n" << endl;

    int min_sum = 0;

    //Vector declaration
    //vector<vector<int> > array(4);
    //for(int i=0; i<3; i++)
    //    array[i].resize(3);
    //for(int i=0; i<3; i++)            //Although 'i' has been declared in the for loop above.
    //    for(int j=0; j<3; j++)        //Still need to declare again in this for loop.
    //        array[i][j] = (i+j);

    //Declaration and initialization way 1
    vector<vector<int> > array(4);
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

    TraverseWithoutHashMap c_traverse_without_hashmap(array);
    min_sum = c_traverse_without_hashmap.MinSum(array);
    cout << "test case 1 >> min_sum = " << min_sum << endl;

    //Declaration and initialization way 2
    //vector<vector<int> > array2 = {
    //    {2},
    //    {3, 4},
    //    {6, 5, 7},
    //    {4, 1, 8, 3}
    //};
	//Saw above declaration way online, but not work for C++98.
	vector<vector<int> > array2(array);
    array2[2][1] = -3;

    array2[3][1] = 0;
    array2[3][2] = -1;
    array2[3][3] = 0;

    min_sum = c_traverse_without_hashmap.MinSum(array2);
    cout << "test case 2 >> min_sum = " << min_sum << endl;

    cout << "\nProgram ends!" << endl;
    return 0;

}
