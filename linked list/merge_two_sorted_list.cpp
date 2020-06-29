/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains N and M, and next two line contains N and M sorted elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N, M <= 104
1 <= Node's data <= 105

Example:
Input:
2
4 3
5 10 15 40
2 3 20
2 2
1 1
2 4
Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
Testcase 2: After merging the given two linked list , we have 1, 1, 2, 4 as output.
*/






// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);


/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends




/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* h1, Node* h2)
{
    if(!h1) return h1;
    if(!h2) return h1;

    struct Node *start=(struct Node*)malloc(sizeof(struct Node)); // dummy
    struct Node *tail=start;

    while(h1 && h2){
        if(h1->data <= h2->data){
            tail->next=h1;
            tail=tail->next;
            h1=h1->next;
        } else {
            tail->next=h2;
            tail=tail->next;
            h2=h2->next;
        }
    }
    if(h1){
        tail->next=h1;
    }
    if(h2){
        tail->next=h2;
    }

    return start->next;
}
