#include <time.h>
#include <stdio.h>
#include <stdlib.h>  /*  for malloc */
#include "permutations.hpp"
#include <iostream>
#include <vector>
using namespace std;

unsigned int Permutations::factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}


void Permutations::swap(vector<int> s, int x, int y)
{
	int tmp = s[x];
	s[x] = s[y];
	s[y] = tmp;
}

void Permutations::perm1(vector<int>& s) 
{
    int m, k, p , q, i;
    // printS(); //Comment out to avoid seeing the permutations
    int NUMELEMENTS = s.size();
    int permsThisCall = factorial(NUMELEMENTS);
    for(i = 1; i < permsThisCall; i++)
    {
    	m = NUMELEMENTS-2;
       	while(s[m]>s[m+1])
       	{
        	m = m - 1;
       	}
       	k = NUMELEMENTS-1;
       	while(s[m] > s[k])
       	{
        	k = k - 1;
       	}
       	swap(s,m,k);
       	p = m + 1;
       	q = NUMELEMENTS-1;
       	while(p < q)
       	{
        	swap(s,p,q);
         	p++;
         	q--;
       	}
       	// printS(); //Comment out to avoid seeing the permutations
    }
} 




