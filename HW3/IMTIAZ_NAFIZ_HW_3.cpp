/* Homework #3 , Nafiz Imtiaz
AUTHOR : NAFIZ IMTIAZ
COURSE = CS 2413 
PROGRAM : DECIMAL TO BINARY, OCTAL, HEXADECIMAL CONVERTER
FILENAME : IMTIAZ_NAFIZ_HW_3.cpp
*/

#include <iostream>
using namespace std;

//making node class
class Node{
  public:
  Node(){
    next = 0;
  }
  Node(int i, Node *in = 0){
    data = i ; next = in; 
  }  
  int data;
  Node* next;
};

//making linked list class
class LinkedList{
public:
  Node *head;
  Node *tail;
  //constructor
  LinkedList(){
    head = 0;
    tail = 0;
  }
  void addFirst(int data){
    Node *n = new Node(data);
    if (head == 0){
      head = n;
      tail = n;
    }
    else{
      n->next = head;
      head = n;
    }
  }
  void removeFirst(){
    if(head == 0){
      cout << "The linked list is empty" << endl;
    }
    else if(head == tail){
      delete head;
      head = 0;
      tail = 0;
    }
    else{
      Node *n = head;
      head = head->next;
      delete n;
    }
  }
    bool isEmpty(){
      return head == 0;
    }
    int top(){
      return head->data;
    }

};

//making Stack 
class Stack {
  LinkedList* l;
  public: 
  Stack(){
    l = new LinkedList();
  }
//push funtion 
  void push(int i){
    l->addFirst(i);  
}
//pop function
  void pop(){
    l->removeFirst();
  
  }
//function to check if stack is empty
  bool isEmpty(){
    return l->isEmpty();
  }
//function returns the top value
  int top(){
    return l->top();
  }

};

//function to convert Decimal to Binary
void Dec_to_Bin(int i){
  Stack mystack;
  while (i > 0){
    int rem = i%2;
    i = i /2;
    mystack.push(rem);
  }
  while (!mystack.isEmpty()){
    int item;
    item = mystack.top();
    mystack.pop();
    cout << item;
  }
}

//Function to convert Decimal to Octal
void Dec_to_Oct(int i){
  Stack mystack;
  while (i > 0){
    int rem = i % 8;
    i = i / 8;
    mystack.push(rem);
  }
  while (!mystack.isEmpty()){
    int item;
    item = mystack.top();
    mystack.pop();
    cout << item;
  }
}

//Function to convert Decimal to Hexadecimal
void Dec_to_Hex(int i){
  Stack mystack;
  while (i > 0){
    int rem = i % 16;
    if(rem<10){
      mystack.push(rem + 48);
    }else{
      mystack.push(rem + 55);
    }
    i = i /16;
  }
  while (!mystack.isEmpty()){
    char item;
    item = mystack.top();
    mystack.pop();
    cout <<item;
  }
}

//driver function
int main() {
  char input;
  int num;
  while (input != '3'){

  cout <<"\n*********************************************************"<<endl;
  cout <<"                       MENU                     "  <<endl;
  cout << "Binary(0), Octal (1) , Hexadecimal(2) , Exit Program(3)" <<endl;
  cout << "                    Choose? " ;
  cin  >>  input;

  
//swtich cases
  switch(input){
    case '0':
    //Binary
    cout << "Enter the decimal number to be converted to Binary: ";
    cin >> num;
    cout << "Binary number: ";
    Dec_to_Bin(num);


    break;
    case '1':
    // octal

    cout << "Enter the decimal number to be converted to Octal: ";
    cin >> num;
    cout << "Octal number: ";
    Dec_to_Oct(num);


    break;
    case '2':
    //Hexadecimal
    cout << "Enter the decimal number to be converted to Hexadecimal: ";
    cin >> num;
    cout << "Hexadeciamal number: ";
    Dec_to_Hex(num);
    break;

    case '3':
    cout << "Program ends!";
    break;

    default:
    cout << "Wrong Input! Try again" << endl;
    cout <<"                      MENU                     "  <<endl;
    cout << "Binary(0), Octal (1) , Hexadecimal(2) , Exit Program(3)" <<endl;
    cout << "                    Choose? " ;
    cin  >>  input;

  }
  }
  return 0;
}