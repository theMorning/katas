#include <sstream>
#include <gtest/gtest.h>
#include "matrix_rotate.hpp"

TEST(MatrixRotateTest, EmptyMatrix) {
  vector<vector<int>> matrix {
    {}
  };

  matrix_rotate(matrix);
  ASSERT_EQ(matrix, vector<vector<int>>({{}}));
}
TEST(MatrixRotateTest, OneElementMatrix) {
  vector<vector<int>> matrix {
    {42}
  };

  matrix_rotate(matrix);
  ASSERT_EQ(matrix, vector<vector<int>>({{42}}));
}
TEST(MatrixRotateTest, TwoByTwoMatrix) {
  vector<vector<int>> matrix {
    {3,4},
    {6,8}
  };

  matrix_rotate(matrix);
  ASSERT_EQ(matrix, vector<vector<int>>({{4, 8}, {3, 6}}));
}
TEST(MatrixRotateTest, FourByFourMatrix) {
  vector<vector<int>> matrix {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  matrix_rotate(matrix);
  ASSERT_EQ(matrix, vector<vector<int>>({
    {4, 8, 12, 16},
    {3, 7, 11, 15},
    {2, 6, 10, 14},
    {1, 5, 9, 13} 
  }));
}


TEST(MatrixRotateTest, PrintEmptyMatrix) {
  vector<vector<int>> matrix {
    {}
  };
  std::ostringstream output_buffer;
  print_matrix(matrix, output_buffer);
  ASSERT_EQ(output_buffer.str(), "\n");
}
TEST(MatrixRotateTest, PrintOneElementMatrix) {
  vector<vector<int>> matrix {
    {42}
  };
  std::ostringstream output_buffer;
  print_matrix(matrix, output_buffer);
  ASSERT_EQ(output_buffer.str(), "42 \n");
}
TEST(MatrixRotateTest, PrintTwoByTwoMatrix) {
  vector<vector<int>> matrix {
    {3,4},
    {6,8}
  };
  std::ostringstream output_buffer;
  print_matrix(matrix, output_buffer);
  ASSERT_EQ(output_buffer.str(), "3 4 \n6 8 \n");
}
TEST(MatrixRotateTest, PrintFourByFourMatrix) {
  vector<vector<int>> matrix {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  std::ostringstream output_buffer;
  print_matrix(matrix, output_buffer);
  ASSERT_EQ(output_buffer.str(), "1 2 3 4 \n5 6 7 8 \n9 10 11 12 \n13 14 15 16 \n");
}