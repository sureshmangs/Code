/*
In this problem we consider a special type of an auction, which is called the second-price auction. As in regular auction n bidders place a bid which is price a bidder ready to pay. The auction is closed, that is, each bidder secretly informs the organizer of the auction price he is willing to pay. After that, the auction winner is the participant who offered the highest price. However, he pay not the price he offers, but the highest price among the offers of other participants (hence the name: the second-price auction).

Write a program that reads prices offered by bidders and finds the winner and the price he will pay. Consider that all of the offered prices are different.

Input
The first line of the input contains n (2?=?n?=?1000) — number of bidders. The second line contains n distinct integer numbers p1,?p2,?... pn, separated by single spaces (1?=?pi?=?10000), where pi stands for the price offered by the i-th bidder.

Output
The single output line should contain two integers: index of the winner and the price he will pay. Indices are 1-based.

Examples
inputCopy
2
5 7
outputCopy
2 5
inputCopy
3
10 2 8
outputCopy
1 8
inputCopy
6
3 8 2 9 4 14
outputCopy
6 9
*/



#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int first = -1, second = -1, find, sind;
    
    for (int i = 1; i <= n; i++) {
    	int p;
    	cin >> p;
    	
    	if (p > first) {
    		second = first;
    		sind = find;
    		first = p;
    		find = i;
    		
		} else if (p > second) {
			second = p;
			sind = i;
		}
	}
	
	cout << find << " " << second;
  	
    return 0;
}
