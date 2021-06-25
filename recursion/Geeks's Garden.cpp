/*
Geek has a rosarium and it has N*M slots, some of them are empty and some of them have roses. Given N*M character array consists of 0's and 1's. 0 represents an empty spot and 1 represents a rose. The task is to find the maximum number of adjacent roses in geek's rosarium. For a spot (i, j) adjacent spots are (i+1, j), (i-1, j), (i, j-1), (i, j+1), (i-1, j-1), (i-1, j+1), (i+1, j-1),  and (i+1, j+1).

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines consist of M characters.

Output: For each test case, print the maximum number of adjacent roses.

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. '0' <= arr[i][j] <= '1'

Example:
Input:
2
2 2
10
01
3 4
1001
0011
0101

Output:
2
5
*/




#include<bits/stdc++.h>
using namespace std;

#define MAX 100

pair <int, int> dir[] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void solve(int i, int j, int a[MAX][MAX], int n, int m, int &cnt, bool vis[MAX][MAX]) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true || a[i][j] == 0) return;
    
    vis[i][j] = true;
    cnt++;
    
    for (auto &it: dir) {
        solve(i + it.first, j + it.second, a, n, m, cnt, vis);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        int a[MAX][MAX];
        
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int k = 0;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[k++] - '0';
            }
        }
        
        bool vis[MAX][MAX];
        memset(vis, false, sizeof(vis));
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    int cnt = 0;
                    solve(i, j, a, n, m, cnt, vis);
                    res = max(res, cnt);
                }
            }
        }
        
        cout << res << "\n";
    }


return 0;
}
