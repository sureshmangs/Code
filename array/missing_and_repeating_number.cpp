/*
Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3
1 3 3

Output:
2 1
3 2

Explanation:
Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
Testcase 2: Repeating number is 3 and smallest positive missing number is 2.
*/









#include<bits/stdc++.h>
using namespace std;

void missDup(int a[], int n, int &x, int &y){

    int txor=0;
    for(int i=0;i<n;i++)
        txor^=a[i];  // all elements xor

    for(int i=1;i<=n;i++)
        txor^=i;    // all numbers 1 to n xor

    int setBit=txor & (-txor); // righmost set bit

    // Dividing all elements into two groups based on their set bit
    for(int i=0;i<n;i++){
        if(a[i] & setBit)
             x^=a[i];
        else y^=a[i];
    }
    for(int i=1;i<=n;i++){
        if(i & setBit)
             x^=i;
        else y^=i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int x=0, y=0;  // missing and duplicate(order yet to be found)
        //cout<<x<<" "<<y<<endl;
        missDup(a, n, x, y);
        // x, y have our desired result
        // find missing and duplicate
        int dup, miss;
        for(int i=0;i<n;i++){
            if(a[i]==x) { dup=x; miss=y; break;  }
            else if(a[i]==y) { dup=y; miss=x; break;  }
        }
        cout<<dup<<" "<<miss<<endl;
    }

return 0;
}




// Alter
// 1. sort() and check adjacent
// 2. use sum and sum^2 equation
// 3. check frequencies
