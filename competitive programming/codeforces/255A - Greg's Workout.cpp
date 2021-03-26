/*
Greg is a beginner bodybuilder. Today the gym coach gave him the training plan. All it had was n integers a1,?a2,?...,?an. These numbers mean that Greg needs to do exactly n exercises today. Besides, Greg should repeat the i-th in order exercise ai times.

Greg now only does three types of exercises: "chest" exercises, "biceps" exercises and "back" exercises. Besides, his training is cyclic, that is, the first exercise he does is a "chest" one, the second one is "biceps", the third one is "back", the fourth one is "chest", the fifth one is "biceps", and so on to the n-th exercise.

Now Greg wonders, which muscle will get the most exercise during his training. We know that the exercise Greg repeats the maximum number of times, trains the corresponding muscle the most. Help Greg, determine which muscle will get the most training.

Input
The first line contains integer n (1?=?n?=?20). The second line contains n integers a1,?a2,?...,?an (1?=?ai?=?25) — the number of times Greg repeats the exercises.

Output
Print word "chest" (without the quotes), if the chest gets the most exercise, "biceps" (without the quotes), if the biceps gets the most exercise and print "back" (without the quotes) if the back gets the most exercise.

It is guaranteed that the input is such that the answer to the problem is unambiguous.

Examples
inputCopy
2
2 8
outputCopy
biceps
inputCopy
3
5 1 10
outputCopy
back
inputCopy
7
3 3 2 7 9 6 8
outputCopy
chest
Note
In the first sample Greg does 2 chest, 8 biceps and zero back exercises, so the biceps gets the most exercises.

In the second sample Greg does 5 chest, 1 biceps and 10 back exercises, so the back gets the most exercises.

In the third sample Greg does 18 chest, 12 biceps and 8 back exercises, so the chest gets the most exercise.
*/





#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector <int> v(n);
	
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int chest = 0, bi = 0, back = 0;
	
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) chest += v[i];
		else if (i % 3 == 1) bi += v[i];
		else back += v[i];
	}
	
	if (chest > bi && chest > back) cout << "chest";
	else if (bi > chest && bi > back) cout << "biceps";
	else cout << "back";

    return 0;
}

