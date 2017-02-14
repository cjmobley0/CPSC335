// Assignment 2: Longest non-decreasing subsequence problem, power set algorithm                                                                   
// Christopher Mobley (CWID: 891-10-3897)
// Given a sequence of elements the program finds a subsequence of it in which the subsequence's
// elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible.      


// The program reads the number of elements in the sequence, then the elements and outputs the sorted
// sequence and the running time.          
// INPUT: a positive integer n and a list of n elements                     	
// OUTPUT: a longest non-decreasing subsequence of the initial sequence         	
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

// Prototyping
void print_sequence(float*, int);
void print_sequence(int *, int);
void printPowerset(float*, int, int*, int&);
void checkSet(float*, int, int[], int*, int&);
int get_bestSet();


int main()
{
	int n, bestSize, i;
	float *A, *R;
	int *bestSet;
	

	// Header                                                       
	cout << endl << "CPSC 335-x - Programming Assignment #2" << endl;
	cout << "Longest non-decreasing subsequence problem, powerset algorithm" << endl;
	cout << "Enter the number of elements in the sequence" << endl;

	// Read the number of elements                    	
	cin >> n;

	// Allocate space for input sequence and array R
	A = new float[n];
	R = new float[n];

	// Read input sequence
	cout << "Enter the elements in the sequence" << endl;
	for (i = 0; i < n; i++)
		cin >> A[i];

	//Print Sequence
	cout << "Input sequence entered " << endl;
	print_sequence(A, n);

	// Start chronograph

	// Allocate space for best set
	bestSet = new int[n + 1]();
	bestSize = 0;

	//Calculate the best sequence
	printPowerset(A, n, bestSet, bestSize);
	print_sequence(bestSet, bestSize);
	
	// At this point, we have found that longest set of indices of A that are non-decreasing
	// Retrieve the indices for generating the subsequence
	for (i = 0; i < bestSize; i++)
	{
		R[i] = A[bestSet[i+1]-1];
	}
	
	cout << "The longest non­decreasing subsequence has length " << endl;
	cout << bestSize << endl;
	cout << "The longest non­decreasing subsequence is" << endl;
	print_sequence(R, bestSize);
	

	system("PAUSE");
	return 0;
};

void print_sequence(int* daArray, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << daArray[i] << " ";
	}
	cout << endl;
}

void print_sequence(float* daArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << daArray[i] << " ";
	}
	cout << endl;
}


void printPowerset(float *daArray, int n, int *bestSet, int &bestSize)
{
	int *stack, k;
	stack = new int[n+1]();
	stack[0] = 0;
	k = 0;

	// Generate subsequences to reference to
	while (1)
	{
		if (stack[k] < n)
		{
			stack[k + 1] = stack[k] + 1;
			k++;
		}
		else
		{

			stack[k - 1]++;
			k--;
		}

		if (k == 0)
			break;
		cout << "________________________________________________________________" << endl;
		cout << "Current indices in powerset being analyzed" << endl;
		print_sequence(stack, k);
		checkSet(daArray, k, stack , bestSet, bestSize);
	}

	delete[] stack;
	return;
}

void checkSet(float *daArray, int k, int *stack, int*bestSet, int &bestSize)
{
	int i;

	// Check that stack generates a subsequence of non-deacreasing order
	if (k < 2)// set only contained 1 index
	{
		cout << "Nothing to compare..." << endl << endl;
		if (k > bestSize)// Found better set
		{// Store newfound better stack into bestSet
			bestSet = stack;
			// Update bestsize to k
			bestSize = k;
			return;
		}
	}
	else
	{
		cout << "Comparing..." << endl;
		for (i = 0; i < k - 1; i++)
		{	// Exit if next value is not greater
			cout << "Is " << daArray[stack[i + 1] - 1] << " < " << daArray[stack[i + 2] - 1] << " ?" << endl;
			if (daArray[stack[i + 1] - 1] > daArray[stack[i + 2] - 1])
			{
				cout << "Nope..." << endl << endl;
				return;
			}
		}
	}
	// At this point, the indices in response to A in non-decreasing
	// Now compare with current best set
	if (k > bestSize)
	{
		cout << "New best set: " << endl;
		bestSet = stack;
		bestSize = k;
		print_sequence(bestSet, bestSize);

		return;

	} // Nothing to update: set is non-decreasing but k <= bestSize
	else
		return;
}
