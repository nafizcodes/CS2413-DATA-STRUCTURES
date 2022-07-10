#include <iostream>
#include <string>

using namespace std; 

string reverse;
string edited;
string :: reverse_iterator it1;
string :: iterator it2;


bool checkcharacter(char x){
  if ( x == ' '){
    return false;
  }else{
    return true;
  }
}
void check(string input){

  cout <<"Intial string is: "<<input<<endl;

  for (it2 = input.begin(); it2 != input.end(); it2++){
    if (checkcharacter(*it2)){
      edited.push_back(*it2);
    }
  }

  cout <<"\n\nThe reversed string is"<<endl;

  for (it1 = input.rbegin(); it1 != input.rend(); it1++ ){
    
    if (checkcharacter(*it1)){
      reverse.push_back(*it1);
    }
  }

  cout <<reverse ;

  if (edited.compare(reverse) == 0 ){
    cout << "\n\nStrings are palindrome"<<endl;
  }else{
    cout << "\n\nStrings are not equal";
  }
  }

int main(){
  string input;
  cout <<"Enter the line of the string: ";
  getline(cin, input);
  check(input);

 return 0;
}