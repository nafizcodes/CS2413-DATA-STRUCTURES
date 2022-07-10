#include <iostream>
#include <queue>
using namespace std;

class Btnode{
  public:
    int data;
    Btnode* left;
    Btnode* right;

    Btnode(int d){
      data = d;
      left = NULL;
      right = NULL;
    }
};
// Function to create a new Node in heap
//Btnode* GetNewNode(int data);
// To insert data in BST, returns address of root node 
Btnode* Insert(Btnode* root,int data);
//search
bool Search(Btnode* root,int data);
//preorder
void PrintTreePreorder(Btnode* node);
//inorder
void PrintTreeInorder(Btnode* node);
//postorder
void PrintTreePostorder(Btnode* node);
//Bft
void Breadthfirst(Btnode* node);
//delete
Btnode* Delete(Btnode* node, int data);
//max number
Btnode* max(Btnode* r);
//min number
Btnode* min(Btnode* r);


int main() {
Btnode* root = NULL;
int input;
int sizeValue;
int v;
while (true){
cout <<"*******************************************************************"<<endl;
cout << "                       M E N U                    " << endl;
cout << "Create (0), Search (1), Breadth-First Traversal (2)\nDepth-First Traversal: preorder (3), inorder (4), postorder (5),\nDelete(6),Exit Program (7) " << endl;
cout << "Choose? " ;

cin >> input;

switch (input){
  
  case 0:
  //create
  cout << "How many members you want to enter: ";
  cin >> sizeValue;
  cout << "Enter the members of the tree:" << endl;
  cout << "(Press enter key after each entry)" << endl;
  for(int i = 0; i < sizeValue; i++){
    cin >> v;
    root = Insert(root,v);
  }
  
 
  cout << " Binary Tree Created" <<endl;
  
  break;

  case 1:

  int number;
	cout<<"Enter number be searched: ";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
  //search

  break;

  case 2:

  Breadthfirst(root);
  cout <<endl;
  //bft

  break;

  case 3:

  //predorder
  PrintTreePreorder(root);
  cout <<endl;
  break;

  case 4:

  //inorder
  PrintTreeInorder(root);
  cout <<endl;
  break;

  case 5:
 
 //postorder
  PrintTreePostorder(root);
  cout << endl;
  break;

  case 6:
  cout << "Enter the value to be deleted: ";
  cin >> v;
  Delete(root,v);
  cout << "    Deleted successfully" << endl;
  break;

  case 7:
  cout << "Program Ends!";
  //exit
  break;

  default:
    cout <<"Inavlid option";  
}
}

return 0;
}

// To insert data in BST, returns address of root node 
Btnode* Insert(Btnode* root,int data) {
	if(root == NULL) { // empty tree
		root = new Btnode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}


//search
bool Search(Btnode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
//preorder
void PrintTreePreorder(Btnode* node){
  if (node == NULL){
    return;
  }else{
    cout << node -> data << " ";
    PrintTreePreorder(node -> left);
    PrintTreePreorder(node -> right);
  }
}

//inorder
void PrintTreeInorder(Btnode* node){
  if (node == NULL){
    return;
  }else{
    PrintTreeInorder(node -> left);
    cout << node -> data << " ";
    PrintTreeInorder(node -> right);
  }
}
//postorder
void PrintTreePostorder(Btnode* node){
  if (node == NULL){
    return;
  }else{
    PrintTreePostorder(node -> left);
    PrintTreePostorder(node -> right);
    cout << node -> data << " ";
  }
}

void Breadthfirst(Btnode* node){
  queue<Btnode*> q1;
  if (node == NULL){
    return ;
  }else{
    q1.push(node);
    while(q1.empty() == false){
      Btnode* t = q1.front();
      cout << t->data;
      cout << " ";
      q1.pop();
      if(t->left != 0){
        q1.push(t->left);
      }
      if(t->right != 0){
        q1.push(t->right);
      }
    }
  }
}

Btnode* Delete(Btnode* node, int data){
  if (Search(node,data) == false){
    cout << "Element does not exist"<< endl;
  }else {
    //empty tree
    if (node == 0){
      cout << "tree is empty" << endl;
      return NULL;
    //one node or leaf node
    }if(node->left == 0 && node->right == 0){
      delete node;
      return NULL;
      //one child left
    }if(data < node->data){
      node->left = Delete(node->left,data);
      //one child right
    }else if(data > node->data){
      node->right = Delete(node->right,data);
    }//
    else{
      Btnode *t = max(node->left);
      node->data = t->data;
      node->left = Delete(node->left,t->data);
    }

  }
  return node;
}

Btnode* max(Btnode* r){
  while(r->right != NULL){
    r = r->right;
  }
  return r;
}

Btnode* min(Btnode* r){
  while (r->left != NULL){
    r = r->left;
  }
  return r;
}
