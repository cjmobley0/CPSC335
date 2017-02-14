// Assignment 1: Alternating disks problem, left-to-right algorithm                                                                                                                                                               
// Christopher Mobley (CWID: 891-10-3897)                                                                                                                                                                                       
// Given 2n alternating disks (light, dark) the program reads the number of single color disks                                                                                                                                    
// (light or dark), arranges the disks in the correct order and outputs the number of swaps                                                                                                                               
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark                                                                                                                                                                        
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,                                                                                                                               
// and an integer m representing the number of moves to move the dark ones after the light ones 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


void print_disks(int n, char *disks){
	cout << "List of disks" << endl;
	
	for (int i = 0; i < n; i++){
		cout << disks[i] << " ";
	}
	cout << endl;
};

int main(){

	clock_t begin = clock();

	int n, m = 0, k, i, disk_n;
	char *disks;

	// Display Header
	cout << endl << "CPSC 335-1 Programming Assignment # 1 " << endl;
	cout << "The alternative disks problem: left-to-right algorithm" << endl;
	cout << "Enter the number of single color disks (light or dark)" << endl;

	// Read number of disks
	cin >> n;

	// Allocate space for disks
	disks = new char[n];

	// Set of initial config for disks to alternate
	/* This alg creates a list of 10101010... instead
	for (i = 0; i < n; i++){
		disks[2 * i] = 48; // 48 is 1 in ASCII
		disks[2 * i + 1] = 49; // 49 is 0 in ASCII
	}
	*/

	// Create list such that 110011001100...
	disk_n = 2 * n;
	for (i = 0; i < n; i++){
		if (i % 2 == 0){
			disks[2*i] = 49; // 49 = 1 = dark
			disks[2*i + 1] = 49;
		}
		else{
			disks[2*i] = 48; // 48 = 0 = light
			disks[2*i + 1] = 48;
		}
	}

	// Print initial config of the list of disks
	cout << "Initial configuration" << endl;
	print_disks(disk_n, disks);

	// Loop to push light one before dark ones
	for (i = 0; i < n; i++){
		for (k = 0; k < disk_n; k++){
			// Swap if ...[0|1]...
			if (disks[k] == 48 && disks[k + 1] == 49){
				swap(disks[k], disks[k + 1]);
				m++;
			}
		}
		print_disks(disk_n, disks);
	}
	
	// After sorting them
	cout << "After moving dark ones to the left" << endl;
	print_disks(disk_n, disks);
	cout << "Number of swaps is " << m << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Elapsed Time: " << elapsed_secs << endl;


	system("PAUSE");
	return 0;

};

/*
Example #1:
K:\202> ast1a
CPSC 335-x - Programming Assignment #1
The alternating disks problem: left-to-right algorithm
Enter an even number of single color disks (light or dark)
4
Initial configuration
List of disks
d d l l d d l l
After moving darker ones to the left
List of disks
d d d d l l l l
Number of swaps is 4.
Example #2:
K:\202> ast1a
CPSC 335-x - Programming Assignment #1
The alternating disks problem: left-to-right algorithm
Enter an even number of single color disks (light or dark)
6
Initial configuration
List of disks
d d l l d d l l d d l l
After moving darker ones to the left
List of disks
d d d d d d l l l l l l
Number of swaps is 12


*/