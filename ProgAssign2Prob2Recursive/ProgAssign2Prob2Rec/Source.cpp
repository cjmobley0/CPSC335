// Assignment 3: Euclidean traveling salesperson problem: exhaustive optimization algorithm
// Christopher Mobley (CWID: 891-10-3897)
// A special case of the classical traveling salesman problem (TSP) where the input is a Euclidean graph
// INPUT: a positive integer n and a list P of n distinct points representing vertices of a Euclidean graph
// OUTPUT: a list of n points from P representing a Hamiltonian cycle of minimum total weight for the graph.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <chrono>
using namespace std;

struct point2D {
	float x; // x coordinate
	float y; // y coordinate
};

void print_cycle(int, point2D*, int*);

float farthest(int, point2D*);

void print_perm(int, int*, point2D*, int *, float&);

int main()
{
	// Variable Declarations
	point2D *P; 
	int *bestSet, *A;
	int i, n;
	float bestDist, Dist;

	// Display Header
	// display the header
	cout << endl << "CPSC 335-x - Programming Assignment #3" << endl;
	cout << "Euclidean traveling salesperson problem: exhaustive optimization algorithm" << endl;
	cout << "Enter the number of vertices (>2) " << endl;

	// read the number of elements
	cin >> n;

	// if less than 3 vertices then terminate the program
	if (n <3)
		return 0;

	// allocate space for the sequence of 2D points
	P = new point2D[n];

	// Read input sequence
	cout << "Enter the distinct points" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "x = ";
		cin >> P[i].x;
		cout << " y = ";
		cin >> P[i].y;
	}

	// Allocate space for the best set based on the indices of points
	bestSet = new int[n];

	// Create bestSet array of indices
	for (i = 0; i < n; i++)
		bestSet[i] = i;

	system("PAUSE");
	return 0;
}