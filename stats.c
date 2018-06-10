#include "stats.h"

//****************************************************************************
//	Statistics Function Definitions
//****************************************************************************

//****	MEAN  ****//
double findMean(int data[], unsigned long int size) {
	unsigned long int i;
	long double sum = 0; 
	for(i = 0; i < size; ++i) {
		sum += data[i];
	}

	return sum/size;
}
//****	MEDIAN  ****//
double findMedian(int data[], unsigned long int size) {
	double median;
	if(size%2 == 0)
		median = ((data[size/2] + data[size/2 - 1])/2.0);
	else
		median = data[size/2];

	return median;
}
//****	MODE  ****//
void findMode(int data[], unsigned long int size, int* mode, unsigned long int *mode_frequency, unsigned long int *num_modes) {
	unsigned long int count = 1;
	unsigned long int current = 1;
	int num = data[0];
	
	mode[0] = num;
	unsigned long int i, j = 1;

	for(i = 1; i < size; ++i) {
		if(data[i] == num) {
			++count;
		}
		else {
			if(count == current) {
				mode[++j-1] = num;
			}
			if(count > current) {
				current = count;
				mode[0] = num;
				j = 1;
			}
			count = 1;
			num = data[i];
		}	
	}
	*num_modes = j;
	*mode_frequency = current; //	stores frequency of mode
}
//****	STANDARD DEVIATION  ****//
double findStdDev(int data[], unsigned long int size) {
	long double sum = 0;
	unsigned long int i;
	
	double mean = findMean(data, size);
	for(i = 0; i < size; ++i) {
		sum += (data[i] - mean)*(data[i] - mean);
	}
	if(sum == 0)
		return 0;

	return sqrtl(sum / (size-1));
}
//	Private  
static double getStdDev(int data[], double mean, unsigned long int size) {
	long double sum = 0;
	unsigned long int i;

	for(i = 0; i < size; ++i) {
		sum += (data[i] - mean)*(data[i] - mean);
	}
	if(sum == 0)
		return 0;
	
	return sqrtl(sum / (size-1));
}
//****	COEFFICIENT OF VARIATION  ****//
double findCoVariation(int data[], unsigned long int size) {
	double sd = findStdDev(data, size);
	if(sd == 0)
		return 0; 
	
	double result = sd / findMean(data, size);
	return result * 100;
}
//	Private
static double getCoVariation(double stdDev, double mean) {
	if(stdDev == 0)
		return 0; 
	
	double result = stdDev / mean;
	return result * 100;
}
//****	PRINT ALL STATS  ****//
void printStats(int particles[], unsigned long int size)
{
    int mode[size]; 
	unsigned long int mode_frequency = 0;
	unsigned long int num_modes = 0;
	unsigned long int i;
 
	double average = findMean(particles, size);
	
	printf("\n\n*****************************************\n*\t\tSTATS\t\t\t*\n*****************************************\n", average);
	printf("Mean: %f", average);
	double median = findMedian(particles, size);
	
	//	remove trailing zeros from output
	char s[20];
	sprintf(s,"%.*g", 3, ((int)(pow(10, 3)*(fabs(median) - abs((int)median)) +0.5))/pow(10,3));
    printf("\nMedian: %d%s", (int)median, s+1);
	
	findMode(particles, size, mode, &mode_frequency, &num_modes);
	
	for(i = 0; i < num_modes; ++i) 
		printf("\nMode: %d", mode[i]);
	
	printf("\t Mode Frequency: %d", mode_frequency);
	
	double stdDev = getStdDev(particles, average, size);
	printf("\nStandard Deviation: %f", stdDev);
	printf("\nCoefficient of Variance: %f", getCoVariation(stdDev, average));
	printf("\n*****************************************");
}