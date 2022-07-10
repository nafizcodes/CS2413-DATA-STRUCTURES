/* Author: NAFIZ IMTIAZ
Program: Breadth first traversal of graph
*/

#include <iostream>
#include <list>

using namespace std;

class Graph {
  int verticesNum;
  list<int>* adjLists;
  bool* visited;

  public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

Graph::Graph(int vertices) {
  verticesNum = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS 
void Graph::BFS(int startVertex) {
  visited = new bool[verticesNum];
  for (int i = 0; i < verticesNum; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " \n";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}