In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false´
Explanation: No possible partition.
Example 3:

Input: deck = [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: deck = [1,1]
Output: true
Explanation: Possible partition [1,1].
Example 5:

Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].


Constraints:

1 <= deck.length <= 10^4
0 <= deck[i] < 10^4









class Solution {
public:

    int gcdd(int a, int b){
        if(a==0) return b;
        return gcdd(b%a, a);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;  // <number , frequency>
        int n=deck.size();
        for(int i=0;i<n;i++){
            mp[deck[i]]++;
        }
        int gcd=mp.begin()->second;  // first frequency

        for(auto it=mp.begin(); it!=mp.end(); it++){
            gcd=gcdd(gcd, it->second);  // get gcd
        }

        return gcd>=2;
    }
};
