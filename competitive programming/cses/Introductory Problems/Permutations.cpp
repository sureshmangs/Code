#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];

    int i=0;
    int tmp=n;

    if(n%2==0){
        while(n>0){
            a[i]=n;
            cout<<n<<" ";
            n-=2;
            i++;

        }
        n=tmp-1;  // for odd
        while(n>0){
            a[i]=n;
            n-=2;
            i++;
            cout<<a[i]<<" ";
        }
    } else {
        n=tmp-1;   // for even
        while(n>0){
            a[i]=n;
            n-=2;
            i++;
        }

        n=tmp;
        while(n>0){
            a[i]=n;
            n-=2;
            i++;
        }
    }



    return 0;
}
