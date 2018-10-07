#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* n){
	struct node* p = n;
	while(p!=NULL){
		printf("%d\n",p->data);
		p = p->next;
	}
}

void dele(struct node** head,int h){
	struct node* t = *head,*prev;
	if(t->data==h){
		*head = t->next;
		free(t);
	}
	else{
		while((t->next!=NULL)&&(t->data!=h)){
			prev = t;
			t = t->next;
		}
		if(t->data==h){
			if(t->next==NULL){
				prev->next = NULL;
				free(t);
			}
			else{
				prev->next = t->next;
				free(t);
			}
		}
		else{
			printf("element not present in the list\n");
		}
	}
}

void del_pos(struct node** head,int pos){
	struct node* t = *head,*prev;
	if(pos==0){
		*head = (*head)->next;
		free(t);
	}
	else{
		for(int i=0;i<pos;i++){
			if((t->next==NULL)&&(i<pos)){
				printf("element not present in the list\n");
				return;
			}
			else{
				prev = t;
				t = t->next;
			}
		}
		prev->next = t->next;
		free(t);
	}
}

int coun(struct node** head){
	struct node* t = *head;
	int c = 0;
	while(t!=NULL){
		c++;
		t = t->next;
	}
	return c;
}

int coun1(struct node** head){
	struct node* t = *head;
	int c = 0;
	if(t==NULL){
		return 0;
	}
	else{
		return (1+coun1(&(t->next)));
	}
}

void push(struct node** head,int h){
	struct node* ele = (struct node*)malloc(sizeof(struct node));
	ele->data = h;
	ele->next = *head;
	*head = ele;
}

void append(struct node** head,int h){
	struct node* ele = (struct node*)malloc(sizeof(struct node));
	ele->data = h;
	ele->next = NULL;
	if(*head==NULL){
		*head = ele;
	}
	else{
		struct node* last = *head;
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = ele;
	}
}

void merge(struct node** head,struct node** head1,struct node** answer){
	struct node *i1,*i2,*prev;
	if((*head)->data <= (*head1)->data){
			*answer = *head;
			prev = *head;
			i1 = (*head)->next;
			i2 = *head1;
		}
	else{
		*answer = *head1;
		prev = *head1;
		i2 = (*head1)->next;
		i1 = *head;
	}
	while((i1!=NULL)&&(i2!=NULL)){
		if(i1->data <= i2->data){
			prev->next = i1;
			prev = i1;
			i1 = i1->next;
		}
		else{
			prev->next = i2;
			prev = i2;
			i2 = i2->next;
		}
	}
	if(i1==NULL){
		prev->next = i2;
	}
	else{
		prev->next = i1;
	}
}

void insertafter(struct node* prev,int h){
	struct node* ele = (struct node*)malloc(sizeof(struct node));
	ele->data = h;
	if(prev==NULL){
		printf("\nprevious node should not be NULL\n");
	}
	ele->next = prev->next;
	prev->next = ele;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct node* head = NULL;
	struct node* head1 = NULL;
	struct node* answer = NULL;
	push(&head,6);
	push(&head,4);
	push(&head,3);
	push(&head1,9);
	push(&head1,5);
	push(&head1,1);
	merge(&head,&head1,&answer);
	printlist(answer);
}