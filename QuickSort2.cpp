/*
 * main.cpp
 *
 * Description:
 *     This file implements the QuickSort algorithm, a recursive divide-and-conquer
 *     sorting technique that uses a pivot to partition the array into two subarrays.
 *     The algorithm sorts an array of integers in ascending order by repeatedly dividing
 *     it around the pivot element. The partitioning function ensures that elements
 *     less than the pivot appear before it, while elements greater than the pivot
 *     appear after it.
 *
 * File Details:
 *     Filename: main.cpp
 *     Created On: Nov 11, 2024
 *     Author: Jana Wael
 *
 * Functions:
 *     - Partition: Rearranges the array based on a pivot element, placing smaller elements
 *                  on the left and larger elements on the right.
 *     - QuickSort: Recursively applies the QuickSort algorithm to subarrays created by partitioning.
 *     - main: Initializes the array, calls QuickSort, and prints the sorted array.
 *
 * Compilation:
 *     g++ main.cpp -o QuickSort
 *
 * Execution:
 *     ./QuickSort
 *
 * Example Output:
 *     2 4 5 10 72 344
 */

#include <bits/stdc++.h> // Includes standard libraries in one header file
using namespace std;

/*
 * Partition Function
 * 
 * Parameters:
 *     - arr: Pointer to the array to be partitioned.
 *     - start: Starting index of the array section to partition.
 *     - end: Ending index of the array section to partition.
 * 
 * Description:
 *     This function selects the last element as the pivot, then iterates over the array,
 *     moving elements smaller than the pivot to the left. The `p_index` variable tracks
 *     the position where the pivot will be placed to ensure elements on the left are smaller
 *     and those on the right are larger. The function returns the final position of the pivot.
 * 
 * Returns:
 *     The index of the pivot element after partitioning.
 */
int Partition(int* arr, int start, int end) {
    int pivot = arr[end]; // Choose last element as pivot
    int p_index = start;  // Index for pivot placement

    // Traverse the array and swap elements smaller than pivot to the left
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[p_index]); // Move smaller element to p_index
            p_index++;                  // Increment pivot index
        }
    }

    // Place pivot element at its correct position
    swap(arr[p_index], arr[end]);
    return p_index; // Return pivot's final position
}

/*
 * QuickSort Function
 * 
 * Parameters:
 *     - arr: Pointer to the array to be sorted.
 *     - start: Starting index of the section to be sorted.
 *     - end: Ending index of the section to be sorted.
 * 
 * Description:
 *     This function recursively sorts the array by partitioning it around a pivot,
 *     then applying QuickSort to the left and right subarrays around the pivot.
 *     The base case stops recursion when the array section has zero or one element.
 */
void QuickSort(int* arr, int start, int end) {
    if (start >= end)
        return; // Base case: no sorting needed if one or zero elements

    // Partition the array and obtain the pivot index
    int pivot_index = Partition(arr, start, end);

    // Recursively sort elements on either side of the pivot
    QuickSort(arr, start, pivot_index - 1); // Sort left subarray
    QuickSort(arr, pivot_index + 1, end);   // Sort right subarray
}

/*
 * Main Function
 * 
 * Description:
 *     Initializes an array of integers, sorts it using the QuickSort function,
 *     and prints the sorted result.
 * 
 * Returns:
 *     0 on successful execution.
 */
int main() {
    int v[6] = {4, 2, 72, 5, 10, 344}; // Sample array

    // Sort the array using QuickSort
    QuickSort(v, 0, 5);

    // Output the sorted array
    for (int i = 0; i < sizeof(v) / sizeof(int); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0; // Indicate successful program completion
}
