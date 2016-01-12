//============================================================================
// Name        : substring_is_a_palindrome_or_not.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
using namespace std;

void test_isPalindrome();
void test_getIsPalindrome();

//========================================================
// What: 
//  String starting at "begin" ending at "end" is a 
// palindrome or not.
// Case: 
//  (*)string==NULL, return false;
//  (*)empty string, return false.
//  (*)Only one char string, return true.
//========================================================

bool isPalindrome(char* string, int begin, int end) {
    int i = 0;
    int j = 0;

    if (string == NULL || string[0] == '\0') {
        return false;
    }

    for (i=begin, j=end; i<j; ++i, --j) {
        if (string[i] != string[j]) {
            return false;
        }
    }
    return true;
}

//========================================================
//What:
//  Given a string, acquire the result of a 2D array
//to tell string(i, j) is a panlindrome or not. 'i' is 
//the starting index, 'j' is the ending index.
//========================================================

void getIsPalindrome(char* string, int size, bool** palindromeFlag) {
    
    int i, j;
    int length, start;

    //
    //Special case
    //
    if (string == NULL || palindromeFlag == NULL || string[0] == '\0') {
        return;
    }

    //
    //Init arr to store result
    //
    for (i=0; i<size; ++i) {
        for (j=0; j<size; ++j) {
            palindromeFlag[i][j] = false;
        }
    }

    //
    //Acquire result for 1 char string
    //
    for (i=0; i<size; ++i) {
        palindromeFlag[i][i] = true;
    }

    //
    //Acquire result for string containing two continuous chars
    //
    //for (i=0; i<size-1; ++i) {                //GOOD.
    //    j = i + 1;
    for (i=0, j=i+1; j<size; ++i, ++j) {        //Use ending condition as the judgement makes more sense.
                                                //By this way, it is easy to avoid "forget" -1 mistake.
        if (*(string+i) == *(string+j)) {
            palindromeFlag[i][j] = true;
        }
    }

    //
    //Acquire other results for palindromeFlag
    //
    for (length=2; length<size; ++length) {
        for (start=0; start+length<size; ++start) {
            palindromeFlag[start][start+length] = 
                isPalindrome(string, start+1, (start+length-1)) && 
                (string[start] == string[start+length]);
        }
    }

    return;
}

int minCut(char* string, int size, bool** palindromeFlag) {

    int minCut = 0;
    int i = 0;
    int cutPos = 0;

    //
    //Preparation
    //
    getIsPalindrome(string, size, palindromeFlag);

    //
    //Worst case initialization
    //
    int* f = new int [size+1];
    for (i=0; i<(size+1); ++i) {
        f[i] = i-1;
    }

    //
    //For testing
    //
    //for (i=0; i<(size+1); ++i) {
    //    cout << "f[" << i << "] = " << f[i] << " " << endl;
    //}

    //
    //Acquire the result
    //
    for (i=1; i<(size+1); ++i) {
        for (cutPos=0; cutPos<i; ++cutPos) {
            if (palindromeFlag[cutPos][i-1]) {
                f[i] = min(f[i], f[cutPos]+1);
            }
        }
    }

    //
    //For testing
    //
    for (i=0; i<size+1; ++i) {
        cout << f[i] << endl;
    }
    minCut = f[size];

    return minCut;

}

int main() {

    cout << "Program starts!\n" << endl;

    int row, column, size, minCutCount;
    //char subString1[] = "abacfggg";
    char subString2[] = "subSaaaa";
    size = 8;
    row = size;
    column = size;
    minCutCount = 0;

    //memory allocation
    bool** pArr = new bool*[row];
    for (int i=0; i<row; ++i) {
        pArr[i] = new bool[column];
    }

    test_isPalindrome();
    test_getIsPalindrome();

    cout << "Target string is:" << endl;
    cout << subString2 << endl;
    minCutCount = minCut(subString2, size, pArr);
    cout << "minCutCount = " << minCutCount << endl;

    //memory cycle
    for (int i=0; i<row; ++i) {
        delete [] pArr[i];
    }
    delete [] pArr;

    cout << "Program ends!\n" << endl;

    return 0;

}


//========================================================
// Testing function definitions
//========================================================

void test_isPalindrome() {

    bool result = false;

    char subPalindrome1[] = "ababa";
    char subPalindrome2[] = "aabb";
    char subPalindrome3[] = "";
    char subPalindrome4[] = "a";

    cout << "==============================================" << endl;
    cout << "testing_isPalindrome starts" << endl;
    cout << "==============================================" << endl;

    result = isPalindrome(subPalindrome1, 0, 4);
    if (result) {
        cout << "\nCORRECT << subPalindorm1 is a panlindrom string!\n" << endl;
    }
    else {
        cout << "ERROR << subPalindorm1 is a NOT panlindrom string!\n" << endl;
    }

    result = isPalindrome(subPalindrome2, 0, 3);
    if (result) {
        cout << "ERROR << subPalindorm2 is a panlindrom string!\n" << endl;
    }
    else {
        cout << "CORRECT << subPalindorm2 is NOT a panlindrom string!\n" << endl;
    }


    result = isPalindrome(subPalindrome3, 0, 0);
    if (result) {
        cout << "ERROR << subPalindorm3 is a panlindrom string!\n" << endl;
    }
    else {
        cout << "CORRECT << subPalindorm3 is NOT a panlindrom string!\n" << endl;
    }

    result = isPalindrome(subPalindrome4, 0, 0);
    if (result) {
        cout << "CORRECT << subPalindorm4 is a panlindrom string!\n" << endl;
    }
    else {
        cout << "ERROR << subPalindorm4 is NOT a panlindrom string!\n" << endl;
    }

    cout << "==============================================" << endl;
    cout << "testing_isPalindrome done" << endl;
    cout << "==============================================" << endl;

}


//========================================================
//What:
//  Display 1 if string(i,j) is a palindrome, otherwise
//display 0. Row # stands for i, column # stands for j.
//Case:
//  (*)
//========================================================

void test_getIsPalindrome() {

    cout << "\n==============================================" << endl;
    cout << "testing_getIsPalindrome starts" << endl;
    cout << "==============================================" << endl;

    char subPalindrome2[] = "aabbc";
    int row = 5;            //from string size
    int column = 5;         //from string size, should equal to row.

    //
    //memory allocation
    //
    bool** pArr = new bool*[row];
    for (int i=0; i<row; ++i) {
        pArr[i] = new bool[column];
    }

    //
    //run testing over string subPalindrome2
    //
    getIsPalindrome(subPalindrome2, row, pArr);

    for (int i=0; i<row; ++i) {
        for (int j=0; j<column; ++j) {
            if (pArr[i][j]) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;

    //
    //run testing over string subPalindrome
    //
    char subPalindrome[] = "aaaaa";
    row = 5;
    column = 5;
    getIsPalindrome(subPalindrome, row, pArr);

    for (int i=0; i<row; ++i) {
        for (int j=0; j<column; ++j) {
            if (pArr[i][j]) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;

    //
    //run testing over string subPalindrome3
    //
    char subPalindrome3[] = "a";
    int row2 = 1;
    int column2 = 1;

    //
    //memory allocation for subPalindorm3
    //
    bool** pArr2 = new bool*[row2];
    for (int i=0; i<row2; ++i) {
        pArr2[i] = new bool[column2];
    }
    getIsPalindrome(subPalindrome3, row2, pArr2);

    for (int i=0; i<row2; ++i) {
        for (int j=0; j<column2; ++j) {
            if (pArr2[i][j]) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    //
    //memory cycle
    //
    for (int i=0; i<row; ++i) {
        delete [] pArr[i];
    }
    delete [] pArr;

    for (int i=0; i<row2; ++i) {
        delete [] pArr2[i];
    }
    delete [] pArr2;

    cout << "==============================================" << endl;
    cout << "testing_getIsPalindrome done" << endl;
    cout << "==============================================" << endl;

    return;

}
