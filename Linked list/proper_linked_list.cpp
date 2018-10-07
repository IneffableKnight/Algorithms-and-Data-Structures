#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
	node* ele = (struct node*)malloc(sizeof(struct node));
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
	printf("So the linked list final form is :\n");
	printlist(head);
	printf("\n");
	std::cout<<coun1(&head);
	printf("\n");
	dele(&head,5);
	printf("\n");
	printlist(head);
	printf("\n");
	del_pos(&head,pos);
	printf("\n");
	//std::cout<<5;
	printlist(head);
}