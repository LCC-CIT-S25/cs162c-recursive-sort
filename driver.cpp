/*
 * CS162C Lab 02: recursive algorithms
 *
 * Name:
 * Version:
 * Date:
 */

#include <iostream>
#include <iomanip>

constexpr int MAX_WIDTH = 10;
constexpr int MAX_MAZE_D1 = MAX_WIDTH;

void print2DintArray(int array[][MAX_WIDTH], size_t d0, size_t d1, int printWidth = 5) {
 for (size_t i = 0; i < d0; i++) {
     for (size_t j = 0; j < d1; j++) {
         std::cout << std::setw(printWidth) << array[i][j];
     }
     std::cout << std::endl;
 }
}


bool testRowSort(int array[][MAX_WIDTH], size_t d0, size_t d1, int expected[][MAX_WIDTH]) {

    // TODO: call sorting function

    // Check each value is as expected
    for (size_t i=0; i < d0; i++) {
        for (size_t j=0; j < d0; j++) {
            if (array[i][j] != expected[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool testRowSort0() {
    int array0[][MAX_WIDTH] = {
        { 1, 2, 13, 0},
        { 12, 6, -1, 2}
    };
    int expected_result[][MAX_WIDTH] ={
        { 0, 1, 2, 13},
        { -1, 2, 12, 6 }
    };

    // if you pass in a larger width you can see what the initialization of memory does
    print2DintArray(array0, 2, MAX_WIDTH);

    return testRowSort(array0, 2, 4, expected_result);
}

bool testMaze(int maze[][MAX_MAZE_D1], size_t d0, size_t d1, const int expectedCost) {
    int minCost0 = 0;
    // TODO: Add calls to test functions
    // minCost0 = /* replace with call */;

    if (expectedCost != minCost0) {
        std::cerr << "Calculate minimum cost for maze0 " << minCost0 <<
            " != " << expectedCost << " (expected min cost)" << std::endl;
        return false;
    }

    return true;
}

bool testMaze0() {
    const int expected_minCost0 = 7;
    // array must be declared with MAX D1 for functions to work.
    int test_maze0[][MAX_MAZE_D1] = {
        { 1, 1, 1, 1},
        { 2, 2, 6, 3},
        { 5, 1, 1, 1},
    };

    return testMaze(test_maze0, 3, 4, expected_minCost0);
}

int main() {

    if (!testRowSort0()) {
        return 1;
    }

    if (!testMaze0()) {
        return 1;
    }

    return 0;
}