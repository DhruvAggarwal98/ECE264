#include <stdio.h>
#include <stdlib.h>
#include "pe11.h"

#ifndef PRINT
void print(struct node** head)
{
	struct node *temp=*head;
   	FILE* lp = fopen("a.txt","w+"); 
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
	fclose(lp);
}
#endif

#ifndef INSF
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

#ifndef INSA
void insertAt(struct node** head,struct node * n,int index)
{
	if(getLength(head)<index){
        return;
    }
	if(index < 0){
	  return;
	}
    int i=0;
    struct node *h = malloc(sizeof(h));
    h->value=n->value;
    if(head ==NULL)
      {
	return;
      }
    struct node* temp=*head;
    if(index==0){
        h->next=temp;
        *head=h;
        return;
    }
    for(i=0;i<index-1;i++){
            temp=temp->next;
    }
    h->next=temp->next;
    temp->next=h;
    
}
#endif

#ifndef INSL
void insertLast(struct node** head,struct node *n)
{
	  struct node *temp=malloc(sizeof(temp));
    temp->next=NULL;
    temp->value=n->value;
    struct node* h=*head;
    if(head==NULL){
      return;
    }
    if(getLength(head)==0){
      insertFirst(head,n);
      return;
    }
    struct node * p=h;
    while((p->next)!=NULL){
        p=p->next;
    }
    p->next=temp;
    *head=h;	
}
#endif

#ifndef DELFM
void deleteFirstMatch(struct node**head,int value)
{
  struct node *h = malloc(sizeof(h));
    struct node* temp=*head;
    if(temp == NULL){
      return;
    }


    if(value==temp->value){
        temp=temp->next;
        *head=temp;
        return;
    }
    if(value!=temp->value&&temp->next==NULL){
      return;
    }
    while(value!=temp->next->value){
        if(temp->next->next==NULL){
            return;
        }
        temp=temp->next;
        
    }
    h=temp->next->next;
    temp->next=h;
	
}
#endif

#ifndef DelA
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
#endif

#ifndef DELAM
void deleteAllMatches(struct node** head,int value)
{
	struct node* temp = *head, *prev = NULL;
	if(head == NULL)
	  {
	    return;
	  }
	while (temp != NULL && temp->value == value){
            *head = temp->next;
            free(temp);
            temp = *head;
        }
        while (temp != NULL){
            while(temp != NULL && temp->value != value){
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }


}
#endif

#ifndef L
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
#endif

#ifndef FREEMEM
void freeMemory(struct node** head)
{
	struct node* temp;
	while(*head != NULL)
	{
		temp = *head;
		*head = (*head) -> next;
		free(temp); 
	}

 	

}
#endif
