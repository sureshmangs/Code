#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();


stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}

stack<int>ss;

void push(int a)
{
     s.push(a);
     if(ss.empty() || ss.top() >= a) ss.push(a);
}

bool isFull(int n)
{
     if(s.size()==n) return true;
     else return false;
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{   if(s.empty()) return -1;
    if(s.top()==ss.top()) ss.pop();
    s.pop();
}

int getMin()
{
   if(!s.empty()) return ss.top();
   else return -1;
}
