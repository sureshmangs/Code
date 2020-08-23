/*
Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL

Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL
*/





#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int data;
	Node* next;
};


Node *reverse (Node *head, int k){
	Node* current = head;
	Node* ahead = NULL;
	Node* prev = NULL;
	int count = 0;

	// reverse first k nodes of the linked list
	while (current != NULL && count < k)
	{
		ahead = current->next;
		current->next = prev;
		prev = current;
		current = ahead;
		count++;
	}

	// ahead is now a pointer to (k+1)th node
	// Recursively call for the list starting from current.
	// And make rest of the list as next of first node */
	if (ahead != NULL)
        head->next = reverse(ahead, k);

	// prev is new head of the input list
	return prev;
}


void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *node){
	while (node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
}


int main(){
	Node* head = NULL;

	// 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"Given linked list \n";
	printList(head);
	head = reverse(head, 3);

	cout<<"\nReversed Linked list \n";
	printList(head);

	return(0);
}





/*
we have used a stack which will store the nodes of the given linked list.
Firstly, push the k elements of the linked list in the stack.
Now pop elements one by one
*/
