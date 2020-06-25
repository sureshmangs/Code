/*
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/








#include<bits/stdc++.h>
using namespace std;

long long invCount;

void merge(vector<long long> &v, long long l, long long mid, long long r){
    long long n1=mid-l+1;
    long long n2=r-(mid+1)+1;
    vector<long long> L(n1);
    vector<long long> R(n2);

    for(long long i=0;i<n1;i++)
        L[i]=v[l+i];
    for(long long j=0;j<n2;j++)
        R[j]=v[mid+1+j];

    long long i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            v[k]=L[i];
            i++;
        } else {
            v[k]=R[j];
            j++;
            invCount+=n1-i;
        }
        k++;
    }

    while(i<n1){
        v[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        v[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<long long> &v, long long l, long long r){
    if(l<r){
        long long mid=l+(r-l)/2;
        mergeSort(v, l, mid);
        mergeSort(v, mid+1, r);
        merge(v, l, mid, r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> v;

        for(long long i=0;i<n;i++){
            long long ch;
            cin>>ch;
            v.push_back(ch);
        }

        invCount=0;
        mergeSort(v, 0, n-1);
        cout<<invCount<<endl;
    }

return 0;
}
