#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* right;
  node* left;

  node(int d){
    data = d;
    left = 0;
    right = 0;
  }
};

int isBST(node* root);
int isBSTfunc(node* root, int min, int max);
int MIN(node* root);
int MAX(node* root);
void PrintTreeInorder(node* root);

int main(){
 node *root = new node(4);
 root->left = new node(2);
 root->right = new node(5);
 root->left->left = new node(1);
 root->left->right = new node(3);
 cout << "Inorder of the binary tree is ";
 PrintTreeInorder(root);
 
  int INT_MIN;
  int INT_MAX;

  INT_MIN = MIN(root);
  INT_MAX = MAX(root);

  cout << endl;

 if(isBST(root))
 cout<<"NOT a BST";
else
 cout<<"IS BST";

return 0;
}

int isBST(node* root)
{
    int INT_MIN;
    int INT_MAX;
    return(isBSTfunc(root, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */

int isBSTfunc(node* root, int min, int max)
{
    if (root==NULL)
        return 1;

    if (root->data < min ||root->data > max)
        return 0;
     
    return
        isBSTfunc(root->left, min, root->data - 1) && 
        isBSTfunc(root->right, root->data + 1, max);
}

int MIN(node* root){
  while(root->left != NULL){
    root = root->left;
  }
   return root->data;
}

int MAX(node* root){
  while(root->right != NULL){
    root = root->right;
  }
  return root->data;
}

void PrintTreeInorder(node* root){
  if (root == NULL){
    return;
  }else{
    PrintTreeInorder(root -> left);
    cout << root -> data << " ";
    PrintTreeInorder(root -> right);
  }
}