//***********************************************************************************
//	Name: Zachary DeVita		Folder Name: beckmancoulter_assign
//	Company: Beckman Coulter
//	Date:	3/20/2018
//-----------------------------------------------------------------------------------
//	Program Name: statistical_analysis.c
//	Compile Instruction: gcc -Wall -g -std=c99 -o run simple_version.c
//
//	Program Description: program conducts statistical analysis of data. 
// 	Data currently in datastore is analyzed at startup. User is given options 
//	to add additional data via input file or by hand. Any change in data is
//	updated in the datastore, and the statistical output is then recalculated
//	with the changes. 
//***********************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MIN_PARTICLE_SIZE 10		//	No units on test data so range isn't verified 
#define MAX_PARTICLE_SIZE 3500000

#define INITIAL_BUFFER_SIZE 1024
#define BUFFER_SIZE_MULTIPLIER 2
#define MAX_USER_INPUT_SIZE 10
#define MAX_SIZE_PARTICLE 8
#define MAX_SIZE_FILENAME 20
#define DATA_STORE "datastore.txt"
#define DATA_BACKUP "temp.txt"

#include "stats.c"
#include "fileops.c"

int comparator(const void *lh_value, const void *rh_value) {
   return (*(int*)lh_value - *(int*)rh_value );
}

//	TODO: add external mergesort
//	TODO: change numbers to unsigned long long
//	TODO: convert array storing particles to linked list


//****************************************************************************
//	MAIN
//****************************************************************************
int main(int argc, char const* argv[]) {
	char input[2];
	int size, error;
	int bufferSize = INITIAL_BUFFER_SIZE;
	int particles[bufferSize];
	int isEmpty = 0;
	char inputFileName[MAX_SIZE_FILENAME] = DATA_STORE;
	
	while(1) {
		isEmpty = 0;
		printf("\n\ninputFileName: %s", inputFileName);
		size = getData(inputFileName, particles, &bufferSize, "r");
		if(size == 0) {
			printf("\n\nThe selected file has no data...");
			isEmpty = 1;
			FILE *fptr = fopen(inputFileName, "w");
			fclose(fptr);
		}
		else {
			qsort((void*)particles, size, sizeof(particles[0]), comparator);
			printStats(particles, size);
		}
		
		printf("\n\nSelect from the following options...\n");
		printf("Enter 1 to add particles from a txt file.\n");
		printf("Enter 2 to add particles by hand, delimited by a comma.\n");
		printf("Enter 3 to display particle sizes.\n");
		printf("Enter 4 to enter an alternative file to analyze.\n");
		printf("Enter 5 to undo your most recent changes.\n");
		printf("Enter 'q' to quit\n\n");
		printf("Input: _____\b\b\b");

		scanf("%s", input);
		if(toupper(input[0]) == 'Q')
			return 0;
		
		switch (input[0]) {
			case '1': {
				if(isEmpty) {
					printf("WARNING: selected txt file is empty");
					printf("\nPress Any Key to Continue\n");  
					while(getchar()!='\n');
				}
				else if(cloneFile(inputFileName, DATA_BACKUP)) {
					printf("ERROR: cloneFile() file cannot be found");
					printf("\nPress Any Key to Continue\n");  
					while(getchar()!='\n')
					continue;
				}
				char filename[bufferSize];
				printf("Enter the file name...\n");
				scanf("%s", filename);
				error = concatDataFile(filename, inputFileName, &bufferSize);
				if(error) {
					printf("ERROR: concatDataFile() file name cannot be found");
					printf("\nPress Any Key to Continue\n");  
					getchar();
					continue;
				}
				break;
			}
			case '2': {
				if(isEmpty) {
					printf("WARNING: selected txt file is empty");
					printf("\nPress Any Key to Continue\n");  
					while(getchar()!='\n');
				}
				else if(cloneFile(inputFileName, DATA_BACKUP)) {
					printf("ERROR: cloneFile() file name cannot be found");
					printf("\nPress Any Key to Continue\n");  
					getchar();
					continue;
				}
				error = addDataByHand(inputFileName, &bufferSize);
				if(error) {
					printf("ERROR: addDataByHand() file name cannot be found");
					printf("\nPress Any Key to Continue\n");  
					getchar();
					continue;
				}
				break;
			}
			case '3': {
				printf("\n\n****************************************\n*\t\tPARTICLES\t\t*\n****************************************\n");
				printf("%d", particles[0]);
				for(unsigned long int i = 1; i < size; ++i) {
					printf(", %d", particles[i]);
					if(i%10 == 0)
						printf("\n"); 
				}
				break;
			}
			case '4': {
				printf("\nEnter the file name...\n");
				scanf("%s", inputFileName);
				break;
			}
			case '5': {
				if(cloneFile(DATA_BACKUP, inputFileName)) {
					printf("ERROR: file name cannot be found");
					printf("\nPress Any Key to Continue\n");  
					getchar();
					continue;
				}
				break;
			}
			default: {
			    printf("\nInvalid input, try again.");
				printf("\nPress Any Key to Continue\n");  
				getchar();
				break;
			}
				
		}
	}
}



