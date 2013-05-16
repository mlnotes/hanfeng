/* 
 * File:   main.cpp
 * Author: Zhu Hanfeng
 *
 * Created on 2013年5月16日, 上午11:49
 */

#include <iostream>
#include "structure/HFVector.h"

void test_vector()
{
    std::cout << "Testing HFVector...\n";
    
    int *a = new int[50];
    for(int i = 0; i < 3; ++i)
        a[i] = i;
    
    hanfeng::HFVector<int32_t> v(a, 3);
    v.display_vector();
    
//    v.random(0, 1);
    
//    v.display_vector();
    
    std::cout << v.sum() << '\n';
}

int main(int argc, char** argv) 
{
    std::cout << "hanfeng, a toy for Machine Learning\n";
    
    test_vector();
    return 0;
}