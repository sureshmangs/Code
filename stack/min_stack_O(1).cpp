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

int minx;

void push(int x)
{
     if(s.empty()){
       s.push(x);
       minx=x;
   } else{
       if(x>=minx) s.push(x);
       else {
           s.push(2*x-minx);
           minx=x;
       }
   }
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
{
    if(s.empty()) return -1;
   if(s.top() >= minx){ int tmp=s.top();   s.pop(); return tmp; }
   else {
       int tmp=minx;
       minx=2*minx-s.top();
       s.pop();
       return tmp;
   }
}

int getMin()
{
    if(s.empty()) return -1;
   else return minx;
}


int getTop(){
    if(s.empty()) return -1;
    if(s.top()>= minx) return s.top();
    else return minx;
}
