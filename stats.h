//***********************************************************************************
//	Name: Zachary DeVita		Folder Name: beckmancoulter_assign
//	Company: Beckman Coulter
//	Date:	3/20/2018
//-----------------------------------------------------------------------------------
//	Program Name: stats.h
//	Program Description: header file which contains declarations for all functions used in 
// 	statistical analysis, and documentation.
//***********************************************************************************

#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED

/*	
double findMean(int data[], unsigned long int size) 
Finds the mean of a given array of numbers.
Parameters:	 data[] - the array of data being analyzed
			   size - the number of elements in the array
Precondition:	data[] array isn't NULL
Postcondition:	the mean value is output */
double findMean(int data[], unsigned long int size);

/*	
double findMedian(int data[], unsigned long int size) 
Finds the median of a sorted array of numbers.
Parameters:	 data[]	- the array of sorted data being analyzed
			   size - the number of elements in the array
Precondition:	data[] array isn't NULL and is sorted
Postcondition:	the median value is output */
double findMedian(int data[], unsigned long int size);

/*	
void findMode(int data[], unsigned int long size, int* mode, unsigned long int *mode_frequency, unsigned long int *num_modes) 
Finds the mode or modes and frequency of mode value for a sorted array of numbers.
Parameters:	 data[]	- the array of sorted data being analyzed
			   size - the number of elements in the array
			  *mode - an array passed by reference in order to store all mode values
	*mode_frequency - integer passed by reference that stores the frequency of the mode
		 *num_modes - integer passed by reference that stores the number of modes
Precondition:	data[] array is sorted
Postcondition:	the mode/s are stored in mode[], and the frequency is stored */
void findMode(int data[], unsigned long int size, int* mode, unsigned long int *mode_frequency, unsigned long int *num_modes);

/*	
double findStdDev(int data[], unsigned long int size) 
Finds the standard deviation of an array of numbers. This function can be used 
independently from the printStats() function, but is less efficient to use if all 
statistics are being printed. It requires calling the findMean() function, and is 
redundant in cases where the mean is already being calculated.
Parameters:	 data[]	- the array of data being analyzed
			   size - the number of elements in the array
Precondition:	
Postcondition:	the standard deviation value is output */
double findStdDev(int data[], unsigned long int size);

/*	
static double getStdDev(int data[], double mean, unsigned long int size) 
Finds the standard deviation of an array of numbers. This function is only called 
from the printStats() function; it is optimized for the printStats() function because it 
utilizes the mean value that gets calculated in the same function, prior to it being 
called. This required value is the reason for the static access modifier which limits the scope of 
the function by restricting access to this class.
Parameters:	 data[]	- the array of data being analyzed
			   mean - the average value of the array
			   size - the number of elements in the array
Precondition:	the mean value has already been calculated
Postcondition:	the standard deviation value is output */
static double getStdDev(int data[], double mean, unsigned long int size);

/*	
double findCoVariation(int data[], unsigned long int size)
Finds the Coefficient of Variation for an array of numbers. This function can be used 
independently from the printStats() function, but is less efficient to use if all 
statistics are being printed. It requires calling the findMean() and findStdDev() 
functions, and is redundant in cases where the mean and standard deviation is already 
being calculated.
Parameters:	 data[]	- the array of sorted data being analyzed
			   size - the number of elements in the array
Precondition:	
Postcondition:	the Coefficient of Variation is output */
double findCoVariation(int data[], unsigned long int size);

/*	
static double getCoVariation(double stdDev, double mean)
Finds the Coefficient of Variation for an array of numbers. This function is only called 
from the printStats() function; it is optimized for the printStats() function because it 
utilizes the mean & standard deviation that get calculated in the same function, prior to 
it being called. These required values are the reason for the static access modifier which 
limit the scope of the function by restricting access to this class. 
Parameters:	 stdDev	- the standard deviation for the set of data
			   mean - the mean value for the set of data
Precondition:	the mean and standard deviation values have already been calculated
Postcondition:	the Coefficient of Variation is output */
static double getCoVariation(double stdDev, double mean);

/*	
void printStats(int particles[], unsigned long int size) 
Calculates and prints entire set of statistics for the given data set.
Parameters: particles[] - the array of unsorted particle size data.
			       size - the number of elements in the array
Precondition:	
Postcondition:	prints out statistics calculated from data set */
void printStats(int particles[], unsigned long int size);


#endif