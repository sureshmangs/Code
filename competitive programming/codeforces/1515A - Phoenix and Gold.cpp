/*
Phoenix has collected n pieces of gold, and he wants to weigh them together so he can feel rich. The i-th piece of gold has weight wi. All weights are distinct. He will put his n pieces of gold on a weight scale, one piece at a time.

The scale has an unusual defect: if the total weight on it is exactly x, it will explode. Can he put all n gold pieces onto the scale in some order, without the scale exploding during the process? If so, help him find some possible order.

Formally, rearrange the array w so that for each i (1=i=n), ?j=1iwj?x.

Input
The input consists of multiple test cases. The first line contains an integer t (1=t=1000) — the number of test cases.

The first line of each test case contains two integers n and x (1=n=100; 1=x=104) — the number of gold pieces that Phoenix has and the weight to avoid, respectively.

The second line of each test case contains n space-separated integers (1=wi=100) — the weights of the gold pieces. It is guaranteed that the weights are pairwise distinct.

Output
For each test case, if Phoenix cannot place all n pieces without the scale exploding, print NO. Otherwise, print YES followed by the rearranged array w. If there are multiple solutions, print any.

Example
inputCopy
3
3 2
3 2 1
5 3
1 2 3 4 8
1 5
5
outputCopy
YES
3 2 1
YES
8 1 2 3 4
NO
Note
In the first test case, Phoenix puts the gold piece with weight 3 on the scale first, then the piece with weight 2, and finally the piece with weight 1. The total weight on the scale is 3, then 5, then 6. The scale does not explode because the total weight on the scale is never 2.

In the second test case, the total weight on the scale is 8, 9, 11, 14, then 18. It is never 3.

In the third test case, Phoenix must put the gold piece with weight 5 on the scale, and the scale will always explode
*/



#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int n, x;
    	cin >> n >> x;
    	
    	queue <int> q;
    	
    	int sum = 0;
    	
    	for (int i = 0; i < n; i++) {
    		int ch;
    		cin >> ch;
    		q.push(ch);
    		sum += ch;
		}
		
		if (sum == x) {
			cout << "NO" << endl;
		} else {
			sum = x;	
			cout << "YES" << endl;
			int first = q.front();
			q.pop();
			
			if (first == x) {
				q.push(first);
			} else {
				sum -= first;
				cout << first << " ";;
			}
			
			while (!q.empty()) {
				int tmp = q.front();
				q.pop();
				if (tmp == sum) q.push(tmp);
				else {
					cout << tmp << " ";
					sum -= tmp;
				}
			}
			cout << endl;
		}
	}
  	
    return 0;
}
