//============================================================================
// Name        : triangle_traverse_without_hashmap.cpp
// Author      : gumpjunior
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include "triangle_traverse_without_hashmap.hpp"
using namespace std;

TestClass::TestClass(int init_a_class_data_member_) {
    a_class_data_member_ = init_a_class_data_member_;
}

TestClass::~TestClass() {};

void TestClass::test_function() {
    cout << "DEBUG << function test" << endl; 
    cout << "DEBUG << a_class_data_member_" << a_class_data_member_ << endl;
}

