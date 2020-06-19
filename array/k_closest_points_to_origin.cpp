/*
Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

Note: The distance between two points on a plane is the Euclidean distance.

Examples:

Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2
Output : [[3, 3], [-2, 4]]
Square of Distance of origin from this point is
(3, 3) = 18
(5, -1) = 26
(-2, 4) = 20
So rhe closest two points are [3, 3], [-2, 4].

Input : point = [[1, 3], [-2, 2]], K  = 1
Output : [[-2, 2]]
Square of Distance of origin from this point is
(1, 3) = 10
(-2, 2) = 8
So the closest point to origin is (-2, 2)
*/





#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int, pair<int, int> > > maxh;   // max heap
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            maxh.push({dist, {x, y} });
            if(maxh.size()>k) maxh.pop();
        }
        int i=0;
        vector<vector<int> > res;
        while(!maxh.empty()){
            pair<int, int> p=maxh.top().second;
            maxh.pop();
            int x=p.first;
            int y=p.second;
            res.push_back({x, y});
        }
        return res;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > points;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            points.push_back({x,y});
        }
        int k;
        cin>>k;
        vector<vector<int> > res;
        res=kClosest(points, k);
        for(int i=0; i<k;i++){
            cout<<res[i][0]<<" "<<res[i][1]<<endl;
        }
    }
}
