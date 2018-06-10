//***********************************************************************************
//	Name: Zachary DeVita		Folder Name: beckmancoulter_assign
//	Company: Beckman Coulter
//	Date:	3/20/2018
//-----------------------------------------------------------------------------------
//	Program Name: fileops.h
//	Program Description: header file which contains declarations for all functions used  
// 	for manipulating files, input/output.
//***********************************************************************************

#ifndef FILEOPS_H_INCLUDED
#define FILEOPS_H_INCLUDED

/*	
static void verifyFile(FILE* fptr, char *filename) 
Checks if file is NULL and returns error if so.
Parameters:	*fptr - pointer to file
		*filename - name of the txt file
Precondition:	
Postcondition:	Returns 0 if verified, 1 if doesn't exist  */
static int verifyFile(FILE* fptr, char *filename);
/*	
static FILE* openFile(char* filename, char* mode) 
Opens specified txt file in user defined mode.
Parameters:	*filename - string containing name of txt file
			    *mode - identifies whether read, write or append is desired
Precondition:	if mode is set to read or append, then file must exist
Postcondition:	File is opened with specified access specified by mode. If mode is 
				set to write, file is created if it doesn't exist.  */
static FILE* openFile(char* filename, char* mode); 

/*	
unsigned long int getData(int data[], int *bufferSize, char *mode) 
Retrieves data from datastore.txt and stores it in data[] array.
Parameters:	*filename - the name of the txt file containing the data being analyzed   
			   data[] - the integer array being populated from txt file
		  *bufferSize - the initial, default size of the data[] array
		        *mode - identifies whether read, write or append is desired
Precondition:	The txt file contains comma separated integers
Postcondition:	data is retrieved from txt file and stored in array */
unsigned long int getData(char *filename, int data[], int *bufferSize, char *mode);

/*	
int cloneFile(char *input, char *output) 
Clones a txt file and saves it with name stored in output string.
Parameters:	   *input - file name of original txt file
			  *output - file name for cloned copy of txt file
Precondition:	input file exists and it contains comma separated integers
Postcondition:	original file is cloned and saved as output string */
int cloneFile(char *input, char *output);

/*	
int concatDataFile(char *filename, int *bufferSize) 
Appends the contents of one comma separated txt file to another.
Parameters:	*filename - the name of the txt file containing the data needing appended
		  *bufferSize - the current size of the array containing particle data
Precondition:	file specified by filename must exist and contain comma separated integers
Postcondition:	input file is appended to file containing particle data */
int concatDataFile(char *input, char *output, int *bufferSize);

/*	
int addDataByHand(int *bufferSize) 
Appends hand-typed particle sizes to file containing particle sizes, one at a time.
Parameters: *bufferSize - the size of the array containing the particle data
Precondition:	
Postcondition:	user input is appended to txt file containing particle data */
int addDataByHand(char *filename, int *bufferSize);


#endif