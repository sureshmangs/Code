#include<bits/stdc++.h>
using namespace std;

int sod(int n){
    int sd = 0;
    while(n){
        sd += n % 10;
        n /= 10;
    }
    return sd;
}

bool isUnique(int n){
    set <int> s;
    int digits = 0;
    while(n){
        s.insert(n % 10);
        n /= 10;
        digits++;
    }
    return s.size() == digits;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int xsod = sod(x);

        int i = 1;
        bool flag = false;
        while(i < INT_MAX){
            if(isUnique(i) && sod(i) == x){
                    flag = true;
                break;
            }
            i++;
        }

        if(!flag) cout << -1 << endl;
        else cout << i << endl;
    }

    return 0;
}

