Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.







class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int p1p2=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        int p2p3=(p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]);
        int p3p4=(p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]);
        int p4p1=(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1]);
        int p1p3=(p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]);
        int p2p4=(p2[0]-p4[0])*(p2[0]-p4[0])+(p2[1]-p4[1])*(p2[1]-p4[1]);

        set<int>s;
        s.insert(abs(p1p2));
        s.insert(abs(p2p3));
        s.insert(abs(p3p4));
        s.insert(abs(p4p1));
        s.insert(abs(p1p3));
        s.insert(abs(p2p4));

        set<pair<int, int>> p;
        p.insert({p1[0], p1[1]});
        p.insert({p2[0], p2[1]});
        p.insert({p3[0], p3[1]});
        p.insert({p4[0], p4[1]});

        if(s.size()==2 && p.size()==4) return true;

        return false;
    }
};

/*
In each case, after sorting, we obtain the following conclusion regarding the connections of the points:
p_0p_1p 0 ​ p 1 ​ , p_1p_3p 1 ​ p 3 ​ , p_3p_2p 3 ​ p 2 ​ and p_2p_0p 2 ​ p 0 ​
form the four sides of any valid square.
p_0p_3p 0 ​ p 3 ​ and p_1p_2p 1 ​ p 2 ​ form the diagonals of the square.
Thus, once the sorting of the points is done, based on the above knowledge,
we can directly compare p_0p_1p 0 ​ p 1 ​ , p_1p_3p 1 ​ p 3 ​ , p_3p_2p 3 ​ p 2 ​ and p_2p_0p 2 ​ p 0 ​
 for equality of lengths(corresponding to the sides); and p_0p_3p 0 ​ p 3 ​ and p_1p_2p 1 ​ p 2 ​
    for equality of lengths(corresponding to the diagonals).
*/
