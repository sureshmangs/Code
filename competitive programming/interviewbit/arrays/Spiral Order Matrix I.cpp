Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]






vector<int> Solution::spiralOrder(const vector<vector<int> > &ar) {
    int m=ar.size();
    int n=ar[0].size();
    vector<int>res;
    int t=0, b=m-1, l=0, r=n-1;
    int dir=0;  // direction r d l u
    while(t<=b && l<=r){
        if(dir==0){
            for(int i=l; i<=r;i++) res.push_back(ar[t][i]);
            t++;
            dir=1;
            continue;
        }
        if(dir==1){
            for(int i=t; i<=b;i++) res.push_back(ar[i][r]);
            r--;
            dir=2;
             continue;
        }
        if(dir==2){
            for(int i=r; i>=l; i--) res.push_back(ar[b][i]);
            b--;
            dir=3;
             continue;
        }
        if(dir==3){
            for(int i=b; i>=t;i--) res.push_back(ar[i][l]);
            l++;
            dir=0;
             continue;
        }
    }
    return res;
}
