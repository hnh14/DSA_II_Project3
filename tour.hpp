#include <iostream>
#include <algorithm>


class Tour {
    private:
        int size;
        int* cities;
    public:
        Tour(int);
        Tour(Tour*);
        int at(int);
        int getSize();
        void Print();
        void permutation();;
        void Cross();
};