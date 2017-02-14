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
void print_perm(int, int*, int, point2D*, int *, float&);

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
	if (n < 3)
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

	// Start the chronograph to time the execution of the algorithm
	//auto start = chrono::high_resolution_clock::now();

	// Calculate furthest pair of vertices
	Dist = farthest(n, P);
	bestDist = n * Dist;

	// Populate the starting array for the permutation algorithm
	A = new int[n];
	for (i = 0; i < n; i++){
		A[i] = i;
	}

	// Calculate Hamiltonian Cycle of minimum weight
	print_perm(n, A, n, P, bestSet, bestDist);

	// after shuffling them
	cout << "The Hamiltonian cycle of the minimum length " << endl;
	print_cycle(n, P, bestSet);
	cout << "Minimum length is " << bestDist << endl;

	// de-allocate the dynamic memory space
	delete[] P;
	delete[] A;
	delete[] bestSet;

	system("PAUSE");
	return 0;
};

/***********************************************************
Function: print_cycle
Print a sequence of 2D points in a 2D plane (P)
given the number of elements (n)
and the actual sequence stored as an array of 2D points (seq)

n = number of points
P = array of coordinates
seq = permutation over the set of indices
************************************************************/
void print_cycle(int n, point2D *P, int *seq)
{
	int i = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "(" << P[seq[i]].x << "," << P[seq[i]].y << ") ";
		cout << "(" << P[seq[0]].x << "," << P[seq[0]].y << ") ";
		cout << endl;
	}
}

/****************************************************************
Function: farthest
Calculate furthest distance between any two 2D points

n = number of points
P = 2D point array coordinates
*****************************************************************/
float farthest(int n, point2D *P)
{
	float max_dist = 0;
	int i, j;
	float dist;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			dist = abs(P[i].x - P[j].x) + abs(P[i].y - P[j].y);

			// Set new max distance
			if (max_dist < dist)
				max_dist = dist;
		}
	}
	return max_dist;
}

/*******************************************************************
Function: print_perm
Generates the permuation of indices based on given list of points

n = number of points
A = holds permutations 1...n
sizeA = A constant of n since n undergoes n-1 through recursion
P =  point2D array
bestSet = holds best set of permutation
bestDist =
********************************************************************/
void print_perm(int n, int *A, int sizeA, point2D *P, int *bestSet, int &bestDist)
{
	int i;
	float dist = 0;

	if (n == 1)
	{
		// Print current permutation
		cout << endl;
		cout << "Permutation to compare: ";
		for (i = 0; i < sizeA; i++)
			cout << A[i] << " ";
		cout << endl;

		// Calculate permutation's distance
		for (i = 0; i < n; i++)
		{
			cout << "someont" << endl;
		}

		// Compare with current shortest Hamiltonian Cycle and set bestDist if needed


	}
	else
	{
		for (i = 0; i < n - 1; i++)
		{
			print_perm(n - 1, A, sizeA, P, bestSet, bestDist);
			if (n % 2 == 0)
			{
				swap(A[i], A[n - 1]);
			}
			else
			{
				swap(A[0], A[n - 1]);
			}
		}
		print_perm(n - 1, A, sizeA, P, bestSet, bestDist);
	}
}
