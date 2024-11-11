/*
 * main.cpp
 *
 *  Created on: Nov 11, 2024
 *      Author: Jana Wael
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void Merge(vector<int>L, vector<int>R, vector<int>&A)
{
	int nL = 0, nR = 0, nA = 0;
	while(nL < L.size() && nR < R.size())
	{
		if(L[nL] < R[nR])
		{
			A[nA++] = L[nL++];
		}
		else
		{
			A[nA++] = R[nR++];
		}
	}
	while(nL < L.size())
	{
		A[nA++] = L[nL++];
	}
	while(nR < R.size())
	{
		A[nA++] = R[nR++];
	}
}

vector<int> MergeSort(vector<int> A) {
    if (A.size() <= 1) {
        return A;
    }

    int mid = A.size() / 2;
    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());

    left = MergeSort(left);
    right = MergeSort(right);

    Merge(left, right, A);
    return A;
}



int main()
{
	vector<int> v= {6,4,7,2,1,100,45};
	v = MergeSort(v);
	for(int i = 0 ; i < v.size() ; i++)
	{
		cout << v[i] << " " ;
	}
}


