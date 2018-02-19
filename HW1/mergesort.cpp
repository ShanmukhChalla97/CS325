/* Name: Shanmukh Challa
 * Class/Date: CS325/Winter 2018
 * Description: This program takes in data from a file "data.txt", and performs a merge sort. Then, the program will input the sorted array into a file "merge.out".
 * Resources used: //http://www.cplusplus.com/doc/tutorial/files/
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

void mergeSort(int array[], int low, int up); //Divide up the original array into multiple smaller arrays
void merge(int array[], int temp[], int low1, int up1, int low2, int up2); //Sort the smaller arrays and merge them together
void copy(int array[], int temp[], int low, int up); //Copy the temp array over to the original array

int main (){
  int array[1000] = {0}; //Array to store values from the file
  int size =0;
  int data;

  FILE * inputFile; //Declaring input file
  FILE * outputFile; //Declaring output file
  inputFile = fopen("data.txt","r+"); //Open input file
  outputFile = fopen("merge.out","w"); //Open output file

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

  mergeSort(array, 0, size-2); //Call the merge sort function

  for (int i = 0; i < size-2; i++) { //input the sorted array back into the output file
	    fprintf(outputFile, "%d ", array[i]); //Print the sorted index in the output file

	}
	fprintf(outputFile, "\n"); //End the file write with a new line
  fclose(outputFile); //Close the output file

  return 0;
}

void mergeSort(int array[], int low, int up)
{
  int mid;
  int temp[up]; //Create a temp array

  if (low == up) //If they are equal, then just return
  {
    return;
  }

  mid = (low + up) / 2; //Locate a middle

  mergeSort(array, low, mid); //Recursively divide the array into smaller arrays. Sort from the lowest to the middle number.
  mergeSort(array, mid+1, up); //Recursively divide the array into smaller arrays. Sort from the middle+1 to the lowest number.

  merge(array, temp, low, mid, mid+1, up); //Merge the two separated arrays together, and move them to a temp
  copy(array, temp, low, up); //Copy the temp array back over to the original array
}

void merge(int array[], int temp[], int low1, int up1, int low2, int up2) //Merge the arrays
{
  int i = low1;
  int j = low2;
  int k = low1;

  while((i <= up1) && (j <= up2)){
    if (array[i] <= array[j]) //If one element is greater than the other, then switch
      temp[k++] = array[i++]; //Switch with the other array
    else
      temp[k++] = array[j++]; //Switch with the same array

  }

  while (i <= up1)
    temp[k++] = array[i++]; 

  while (j <= up2)
    temp[k++] = array[j++];
}

void copy(int array[], int temp[], int low, int up) { //Copy all the numbers in the temp array to the original array
  for (int i = low; i <= up; i++)
    array[i] = temp[i];
}
