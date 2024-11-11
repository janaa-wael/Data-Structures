/*
 * QuickSort.cpp
 *
 * Description:
 *     This file implements the QuickSort sorting algorithm using a custom
 *     partitioning function. QuickSort is a divide-and-conquer algorithm
 *     that recursively partitions the array around a pivot, placing smaller
 *     elements to the left and larger elements to the right, until the
 *     array is fully sorted.
 *
 * File Details:
 *     Filename: QuickSort.cpp
 *     Created On: Nov 11, 2024
 *     Author: Jana Wael
 *
 * Functions:
 *     - Partition: Rearranges elements around a pivot, positioning smaller
 *                  elements before it and larger ones after it, and returns
 *                  the pivot's index.
 *     - QuickSort: Recursively sorts the subarrays created by partitioning.
 *     - main: Initializes an array, calls QuickSort on it, and prints the sorted result.
 *
 * Compilation:
 *     g++ QuickSort.cpp -o QuickSort
 *
 * Execution:
 *     ./QuickSort
 *
 * Example Output:
 *     2 4 5 10 72 344
 */

#include <bits/stdc++.h> // Includes standard C++ libraries in one header file
using namespace std;

/*
 * Partition Function
 * 
 * Parameters:
 *     - v: Pointer to the integer array to be partitioned.
 *     - start: Starting index of the section to be partitioned.
 *     - end: Ending index of the section to be partitioned.
 * 
 * Description:
 *     This function uses the last element as a pivot. It iterates over the
 *     array section, adjusting pointers 'left' and 'right' to place all
 *     elements smaller than the pivot to the left and all elements greater
 *     to the right. Elements at 'left' and 'right' are swapped when they are
 *     out of order relative to the pivot, and the pivot is finally placed in
 *     its correct position in the sorted array.
 * 
 * Returns:
 *     The index where the pivot element is placed after partitioning.
 */
int Partition(int* v, int start, int end) {
    int pivot = v[end];    // Choose last element as pivot
    int left = start;      // Left pointer starts from the beginning
    int right = end - 1;   // Right pointer starts just before the pivot

    // Loop until the two pointers cross
    while (true) {
        // Move 'left' forward until finding an element >= pivot
        while (left <= right && v[left] < pivot)
            left++;

        // Move 'right' backward until finding an element <= pivot
        while (right >= left && v[right] > pivot)
            right--;

        // Check if pointers have crossed, ending partitioning
        if (left >= right)
            break;

        // Swap elements at left and right pointers
        swap(v[left], v[right]);
        left++;
        right--;
    }

    // Place the pivot in its correct position
    swap(v[left], v[end]);
    return left; // Return the final index of the pivot
}

/*
 * QuickSort Function
 * 
 * Parameters:
 *     - v: Pointer to the integer array to be sorted.
 *     - start: Starting index of the section to be sorted.
 *     - end: Ending index of the section to be sorted.
 * 
 * Description:
 *     This function recursively sorts the array by partitioning it around a pivot,
 *     then sorting the left and right subarrays separately. The recursion stops
 *     when the array section has one or zero elements (base case).
 */
void QuickSort(int* v, int start, int end) {
    if (start >= end)
        return; // Base case: no sorting needed if one or zero elements

    // Partition the array and get the pivot index
    int pivot_index = Partition(v, start, end);

    // Recursively sort elements before and after the pivot
    QuickSort(v, start, pivot_index - 1); // Sort left subarray
    QuickSort(v, pivot_index + 1, end);   // Sort right subarray
}

/*
 * Main Function
 * 
 * Description:
 *     Initializes an array of integers, sorts it using QuickSort, and prints
 *     the sorted result to the console.
 * 
 * Returns:
 *     0 on successful execution.
 */
int main() {
    int v[6] = {4, 2, 72, 5, 10, 344}; // Sample array to be sorted

    // Sort the array using QuickSort
    QuickSort(v, 0, 5);

    // Output the sorted array
    for (int i = 0; i < sizeof(v) / sizeof(int); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0; // Indicate successful program completion
}
