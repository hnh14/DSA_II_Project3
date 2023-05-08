#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H 
#include <vector>

class Permutations {
    public:
        static unsigned int factorial(unsigned int n);
        static void swap(vector<int> s, int x, int y);
        static void perm1(vector<int>& s);
};

#endif