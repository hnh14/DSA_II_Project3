#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.hpp"

int main() {
    int numCities, numTours, numGens, genPercentage;

    std::cout << "Please enter the number of cities to run: " << std::endl;
    std::cin >> numCities;

    std::cout << "Please enter how many individual tours are in a given generation: " << std::endl;
    std::cin >> numTours;

    std::cout << "Please enter how many generations to run: " << std::endl;
    std::cin >> numGens;

    std::cout << "Please enter what percentage of a generation should be comprised of mutated tours (1-100): " << std::endl;
    std::cin >> genPercentage;

    Matrix matrix;
    
    time_t BruteTime;
    double BruteCost = matrix.Brute(numCities);

    time_t GeneticTime;
    double GeneticCost = matrix.Genetic(numCities, numTours, numGens, genPercentage);

    std::cout << "Number of cities to run: " << numTours << std::endl
              << "Optimal Cost from Brute Force: " << BruteCost << std::endl
              << "Time of Brute Force: " << std::endl
              << "Cost from Genetic Algorithm: " << GeneticCost << std::endl
              << "Time of Genetic Algorithm" << std::endl
              << "Percent of Optimal: " << (GeneticCost / BruteCost)*100.0 << "%" << std::endl;
    
}