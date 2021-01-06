/*
Argus was charged with guarding Io, which is not an ordinary cow. Io is quite an explorer, and she wanders off rather frequently, making Argus' life stressful. So the cowherd decided to construct an enclosed pasture for Io.

There are n trees growing along the river, where Argus tends Io. For this problem, the river can be viewed as the OX axis of the Cartesian coordinate system, and the n trees as points with the y-coordinate equal 0. There is also another tree growing in the point (0,1).

Argus will tie a rope around three of the trees, creating a triangular pasture. Its exact shape doesn't matter to Io, but its area is crucial to her. There may be many ways for Argus to arrange the fence, but only the ones which result in different areas of the pasture are interesting for Io. Calculate the number of different areas that her pasture may have. Note that the pasture must have nonzero area.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. Then t test cases follow, each one is described in two lines.

In the first line of each test case there is a single integer n (1≤n≤50) denoting the number of trees growing along the river. Next line contains n distinct integers x1<x2<…<xn−1<xn (1≤xi≤50), the x-coordinates of trees growing along the river.

Output
In a single line output an integer, the number of different nonzero areas that triangles with trees as vertices may have.

Example
inputCopy
8
4
1 2 4 5
3
1 3 5
3
2 6 8
2
1 2
1
50
5
3 4 5 6 8
3
1 25 26
6
1 2 4 8 16 32
outputCopy
4
2
3
1
0
5
3
15
Note
In the first test case, we have 6 non-degenerate triangles with the following areas: 0.5, 0.5, 1, 1.5, 1.5 and 2. The pasture can have 4 different areas, and thus 4 is the answer.

In the second test case, we have 3 non-degenerate triangles with the following areas: 1, 1 and 2. The pasture can have 2 different areas, so 2 is the answer.

The following two drawings present the situation in the second test case. The blue triangles in the first drawing have area 1. The red triangle in the second drawing has area 2.
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        set<int> s;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                s.insert(v[j]-v[i]);
            }
        }

        cout<<s.size()<<endl;


    }

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        int x1=0, y1=1;
        unordered_map<string, int> m;

        for(int i=0;i<n-1;i++){
            int x2=v[i];
            for(int j=i+1;j<n;j++){
                int x3=v[j];

                double a = sqrt(x2*x2 + 1);
                double b = sqrt(x3*x3 + 1);
                double c = sqrt((x3-x2)*(x3-x2));

                double s = (double)(a+b+c)/2;
                string area = to_string((double)sqrt(s*(s-a)*(s-b)*(s-c)));
                m[area]++;
            }
        }
        int cnt=0;
        for(auto it=m.begin(); it!=m.end(); it++) cnt++;
        cout<<cnt<<endl;
    }

    return 0;
}
*/
