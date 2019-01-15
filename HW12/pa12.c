#include <stdio.h>
#include <stdlib.h>
#include "pa12.h"

void insertFirst(struct node** head, struct node*n);
void deleteAt(struct node** head,int index);
int getLength(struct node** head);


#ifndef INIT
//head: the head of the singly linkedlist.
//length: the length of the singly linkedlist.
//This function will create and initialize the singly linkedlist with length=length, 
//The values of the nodes within the singly linkedlist will be the same as array indices.
//For example, if the singly linkedlist length is 4, the values of the nodes will be 0 1 2 3

void init(struct node **head,int length)
{
	//if(head == NULL)
	// {
	// return;
	//}  
	/* int i = 0;
	   struct node* temp = *head;
	   temp -> next =NULL;
	   while(i < length)
	   {
	   temp -> next = malloc(sizeof*(temp -> next));
	   temp = temp -> next;
	   temp -> value = i;
	   temp -> next = NULL;
	   }
	   temp = *head;*/


	int i = 0;
	struct node* n = malloc(sizeof(n));
	while(i< length){
		n->value=length-i-1;
		insertFirst(head, n);

		i++;



	}
	free(n);
}

void insertFirst(struct node** head,struct node * n)
{       
	if(head==NULL){
		return;
	}
	struct node *temp=malloc(sizeof(temp));
	temp->value=n->value;
	temp->next=*head;
	*head=temp;
}
#endif





#ifndef PRINT
//head: the head of the singly linkedlist.
//This function will print the values of the nodes within the singly linkedlist.
//For example, if the values of the nodes within the singly linkedlist are 1 5 6 8 9 10, this function will print 1,5,6,8,9,10
//Note: there is no extra comma nor at the beginning nor at the end.
void print(struct node **head)
{
	struct node *temp=*head;
	if (head == NULL)
	{
		return;
	}
	while(temp!=NULL){
		if(temp -> next == NULL)
		{
			printf("%d", temp -> value);
		}
		else
		{ 
			printf("%d,",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");	




}
#endif

#ifndef JOSPI
//head: the head of the singly linkedlist.
//k : this variable will be used for counting if count = k, the element will be out.
//p : this variable will be used for printing if the number of remaining elements/nodes is divisible by p (call the print function).
//length: the length of the singly linkedlist.
//This function will solve the josephus problem using the singly linkedlist.
void josp(struct node ** head,int k,int p,int length)
{
	//printf("%d",p);
	//int i=0;
	int skip=k;

	while(length>0){

		if(skip>=length){
			skip=skip-length;
		}


		else{
			deleteAt(head,skip);
			length--;
			if(length%p==0){
				if(length!=0){
					print(head);
				}
			}
			skip+=k;		
		}
	}
}

#endif
void deleteAt(struct node** head,int index)
{       
	struct node *h = malloc(sizeof(h));
	struct node* temp=*head;
	if(index < 0)
	{ 
		return;
	}
	if(temp ==NULL)
	{ 
		return;
	}

	if(getLength(head)<=index){
		return;
	}
	if(index==0){
		temp=temp->next;
		*head=temp;
		return;
	}
	int i=0;
	while(i<index-1){
		temp=temp->next;
		i++;
	}
	h=temp->next->next;
	temp->next=h;

}
int getLength(struct node** head)
{
	int length=0;
	struct node* temp=*head;
	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	return length;
}


#ifndef INITII
//head: the head of the doubly linkedlist.
//length: the length of the doubly linkedlist.
//This function will create and initialize the doubly linkedlist with length=length, 
//The values of the nodes within the doubly linkedlist will be the same as array indices.
//For example, if the doubly linkedlist length is 4, the values of the nodes will be 0 1 2 3
//NOTE: this is a doubly linkedlist you should assign the prev pointer for each node probably.
//NOTE: head->prev is NULL as well as tail->next.

void init2(struct dnode ** head,int length)
{



}
#endif


#ifndef PRINTII
//head: the head of the doubly linkedlist.
//This function will print the values of the nodes within the doubly linkedlist.
//For example, if the values of the nodes within the doubly linkedlist are 1 5 6 8 9 10, this function will print 1,5,6,8,9,10
//Note: there is no extra comma nor at the beginning nor at the end.
void print2(struct dnode ** head)
{



}

#endif


#ifndef JOSPII
//head: the head of the doubly linkedlist.
//k : this variable will be used for counting if count = k, the element will be out.
//q : this variable will be used for flipping the direction. If while counting, the value of the node is divisible by q,
//you will take the node out, flip the direction, and continue counting.
//length: the length of the doubly linkedlist.
//This function will solve the modified josephus problem using the doubly linkedlist.
//NOTE: you should call the print2() function after any delete operation.
void josp2(struct dnode **head, int k, int q,int length)
{


}

#endif




