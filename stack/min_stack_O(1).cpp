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


/*
How does this approach work?
When element to be inserted is less than minEle, we insert “2x – minEle”.
The important thing to notes is, 2x – minEle will always be less than x (proved below),
i.e., new minEle and while popping out this element we will see that something unusual has happened as the popped element is less than the minEle.
So we will be updating minEle.

How 2*x - minEle is less than x in push()?
x < minEle which means x - minEle < 0

// Adding x on both sides
x - minEle + x < 0 + x

2*x - minEle < x

We can conclude 2*x - minEle < new minEle
While popping out, if we find the element(y) less than the current minEle, we find the new minEle = 2*minEle – y.

How previous minimum element, prevMinEle is, 2*minEle - y
in pop() is y the popped element?

 // We pushed y as 2x - prevMinEle. Here
 // prevMinEle is minEle before y was inserted
 y = 2*x - prevMinEle

 // Value of minEle was made equal to x
 minEle = x .

 new minEle = 2 * minEle - y
            = 2*x - (2*x - prevMinEle)
            = prevMinEle // This is what we wanted

Similar approach can be used to find the maximum element as well.
Implement a stack that supports getMax() in O(1) time and constant extra space.

Source: GeeksForGeeks
*/

