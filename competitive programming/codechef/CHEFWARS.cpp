/*
On the ice planet Hoth, Chef has run into his arch-nemesis, DarthForces. Darth has a peculiar fighting style ― he does not attack, but simply defends and lets his opponent tire himself out.

Chef has a lightsaber which has an attack power denoted by P. He keeps hitting Darth with the lightsaber. Every time he hits, Darth's health decreases by the current attack power of the lightsaber (by P points), and afterwards, P decreases to ⌊P2⌋.

If the attack power becomes 0 before Darth's health becomes 0 or less, Chef dies. Otherwise, Darth dies. You are given Darth's initial health H and the initial attack power P. Tell Chef if he can beat Darth or if he should escape.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers H and P.
Output
For each test case, print a single line containing the integer 1 if Chef can beat Darth or 0 otherwise.

Constraints
1≤T≤105
1≤P≤105
1≤H≤106
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
10 4
10 8
Example Output
0
1
Explanation
Example case 1: Chef attacks with power 4, Darth's health becomes 6. Chef attacks with power 2, Darth's health becomes 4. Chef attacks with power 1 and Darth's health becomes 3, but Chef's attack power becomes 0.

Example case 2: Chef attacks with power 8, Darth's health becomes 2. Chef attacks with power 4, Darth's health becomes 0. Chef kills Darth.
*/










#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long h, p;
        cin>>h>>p;
        while(h && p){
            h-=p;
            p/=2;
        }
        if(h>0) cout<<"0"<<endl;  // chef dies
        else cout<<"1"<<endl; // chef wins
    }

return 0;
}
