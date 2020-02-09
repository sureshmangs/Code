#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void jugglingRotate(int a[], int n, int d){
    d%=n;
    int steps=gcd(n, d);
    for(int i=0;i<steps;i++){
        int tmp=a[i];
        int j=i;
        while(1){
            int k=j+d;
            if(k>=n) k-=n;
            if(i==k)
                break;
            a[j]=a[k];
            j=k;
        }
        a[j]=tmp;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int d;
    cin>>d;
    jugglingRotate(a, n, d);


return 0;
}
