#include "fileops.h"

//****************************************************************************
//	File I/O Definitions
//****************************************************************************

//****	VERIFY FILE  ****//
static int verifyFile(FILE* fptr, char *filename) {
	if (fptr == NULL)
    {
        printf("ERROR: openFile(%s) returns NULL.\n", filename);
        return -1;
    }
	return 0;
}
//****	OPEN FILE  ****//
static FILE* openFile(char* filename, char* mode) {
    FILE* fptr = fopen(filename, mode);
    if(verifyFile(fptr, filename) == -1) //	error
		return NULL;	
	
    return fptr;
}
//****	GET DATA  ****//
unsigned long int getData(char *filename, int data[], int *bufferSize, char *mode) {
	FILE* input = openFile(filename, mode);	//	Open file for reading
	if(input == NULL) {
		fclose(input);
		return 0;
	}
	
	unsigned long int size = 0;
	while(fscanf(input, "%d,", &data[size]) != EOF) {
		++size;
		if(size == *bufferSize) {	// increase array size
			*bufferSize *= BUFFER_SIZE_MULTIPLIER;
			getData(filename, data, bufferSize, "r");
			break;
		}
    }
	fclose(input);
	
	return size;
}
//****	CLONE FILE  ****//
int cloneFile(char *input, char *output) {
	char c;
	
	FILE* storage = openFile(input, "r");	//	Open file for reading
	FILE* temp = openFile(output, "w");	//	Open file for writing
	if(storage == NULL) {
		fclose(storage);
		fclose(temp);
		return 1;
	}
	
	while((c = fgetc(storage)) != EOF)
		fputc(c, temp);
	
	fclose(storage);
	fclose(temp);
	
	return 0;	//	SUCCESS
}
//****	CONCATENATE FILE  ****//
int concatDataFile(char *input, char *output, int *bufferSize) {
	int value;

	FILE* storage = openFile(output, "a");	//	Open file for appending
	FILE* append = openFile(input, "r");	//	Open file for reading
	if(storage == NULL || append == NULL) {
		fclose(storage);
		fclose(append);
		return 1;
	}
	
	while(fscanf(append, "%d,", &value) != EOF) {
		fprintf(storage, ",%d", value);
    }
	fclose(storage);
	fclose(append);
	
	return 0;	//	SUCCESS
}
//****	APPEND FILE W/USER INPUT  ****//
int addDataByHand(char *filename, int *bufferSize) {
	int input, temp;

	FILE* storage = openFile(filename, "a");	//	Open file for writing
	if(storage ==  NULL) {
		fclose(storage);
		return 1;
	}
	
	printf("\nEnter particle sizes, one at a time, then press Enter. Enter a \"0\" when you are done...\n\n");
	while(1) {
		printf("Particle Size: ");  
		int status = scanf("%d", &input);
		while(status != 1) {
			while((temp=getchar()) != EOF && temp != '\n');
			printf("\nInput must be an integer! Try again...\n");
			printf("\nParticle Size: ");  
			status = scanf("%d", &input);
		}
		if(input == 0) {
			fclose(storage);
			return 0;	//	SUCCESS
		}
		fprintf(storage, ",%Lu", input);
    }
}