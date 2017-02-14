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
	int rightLimiter; // Var that tracks rightmost swap location
	char *disks;

	// Display Header
	cout << endl << "CPSC 335-1 Programming Assignment # 1 " << endl;
	cout << "The alternative disks problem: lawnmower algorithm" << endl;
	cout << "Enter the number of single color disks (light or dark)" << endl;

	// Read number of disks
	cin >> n;

	// Allocate space for disks
	disks = new char[2 * n];

	// Create list such that 0011001100...
	disk_n = 2 * n;
	for (i = 0; i < n; i++){
		if (i % 2 == 0){
			disks[2 * i] = 48; // 48 = 0 = dark
			disks[2 * i + 1] = 48;
		}
		else{
			disks[2 * i] = 49; // 49 = 1 = light
			disks[2 * i + 1] = 49;
		}
	}

	// Print initial config of the list of disks
	cout << "Initial configuration" << endl;
	print_disks((n * 2), disks);


	// Loop to push dark(0) before light(1)
	rightLimiter = disk_n;
	for (i = 0; i < (n/2 + 1); i++){
		// Left to right
		for (k = 0; k < disk_n; k++){
			// Swap if ...[1|0]...
			if (disks[k] == 49 && disks[k + 1] == 48){
				swap(disks[k], disks[k + 1]);
				rightLimiter = k; // Keep track of rightmost swap
				m++;
			}
		}// End of scan of list

		//print_disks((n * 2), disks);

		disk_n = rightLimiter;
		//cout << " L-R scan done" << endl;

		// Right to left
		for (k = rightLimiter; k > 0; k--)
		{	// Swap if ...[1|0]...
			if (disks[k - 1] == 49 && disks[k] == 48){
				swap(disks[k - 1], disks[k]);
				m++;
			}
		}
		//print_disks((n * 2), disks);

	}

	// After sorting them
	cout << "After moving dark ones to the left" << endl;
	print_disks((n * 2), disks);
	cout << "Number of swaps is " << m << endl;


	system("PAUSE");
	return 0;

};

/********************* OUTPUT ************************


CPSC 335-1 Programming Assignment # 1
The alternative disks problem: lawnmower algorithm
Enter the number of single color disks (light or dark)
4
Initial configuration
List of disks
0 0 1 1 0 0 1 1
After moving dark ones to the left
List of disks
0 0 0 0 1 1 1 1
Number of swaps is 4
Press any key to continue . . .

_______________________________________________________


CPSC 335-1 Programming Assignment # 1
The alternative disks problem: lawnmower algorithm
Enter the number of single color disks (light or dark)
6
Initial configuration
List of disks
0 0 1 1 0 0 1 1 0 0 1 1
After moving dark ones to the left
List of disks
0 0 0 0 0 0 1 1 1 1 1 1
Number of swaps is 12
Press any key to continue . . .


***************************************************/