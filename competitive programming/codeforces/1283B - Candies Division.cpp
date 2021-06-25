/*
Santa has n candies and he wants to gift them to k kids. He wants to divide as many candies as possible between all k kids. Santa can't divide one candy into parts but he is allowed to not use some candies at all.

Suppose the kid who recieves the minimum number of candies has a candies and the kid who recieves the maximum number of candies has b candies. Then Santa will be satisfied, if the both conditions are met at the same time:

b-a=1 (it means b=a or b=a+1);
the number of kids who has a+1 candies (note that a+1 not necessarily equals b) does not exceed ?k2? (less than or equal to ?k2?).
?k2? is k divided by 2 and rounded down to the nearest integer. For example, if k=5 then ?k2?=?52?=2.

Your task is to find the maximum number of candies Santa can give to kids so that he will be satisfied.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=5·104) — the number of test cases.

The next t lines describe test cases. The i-th test case contains two integers n and k (1=n,k=109) — the number of candies and the number of kids.

Output
For each test case print the answer on it — the maximum number of candies Santa can give to kids so that he will be satisfied.

Example
inputCopy
5
5 2
19 4
12 7
6 2
100000 50010
outputCopy
5
18
10
6
75015
Note
In the first test case, Santa can give 3 and 2 candies to kids. There a=2,b=3,a+1=3.

In the second test case, Santa can give 5,5,4 and 4 candies. There a=4,b=5,a+1=5. The answer cannot be greater because then the number of kids with 5 candies will be 3.

In the third test case, Santa can distribute candies in the following way: [1,2,2,1,1,2,1]. There a=1,b=2,a+1=2. He cannot distribute two remaining candies in a way to be satisfied.

In the fourth test case, Santa can distribute candies in the following way: [3,3]. There a=3,b=3,a+1=4. Santa distributed all 6 candies
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		if (n < k) cout << min(n, k / 2) << "\n";
		else {
			int equal = n / k;
			n  = n -  k * equal;
			
			cout << k * equal + min(n, k / 2) << "\n";
		}
	}
	
    return 0;
}
