/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 *
 *  Description:
 *      This program implements the Bubble Sort algorithm to sort an array of integers in ascending order.
 *      It then prints the sorted array to the console.
 *
 *  Functions:
 *      - BubbleSort: A function that sorts an integer array using the Bubble Sort algorithm.
 *      - main: Initializes an array, sorts it using BubbleSort, and prints the sorted array.
 */

#include <bits/stdc++.h>  // Include all standard libraries
using namespace std;

/*
 * Function: BubbleSort
 * ----------------------
 * Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * 
 * arr: A pointer to the array to be sorted.
 * size: The number of elements in the array.
 */
void BubbleSort(int* arr, int size)
{
    // Outer loop: iterate through the array
	for(int i = 0 ; i < size-1 ; i++)
	{
        // Inner loop: compare adjacent elements and swap if necessary
		for(int j = 0 ; j < size-i-1 ; j++)
		{
            // If the current element is greater than the next, swap them
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];   // Temporary variable for swapping
				arr[j] = arr[j+1];   // Swap current element with next
				arr[j+1] = temp;     // Complete the swap
			}
		}
	}
}

/*
 * Function: main
 * ---------------
 * The entry point of the program.
 * It initializes an integer array, sorts it using the BubbleSort function, and prints the sorted array.
 */
int main()
{
    // Initialize an array of integers
	int arr[6] = {76,23,77,2,5,8};
    
    // Call BubbleSort to sort the array
	BubbleSort(arr, 6);

    // Print the sorted array
	for(int i = 0 ; i < 6 ; i++)
		cout << arr[i] << "  ";   // Output each element followed by a space

    return 0;  // Return 0 to indicate successful execution
}
