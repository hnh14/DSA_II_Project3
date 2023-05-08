#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "matrix.hpp"
#include "tour.hpp"

class Matrix {
private:
    double matrix[20][20];
    int percentage, numTours;
    std::vector<Tour> Tours;
public:
    Matrix();
    double* operator[](int);
    double Brute(int);
    double Genetic(int, int, int, int);
    double NextGeneration(int);
    bool Compare(int*, int*, int);
    void Sort(std::vector<Tour>&);
    double Sum(Tour&);
};

#endif