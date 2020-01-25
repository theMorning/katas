#ifndef BFS_HPP_
#define BFS_HPP_

#include <list>
#include <iostream>

using std::list;

class Graph {
  int vertex_count {0};
  list<int> *adj;

public:
  Graph(int vertex_count);
  void add_edge(int source, int destination);
  int number_of_edges(int source);
  int number_of_vertices();
  void bfs(int source, std::ostream& cout = std::cout);
};

#endif
