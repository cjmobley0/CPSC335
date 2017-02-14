// Assignment 1: Alternating disks problem, Lawnmower Algorithm                                                                                                                                                               
// Christopher Mobley (CWID: 891-10-3897)                                                                                                                                                                                        
// Given 2n alternating disks (light, dark)  the program reads the number of single color disks                                                                                                                                    
// (light or dark), arranges the disks in the correct order and outputs the number of swaps                                                                                                                               
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark                                                                                                                                                                        
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,                                                                                                                               
// and an integer m representing the number of moves to move the dark ones after the light ones  

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void print_disks(int n, char *disks){
	cout << "List of disks" << endl;

	for (int i = 0; i < n; i++){
		cout << disks[i] << " ";
	}
	cout << endl;
};

int main(){
	int n, m = 0, k, i, disk_n;
	int rightLimiter; // Var that tracks rightmost array location
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
			disks[2 * i] = 49; // 49 = 1 = dark
			disks[2 * i + 1] = 49;
		}
		else{
			disks[2 * i] = 48; // 48 = 0 = light
			disks[2 * i + 1] = 48;
		}
	}

	// Print initial config of the list of disks
	cout << "Initial configuration" << endl;
	print_disks(disk_n, disks);

	// Loop to push light one before dark ones
	for (i = 0; i < (n/2 + 1); i++){
		for (k = 0; k < disk_n; k++){
			// Swap if ...[0|1]...
			if (disks[k] == 48 && disks[k + 1] == 49){
				swap(disks[k], disks[k + 1]);
				m++;
			}
		}
		print_disks(disk_n, disks);
	
		cout << " L-R Iterations done" << endl;
		
		for (k = (disk_n - 2); k > 0; k--)
		{
			// Swap if ...[0|1]...
			if (disks[k - 1] == 48 && disks[k] == 49){
				swap(disks[k - 1], disks[k]);
				m++;
			}
			print_disks(disk_n, disks);
		}
		
		print_disks(disk_n, disks);
		
	}

	// After sorting them
	cout << "After moving dark ones to the left" << endl;
	print_disks((n*2), disks);
	cout << "Number of swaps is " << m << endl;


	system("PAUSE");
	return 0;

};
