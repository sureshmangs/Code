/*
Pasha has two hamsters: Arthur and Alexander. Pasha put n apples in front of them. Pasha knows which apples Arthur likes. Similarly, Pasha knows which apples Alexander likes. Pasha doesn't want any conflict between the hamsters (as they may like the same apple), so he decided to distribute the apples between the hamsters on his own. He is going to give some apples to Arthur and some apples to Alexander. It doesn't matter how many apples each hamster gets but it is important that each hamster gets only the apples he likes. It is possible that somebody doesn't get any apples.

Help Pasha distribute all the apples between the hamsters. Note that Pasha wants to distribute all the apples, not just some of them.

Input
The first line contains integers n, a, b (1?=?n?=?100; 1?=?a,?b?=?n) — the number of apples Pasha has, the number of apples Arthur likes and the number of apples Alexander likes, correspondingly.

The next line contains a distinct integers — the numbers of the apples Arthur likes. The next line contains b distinct integers — the numbers of the apples Alexander likes.

Assume that the apples are numbered from 1 to n. The input is such that the answer exists.

Output
Print n characters, each of them equals either 1 or 2. If the i-h character equals 1, then the i-th apple should be given to Arthur, otherwise it should be given to Alexander. If there are multiple correct answers, you are allowed to print any of them.

Examples
inputCopy
4 2 3
1 2
2 3 4
outputCopy
1 1 2 2
inputCopy
5 5 2
3 4 1 2 5
2 3
outputCopy
1 1 1 1 1
*/




#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    vector <int> v(n + 1, 0);
    
    for (int i = 0; i < a; i++) {
    	int ch;
    	cin >> ch;
    	v[ch] = 1;
	}
	
	for (int i = 0; i < b; i++) {
    	int ch;
    	cin >> ch;
    	v[ch] = 2;
	}
	
	for (int i = 1; i <= n; i++) cout << v[i] << " ";
	 

    return 0;
}




/*
#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    unordered_set <int> as, bs;
    
    for (int i = 0; i < a; i++) {
    	int ch;
    	cin >> ch;
    	as.insert(ch);
	}
	
	for (int i = 0; i < b; i++) {
    	int ch;
    	cin >> ch;
    	bs.insert(ch);
	}
	
	for (int i = 1; i <= n; i++) {
		if(as.find(i) != as.end()) cout << 1 << " ";
		else if (bs.find(i) != bs.end()) cout << 2 << " ";
	}
	 

    return 0;
}

*/
