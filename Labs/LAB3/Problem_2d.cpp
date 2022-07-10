//Author: NAFIZ IMTIAZ
//CS2413 LAB3
//PROBLEM_2d

#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>
using namespace std;

int main() {

vector<int> v1;
vector<int> :: iterator it1;

  int size;
  int max = 100;
  srand(time(0));

  size = rand()%max;

  cout <<"Random size of the vector:" << size <<endl;
  int i;
  for (i=0; i<size ; i++ ){
    int n1 =  rand()%max;
    v1.push_back(n1);
  }

//sorting the vector
sort(v1.begin(), v1.end());

cout <<"Displaying the vector: "<<endl;
for (it1 = v1.begin(); it1 < v1.end(); it1++){
    cout <<*it1<<" ";
  } 

cout << "\n\nRepeat items: "<< endl; 
for (int i = 0; i < size;i++) {

    int repeat = count(v1.begin(), v1.end(), v1[i]);
    
    // prinitng the result
    if ( repeat > 1 )
        cout << v1[i] << " is repeated for times: " << repeat << endl;
        
    // terminating when first non duplicated one is found
    int last = v1[i];
    while(v1[i] == last) {
        ++i;
    }
}

return 0;

}