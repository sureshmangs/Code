/*
Input: arr[] = {7, 10, 4, 3, 20, 15}
           k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
           k = 4
Output: 10
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

int kthSmallest(int a[], int low, int high, int k){
    // If k is smaller than number of elements in array
    if(k > 0 && k <= high - low + 1){
        int pIndex = partion(a, low, high);
        if(pIndex-low == k-1) return a[pIndex];
        else if(pIndex-low > k-1) kthSmallest(a, low, pIndex-1, k);
        else kthSmallest(a, pIndex+1, high, k-pIndex+low-1);
    }
    // If k is more than number of elements in array
    else return INT_MAX;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k;
    cin>>k;

    cout<<kthSmallest(a, 0, n-1, k);   // <array , low, high>
}
