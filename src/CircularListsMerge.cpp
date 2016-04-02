/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>
int Merge(struct node **l1, struct node **l2);
struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	if (head1 == NULL || head2 == NULL) return -1;
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int count = 0;
	count = Merge(head1, head2);
	return count;
}
int Merge(struct node **l1, struct node **l2){
	struct node *p1, *p2, *Endref1, *Endref2, *finish, *headfinsh;
	int count = 0;
	finish = NULL;
	Endref1 = *l1;
	Endref2 = *l2;
	int one = 0, two = 0;
	p1 = *l1;
	p2 = *l2;
	int flag = 0;

	//Init pointing to lowest value
	if (p1->data < p2->data){
	finish = p1;
	headfinsh = finish;
	p1 = p1->next;
	count++;
	}
	else {
	finish = p2;
	headfinsh = finish;
	p2 = p2->next;
	count++;
	}

	while (1){
	if (p1->data > p2->data){
		finish->next = p2;
		count++;
		finish = finish->next;
		p2 = p2->next;
	if (p2 == Endref2) break;
	}
	else{
		finish->next = p1;
		count++;
	finish = finish->next;
	p1 = p1->next;
	if (p1 == Endref1) break;
	}
	}

	if (p1 == Endref1){
		finish->next = p2; two = 1;

	}
	else {
		finish->next = p1;
		one = 1;
	}

	if (one == 1){
		while (finish->next != Endref1)
		{
			finish = finish->next;
			count++;
		}
	}
	else
	{
		while (finish->next != Endref2)
		{
			finish = finish->next;
			count++;
		}
	}

	// making cicular LL
	finish->next = headfinsh;
	
	// making head1 point to new CLL
	l1 = &headfinsh;
	return count;
}
