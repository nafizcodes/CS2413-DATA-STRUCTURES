#include <iostream>
#include <queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
      data = d;
      left = 0;
      right = 0;
    }
};
  
int Width_Max(Node* root)
{
    if (root == NULL)
        return 0;

    int width = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        width = max(count, width);

        while (count--) {
            Node* temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return width;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Maximum width is " << Width_Max(root) << endl;
    return 0;
}
  