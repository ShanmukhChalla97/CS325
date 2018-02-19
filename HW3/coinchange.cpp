/* Author: Shanmukh Challa
 * Date: Winter 2018
 * Description: This program will take a hard-coded list of coins, and efficiently use the least number of coins to
 *      reach the amount A.
 * References used:
 *      https://www.youtube.com/watch?annotation_id=annotation_2195265949&feature=iv&src_vid=Y0ZqKpToTic&v=NJuKJ8sasGk
 *      https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 */

#include <bits/stdc++.h>
#include <iostream>
#include <time.h>

using namespace std;

int coinChange(int V[], int A, int size); //
void printCoins(int V[], int storeCoins[], int A); //Print out the numbers to the console

int main() {
  int V[] = {1, 3, 7, 12};
  int size = (sizeof(V)/sizeof(V[0]));
  int A = 29;

  coinChange(V, A, size);

  return 0;

  /*
  int array[1000000]; //Array to store values from the data.txt file
  int size = 0;
  int index = 0;
  int tracker = 0;
  int A = 29;
  int j;

  FILE * inputFile; //input file
  FILE * outputFile; //output file
  inputFile = fopen("amount.txt", "r+"); //Open data.txt with read rights
  outputFile = fopen("change.txt", "w"); //Open stooge.out with write rights

  if (inputFile == NULL) //If there is nothing in the input file, print out an error message
  {
    perror("Unable to open file!\n");
    return -1;

  } else { //Else, read in all the values from the input file and store them in the array declared above
      while (!feof(inputFile) )
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
   */
}

int coinChange(int V[], int A, int size) {
  int minCoins[A + 1]; //Initialize a new array to store the minimum number of coins
  int storeCoins[A + 1]; //Initialize a new array to store the coins used

  minCoins[0] = 0; //Set the first value to 0

  for(int i= 1; i <= A; i++){ //For the size of A, do the following
      minCoins[i] = INT_MAX; //Set each value in minCoins to infinity
      storeCoins[i] = -1; //Set each value in storeCoins to -1
  }

  for(int k= 0; k < size; k++) { //
      for(int j= 1; j <= A; j++){
          if(j >= V[k]){
              if (minCoins[j - V[k]] + 1 < minCoins[j]) {
                  minCoins[j] = 1 + minCoins[j - V[k]];
                  storeCoins[j] = k;
              }
          }
      }
  }

  printCoins(V, storeCoins, A); //Call the function to print coins
  return minCoins[A];
}

void printCoins(int V[], int storeCoins[], int A) { //Print out the coins used to the console
   while (A != 0) { //While the amount is not equal to zero
       int j = storeCoins[A];
       cout << V[j] << " "; //Print out the coin
       A = A - V[j]; //Subtract the coin from the amount,
   }
   cout << endl;
   cout << "4" << endl;
}
