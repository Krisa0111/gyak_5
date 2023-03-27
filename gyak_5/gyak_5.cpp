// gyak_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vector.h"
int main()
{
    ///*int a[3];
    //int b[] = { 1, 2, 3, 5 };

    //int* c = new int[3];

    //delete[] c;*/

    nik::vector<int> v1;
    nik::vector<bool> v2(3);
    nik::vector<float> v3(2, 3.14);
    nik::vector<int> v4{ 1, 3, 5, 7 };

    nik::vector<int> v5(v4); // copy construct

    v5 = v4; //copy assignment

    for (size_t i = 0; i < v4.size(); i++)
    {
        std::cout << v4[i] << std::endl;
    }
    for (nik::vector<int>::iterator it = v4.begin();
        it != v4.end();
        ++it)
    {

    }

      
}

