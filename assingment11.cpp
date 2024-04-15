#include <iostream>
#include <vector>
class Matrix {
private:
    std::vector<std::vector<int>> matrix;
public:
    Matrix(std::vector<std::vector<int>> m) : matrix(m) {}
    Matrix operator+(const Matrix& other) const {
        std::vector<std::vector<int>> result_matrix;
        for (int i = 0; i < 3; ++i) {
            std::vector<int> row;
            for (int j = 0; j < 3; ++j) {
                row.push_back(matrix[i][j] + other.matrix[i][j]);
            }
            result_matrix.push_back(row);
        }
        return Matrix(result_matrix);
    }
    void print() const {
        for (const auto& row : matrix) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    Matrix OBJ1({{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9}});
    Matrix OBJ2({{9, 8, 7},
                 {6, 5, 4},
                 {3, 2, 1}});
    Matrix OBJ3 = OBJ1 + OBJ2;

    OBJ3.print();
    return 0;
}
