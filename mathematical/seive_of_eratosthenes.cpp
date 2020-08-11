/*
Given a number N, calculate the prime numbers upto N using Sieve of Eratosthenes.

Input:
The first line of the input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input containing N.

Output:
For all testcases, in a new line, print all the prime numbers upto or equal to N.

Constraints:
1 <= T<= 100
1 <= N <= 104

Example:
Input:
2
10
35
Output:
2 3 5 7
2 3 5 7 11 13 17 19 23 29 31
*/

#include <bits/stdc++.h>
using namespace std;

void seive(int n)
{
    bool seive[n + 1];
    fill(seive, seive + n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (seive[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                seive[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (seive[p] == true)
            cout << p << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        seive(n);
        cout << endl;
    }

    return 0;
}
