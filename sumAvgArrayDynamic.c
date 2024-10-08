#include <stdio.h> //include statment for standard libraries
#include <stdlib.h>  //to use atoi

//function prototypes
int computeSum(int length, int * intArray);
float computeAvg(int length, int sum);

/** main method: Write a program that calculates the sum and average of an array of 
*                integers, and create a separate function to compute each. 
*   - dynamically allocate the memory
*   - usage of sumAvgArray.c: ./sumAvgArray.out 1 2 3	<- length 4, indexes 0-3
*/ 
int main(int argc, char *argv[]) { 
	if(argc >= 2) { //if correct number of command line args

		int length = argc - 1;

		//need to take in integers, and dynamically make an array
		int *intArray = (int *) malloc (sizeof(int) * length); //allocate space on heap
    if (intArray == NULL) {
        printf("Memory allocation failed! \n");
        return 1;
    } //if

		for (int i = 0; i < length; i++) { //fill out dynamically allocated array
			*(intArray + i) = atoi(argv[i + 1]);
		} //for

		//print array values
		printf("[");
		for (int i = 0; i < length; i++) {
			if (i == length - 1) { //at end
				printf("%d]", *(intArray + i)); //de-reference and print
			} else {
				printf("%d, ", *(intArray + i)); //de-reference and print
			} //if
		} //for
		
		//calculate w/ functs
		int sumOutCome = computeSum(length, intArray); //get sum
		printf("sum: %d \n", sumOutCome); //print sum
		float avgOutCome = computeAvg(length, sumOutCome); //get avg
		printf("avg: %.2f \n", avgOutCome); //print average w/ 2 dec places

		//free dynamically allocated memory
		free(intArray);

		return 0; //return main
	} else {
		printf("Incorrect number of cmd line inputs. \n");
		return 1; //return main on error
	} //if
} //main

//function implementation
int computeSum(int length, int * intArray) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum = sum + *(intArray + i);
	} //for	
	return sum;
} //computeSum

float computeAvg(int length, int sum) {
	return (float) sum/length; //calcuates/retuns the avg
} //computeAvg
