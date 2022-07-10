#include <iostream>
using namespace std;

//TreeNode
class TreeNode{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int d){
    data = d;
    left = 0;
    right = 0;
  }
};

//convert tree to mirror
void converttomirror(TreeNode* node){
  if (node == NULL){
    return;
  }else{
    int d;
    TreeNode* temp = new TreeNode(d);
    converttomirror(node -> left);
    converttomirror( node -> right);
    temp = node -> left;
    node -> left = node -> right;
    node -> right = temp; 
  }
}

//preorder
void PrintTreePreorder(TreeNode* node){
  if (node == NULL){
    return;
  }else{
    cout << node -> data << " ";
    PrintTreePreorder(node -> left);
    PrintTreePreorder(node -> right);
  }
}

//inorder
void PrintTreeInorder(TreeNode* node){
  if (node == NULL){
    return;
  }else{
    PrintTreeInorder(node -> left);
    cout << node -> data << " ";
    PrintTreeInorder(node -> right);
    
  }
}
//postorder
void PrintTreePostorder(TreeNode* node){
  if (node == NULL){
    return;
  }else{
    PrintTreePostorder(node -> left);
    PrintTreePostorder(node -> right);
    cout << node -> data << " ";
  }
}

int main() {
  TreeNode* root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
  root -> right = new TreeNode(3);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(7);
  cout << "Preorder of Original Tree: ";
  PrintTreePreorder(root);
  cout <<endl;
  cout << "Inorder of Original Tree: ";
  PrintTreeInorder(root);
  cout << endl;
  cout << "Postorder of Original Tree: ";
  PrintTreePostorder(root);
  cout << endl;
  converttomirror(root);
  cout << "Preorder of Mirror Tree: ";
  PrintTreePreorder(root);
  cout << endl;
  cout << "Inorder of Mirror Tree: ";
  PrintTreeInorder(root);
  cout << endl;
  cout << "Postorder of Mirror Tree: ";
  PrintTreePostorder(root);
  cout << endl;

return 0;
}