//Author: Nafiz Imtiaz
//Lab6 CS2413 course
//Program to calculate the mathematical expression using Binary tree and stack


#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Making Tree node 
class TreeNode{
public:
  char data;
  TreeNode* left;
  TreeNode* right;
  //constructor
  TreeNode(int d){
    data = d;
    left = 0;
    right = 0;
  }
  TreeNode(int d,TreeNode* l,TreeNode* r){
    data = d;
    left = l;
    right = r;
  }
};


//prototype of the functions
bool valid(string s);
bool isDigit(char c);
bool isOperator(char c);
string postfix(string s);
int prec(char c);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
TreeNode* createTree(string s);
void printData(char c );
int calculate(TreeNode* root);
int power(int base, int powerraised);


//Driver function
int main(){
  string expression;
  cout << "Enter expression: ";
  cin >> expression;
  
  //is expression is valid
  if(valid(expression)){
    string s = postfix(expression);
    //cout << s << endl;
    TreeNode* root = createTree(s);
    cout << "Result is " << calculate(root)<< endl;
    cout <<"Predorder: ";
    preorder(root);
    cout <<endl;
    cout <<"Inorder: ";
    inorder(root);
    cout <<endl;
    cout << "Postorder: ";
    postorder(root);
    cout <<endl;
  }
  else{
    cout << "Invalid " << endl;
  }
  return 0;
}

bool valid(string s){
  bool ans;
  for(int i = 0; i < s.size(); i++){
    char c = s[i]; 
    if(isDigit(c) || isOperator(c) || c == '(' || c == ')'){
      ans = true;
    }
    else{
      ans = false;
      return ans;
    }
  }
  return ans;
}

//isdigit
bool isDigit(char c){
  if(c >= '0' && c <= '9'){
    return true;
  }
  else{
    return false;
  }
}

//isOperator
bool isOperator(char c){
  if (c == '+' || c == '-' || c == '*' || c== '/' || c == '^' || c== '%'){
    return true;
  } 
  else{
    return false;
  }
}

//converting to postfix
string postfix(string s){
  stack<char> stack;
  string result = "";

  for(char c:s){
    if(isDigit(c)){
      result += c;
    }
    else if(isOperator(c)){
      while(!stack.empty() && prec(c) <= prec(stack.top())) {
                result += stack.top();
                stack.pop(); 
            }
      stack.push(c);  
    }
    else if(c == '('){
      stack.push(c);
    }
    else if (c == ')'){
      while(stack.top() != '('){
        result += stack.top();
        stack.pop();
      }
      stack.pop();
    }
  }
     // Pop all the remaining elements from the stack
    while(!stack.empty()) {
        result += stack.top();
        stack.pop();
    
  }
  return result;
}

//precedence function
int prec(char c){
  if (c == '^'){
    return 2;
  }
  else if(c == '*' || c == '/' || c == '%'){
    return 1;
  }
  else if(c == '+' || c == '-'){
    return 0;
  }
  else{
    return -1;
  }
}

//inorder function
void inorder(TreeNode* root){
  if (root == 0){
    return;
  }
  inorder(root->left);
  printData(root->data);
  inorder(root->right);
}

//preorder function
void preorder(TreeNode* root){
  if (root == 0){
    return;
  }
  printData(root->data);
  inorder(root->left);
  inorder(root->right);
}

//postorder function
void postorder(TreeNode* root){
  if (root == 0){
    return;
  }
  inorder(root->left);
  inorder(root->right);
  printData(root->data);
}

//Making the tree
TreeNode* createTree(string s){
  stack<TreeNode*> s1;
  for(char c:s){
    if(isDigit(c)){
      TreeNode* temp = new TreeNode(c);
      s1.push(temp);

    }
    else if(isOperator(c)){
      TreeNode* left = s1.top();
      s1.pop();

      TreeNode* right = s1.top();
      s1.pop();
      //gaurantee to to tow operand
      TreeNode* temp = new TreeNode(c,left, right);
      s1.push(temp);

    }
    else{

    }
  }
  return s1.top(); 
}

//Printing the data after checking
void printData(char c ){
  if(isDigit(c)){
    cout << c - 48 << " ";
  }
  else if(isOperator(c)){
    cout << c <<" ";
  }
  else{

  }

}

//function to do the calculation
int calculate(TreeNode* root){
  int leftvalue;
  int rightvalue;
  if (!root){
    return 0;
  }
  if(root->left == 0 && root->right == 0){
   return root->data - '0';
  }

  
  leftvalue = calculate(root->left);
  rightvalue = calculate(root->right);
  
  
  if (root->data == '+'){
    return leftvalue + rightvalue;    
  }
  if (root->data == '*'){
    return leftvalue * rightvalue;    
  }
   if (root->data == '/'){
    return leftvalue / rightvalue;    
  }
   if (root->data == '-'){
    return leftvalue - rightvalue;    
  }
   if (root->data == '%'){
    return leftvalue % rightvalue;    
  }
   if (root->data == '^'){
    return power(rightvalue, leftvalue);    
  }
  return -1;
}

//power function
int power(int base, int powerraised){
  if ( powerraised == 0){
    return 1;
  }else{
    return (base * power(base, powerraised-1));
  }
}