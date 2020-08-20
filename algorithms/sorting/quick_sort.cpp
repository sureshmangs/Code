/*
Example 1:

Input: N = 5, arr[] = { 4, 1, 3, 9, 7}
Output: 1 3 4 7 9
Example 2:

Input: N = 10,
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output: 1 2 3 4 5 6 7 8 9 10
*/






#include<bits/stdc++.h>
using namespace std;

int partion(int a[], int low, int high){
    int pivot=a[high];
    int pIndex=low;
    for(int i=low; i< high; i++){
        if(a[i] <= pivot){
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[high]);
    return pIndex;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pIndex = partion(a, low, high);
        quickSort(a, low, pIndex-1);
        quickSort(a, pIndex, high);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    quickSort(a, 0, n-1);   // <array , low, high>

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
