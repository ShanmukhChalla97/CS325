/* Name: Shanmukh Challa
 * Class/Date: CS325/Winter 2018
 * Description: This program takes in data from a file "data.txt", and performs an insertion sort. Then, the program will input the sorted array into a file "insert.out".
 * Resources used: //http://www.cplusplus.com/doc/tutorial/files/
 *                 //https://www.geeksforgeeks.org/insertion-sort/
 *                 //https://www.tutorialcup.com/cplusplus/files-streams.htm
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>

using namespace std;

void insertionSort(int array[], int size); //Insertion sort algorithm
void printArray(int arr[], int n); //Print out the array for testing purposes

int main (){
	int array[1000] = {0}; //Array to store values from the file
	int size = 0;
	int data;

	FILE * inputFile; //Declaring input file
	FILE * outputFile; //Declaring output file
	inputFile = fopen("data.txt","r+"); //Open input file
	outputFile = fopen("insert.out", "w"); //Open output file

	if (inputFile == NULL) // If the file did not open, then return an error
	{
		perror("Unable to open file");
		return -1;
	}
	else //If the file opened, then do the following
	{
		while (!feof(inputFile)) //Until the end of file is not reached, do the following
		{
			fscanf (inputFile, "%d", &data); //Scan data from the input file and store it in data
			array[size]=data; //Store the data in a specific index in the array
			size++; //increment the index. Also, gather the size of the input file
		}
	}

	insertionSort(array, size); //Call the insertion sort function
	//printArray(array, size);

	for (int i = 0; i < size; i++) { //input the sorted array back into the output file
	    fprintf(outputFile, "%d ", array[i]); //Print the sorted index in the output file

	}
	fprintf(outputFile, "\n"); //End the file write with a new line
  fclose(outputFile); //Close the output file

	return 0;
}

void insertionSort(int array[], int size)
{
	int i,j, temp;
	for (i = 1; i < size; i++) {//Start the sorting algorithm
		temp = array[i]; //The first number is the key
		j = i-1; //Go through each preceding number to see if the positions need to be switched

		while (j >= 0 && array[j] > temp){ //If the conditions are met, switch the positions
			array[j+1] = array[j]; //Switch positions
			j = j-1;
		}
	  array[j+1] = temp; //Set the next number as the key
	}

}

void printArray(int array[], int size) //Print function for testing purposes
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

}
