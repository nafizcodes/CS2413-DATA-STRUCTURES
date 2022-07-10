//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_1

#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int,10> arr1 = {1,2,3,4,5,6,7,8,9,10};
    
    array<int,10> arr2;
    
    arr2.fill(5);
    
    cout <<"The first element of arr1 is "<< arr1.front() << endl;
    cout <<"The last element of arr1 is "<< arr1.back() <<endl;
    
    arr1.swap(arr2);
    cout <<" Size of arr1 is " << arr1.size()<< endl;
    cout <<" Size of arr2 is " << arr2.size()<< endl;

    return 0;
}