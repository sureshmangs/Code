/*
Devu is a renowned classical singer. He is invited to many big functions/festivals. Recently he was invited to "All World Classical Singing Festival". Other than Devu, comedian Churu was also invited.

Devu has provided organizers a list of the songs and required time for singing them. He will sing n songs, ith song will take ti minutes exactly.

The Comedian, Churu will crack jokes. All his jokes are of 5 minutes exactly.

People have mainly come to listen Devu. But you know that he needs rest of 10 minutes after each song. On the other hand, Churu being a very active person, doesn't need any rest.

You as one of the organizers should make an optimal s?hedule for the event. For some reasons you must follow the conditions:

The duration of the event must be no more than d minutes;
Devu must complete all his songs;
With satisfying the two previous conditions the number of jokes cracked by Churu should be as many as possible.
If it is not possible to find a way to conduct all the songs of the Devu, output -1. Otherwise find out maximum number of jokes that Churu can crack in the grand event.

Input
The first line contains two space separated integers n, d (1?=?n?=?100; 1?=?d?=?10000). The second line contains n space-separated integers: t1,?t2,?...,?tn (1?=?ti?=?100).

Output
If there is no way to conduct all the songs of Devu, output -1. Otherwise output the maximum number of jokes that Churu can crack in the grand event.

Examples
inputCopy
3 30
2 2 1
outputCopy
5
inputCopy
3 20
2 1 1
outputCopy
-1
Note
Consider the first example. The duration of the event is 30 minutes. There could be maximum 5 jokes in the following way:

First Churu cracks a joke in 5 minutes.
Then Devu performs the first song for 2 minutes.
Then Churu cracks 2 jokes in 10 minutes.
Now Devu performs second song for 2 minutes.
Then Churu cracks 2 jokes in 10 minutes.
Now finally Devu will perform his last song in 1 minutes.
Total time spent is 5?+?2?+?10?+?2?+?10?+?1?=?30 minutes.

Consider the second example. There is no way of organizing Devu's all songs. Hence the answer is -1.
*/




#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;
    
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    int sum  = 0;
    
    for (int i = 0; i < n; i++) sum += v[i];
    
    sum += 10 * (n - 1);
    
    if(sum > d) cout << -1;
    else cout << (d - sum) / 5 + (n - 1) * 2;

}

