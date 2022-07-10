//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_2a

#include <iostream>
#include <vector>
using namespace std;

int main() {
 
//declaring the vectors and iterators
  vector<int>v1;
  vector<int> vsorted;
  vector<int> :: iterator it1;
  vector<int> :: iterator it2;

// declaring the variables
  int n;
  int val;
  int i;
  int j; 
  int temp;

  cout << "Enter the number of elements: ";
  cin >> n;


// for loop to push the values into the vectors
  for (i=0; i<n; i++){
    cout <<"Enter the number: ";
    cin >> val;
    v1.push_back(val);
    vsorted.push_back(val);
  }
  
  //prints out the unsorted elements
  cout<<"Unsorted Elements of vector: "<< endl;
  for (it1=v1.begin(); it1<v1.end(); it1++){
    cout <<*it1<<" ";
  }

  
  // sorting 
  for (i=0; i<n; i++){
    for(j=i+1;j<n; j++){
      if (vsorted[i] > vsorted[j]){
        temp = vsorted[i];
        vsorted[i] = vsorted[j];
        vsorted[j] = temp;
      }
    }
  }

//printing the sorted elements
  cout<<"\n\nSorted Elements of vector: "<< endl;
  for (it2=vsorted.begin(); it2<vsorted.end(); it2++){
    cout <<*it2<<" ";
  }

  return 0;
}