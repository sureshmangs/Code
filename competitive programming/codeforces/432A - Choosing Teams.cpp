/*
The Saratov State University Olympiad Programmers Training Center (SSU OPTC) has n students. For each student you know the number of times he/she has participated in the ACM ICPC world programming championship. According to the ACM ICPC rules, each person can participate in the world championship at most 5 times.

The head of the SSU OPTC is recently gathering teams to participate in the world championship. Each team must consist of exactly three people, at that, any person cannot be a member of two or more teams. What maximum number of teams can the head make if he wants each team to participate in the world championship with the same members at least k times?

Input
The first line contains two integers, n and k (1?=?n?=?2000; 1?=?k?=?5). The next line contains n integers: y1,?y2,?...,?yn (0?=?yi?=?5), where yi shows the number of times the i-th person participated in the ACM ICPC world championship.

Output
Print a single number — the answer to the problem.

Examples
inputCopy
5 2
0 4 5 1 0
outputCopy
1
inputCopy
6 4
0 1 2 3 4 5
outputCopy
0
inputCopy
6 5
0 0 0 0 0 0
outputCopy
2
Note
In the first sample only one team could be made: the first, the fourth and the fifth participants.

In the second sample no teams could be created.

In the third sample two teams could be created. Any partition into two teams fits.
*/


#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    
    int student = 0;
    
    for (int i = 0; i < n ; i++) {
    	if(v[i] <= 5 - k) student++;
 	}
 	
 	cout << student / 3;

}

