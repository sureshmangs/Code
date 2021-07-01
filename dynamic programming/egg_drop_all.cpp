You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at 
a floor higher than f will break, and any egg dropped at or below floor f will not break.


Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). 
If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
 

Constraints:

1 <= k <= 100
1 <= n <= 104





// Recursive (TLE)

class Solution {
public:
    // e=eggs  f=floor
    int superEggDrop(int e, int f) {
        if (e == 1 || e == 0) return f;
        if (f == 0 || f == 1) return f;
        
        int mini = INT_MAX;
        
        for (int k = 1; k <= f; k++){
            int tmp = 1 + max(superEggDrop(e - 1, k - 1), superEggDrop(e, f - k));
            if (tmp < mini) mini = tmp;
        }
        return mini;
    }
};















// Recursion Memoization (TLE)

class Solution {
public:
    vector <vector<int>> dp;
    
    int eggDrop(int e, int f){
        if (e == 1 || e == 0) return f;
        if (f == 0 || f == 1) return f;
        
        if (dp[e][f] != -1) return dp[e][f];
        
        int mini = INT_MAX;
        
        int egb, egnb;
        
        for (int k = 1; k <= f; k++){
            if (dp[e - 1][k - 1] != -1) egb = dp[e - 1][k - 1];
            else {
                egb = eggDrop(e - 1, k - 1);
                dp[e - 1][k - 1] = egb;
            }
            if (dp[e][f - k] != -1) egnb = dp[e][f - k];
            else {
                egnb = eggDrop(e, f - k);
                dp[e][f - k] = egnb;
            }

            int tmp = 1 + max(egb, egnb);
            if(tmp < mini) mini = tmp;
        }
        return dp[e][f] = mini;
    }
    
    
    // e = egg, f = floor
    int superEggDrop(int e, int f) {
        dp.resize(e + 1, vector <int> (f + 1, -1));
        
        return eggDrop(e, f);
    }
};
















// Recursive Memoization + Binary Search (Accepted)

class Solution {
public:
    
    vector <vector<int>> dp;
    
    int eggDrop(int e, int f){
        if (e == 1 || e == 0) return f;
        if (f == 0 || f == 1) return f;
        
        if (dp[e][f] != -1) return dp[e][f];
        
        int mini = INT_MAX;
        
        int start = 1, end = f;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            int egb = eggDrop(e - 1, mid - 1);  //egg broken check for down floors of mid (left)
            int egnb = eggDrop(e, f - mid); // not broken check for up floors of mid (right)
            
            int tmp = 1 + max(egb, egnb);   //store max of both 
            
            if (egb < egnb) {           // since right is more than left and we need more in worst case 
                start = mid + 1;        // so start = mid + 1; to gain more temp for worst case : upward
            } else {
                end = mid - 1;          //left > right so we will go downward 
            }
            
            mini = min(mini, tmp);
        }
        
        return dp[e][f] = mini;
    }
    
    int superEggDrop(int e, int f) {
        dp.resize(e + 1, vector <int> (f + 1, -1));
        
        return eggDrop(e, f);
    }
};














// DP (TLE)

class Solution {
public:
    int superEggDrop(int e, int f) {
         int dp[e + 1][f + 1];
        
        for (int i = 0; i < e + 1; i++){
            dp[i][0] = 0; // 0 floors
            dp[i][1] = 1; // 1 floor
        } 
        for (int j = 1; j < f + 1; j++){
            dp[0][j] = 0;  // 0 egg
            dp[1][j] = j;
        }
        
        for (int i = 2; i < e + 1; i++){
            for (int j = 2; j < f + 1; j++){
                dp[i][j] = INT_MAX;
                for( int x = 1; x <= j; x++){
                    int tmp = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                    if (tmp < dp[i][j]) dp[i][j] = tmp;
                }
            }
        }
        return dp[e][f];
    }
};




















// DP + Binary Search (Accepted)

class Solution {
public:
    int superEggDrop(int e, int f) {
        if (e == 1 || e == 0) return f;
        if (f == 0 || f == 1) return f;
        
        int dp[e + 1][f + 1];
        
        for (int i = 0; i < e + 1; i++){
            dp[i][0] = 0; // 0 floors
            dp[i][1] = 1; // 1 floor
        } 
        for (int j = 1; j < f + 1; j++){
            dp[0][j] = 0;  // 0 egg
            dp[1][j] = j;
        }
        
        
        for (int i = 2; i < e + 1; i++){
            for(int j = 2; j < f + 1; j++){
                int mini = INT_MAX;
                int start = 1, end = j;
        
                while (start <= end) {
                    int mid = start + (end - start) / 2;

                    int egb = dp[i - 1][mid - 1];  //egg broken check for down floors of mid (left)
                    int egnb = dp[i][j - mid]; // not broken check for up floors of mid (right)

                    int tmp = 1 + max(egb, egnb);   //store max of both 

                    if (egb < egnb) {           // since right is more than left and we need more in worst case 
                        start = mid + 1;        // so start = mid + 1; to gain more temp for worst case : upward
                    } else {
                        end = mid - 1;          //left > right so we will go downward 
                    }

                    mini = min(mini, tmp);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[e][f];
    }
};
