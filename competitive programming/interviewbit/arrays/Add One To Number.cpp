Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.











vector<int> Solution::plusOne(vector<int> &a) {
    int n=a.size();
      vector<int>res;
    if(n==0){
        res.push_back(1); return res;
    }
    int carry=1; // initially adding one
    for(int i=n-1;i>=0;i--){
        int tmp=a[i]+carry;
        if(tmp>=10){
            carry=1;
            tmp%=10;
        } else carry=0;
        res.push_back(tmp);
    }
    if(carry) res.push_back(1);
    for(int i=res.size()-1; i>=0;i--){
        if(res[i]==0){
            res.erase(res.begin()+i);
        } else break;
    }
    reverse(res.begin(), res.end());
    return res;
}
