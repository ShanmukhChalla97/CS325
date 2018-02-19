/* Author: Shanmukh Challa
 * Class/Date: CS 325/ Winter 2018
 * Description: This code is running a greedy algorithm to find a sequence of activity based on a larger list of activities. First,
 *      we find the start times, end times, and ids. Then, we sort using insertion sort. And finally, we run the activitySelector
 *      function to find a list of sequential activities.
 * References: //http://www.cplusplus.com/forum/general/22813/
 *             //https://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
 *
 */

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void insertionSort(vector<int> finish, vector<int> start, vector<int> id, int size) { //Insertion sort algorithm from HW1
    int i, j, temp1, temp2, temp3;

    for (i = 0; i < size; i++) {
	     temp1 = finish[i];
       temp2 = start[i];
       temp3 = id[i];
	     for (j = i; (j > 0) && (finish[j-1] > temp1); j--) {
	        finish[j] = finish[j-1];
          finish[j] = temp1;
       }
       for (j = i; (j > 0) && (start[j-1] > temp2); j--) {
	        start[j] = start[j-1];
          start[j] = temp2;
       }
       for (j = i; (j > 0) && (id[j-1] > temp3); j--) {
	        id[j] = id[j-1];
          id[j] = temp3;
       }
	     //finish[j] = temp1;
       //start[j] = temp2;
       //id[j] = temp3;

       //cout << id[i] << "     " << start[i] << "     " << finish[i] << "     " << endl;

    }
}

void activitySelector(vector<int> start, vector<int> finish, vector<int> id, int index, int i)
{
    if (index != 0) {
      cout << "Set " << i << endl;
      cout << "Number of activities selected: " << sizeof(index) << endl;
      int k = 1;
      cout << "Activities: " << id[k] << " ";

      for (int j = 1; j < index; j++)
      {
        if (start[j] >= finish[i]) //If the start time is greater then or equal to the finish time
        {
            cout << id[j] << " "; //Print out the ID in that index
            i = j; //Switch i and j
        }
      }
      cout << endl << endl;
    }
}

int main()
{
   int array[1000]; //Array to store values from the act.txt file
   int i = 0;
   int size = 0;
   int index = 0;
   int tracker = 0;
   vector<int> start;
   vector<int> finish;
   vector<int> id;

   FILE * inputFile; //input file

   inputFile = fopen("act.txt", "r+"); //Open data.txt with read rights

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

     index = array[tracker]; //The index is the first element in the file.
     tracker++; //Keep incrementing the index

     for (int j = 0; j < index; j++){ //Run this till the size the index
       for (int k = 0; k < 3; k++){ //There are three sets
         if (k == 0) //The first element of the row is the ID
            id.push_back(array[tracker]);
         if (k == 1) //The second element of the row is the start time
            start.push_back(array[tracker]);
         if (k == 2) //The third element of the row is the finish time
            finish.push_back(array[tracker]);

         tracker++; //increment the index
       }
     }
     i++;
     insertionSort(finish, start, id, index); //Call the insert sort function to sort the finish times, and match with the start time and ID
     activitySelector(start, finish, id, index, i); //Get the most optimal list of activities

   }

   return 0;
}
