/*
This winter is so cold in Nvodsk! A group of n friends decided to buy k bottles of a soft drink called "Take-It-Light" to warm up a bit. Each bottle has l milliliters of the drink. Also they bought c limes and cut each of them into d slices. After that they found p grams of salt.

To make a toast, each friend needs nl milliliters of the drink, a slice of lime and np grams of salt. The friends want to make as many toasts as they can, provided they all drink the same amount. How many toasts can each friend make?

Input
The first and only line contains positive integers n, k, l, c, d, p, nl, np, not exceeding 1000 and no less than 1. The numbers are separated by exactly one space.

Output
Print a single integer — the number of toasts each friend can make.

Examples
inputCopy
3 4 5 10 8 100 3 1
outputCopy
2
inputCopy
5 100 10 1 19 90 4 3
outputCopy
3
inputCopy
10 1000 1000 25 23 1 50 1
outputCopy
0
Note
A comment to the first sample:

Overall the friends have 4?*?5?=?20 milliliters of the drink, it is enough to make 20?/?3?=?6 toasts. The limes are enough for 10?*?8?=?80 toasts and the salt is enough for 100?/?1?=?100 toasts. However, there are 3 friends in the group, so the answer is min(6,?80,?100)?/?3?=?2
*/





#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    
    int x = (k * l) / nl;
    int y = c * d;
    int z = p / np;
    
    cout << min(x, min(y, z)) / n;


    return 0;
}
