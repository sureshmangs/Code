/*
Athenaeus has just finished creating his latest musical composition and will present it tomorrow to the people of Athens. Unfortunately, the melody is rather dull and highly likely won't be met with a warm reception.

His song consists of n notes, which we will treat as positive integers. The diversity of a song is the number of different notes it contains. As a patron of music, Euterpe watches over composers and guides them throughout the process of creating new melodies. She decided to help Athenaeus by changing his song to make it more diverse.

Being a minor goddess, she cannot arbitrarily change the song. Instead, for each of the n notes in the song, she can either leave it as it is or increase it by 1.

Given the song as a sequence of integers describing the notes, find out the maximal, achievable diversity.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤10000) — the number of test cases. Then t test cases follow, each one is described in two lines.

In the first line of each test case there is a single integer n (1≤n≤105) denoting the length of the song. The next line contains a sequence of n integers x1,x2,…,xn (1≤x1≤x2≤…≤xn≤2⋅n), describing the song.

The sum of n over all test cases does not exceed 105.

Output
For each test case, you should output a single line containing precisely one integer, the maximal diversity of the song, i.e. the maximal possible number of different elements in the final sequence.

Example
inputCopy
5
6
1 2 2 2 5 6
2
4 4
6
1 1 3 4 4 5
1
1
6
1 1 1 2 2 2
outputCopy
5
2
6
1
3
Note
In the first test case, Euterpe can increase the second, fifth and sixth element to obtain the sequence 1,3–,2,2,6–,7–, which has 5 different elements (increased elements are underlined).

In the second test case, Euterpe can increase the first element to obtain the sequence 5–,4, which has 2 different elements.

In the third test case, Euterpe can increase the second, fifth and sixth element to obtain the sequence 1,2–,3,4,5–,6–, which has 6 different elements.
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        set<int>s;
        for(auto &x: v){
            if(s.find(x) ==s.end()) s.insert(x);
            else s.insert(x+1);
        }

        cout<<s.size()<<endl;
    }

    return 0;
}
