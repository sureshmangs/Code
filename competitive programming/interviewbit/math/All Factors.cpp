Given a number N, find all factors of N.

Example:

N = 6
factors = {1, 2, 3, 6}
Make sure the returned array is sorted








vector<int> Solution::allFactors(int n) {
    vector<int> res, tmp;
    if(n==0){
        res.push_back(0);
        return res;
    }
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if((i*i)!=n) tmp.push_back(n/i);
        }
    }
    int k=tmp.size();
    for(int i=k-1;i>=0;i--)
        res.push_back(tmp[i]);
    return res;
}
