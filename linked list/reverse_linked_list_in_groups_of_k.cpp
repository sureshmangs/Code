/*
Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL

Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL
*/






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









/*
we have used a stack which will store the nodes of the given linked list.
Firstly, push the k elements of the linked list in the stack.
Now pop elements one by one
*/
