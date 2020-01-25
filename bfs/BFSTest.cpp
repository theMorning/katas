#include <sstream>
#include <gtest/gtest.h>
#include "bfs.hpp"

TEST(BFSTest, EmptyNoVertices) {
  Graph graph(0);
  ASSERT_EQ(graph.number_of_vertices(), 0);
}

TEST(BFSTest, EmptyNoEdges) {
  Graph graph(0);
  ASSERT_EQ(graph.number_of_edges(0), 0);
}

TEST(BFSTest, AddSingleVertex) {
  Graph graph(1);
  ASSERT_EQ(graph.number_of_vertices(), 1);
}

TEST(BFSTest, AddThreeVertices) {
  Graph graph(3);
  ASSERT_EQ(graph.number_of_vertices(), 3);
}

TEST(BFSTest, AddSingleEdge) {
  Graph graph(1);
  graph.add_edge(0, 0);
  ASSERT_EQ(graph.number_of_edges(0), 1);
}

TEST(BFSTest, AddThreeEdges) {
  Graph graph(1);
  graph.add_edge(0, 0);
  graph.add_edge(0, 0);
  graph.add_edge(0, 0);
  ASSERT_EQ(graph.number_of_edges(0), 3);
}

TEST(BFSTest, BFSNoVerticesNoEdges) {
  Graph graph(0);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "");
}

TEST(BFSTest, BFSOneVertexNoEdges) {
  Graph graph(1);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "0\n");
}

TEST(BFSTest, BFSOneVertexOneEdge) {
  Graph graph(1);
  graph.add_edge(0, 0);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "0\n");
}

TEST(BFSTest, BFSTwoVerticesNoEdges) {
  Graph graph(2);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "0\n");
}

TEST(BFSTest, BFSTwoVerticesNoEdgesFromSecondVertex) {
  Graph graph(2);
  std::ostringstream output_buffer;
  graph.bfs(1, output_buffer);
  ASSERT_EQ(output_buffer.str(), "1\n");
}

TEST(BFSTest, BFSTwoVerticesOneEdge) {
  Graph graph(2);
  graph.add_edge(0, 1);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "01\n");
}

TEST(BFSTest, BFSTwoVerticesOneEdgeFromSecondVertex) {
  Graph graph(2);
  graph.add_edge(0, 1);
  std::ostringstream output_buffer;
  graph.bfs(1, output_buffer);
  ASSERT_EQ(output_buffer.str(), "1\n");
}

TEST(BFSTest, BFSTwoVerticesTwoEdges) {
  Graph graph(2);
  graph.add_edge(0, 1);
  graph.add_edge(1, 0);
  std::ostringstream output_buffer;
  graph.bfs(0, output_buffer);
  ASSERT_EQ(output_buffer.str(), "01\n");
}

TEST(BFSTest, BFSTwoVerticesTwoEdgesFromSecond) {
  Graph graph(2);
  graph.add_edge(0, 1);
  graph.add_edge(1, 0);
  std::ostringstream output_buffer;
  graph.bfs(1, output_buffer);
  ASSERT_EQ(output_buffer.str(), "10\n");
}

TEST(BFSTest, BFSFourVerticesSixEdges) {
  Graph graph(4);
  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(1, 2);
  graph.add_edge(2, 0);
  graph.add_edge(2, 3);
  graph.add_edge(3, 3);
  std::ostringstream output_buffer;
  graph.bfs(2, output_buffer);
  ASSERT_EQ(output_buffer.str(), "2031\n");
}
