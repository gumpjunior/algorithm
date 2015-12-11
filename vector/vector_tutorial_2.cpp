//============================================================================
// Name        : vector_tutorial_2.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description : For explanation about this program, refer section "iterator"
// in pdf "vector_tutorial_with_details.pdf" in onenote dropbox.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;        //Required for vector usage.

int main() {

    cout << "Program starts!\n" << endl;

    int size, count;
    vector<int> myVec;
    
    //
    //Initialize vector.
    //
    for (count=0; count<5; ++count) {
        myVec.push_back(count);
    }

    //
    //Acquire vector size.
    //
    //"myVec.resize()" is not used above. Directly push data at the
    //back of the vector. Will output myVec.size() = 10
    size = myVec.size();
    cout << "myVec.size() = " << size << "\n" << endl;

    //
    //Print out vector by iterator.
    //
    //By using "< myVec.end()" in the for loop can still output the
    //last item in the vector.
    count = 0;
    vector<int>::iterator iVec;
    iVec = myVec.begin();
    iVec++;
    *iVec = 99;
    for (iVec=myVec.begin(); iVec<myVec.end(); ++iVec) {
        //cout << "iVec = " << iVec << endl;     //Cannot printout iterator directly. Illegal.
        cout << "myVec[" << count << "] = " << *iVec << endl;
        ++count;
    }

    cout << "\nProgram endts!" << endl;
    return 0;

}
