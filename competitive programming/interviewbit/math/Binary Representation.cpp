Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110







string Solution::findDigitsInBinary(int n) {
    string res;
    if(n==0) res.push_back(0+'0');
    while(n){
        int tmp=n%2;
        n/=2;
        res.push_back(tmp+'0');
    }
    reverse(res.begin(), res.end());
    return res;
}
