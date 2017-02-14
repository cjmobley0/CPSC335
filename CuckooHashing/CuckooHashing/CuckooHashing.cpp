// Assignment 4: Cuckoo Hashing algorithm
// Christopher Mobley (CWID:891-10-3897)
// An open addressing method called Cuckoo Hashing
// INPUT: an input file containing strings of characters, one string per line
// OUTPUT: a detailed list of where the strings are inserted.    

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int TABLE_SIZE = 17;
char t[TABLE_SIZE][2][255];

size_t f(char*, size_t);

bool place_in_hash_table(char*);

int main()
{
	char s[255] = "";
	char null_st[] = "";
	size_t i, len;
	bool placed;

	// clear the tables
	for (i = 0; i < TABLE_SIZE; i++)
	{
		strcpy(t[i][0], null_st);
		strcpy(t[i][1], null_st);
	}

	char filename[255] = "";

	// Header
	cout << endl << "CPSC 335-01 Programming Assignment #4: ";
	cout << "Cuckoo Hashing Algorithm" << endl;

	// Read string from file
	cout << "Input the file name: " << endl;
	cin >> filename;

	// Open the file for reading
	FILE *file = fopen(filename, "r");
	if (file != NULL)
	{
		// Print list to insert

		// Read line by line from the file
		while (fgets(s, 255, file) != NULL)
		{
			len = strlen(s); // declare len var
			s[len - 1] = '\0'; // Add null char at end of line instead of return

			// Insert string in cuckoo table
			placed = place_in_hash_table(s);

			// Check if placement is successful
			if (!placed)
			{
				cout << "Placement has failed" << endl;
				return -1;
			}
		}
		fclose(file);
	}
	else
	{
		perror(filename);
	}

	system("PAUSE");
	return 0;
};

bool place_in_hash_table(char *s)
{
	bool placed;
	size_t pos;
	int index;
	char temp_s[255], temp[255];

	strcpy(temp_s, s);

	int counter = 0;

	index = 0;

	placed = false;

	pos = f(temp_s, index); // Categorize into hash function

	while ((!placed) && (counter < 2 * TABLE_SIZE))
	{
		if (strcmp(t[pos][index], "") == 0) // if spot is empty
		{
			// <pos> in <index> hash table is avail so store <temp_s> there
			cout << "String <" << temp_s << "> will be placed at";
			cout << " t[" << pos << "][" << index << "]" << endl;
			strcpy(t[pos][index], temp_s);
			placed = true;

			return placed;
		}
		else // Spot isnt empty, but place into spot anyways and replace old string into new spot
		{
			// <pos> in <index> hash  table not avail
			// so obtain string stored in var <temp> and store string <temp_s> there
			// now replace string <temp> in other table
			cout << "String <" << temp_s << "> will be placed at"
				<< "t[" << pos << "][" << index << "]" << " replacing <"
				<< t[pos][index] << ">" << endl;

			// TODO TODO TODO TODO
			// Store current string in t[pos][index] --into--> temp
			// then store temp_s --into--> t[pos][index]
			strcpy(temp, t[pos][index]);
			strcpy(t[pos][index], temp_s);
			strcpy(temp_s, temp);

			// Now find a spot for temp in table 2
			index = 1;
			pos = f(temp_s, index);
			
			// Only store if empty
			if (strcmp(t[pos][index], "") == 0)
			{
				cout << "String <" << temp_s << "> will be placed at "
					<< "t[" << pos << "][" << index << "]" << endl;
				strcpy(t[pos][index], temp_s);

				placed = true;

				return placed;
			}
			else // Otherwise, go back to table 1 and loop again
			{
				index = 0;
			}

			counter++;
		}
	}
	return placed;
};

/*******************************************************
	Function: f
	Compute the hash function

	s = the string (key) to which we apply the hash function
	index = indicates which hash funciton will be used
	if...
	index == 0 means first hash function
	index == 1 means second hash function

*******************************************************/
size_t f(char *s, size_t index)
{
	size_t po;
	int i, val, temp, len, temp_2;
	po = 1;

	len = strlen(s);

	if (index == 0)
	{
		val = s[0];
		val = val % TABLE_SIZE;

		if (val < 0)
			val += TABLE_SIZE;

		if (len == 1)
			return val;

		for (i = 1; i < len; i++)
		{
			temp = s[i];
			po *= 31;

			po = po % TABLE_SIZE;

			if (po < 0)
				po += TABLE_SIZE;

			val += temp * po; 
			val = val % TABLE_SIZE;

			if (val < 0)
				val += TABLE_SIZE;
		}
		return val;
	}
	else if (index == 1)
	{
		val = s[0];
		val = val % TABLE_SIZE;

		if (val < 0)
			val += TABLE_SIZE;

		if (len == 1)
			return val;

		/************************************************************
		Having troubling translating 2nd hashing funtion into code
		but is able to hash in6.txt into two tables.
		*************************************************************/
		for (i = 1; i < len; i++)
		{
			temp_2 = len - i - 1;
			temp = s[temp_2];
			po *= 31;
			po = po % TABLE_SIZE;

			if (po < 0)
				po += TABLE_SIZE;


			val += temp * po;
			val = val % TABLE_SIZE;

			if (val < 0)
				val += TABLE_SIZE;
			
		}
		return val;
	}
};