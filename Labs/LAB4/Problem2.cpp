#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void tokenize( char str[50]){

  char delimeter[] = ".";
  vector <char* > v1;
  vector <char* > :: iterator it1;

  char *token = strtok(str, delimeter);

  cout <<"{" ;
  while (token != NULL ){
    v1.push_back(token);
    token  = strtok(NULL, delimeter);
  }
  for (it1 = v1.begin(); it1 < v1.end(); it1++ ){
    if (it1 == v1.end()-1){
      cout <<*it1 ;    
    }else{
    cout <<*it1 << ",";
  }
  }
  cout << "}";
}

int main(){

  char str[50];
  cout << "Enter the IP address: ";
  cin  >> str;
  tokenize(str);

  return 0;
}