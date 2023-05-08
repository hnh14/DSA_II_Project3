#include "catch/catch.hpp"
#include "../matrix.hpp"
#include <iostream>

TEST_CASE(("Test 1")) {
    Matrix matrix;
    
    // for(int i = 0; i < 20; i++) {
    //     for(int j = 0; j < 20; j++) {
    //         std::cout << matrix[i][j] << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    CHECK((matrix[0][1] == 25.41));

    // CHECK((matrix.Brute(3) == 74.32));
    //Cities, Tours, Gens
    matrix.Genetic(5,5,10,40);
    std::cout << matrix.Brute(5) << std::endl;
}

