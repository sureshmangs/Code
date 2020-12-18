/*
Find and Print All The Prime Numbers Between L and R (Both L and R Inclusive)

Input Format

Take Input Value of L and R

Output Format

Print All The Prime Number Between L and R (Both L and R inclusive)

Constraints

0 < L < 10001
0 < R < 10001
L <= R
SAMPLE INPUT
2 10
SAMPLE OUTPUT
2 3 5 7

*/






#include<bits/stdc++.h>
using namespace std;

void seiveErato(int start, int range, vector <int> &prime){
    vector <bool> seive(range + 1, true);
    seive[0] = false;
    seive[1] = false;
    for(int i = 2; i * i <= range; i++){
        if(seive[i]){
            for(int j = i * i; j <= range; j += i)
                seive[j] = false;
        }
    }

    for(int i = start; i <= range; i++)
        if(seive[i])
            prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    cin >> l >> r;

    vector <int> prime;
    seiveErato(l, r, prime);

    for(auto &x: prime) cout << x << " ";

    return 0;
}
