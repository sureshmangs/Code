#include<bits/stdc++.h>
using namespace std;

int maxHamming(int a[], int n){
    int maxHam=0;
    for(int k=1;k<n;k++){
        int curHam=0;
        int j=k;
        for(int i=0;i<n;i++){
            if(a[i]!=a[j]) curHam++;
            j=(j+1)%n;
        }
        if(curHam>maxHam) maxHam=curHam;
    }
    return maxHam;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   cout<<maxHamming(a, n);

}

