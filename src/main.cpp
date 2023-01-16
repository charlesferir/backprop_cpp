#include <iostream>
#include "Eigen/Eigen"

int main(int, char**) {
    Eigen::Matrix<int, 2, 3> a({{1, 2, 3}, {4, 5, 6}});
    Eigen::Matrix<int, 3, 2> b(a.transpose());
    std::cout << "Hello, world!\n" << a << "\n\n" << b;
}
