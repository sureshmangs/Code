A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.



Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false


Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100








// Using Herons Formula
// If area of triangle is zero, => collinear

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1=points[0][0];
        int y1=points[0][1];
        int x2=points[1][0];
        int y2=points[1][1];
        int x3=points[2][0];
        int y3=points[2][1];

        double a = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double b = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        double c = sqrt((x1-x3)*(x1-x3)+(y3-y1)*(y3-y1));

        double s = (a+b+c)/2;

        double area = sqrt(s*(s-a)*(s-b)*(s-c));

        return area ? true: false;

    }
};
