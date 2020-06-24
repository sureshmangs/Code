You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.





Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false


Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.





class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        int n=coords.size();
        if(n<=2) return true;
        int x1=coords[0][0];
        int y1=coords[0][1];
        int x2=coords[1][0];
        int y2=coords[1][1];
        double dy=y2-y1;
        double dx=x2-x1;
        for(int i=0;i<n-1;i++){
            x1=coords[i][0];
            y1=coords[i][1];
            x2=coords[i+1][0];
            y2=coords[i+1][1];
            int tdy=y2-y1;
            int tdx=x2-x1;
            if(dy*tdx!=dx*tdy) return false;
        }
        return true;
    }
};
