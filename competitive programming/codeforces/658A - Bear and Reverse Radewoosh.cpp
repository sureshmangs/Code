/*
Limak and Radewoosh are going to compete against each other in the upcoming algorithmic contest. They are equally skilled but they won't solve problems in the same order.

There will be n problems. The i-th problem has initial score pi and it takes exactly ti minutes to solve it. Problems are sorted by difficulty — it's guaranteed that pi?<?pi?+?1 and ti?<?ti?+?1.

A constant c is given too, representing the speed of loosing points. Then, submitting the i-th problem at time x (x minutes after the start of the contest) gives max(0,? pi?-?c·x) points.

Limak is going to solve problems in order 1,?2,?...,?n (sorted increasingly by pi). Radewoosh is going to solve them in order n,?n?-?1,?...,?1 (sorted decreasingly by pi). Your task is to predict the outcome — print the name of the winner (person who gets more points at the end) or a word "Tie" in case of a tie.

You may assume that the duration of the competition is greater or equal than the sum of all ti. That means both Limak and Radewoosh will accept all n problems.

Input
The first line contains two integers n and c (1?=?n?=?50,?1?=?c?=?1000) — the number of problems and the constant representing the speed of loosing points.

The second line contains n integers p1,?p2,?...,?pn (1?=?pi?=?1000,?pi?<?pi?+?1) — initial scores.

The third line contains n integers t1,?t2,?...,?tn (1?=?ti?=?1000,?ti?<?ti?+?1) where ti denotes the number of minutes one needs to solve the i-th problem.

Output
Print "Limak" (without quotes) if Limak will get more points in total. Print "Radewoosh" (without quotes) if Radewoosh will get more points in total. Print "Tie" (without quotes) if Limak and Radewoosh will get the same total number of points.

Examples
inputCopy
3 2
50 85 250
10 15 25
outputCopy
Limak
inputCopy
3 6
50 85 250
10 15 25
outputCopy
Radewoosh
inputCopy
8 1
10 20 30 40 50 60 70 80
8 10 58 63 71 72 75 76
outputCopy
Tie
Note
In the first sample, there are 3 problems. Limak solves them as follows:

Limak spends 10 minutes on the 1-st problem and he gets 50?-?c·10?=?50?-?2·10?=?30 points.
Limak spends 15 minutes on the 2-nd problem so he submits it 10?+?15?=?25 minutes after the start of the contest. For the 2-nd problem he gets 85?-?2·25?=?35 points.
He spends 25 minutes on the 3-rd problem so he submits it 10?+?15?+?25?=?50 minutes after the start. For this problem he gets 250?-?2·50?=?150 points.
So, Limak got 30?+?35?+?150?=?215 points.

Radewoosh solves problem in the reversed order:

Radewoosh solves 3-rd problem after 25 minutes so he gets 250?-?2·25?=?200 points.
He spends 15 minutes on the 2-nd problem so he submits it 25?+?15?=?40 minutes after the start. He gets 85?-?2·40?=?5 points for this problem.
He spends 10 minutes on the 1-st problem so he submits it 25?+?15?+?10?=?50 minutes after the start. He gets max(0,?50?-?2·50)?=?max(0,??-?50)?=?0 points.
Radewoosh got 200?+?5?+?0?=?205 points in total. Limak has 215 points so Limak wins.

In the second sample, Limak will get 0 points for each problem and Radewoosh will first solve the hardest problem and he will get 250?-?6·25?=?100 points for that. Radewoosh will get 0 points for other two problems but he is the winner anyway.

In the third sample, Limak will get 2 points for the 1-st problem and 2 points for the 2-nd problem. Radewoosh will get 4 points for the 8-th problem. They won't get points for other problems and thus there is a tie because 2?+?2?=?4.
*/




#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    
    vector <int> p(n), t(n);
    
    for (auto &x: p) cin >> x;
    for (auto &x: t) cin >> x;
    
    int lim= 0, red = 0, ctime = 0;
    
    for (int i  = 0; i < n; i++) {
    	ctime += t[i];
    	lim += max(0, p[i] - c * ctime);
	}
	
	ctime = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		ctime += t[i];
    	red += max(0, p[i] - c * ctime);
	}
	
	if (lim > red) cout << "Limak";
	else if (lim < red) cout << "Radewoosh";
	else cout << "Tie";
    
    return 0;
}
