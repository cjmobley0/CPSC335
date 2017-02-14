// Assignment 3: Euclidean traveling salesperson problem: improved nearest neighbor algorithm
// Christopher Mobley
// A special case of the classical traveling salesman problem (TSP) where the input is a Euclidean graph
// INPUT: a positive integer n and a list P of n distinct points representing vertices of a Euclidean graph
// OUTPUT: a list of n points from P representing a Hamiltonian cycle of relatively minimum total weight
// for the graph.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <chrono>
#include <cmath>
#include <limits>

using namespace std;

struct point2D {
	float x;
	float y;
};

// Prototyping
void print_cycle(int, point2D*, int*);
int farthest_point(int, point2D*);
int nearest(int, point2D*, int, bool*);

int main() {
	// Var dec
	point2D *P;
	int *M = 0;
	bool *Visited;
	int i, n;
	float dist = 0;
	int A = 0, B = 0;

	// display the header
	cout << endl << "CPSC 335-x - Programming Assignment #3" << endl;
	cout << "Euclidean travel salesperson problem: INNI algorithm" << endl;
	cout << "Enter the number of vertices (>2) " << endl;
	// read the number of elements
	cin >> n;

	// if less than 3 vertices then terminate the program
	if (n < 3)
		return 0;

	P = new point2D[n];

	cout << "Enter the points: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << "x = ";
		cin >> P[i].x;
		cout << "y = ";
		cin >> P[i].y;
	}

	// Allocate space for INNA set of indices of points
	M = new int[n];
	for (i = 0; i < n; i++)
		M[i] = i;

	// Allocate the space for the visited array of boolean values
	Visited = new bool[n];

	for (i = 0; i < n; i++)
		Visited[i] = false;

	// Calculate the starting vertex A
	A = farthest_point(n, P);
	i = 0;
	M[i] = A;
	Visited[A] = true;

	for (i = 1; i < n; i++)
	{
		// Calculate the nearest unvisited neighbor from node A
		B = nearest(n, P, A, Visited);
		A = B; // Nearest point found (B), now set A
		M[i] = A;
		Visited[A] = true;
	}

	// Calculate the length of the Hamiltonian Cycle
	dist = 0;
	for (i = 0; i < n - 1; i++)
		dist += abs(P[M[i]].x - P[M[i + 1]].x) + abs(P[M[i]].y - P[M[i + 1]].y);

	dist += abs(P[M[0]].x - P[M[n - 1]].x) + abs(P[M[0]].y - P[M[n - 1]].y);

	// after shuffling them
	cout << "The Hamiltonian cycle of a relative minimum length " << endl;
	print_cycle(n, P, M);
	cout << "The relative minimum length is " << dist << endl;


	delete[] P;
	delete[] M;

	system("PAUSE");
	return 0;
};

/****************************************************************
Function: farthest_point
Calculate furthest distance between any two 2D points.
Is used to set starting vertices.

n = number of points
P = 2D point array coordinates
*****************************************************************/
int farthest_point(int n, point2D *P)
{
	float max_dist = 0;
	int i = 0, j = 0;
	float dist;
	int daFurthestPoint = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j++)
		{
			dist = abs(P[i].x - P[j].x) + abs(P[i].y - P[j].y);

			// Set new max distance and update further point
			if (max_dist < dist)
			{
				max_dist = dist;
				daFurthestPoint = i;
			}
		}
	}
	return daFurthestPoint;
};


/****************************************************************
Function: nearest
Calculate nearest unvisited neighboring point

n = number of points
P = 2D point array coordinates
A = Vertices being analyzed in comparison to neighboring points
Visited = bool value to indicate if value has been visited
*****************************************************************/
int nearest(int n, point2D *P, int A, bool *Visited)
{
	float dist = 0, min_dist = 2147483648;
	int nearestPoint;

	for (int i = 0; i < n; i++)
	{
		if (Visited[i] == false)// If coordinate not visited...
		{
			dist = abs(P[A].x - P[i].x) + abs(P[A].y - P[i].y); // then measure distance
			if (min_dist > dist)
			{
				min_dist = dist;
				nearestPoint = i; // update nearest point
			}
		}
	}

	return nearestPoint;
};

/****************************************************************
Function: print_cycle
Calculate the nearest unvisited neighboring point

n = number of points
P = 2D point array coordinates
seq = 
*****************************************************************/
void print_cycle(int n, point2D *P, int *seq)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(" << P[seq[i]].x << "," << P[seq[i]].y << ") -> ";
	}
	cout << "(" << P[seq[0]].x << "," << P[seq[0]].y << ") ";
	cout << endl;
};
