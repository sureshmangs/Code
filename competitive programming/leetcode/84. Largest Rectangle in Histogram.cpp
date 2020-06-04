Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.




Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].




The largest rectangle is shown in the shaded area, which has area = 10 unit.



Example:

Input: [2,1,5,6,2,3]
Output: 10





class Solution {
public:

    vector<int> nsl(vector<int>a, int n){
    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(s.empty()) v.push_back(-1);
        else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
        else if(!s.empty() && a[s.top()]>=a[i]){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
                 if(s.empty()) v.push_back(-1);
                 else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
            }
        }
        s.push(i);
    }
    return v;
}

vector<int> nsr(vector<int>a, int n){
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()) v.push_back(n);
        else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
        else if(!s.empty() && a[s.top()]>=a[i]){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
                 if(s.empty()) v.push_back(n);
                 else if(!s.empty() && a[s.top()]<a[i]) v.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}


    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        vector<int>left=nsl(heights,n);
        vector<int>right=nsr(heights,n);
        vector<int> width;
        for(int i=0;i<n;i++){
            width.push_back(right[i]-left[i]-1);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(width[i]*heights[i] > maxi) maxi=width[i]*heights[i];
        }
        return maxi;
    }
};
