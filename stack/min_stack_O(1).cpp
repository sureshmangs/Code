/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the number of integers in a sequence. In the second line are n space separated integers of the stack.

Output Format:
For each testcase, in a new line, print the minimum integer from the stack.

Your Task:
Since this is a function problem, you don't need to take inputs. You just have to complete 5 functions, push() which takes an integer x as input and pushes it into the stack; pop() which pops out the topmost element from the stack; isEmpty() which returns true/false depending upon whether the stack is empty or not; isFull() which takes the size of the stack as input and returns true/false depending upon whether the stack is full or not (depending upon the given size); getMin() which returns the minimum element of the stack.

Expected Time Complexity: O(1) for all the 5 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
1
5
18 19 29 15 16
Output:
15
*/








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
