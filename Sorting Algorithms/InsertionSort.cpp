/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 *
 *  Description:
 *      This program demonstrates the insertion sort algorithm on an integer array.
 *      It sorts an array in ascending order and prints the sorted result to the console.
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts an array using the insertion sort algorithm.
 * 
 * @param arr Pointer to the array to be sorted.
 * @param size Number of elements in the array.
 * 
 * InsertionSort takes each element in the array, compares it with elements 
 * in the sorted portion of the array, and shifts elements to insert it in the correct place.
 */
void InsertionSort(int* arr, int size)
{
    for(int i = 1; i < size; i++)  // Start from the second element
    {
        int value = arr[i];        // Current element to be inserted in the sorted portion
        int hole = i;              // Position where value needs to be inserted

        // Shift elements of the sorted portion of the array to make room for the current element
        while(hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];  // Move larger element one position to the right
            hole--;                     // Move the hole one position left
        }

        arr[hole] = value;  // Place the value in its correct sorted position
    }
}

int main()
{
    // Initialize an array to be sorted
    int arr[5] = {6, 3, 7, 1, 8};

    // Call InsertionSort function to sort the array
    InsertionSort(arr, 5);

    // Print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
