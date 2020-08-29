/*
Given an array of n positive integers.
Write a program to find the sum of maximum sum subsequence of the given array such that
the integers in the subsequence are sorted in increasing order.
For example,
if input is {1, 101, 2, 3, 100, 4, 5},
then output should be 106 (1 + 2 + 3 + 100),

if the input array is {3, 4, 5, 10},
then output should be 22 (3 + 4 + 5 + 10)

if the input array is {10, 5, 4, 3},
then output should be 10
*/


// Time Complexity: O(n^2)
/*
#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n){
	vector<int>sum(n,0);

	for(int i = 0; i < n; i++ )
		sum[i] = arr[i];

	for(int i = 1; i < n; i++ )
		for(int j = 0; j < i; j++ )
			if (arr[i] > arr[j] && sum[i] < sum[j] + arr[i])
				sum[i] = sum[j] + arr[i];

	return *max_element(sum.begin(), sum.end());
}


int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sum of maximum sum increasing subsequence is " << maxSumIS( arr, n ) << endl;
	return 0;
}
*/



// Print MSIS

#include <iostream>
#include <vector>
using namespace std;

void printMSIS(int arr[], int n){
	vector<int> MSIS[n];
	MSIS[0].push_back(arr[0]);

	int sum[n] = { 0 };
	sum[0] = arr[0];

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j] && sum[i] < sum[j]){
				MSIS[i] = MSIS[j];
				sum[i] = sum[j];
			}
		}
		MSIS[i].push_back(arr[i]);
		sum[i] += arr[i];
	}

	for (int i = 0; i < n; i++){
		cout << "MSIS[" << i << "] - ";
		for (int j : MSIS[i])
			cout << j << " ";
		cout << endl;
	}

	// j will contain index of MSIS
	int j = 0;
	for (int i = 1; i < n; i++)
		if (sum[i] > sum[j])
			j = i;

	// print MSIS
	for (int i : MSIS[j])
		cout << i << " ";
}

int main(){
	int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printMSIS(arr, n);

	return 0;
}
