//============================================================================
// Name        : vector_tutorial.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : Vector tutorial program.
// Skills: (*) Embeded vector declaration.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	cout << "Program starts!\n" << endl;

	vector<vector<int> > array(3);
	for(int i=0; i<3; i++)
		array[i].resize(3);         //Set the size for each item of vecotr
	for(int i=0; i<3; i++)			//Although 'i' has been declared in the for loop above.
		for(int j=0; j<3; j++)		//Still need to declare again in this for loop.
			array[i][j] = (i*j);    //Vector is an 2 dimension array 3x3.

	//Output
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<"array["<<i<<"]["<<j<<"] = "<<array[i][j];        //vector access.
			cout<<endl;
		}
	}
	cout<<endl;

	array.resize(5);                //Adding two new entries to existing vectors.
	array[3].resize(3);
	array[4].resize(3);
	//Now the array size is 5x3
	for(int i=0; i<4; i++)			//Intentionally set to 4. The default value of vector element is 0.
		for(int j=0; j<3; j++)
			array[i][j] = (i+j);

	for(int i=0; i<5; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<"array["<<i<<"]["<<j<<"] = "<<array[i][j];
			cout<<endl;
		}
	}
	cout << endl;
	cout << "Program ends!\n" << endl;
	return 0;

}
