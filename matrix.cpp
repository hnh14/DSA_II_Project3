#include "matrix.hpp"
// Opens distances.txt file and fills adjacency matrix
Matrix::Matrix() {
    std::ifstream input;
    input.open("distances.txt");

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(i == j)
                matrix[i][j] = 0;
            else {
                input >> matrix[i][j];
            }
        }
    }
}

//Overloader for [] operator
double* Matrix::operator[](int index) {
    return matrix[index];
}

//Function for Brute Force Algorithm
double Matrix::Brute(int tourSize) {
    //Initializes and fills tour array
    int* tour = new int[tourSize]; 
    for(int i = 0; i < tourSize; i++) {
        tour[i] = i;
    }

    int* shortest = new int[tourSize];
    std::copy(tour, tour+tourSize, shortest);

    //Checks each permutation individually to see if it is the shortest
    std::sort(tour, tour+tourSize);
    while(std::next_permutation(tour, tour+tourSize)) {
        if(Compare(shortest, tour, tourSize)) {
            std::copy(tour, tour+tourSize, shortest);
        }
    }

    double cost = 0;
    for(int i = 0; i < tourSize-1; i++) {
        cost += matrix[shortest[i]][shortest[i+1]];
    }

    return cost;
}

//Boolean function that compares the sizes of two tours 
bool Matrix::Compare(int* shortest, int* tour, int size) {
    double shortSum = 0;
    double newSum = 0;

    for(int i = 0; i < size-1; i++) {
        shortSum += matrix[shortest[i]][shortest[i+1]];
        newSum += matrix[tour[i]][tour[i+1]];
    }

    if(newSum < shortSum) 
        return true;
    else 
        return false;

}

//Creates First Tour Object and Recursively Runs NextGeneration() for the amount of Generations remaining
double Matrix::Genetic(int numCities, int numTours, int numGens, int percent) {
    //Initializes and fills generations
    this->numTours = numTours;
    Tours.push_back(Tour(numCities));
    percentage = numTours * (percent / 100.0);

    for(int i = 1; i < numTours; i++) {
        Tours.push_back(Tour(&Tours.at(i-1)));
    }

    Sort(Tours);

    return NextGeneration(--numGens);
}

//Recursive Function That Keeps One Elite, Creates Crossovers, and Creates New Permutations
double Matrix::NextGeneration(int RemainingGenerations) {
    if(RemainingGenerations <= 0) 
        return Sum(Tours.at(0));
    else
        RemainingGenerations--;

    for(int i = 1; i < percentage; i++) {
        Tours.at(i).Cross();
    }

    for(unsigned long int i = percentage; i < Tours.size(); i++) {
        Tours.at(i) = Tours.at(i-1);
        Tours.at(i).permutation();
    }
    
    Sort(Tours);

    return NextGeneration(RemainingGenerations);
}

//Sorts a Tour Object from lowest to highest Cost
void Matrix::Sort(std::vector<Tour>& tours) {
    for (long unsigned int i = 0; i < tours.size() - 1; i++) {
        for (long unsigned int j = 0; j < tours.size() - i - 1; j++) {
            if (Sum(tours.at(j)) > Sum(tours.at(j+1))) {
                // Swap tours
                Tour temp = tours.at(j);
                tours.at(j) = tours.at(j+1);
                tours.at(j+1) = temp;
            }
        }
    }
}

//Finds the Sum of all Costs
double Matrix::Sum(Tour& tour) {
    double sum = 0;
    for(int i = 0; i < tour.getSize() - 1; i++) {
        sum += matrix[tour.at(i)-1][tour.at(i+1)-1];
    }

    return sum;
}