//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_2c

#include <iostream>
#include <vector>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main(){
  vector<int> v1;
  vector<int> v2;
  vector<int> :: iterator it1;
  vector<int> :: iterator it2;
  
  int size;
  int max = 20;
  srand(time(0));

//taking random number for size
  size = rand()%max;

  cout <<"Vector size is " << size << endl;
  int i;

  //filling the vectors with random numbers
  for (i=0; i<size ; i++ ){
    int n1 =  rand()%max;
    int n2 =  rand() %max;
    v1.push_back(n1);
    v2.push_back(n2);
  }


  cout <<"Vector 1 is: "<< endl;
  for (it1 = v1.begin(); it1 < v1.end(); it1++){
    cout <<*it1<<" ";
  } 
  
  
  cout<<"\n\nVector 2 is: "<<endl;
  for (it2 = v2.begin(); it2 < v2.end(); it2++){
    cout <<*it2<<" ";
  } 

//checking the equality of vectors
  if (v1 == v2) {
        cout << "\n\nBoth vectors are equal";
    }
    else {
        cout << "\n\nBoth vectors are not equal";
    }
 
  return 0;
}
