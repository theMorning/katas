#include "./bfs.hpp"
#include <iostream>
#include <list>

using std::list;
using std::cout;

// Time complexity: O(V + E)
// Space complexity: O(V)
Graph::Graph(int vertex_count) {
  adj = new list<int>[vertex_count];
  this->vertex_count = vertex_count;
}

void Graph::add_edge(int source, int destination) {
  adj[source].push_back(destination);
}

int Graph::number_of_edges(int source) {
  if (source < vertex_count) {
    return adj[source].size();
  } else {
    return 0;
  }
}

int Graph::number_of_vertices() {
  return vertex_count;
}

void Graph::bfs(int source, std::ostream& cout) {
  if (vertex_count == 0) {
    return;
  }

  list<int> q;

  bool *visited = new bool[vertex_count];
  for (int i = 0; i < vertex_count; i++) {
    visited[i] = false;
  }

  visited[source] = true;
  q.push_back(source);

  while (!q.empty()) {
    int item = q.front();
    cout << item;
    q.pop_front();

    for (auto i = adj[item].begin(); i != adj[item].end(); i++) {
      if (!visited[*i]) {
        visited[*i] = true;
        q.push_back(*i);
      }
    }
  }
  cout << std::endl;
}
