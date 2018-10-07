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

void insertafter(struct node* prev,int h){
	struct node* ele = (struct node*)malloc(sizeof(struct node));
	ele->data = h;
	if(prev==NULL){
		printf("\nprevious node should not be NULL\n");
	}
	ele->next = prev->next;
	prev->next = ele;
}

bool detect(struct node** head){
	struct node* one,*twice;
	one = (*head)->next;
	twice = (*head)->next->next;
	if((*head==NULL)||((*head)->next==NULL)||((*head)->next->next==NULL)){
		return false;
	}
	else{
		one = (*head)->next;
		twice = (*head)->next->next;
	}
	while((one!=twice)&&(twice!=NULL)){
		if(twice->next->next){
			twice = twice->next->next;
		}
		else{
			twice = twice->next;
		}
		one = one->next;
	}
	if(twice==NULL){
		return false;
	}
	else{
		return true;
	}
}

bool loop(struct node* head){
	unordered_set<struct node*> s;
	while(head!=NULL){
		if(s.find(head)!=s.end()){
			return true;
		}
		s.insert(head);
		head = head->next;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct node* head = NULL;
	int pos = 3;
	push(&head,3);
	push(&head,4);
	append(&head,5);
	insertafter(head->next,6);
	head->next->next->next->next = head;
	std::cout<<loop(head);
}