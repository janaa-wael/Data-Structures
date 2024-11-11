/*
 * SelectionSort.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 *
 *  Description:
 *      This program implements the Selection Sort algorithm to sort an array of integers in ascending order.
 *      It then prints the sorted array to the console.
 *
 *  Functions:
 *      - SelectionSort: A function that sorts an integer array using the Selection Sort algorithm.
 *      - main: Initializes an array, sorts it using SelectionSort, and prints the sorted array.
 */

#include <bits/stdc++.h>  // Include all standard libraries
using namespace std;

/*
 * Function: SelectionSort
 * ------------------------
 * Sorts an array of integers in ascending order using the Selection Sort algorithm.
 * The Selection Sort algorithm repeatedly finds the smallest element in the unsorted part of the array
 * and swaps it with the first unsorted element.
 *
 * arr: A pointer to the array to be sorted.
 * size: The number of elements in the array.
 */
void SelectionSort(int* arr, int size)
{
	// Outer loop: iterate through each element of the array
	for (int i = 0; i < size; i++)
	{
		// Assume the current element (arr[i]) is the smallest in the unsorted part
		int min_value = arr[i];
		int min_index = i;

		// Inner loop: find the minimum element in the unsorted part of the array
		for (int j = i + 1; j < size; j++)
		{
			// If a smaller element is found, update min_value and min_index
			if (min_value > arr[j])
			{
				min_value = arr[j];
				min_index = j;
			}
		}

		// Swap the found minimum element with the first element of the unsorted part
		swap(arr[i], arr[min_index]);
	}
}

/*
 * Function: main
 * ---------------
 * The entry point of the program.
 * It initializes an integer array, sorts it using the SelectionSort function, and prints the sorted array.
 */
int main()
{
	// Initialize an array of integers
	int arr[7] = { 76, 34, 8, 2, 57, 3456, 5 };

	// Call SelectionSort to sort the array in ascending order
	SelectionSort(arr, 7);

	// Print the sorted array
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";   // Output each element followed by a space

	return 0;  // Return 0 to indicate successful execution
}
