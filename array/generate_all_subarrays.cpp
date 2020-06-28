/*
A subbarray is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. The subbarays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4). In general, for an array/string of size n, there are n*(n+1)/2 non-empty subarrays/subsrings.
*/






#include<bits/stdc++.h>
using namespace std;

void allSubArray(int a[], int n)
{
	for (int i=0; i <n; i++){
		for (int j=i; j<n; j++){
			for (int k=i; k<=j; k++)
				cout << a[k] << " ";
			cout << endl;
		}
	}
}

int main()
{   int n=4;
	int a[] = {1, 2, 3, 4};
	allSubArray(a, n);
	return 0;
}
