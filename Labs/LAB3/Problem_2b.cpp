//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_2b


#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;


int main(){

//Defining the vectors
  vector<int> v1; 
  vector<int> v2;
  vector<int> :: iterator it1;
  vector<int> :: iterator it2;

//declaring the variables
  int i;
  int n;
  int element;
  int j;


  cout<<"Enter the number of vector integer elements greater than 100: "<<endl;
  cin >> n;

  if (n<100){
    cout << "Failed!" <<endl;
    cout << "Enter the number of vector integer elements greater than 100 again: ";
    cin >>n; }

//filling the vectors
  for(i=1;i<= n; i++){
    v1.push_back(i);
  }

  cout <<"Enter each element of vector of 10 elements: "<<endl;
  
  //filling the vector of 10 elements
  for(j=1;j<=10;j++){
    cin >> element;
    v2.push_back(element);
  }

  //crosschecking the vector elements
 /*for (it1 = v1.begin(); it1 < v1.end(); it1++){
    cout <<*it1<<" ";
  } 
  
  cout<<"\n\n";
   for (it2 = v2.begin(); it2 < v2.end(); it2++){
    cout <<*it2<<" ";
  } 
*/


  int count = 0;  //counter to count the elements present

//finding the number of same elements present
  for (it1 = v1.begin(); it1 < v1.end(); it1++){
    for (it2 = v2.begin(); it2 < v2.end(); it2++){
      if (*it1 == *it2){
        count++;
    }
    }
  }

  cout <<"\nNumber of elements contained the vector is "<< count <<endl;

  double percent;
  percent = (double(count)/10.0) * 100.0 ;
  cout << "Percentage contained in the vector: " << percent <<endl;

  cout << "Percentage not contained in the vector: " << 100.0 - percent <<endl;



  return 0;
}
