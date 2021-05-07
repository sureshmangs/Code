/*
Let's call a positive integer n ordinary if in the decimal notation all its digits are the same. For example, 1, 2 and 99 are ordinary numbers, but 719 and 2021 are not ordinary numbers.

For a given number n, find the number of ordinary numbers among the numbers from 1 to n.

Input
The first line contains one integer t (1=t=104). Then t test cases follow.

Each test case is characterized by one integer n (1=n=109).

Output
For each test case output the number of ordinary numbers among numbers from 1 to n.

Example
inputCopy
6
1
2
3
4
5
100
outputCopy
1
2
3
4
5
18
*/






/*
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector <long long> v;
    
    for (int i = 1; i <= 9; i++) {
    	string s = "";
    	for (int j = 1; j <= 9; j++) {
    		s += (i + '0');
    		v.push_back(stoi(s));
		}
	}
	
    
    while (t--) {
    	int n;
    	cin >> n;
    	
    	int res = 0;
    	
    	for (auto &x: v) {
    		if (x <= n) res++;
		}
		cout << res << endl;
    	
	}
  	
    return 0;
}*/





#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int n;
    	cin >> n;
    	
    	int res = 0;
    	
    	for (int i = 1; i <= 9; i++) {
    		for (long long num = i; num <= n; num = num * 10 + i) {
    			res++;
			}
		}
    	
		cout << res << endl;
    	
	}
  	
    return 0;
}
