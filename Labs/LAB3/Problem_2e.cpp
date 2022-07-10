//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_2e

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

//declaring the vectors
vector <int> v1 = {20,10,70,30,50};
vector <int> v2 = {77,11,55,22,33};
vector <int> :: iterator it1;
vector <int> :: iterator it2;
vector <int> :: iterator it3;
vector <int> :: iterator it4;


//sorting the vector
sort(v1.begin(), v1.end());

cout<< "The sorted vector v1 is "; 
for(it1= v1.begin() ; it1 < v1.end() ; it1++ ){
    cout << *it1 <<" ";
}

//sorting the vector

sort(v2.begin(), v2.end());
cout<< "\n\nThe sorted vector v2 is "; 
for(it2= v2.begin() ; it2 < v2.end() ; it2++ ){
    cout<< *it2 <<" ";
}

for (it3 = v2.begin(); it3 < v2.end(); it3++){
  v1.push_back(*it3);
}


sort(v1.begin(), v1.end());

cout<< "\n\nThe sorted - merged vector is "; 
for(it4= v1.begin() ; it4< v1.end() ; it4++ ){
    cout << *it4 <<" ";
}
return 0;
}