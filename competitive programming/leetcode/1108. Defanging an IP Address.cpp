Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".



Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"


Constraints:

The given address is a valid IPv4 address.


class Solution {
public:
    string defangIPaddr(string address) {
           string res;
           string tmp="[.]";
           int n=address.length();
            for(int i=0;i<n;i++){
                if(address[i]=='.'){
                    res+=tmp;
                }  else res+=address[i];
            }
            return res;
    }
};



class Solution {
public:
    string defangIPaddr(string address) {
        int n=address.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(address[i]=='.') cnt++;
        }
        int last=n+(cnt*2);
        while(cnt--){
            address+="  ";
        }
        for(int i=n-1,j=last-1; i>=0;i--){
            if(address[i]=='.'){
                address[j]=']';
                address[j-1]='.';
                address[j-2]='[';
                j-=3;
            } else {
                 address[j]=address[i];
                j-=1;
            }
        }
        return address;
    }
};
