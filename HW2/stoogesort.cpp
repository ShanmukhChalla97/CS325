/* Author: Shanmukh Challa
 * Class/Date: CS 325/Winter 2018
 * Description: Read in data values from a data.txt file that can have multiple lines of numbers. Using these values,
 *    perform stooge sort. Finally, print out all values into a stooge.out file.
 * References:
 *   //https://www.geeksforgeeks.org/ceil-floor-functions-cpp/
 *   //https://en.wikipedia.org/wiki/Stooge_sort
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctime>


using namespace std;

void stoogeSort(int array[], int m, int n); //Main function for performing stooge sort
void printArray(int array[], int n); //Test function to print out the array

int main()
{
  int array[1000]; //Array to store values from the data.txt file
  int size = 0;
  int index = 0;
  int tracker = 0;
  int j;

  FILE * inputFile; //input file
  FILE * outputFile; //output file
  inputFile = fopen("data.txt", "r+"); //Open data.txt with read rights
  outputFile = fopen("stooge.out", "w"); //Open stooge.out with write rights

  if (inputFile == NULL) //If there is nothing in the input file, print out an error message
  {
    perror("Unable to open file!\n");
    return -1;

  } else { //Else, read in all the values from the input file and store them in the array declared above
      while (!feof(inputFile))
      {
        fscanf(inputFile, "%d", &array[size]);
        size++;

      }
  }
  fclose(inputFile); //Close input file after reading it

  while (tracker < size) {
    index = tracker;
    tracker++;
    int newArray[array[tracker]];

    for (j = 0; j < array[index]; j++){
      newArray[j] = array[tracker];
      tracker++;
    }
    stoogeSort(newArray, 0, array[index]);

    for (int t = 0; t < array[index]; t++) //Run through the for loop with the size of each line
    {
        fprintf(outputFile, "%d ", newArray[t]); //Print out the values in newArray into the output file stooge.out
    }
    fprintf(outputFile, "\n"); //Add a new line to the output file
  }
  fclose(outputFile); //Close the output file

  return 0;
}

void stoogeSort(int array[], int m, int n)
{
  int temp, k; //Declare a temp variable for switching, and k to store a third.

  if (array[m] > array[n]) //Switch if the array at index m is greater than array at index n
  {
    temp = array[m];
    array[m] = array[n];
    array[n] = temp;

  }
  if (n-m+1 > 2) { //Check if there are atleast three values so we can divide them into two thirds.
      k = (n-m+1)/3;
      stoogeSort(array, m, n-k); //Sort the first two-thirds of the array
      stoogeSort(array, m+k, n); //Sort the second two-thirds of the array
      stoogeSort(array, m, n-k); //Again, sort the first two-thirds of the array

  }
}

void printArray(int array[], int n) //Test function. Simply print out the values in the array
{
  for (int i = 0; i < n; i++)
  {
      cout << array[i] << " ";
  }
  cout << endl;
}
