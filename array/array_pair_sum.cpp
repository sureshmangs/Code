/*
Given an array A of N positive integers and another number X.
Determine whether or not there exist two elements in A whose sum is exactly X.
*/




#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_set<int> s;
    int sum;
    cin>>sum;
    for(int i=0;i<n;i++){
        if(s.find(sum-a[i])!=s.end()){
            cout<<sum-a[i]<<" "<<a[i]<<endl;
        }
        else {
            s.insert(a[i]);
        }
    }
}

