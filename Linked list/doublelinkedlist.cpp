#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
	int data;
	node * next;
	node * prev;
};

void printlist(node * head){
	node * p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

void push(node ** head,int x){
	node * temp = new node;
	temp->data = x;
	temp->next = (*head);
	temp->prev = NULL;
	if(temp->next){
		temp->next->prev = temp;
	}
	*head = temp;
}

void insert(node * head,int x,int y){
	node * t = head;
	while((t->next!=NULL)&&((t->data)!=x)){
		t = t->next;
	}
	if((t->data)==x){
		node * temp = new node;
		temp->data = y;
		temp->next = t->next;
		temp->prev = t;
		if(temp->next){
			temp->next->prev = temp;
		}
		temp->prev->next = temp;
	}
	else{cout<<"There is no such element"<<endl;}
}

bool find(node * head,int x){
	node * t = head;
	while((t->next!=NULL)&&((t->data)!=x)){
		t = t->next;
	}
	if((t->data)==x){
		return true;
	}
	else{return false;}
}

void append(node * head,int y){
	node * t = head;
	while((t->next!=NULL)){
		t = t->next;
	}
	node * temp = new node;
	temp->data = y;
	temp->next = t->next;
	temp->prev = t;
	temp->prev->next = temp;
}

int count(node * head){
	node * t = head;
	int count = 0;
	while((t!=NULL)){
		t = t->next;
		count++;
	}
	return count;
}

void delet(node ** head,int x){
	node * t = *head;
	while((t->next!=NULL)&&((t->data)!=x)){
		t = t->next;
	}
	if((t->data)!=x){
		cout<<"No such element is present in the list"<<endl;
		return;
	}
	else{
		if(t->prev!=NULL){
			t->prev->next = t->next;
		}
		else{
			*head = t->next;
		}
		if(t->next!=NULL){
			t->next->prev = t->prev;
		}
		delete(t);
	}
}

void reverse(node ** head){
	node * cur = *head,*temp;
	while(cur->next){
		temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;
		cur = cur->prev;
	}
	cur->next = cur->prev;
	cur->prev = NULL;
	*head = cur;
}

void swapnode(node ** head,int x,int y){
	node * t1 = *head,* t2 = *head;
	if(x==y){return;}
	while((t1->next)&&(t1->data!=x)){
		t1 = t1->next;
	}
	while((t2->next)&&(t2->data!=y)){
		t2 = t2->next;
	}
	if(t1->data!=x||t2->data!=y){cout<<"no such elements present"<<endl;return;}
	if(t1->prev){
		t1->prev->next = t2;
	}
	else{
		*head = t2;
	}
	if(t2->prev){
		t2->prev->next = t1;
	}
	else{
		*head = t1;
	}
	if(t1->next){
		t1->next->prev = t2;
	}
	if(t2->next){
		t2->next->prev = t1;
	}
	node * temp;
	temp = t1->next;
	t1->next = t2->next;
	t2->next = temp;
	temp = t1->prev;
	t1->prev = t2->prev;
	t2->prev = temp;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	node * head = NULL;
 	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	insert(head,5,15);
	append(head,53);
	cout<<count(head)<<endl;
	cout<<find(head,533)<<endl;
	delet(&head,8);
	printlist(head);
	reverse(&head);
	printlist(head);
	swapnode(&head,15,51);
	printlist(head);
}