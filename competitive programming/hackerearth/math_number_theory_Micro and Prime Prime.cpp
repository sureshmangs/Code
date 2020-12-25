/*
Micro just learned about prime numbers. But he quickly got bored of them, so he defined a new kind of numbers and called them Prime Prime Numbers. A number X is Prime Prime if number of prime numbers from 1 to X (inclusive) are prime. Now he wants to find out the number of Prime Prime numbers from L to R (inclusive). Help Micro with it.

Input:
First line consists of a single integer T denoting number of test cases
Following T lines consists of two space separated integers denoting L and R

Output:
Print the number of Prime Prime Numbers for each between L and R for each test case in a new line.

Constraints:


SAMPLE INPUT
2
3 10
4 12
SAMPLE OUTPUT
4
5
*/





#include<bits/stdc++.h>
using namespace std;

int maxRange = 1000000;

void seiveErato(vector <bool> &seive, int range){
    seive[0] = false;
    seive[1] = false;
    for(int i = 2; i * i <= range; i++){
        if(seive[i]){
            for(int j = i * i; j <= range; j += i)
                seive[j] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector <bool> seive(maxRange + 1, true);
    seiveErato(seive, maxRange);

    vector <int> pprime(maxRange + 1, 0);

    int cprime = 0;

    for(int i = 2; i <= maxRange; i++){
        if(seive[i]) cprime++;
        if(seive[cprime]) pprime[i] = 1;
        else pprime[i] = 0;
    }

    for(int i = 1; i <= maxRange; i++)
        pprime[i] += pprime[i - 1];

    while(t--){
        int l, r;
        cin >> l >> r;

        int res = pprime[r] - pprime[l - 1];

        cout << res << endl;
    }


    return 0;
}
