#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;
vector<vector<int>> adjlist ; // adjacency list
vector<bool> vis; // boolean vector to store visited
vector<int> dis, parent; // vector to store distance and parent

template <class T>
class Node{
public:
  Node<T>(T d, Node* p = 0, Node* n = 0 ){
    data = d;
    prev = p;
    next = n;
  }
  T data;
  Node* prev;
  Node* next;
};

template <class T>
class LinkedList{
  public:
    LinkedList<T>(){
      head = 0;
      tail = 0;
    }
    void addHead(T data){
      Node<T>* n = new Node<T>(data);
      if(head == 0){
        head = n;
        tail = n;
      }
      else{
        n->next = head;
        head->prev = n;
        head = n;
      }
    }
    T deleteHead(){
      T returnValue = head->data;
      if(head == tail){
        delete head;
        head = tail = 0;
      }else{
        head = head->next;
        delete head->prev;
      }
      return returnValue;
    }
    void addTail(T data){
      Node<T>* n = new Node<T>(data);
      if(head == 0){
        head = n;
        tail = n;
      }else{
        tail->next = n;
        n->prev = tail;
        tail = n;
      }
    }
    bool empty(){
      return head == 0;
    }
    T data;
    Node<T>* head;
    Node<T>* tail;

};

template <class T>
class Queue{
  private:
  LinkedList<T> queue;
  public:
  Queue<T>(){
  }
  void enqueue(T data){
    queue.addTail(data);
  }
  T dequeue(){
    T returnValue = queue.head->data;
    queue.deleteHead();
    return returnValue;
  }
  T front(){
    return queue.head->data;
  }
  bool empty(){
    return queue.empty();
  }
};

template <class T>
class Stack{
  private:
    LinkedList<T> stack;
  public:
  Stack<T>(){
    
  }
  T pop(){
    return stack.deleteHead();
  }
  void push(T data){
    stack.addHead(data);
  }
  T top(){
    return stack.head->data;
  }
  bool empty(){
    return stack.empty();
  }
};
void Graph()
{
    adjlist[0].push_back(1); // 0 corresponds to A
    adjlist[0].push_back(2);
    adjlist[0].push_back(3);

    adjlist[1].push_back(4); // 1 corresponds to B

    adjlist[2].push_back(1);
    adjlist[2].push_back(6); // 2 corresponds to C

    adjlist[3].push_back(2); // 3 corresponds to D
    adjlist[3].push_back(6);

    adjlist[4].push_back(2); // 4 corresponds to E
    adjlist[4].push_back(5);

    adjlist[5].push_back(2); // 5 corresponds to F
    adjlist[5].push_back(7);

    adjlist[6].push_back(5); // 6 corresponds to G
    adjlist[6].push_back(7);
    adjlist[6].push_back(8);

    adjlist[7].push_back(4);  // 7 corresponds to H
    adjlist[7].push_back(8);

    adjlist[8].push_back(5);// 8 corresponds to I

}

void dfs(int source)
{
    // depth first search using stack
    Stack<int> s;
    s.push(source);

    while(!s.empty())
    {
        int x = s.top();
        s.pop();

        if(!vis[x])
        {
            char c = x+65; // converting number back to character
            cout<<c<<" ";
            vis[x]=1;
        }

        for(auto i:adjlist[x])
        {
            if(!vis[i])
            s.push(i);
        }
    }
    cout<<"\n";
}

bool bfs(int source,int destination)
{

      Queue<int> q;
      dis[source] = 0;
      vis[source] = 1;
      q.enqueue(source);

      while(!q.empty())
      {
          int x = q.front();
          q.dequeue();

          for(auto i:adjlist[x])
          {
              if(!vis[i])
              {
                  vis[i]=1;
                  parent[i] = x;
                  dis[i] = dis[x] + 1;
                  q.enqueue(i);

                  if(i==destination)
                    return 1;
              }
          }
      }
      return 0;
}

void print_path(int source,int destination)
{
    vector<int> path;// vector to store path
    int temp = destination;
    path.push_back(temp);

    while(parent[temp]!=-1)
    {
        path.push_back(parent[temp]);
        temp = parent[temp];
    }

    for(int i=path.size()-1;i>=0;i--)
    {
        char c = path[i]+65;
        cout<<c<<" ";
    }

    cout<<endl;

}

int main()
{
    // initialisation
    // A-I we have 9 nodes
    adjlist = vector<vector<int>>(9);

    Graph();

    int key;
    while(1)
    {
        vis = vector<bool>(9,0);
        dis = vector<int>(9,INT_MAX);
        parent = vector<int>(9,-1);
        cout<<"                 Menu               \n";
        cout<<"Depth-First Search (0), Minimum Path Search (1)\n";
        cout<<"Exit Program (3)\n";

        bool f=0;
        cout<<"\t\tChoose? ";
        cin>>key;
        char source,destination;
        switch(key)
        {
            case 0:
            cout << "Enter the Source(capital): ";
            cin>>source;
            cout <<"The DFS is : ";
            dfs(source-65); // Converting char to int
            break;
            case 1:
            cout <<"Enter the source(capital) : ";
            cin>>source;
            cout <<"Enter the destination(capital): ";
            cin>>destination;
            cout << "The Minimum path is: ";
            f=bfs(source-65,destination-65);
            if(f)
            print_path(source-65,destination-65);
            else
            cout<<"Source and destination are not connected\n";
            break;
            case 3:
            cout << "PROGRAM ENDS! " <<endl;
            default:
            return 0;
        }
        cout<<endl;
    }
}