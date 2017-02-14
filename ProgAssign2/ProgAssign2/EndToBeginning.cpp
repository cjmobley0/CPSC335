/*******************************************************
// Assignment 2: Longest non-decreasing subsequence problem, 
// end-to-beginning algorithm
// Christopher Mobley
// CWID: 891-10-3897
// Given a sequence of elements the program finds a subsequence 
// of it in which the subsequence's elements are in sorted order, 
// lowest to highest, and in which the subsequence is as long as possible.
********************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <ratio>
#include <thread>

using namespace std;

void getInput(float* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
}

void print_sequence(float* daArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << daArray[i]<< " ";
	}
	cout << endl;
}

void print_sequence(int* daArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << daArray[i] << " ";
	}
	cout << endl;
}

int main()
{
	// Variable Declarations
	int n, i, j, max, index;
	float *A, *R;
	int* H;

	// Header
	cout << "CPSC 335-01 Programming Assignment #2" << endl;
	cout << "Longest non-decreasing subsequence problem, end-to-beginning algorithm" << endl;

	// User Input
	cout << "Enter the number of element in the sequence" << endl;
	cin >> n;

	A = new float[n];
	H = new int[n];

	cout << endl << "Enter the elements in the sequence" << endl;
	getInput(A, n);
	
	// Print input sequence
	cout << "Input Sequence: " << endl;
	print_sequence(A, n);

	// Start chronograph to time the execution of the algorithm
	auto start = chrono::high_resolution_clock::now();

	// Loop to populate the array H with 0 vales
	for (i = 0; i < n; i++)
		H[i] = 0;

	// Loop to calculate the values of array H
	for (i = n - 2; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			if (A[j] > A[i] && H[j] >= H[i]) // Scan array from i to ->
				H[i] = H[j] + 1; // Increment if there exist value greater than whats being analyzed
		}
	}

	// Calculate max number of subsequences to allocate for R
	max = H[0];
	for (i = 1; i < n; i++)
	{
		if (max < H[i])
			max = H[i];
	}
	max++;

	// Allocate space for subsequence R
	R = new float[max];

	/* Add elements to R by whose H's values are in decreasing order
	 * starting with max-1, store in index the H values sought */
	index = max - 1;

	// Store in j the index of element appended to R
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (H[i] == index) // If curr max is found...
		{
			R[j] = A[i]; // ...add corresponding A[i] value to R[j]
			j++; // Move -> 1 R space for next value to store
			index--; // Decrement max for next decreasing value
		}
	}
	

	/*****************
		OUTPUTS
	******************/
	cout << "Sequence in H" << endl;
	print_sequence(H, n);

	cout << "The longest non-decreasing subsequence has length " << endl;
	cout << max << endl;

	cout << "The longest non-decreasing subsequence is" << endl;
	print_sequence(R, max);
	
	/*
	// print the elapsed time in seconds and fractions of seconds             	
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	cout << "elapsed time: " << seconds << " seconds" << endl;
	*/


	delete [] A;
	delete[] H;
	delete[] R;
	system("PAUSE");
	return 0;
};

/**
Example #1:
K:\202> ast2a
CPSC 335-x - Programming Assignment #2
Longest non-decreasing subsequence problem, end-to-beginning algorithm
Enter the number of elements in the sequence
5
Enter the elements in the sequence
0 8 4 12 2
Input sequence
0 8 4 12 2
The longest non-decreasing subsequence has length
3
The longest non-decreasing subsequence is
0 8 12
elapsed time: 0.000106 seconds

Example #2:
K:\202> ast2a
Longest non-decreasing subsequence problem, end-to-beginning algorithm
Enter the number of elements in the sequence
16
Enter the elements in the sequence
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Input sequence
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
The longest non-decreasing subsequence has length
6
The longest non-decreasing subsequence is
0 4 6 9 13 15
elapsed time: 0.000119 seconds




*/