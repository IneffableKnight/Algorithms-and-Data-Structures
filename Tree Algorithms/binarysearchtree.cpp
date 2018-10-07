#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
	int key;
	node * left;
	node * right;
	node * parent;
};

struct node* maxi(node * head){
	while((head->right)!=NULL){
		head = head->right;
	}
	return (head);
}

struct node* min(node * head){
	while((head->left)!=NULL){
		head = head->left;
	}
	return (head);
}

void print_inorder(node * head){
	if(head!=NULL){
		print_inorder(head->left);
		cout<<head->key<<" ";
		print_inorder(head->right);
	}
}

void print_preorder(node * head){
	if(head!=NULL){
		cout<<head->key<<" ";
		print_preorder(head->left);
		print_preorder(head->right);
	}
}

void print_postorder(node * head){
	if(head!=NULL){
		print_postorder(head->left);
		print_postorder(head->right);
		cout<<head->key<<" ";
	}
}

void insert(node ** head,int x){
	node * z = new node;
	z->key = x;
	z->left = NULL;
	z->right = NULL;
	z->parent = NULL;
	if(*head==NULL){
		*head = z;
	}
	else{
		node * c = *head,*p = NULL;
		while(c){
			p = c;
			if((c->key)>x){c = c->left;}
			else{c=c->right;}
		}
		if((p->key)>x){
			p->left = z;
		}
		else{
			p->right = z;
		}
		z->parent = p;
	}
}

struct node* search(node * head,int x){
	node * p;
	while((head)&&((head->key)!=x)){
		p = head;
		if((head->key)>x){head = head->left;}
		else{head = head->right;}
	}
	if(head!=NULL){return head;}
	else{cout<<"the element doesn't exist"<<endl;return NULL;}
}

struct node* suc(node * x){
	if(x->right){
		return min(x->right);
	}
	else{
		while((x)&&(((x->parent)->right)==x)){
			x = x->parent;
		}
		if(((x->parent)->right)!=x){
			return (x->parent);
		}
		else return NULL;
	}
}

struct node* pre(node * x){
	if(x->left){
		return min(x->left);
	}
	else{
		while((x)&&(((x->parent)->left)==x)){
			x = x->parent;
		}
		if(((x->parent)->left)!=x){
			return (x->parent);
		}
		else return NULL;
	}
}

void transplant(node ** head,node * x,node * y){
	///x should not be null elsebad things will happen
	if(x->parent==NULL){
		*head = y;
	}
	else{
		if((x->parent->left)==x){(x->parent->left)=y;}
		else{(x->parent->right)=y;}
		if(y){y->parent = x->parent;}
	}
}

void delet(node ** head,node * x){
	if(x->left==NULL){
		transplant(head,x,x->right);
		delete(x);
	}
	else if(x->right==NULL){
		transplant(head,x,x->left);
		delete(x);
	}
	else {
		node * y = x->right;
		if(y->left){
			y = suc(x);
			//print_inorder(*head);
			//cout<<endl;
			transplant(head,y,y->right);
			//transplant(head,y->left,x->right);
			//can't do that because the function can't deal with NULL x
			y->right = x->right;
			x->right->parent = y;
			//print_inorder(y);
			//cout<<endl;
		}
		transplant(head,x,y);
		x->left->parent = y;
		y->left = x->left;
		delete(x);
	}
	//case3;
	//case4;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    node * head = NULL;
    insert(&head,9);
    insert(&head,6);
    insert(&head,71);
    insert(&head,66);
    insert(&head,5);
    insert(&head,10);
    insert(&head,61);
    insert(&head,170);
    insert(&head,8);
    print_inorder(head);
    cout<<endl;
    /*print_preorder(head);
    cout<<endl;
    print_postorder(head);
    cout<<endl;
    cout<<(maxi(head)->key)<<endl;
    cout<<(min(head)->key)<<endl;*/
    node * x = search(head,9);
    //cout<<x->key<<endl;
    /*node * y = pre(x);
    cout<<y->key<<endl;
    y = suc(x);
    cout<<y->key<<endl;*/
    delet(&head,x);
    print_inorder(head);
}