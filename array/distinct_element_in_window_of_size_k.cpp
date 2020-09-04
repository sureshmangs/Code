#include <bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int k, int n){
	unordered_map<int, int> m;
	int dist_count = 0;

	// Traverse the first window and store count of every element in hash map
	for(int i = 0; i < k; i++){
		if(m[arr[i]] == 0)
			dist_count++;
		m[arr[i]]++;
	}

	// Print count of first window
	cout<<dist_count<<" ";

	// Traverse through the remaining array
	for (int i = k; i < n; i++){
		// Remove first element of previous window
		// If there was only one occurrence, then reduce distinct count
		if(m[arr[i - k]] == 1)
			dist_count--;

		// reduce count of the removed element
		m[arr[i - k]]--;

		// Add new element of current window
		// If this element appears first time, increment distinct element count

		if (m[arr[i]] == 0)
			dist_count++;

		m[arr[i]]++;

		// Print count of current window
		cout<<dist_count<<" ";
	}
}

int main(){
	int arr[] = { 1, 2, 1, 3, 4, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	countDistinct(arr, k, size);

	return 0;
}
