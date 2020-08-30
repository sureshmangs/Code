You are given K eggs, and you have access to a building with N floors from 1 to N.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N).

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?



Example 1:

Input: K = 1, N = 2
Output: 2
Explanation:
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4


Note:

1 <= K <= 100
1 <= N <= 10000






// DP (TLE)

class Solution {
public:
    // k=e=egg  n=f=floor
    int superEggDrop(int e, int f) {
        int dp[e+1][f+1];

        for(int i=0;i<e+1;i++){
            dp[i][0]=0; // 0 floors
            dp[i][1]=1; // 1 floor
        }
        for(int j=1;j<f+1;j++){
            dp[0][j]=0;  // 0 egg
            dp[1][j]=j;
        }

        for(int i=2;i<e+1;i++){
            for(int j=2;j<f+1;j++){
                dp[i][j]=INT_MAX;
                for(int x=1;x<=j;x++){
                    int tmp=1+max(dp[i-1][x-1], dp[i][j-x]);
                    if(tmp<dp[i][j]) dp[i][j]=tmp;
                }
            }
        }
        return dp[e][f];
    }
};




// Recursive (Memoized) (TLE)

class Solution {
public:
    int dp[101][10001];  // according to the constraints

    int eggDrop(int e, int f, int dp[][10001]){
        if(e==1 || e==0) return f;
        if(f==0 || f==1) return f;

        if(dp[e][f]!=-1) return dp[e][f];

        int mini=INT_MAX;
        int egb, egnb;
        for(int k=1;k<=f;k++){
            if(dp[e-1][k-1]!=-1) egb=dp[e-1][k-1];
            else {
                egb=eggDrop(e-1, k-1, dp);
                dp[e-1][k-1]=egb;
            }
            if(dp[e][f-k]!=-1) egnb=dp[e][f-k];
            else {
                egnb=eggDrop(e, f-k, dp);
                dp[e][f-k]=egnb;
            }

            int tmp = 1 + max(egb, egnb);
            if(tmp<mini) mini=tmp;
        }
        return dp[e][f]=mini;
    }


    // k=e=eggs  n=f=floor
    int superEggDrop(int e, int f) {
        memset(dp, -1, sizeof(dp));
        return eggDrop(e, f, dp);
    }
};

