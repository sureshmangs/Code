#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int size,sum,val;
        cin>>size>>sum;
        vector <int> v;
        for (int i = 0; i < size; i++)
        {
            cin>>val;
            v.push_back(val);
        }
        unordered_set<int> set;
        for (auto i : v)
        {
            set.insert(i);
        }
        bool check = false;
        for(auto i : v)
        {
            if(i<sum)
            {
                int dif = sum-i;
                if(set.find(dif)!=set.end())
                {
                    check = true;
                    cout<<"Yes";
                    break;
                }
            }
        }
        if(check==false)
            cout<<"No";
        cout<<endl;
    }
}

// 5 4
1 2 5 6 7
