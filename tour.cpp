#include "tour.hpp"

//Constructs new Tour in order
Tour::Tour(int size) {
    this->size = size;
    cities = new int[size];

    for(int i = 0; i < size; i++) {
        cities[i] = i+1;
    }
}

//Copies Tour Object and permutates
Tour::Tour(Tour* toCopy) {
    this->size = toCopy->getSize();
    cities = new int[size];

    for(int i = 0; i < size; i++) {
        cities[i] = toCopy->at(i);
    }
    permutation();
    // Print();
}

//Returns City Number
int Tour::at(int index) {
    return cities[index];
}

//Returns Size
int Tour::getSize() {
    return size;
}

//Prints Tour (Used for Testing)
void Tour::Print() {
    for(int i = 0; i < size; i++) {
        std::cout << cities[i] << ", ";
    }

    std::cout << std::endl;
}

//Creates Cross Over Of Tour
void Tour::Cross() {
    int middle = size / 2;

    for(int i = 0; i < middle; i++) {
        std::swap(cities[i], cities[i+middle]);
    }
}

//Permutates Tour
void Tour::permutation() 
{
    std::next_permutation(cities, cities+(size/2));
    std::next_permutation(cities+(size/2), cities+size);
} 

