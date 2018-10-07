#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
	int key;
	bool color;
	node * left;
	node * right;
	node * parent;
};


void print_inorder(node * head,node * tnil,int count){
	if(head!=tnil){
		count++;
		print_inorder(head->right,tnil,count);
		for(int i=0;i<count;i++){
			cout<<"   ";
		}
		if(head->color){cout<<head->key<<"r ";}
		else{cout<<head->key<<"b ";}
		cout<<endl;
		print_inorder(head->left,tnil,count);
	}
}

struct node* maxi(node * head,node * tnil){
	while((head->right)!=tnil){
		head = head->right;
	}
	return (head);
}

struct node* min(node * head,node * tnil){
	while((head->left)!=tnil){
		head = head->left;
	}
	return (head);
}

struct node* search(node * head,int x,node * tnil){
	node * p;
	while((head!=tnil)&&((head->key)!=x)){
		p = head;
		if((head->key)>x){head = head->left;}
		else{head = head->right;}
	}
	if(head!=tnil){return head;}
	else{cout<<"the element doesn't exist"<<endl;return NULL;}
}

struct node* suc(node * x,node * tnil){
	if(x->right){
		return min(x->right,tnil);
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

struct node* pre(node * x,node * tnil){
	if((x->left)!=tnil){
		return min(x->left,tnil);
	}
	else{
		while((x!=tnil)&&(((x->parent)->left)==x)){
			x = x->parent;
		}
		if(((x->parent)->left)!=x){
			return (x->parent);
		}
		else return NULL;
	}
}

void leftrotate(node ** head,node * x,node * tnil){
	node * y = x->right;
	x->right = y->left;
	if((y->left)!=tnil){y->left->parent=x;}
	y->parent = x->parent;
	if(x->parent==tnil){*head = y;}
	else if(x->parent->left==x){x->parent->left = y;}
	else{x->parent->right = y;}
	y->left = x;
	x->parent = y;
}

void rightrotate(node ** head,node * y,node * tnil){
	node * x = y->left;
	y->left = x->right;
	if((x->right)!=tnil){x->right->parent=y;}
	x->parent = y->parent;
	if(y->parent==tnil){*head = x;}
	else if(y->parent->left==y){y->parent->left = x;}
	else{y->parent->right = x;}
	x->right = y;
	y->parent = x;
}

int blackhieght(node * head,node * tnil){
	int count = 0;
	while(head!=tnil){
		if(!(head->color)){
			count++;
		}
		head = head->left;
	}
	return count;
}

//we can't use if instead of elseif because 
//if will just check right or left instead of z.p
//color. so after each step we need to check that 
//whether we need to go furthur. whereas 2nd and
// 3rd case are coupled so...
//2nd and 3rd step lead to the end.

void insert_fixup(node ** head,node * z,node * tnil){
	//cout<<"before"<<endl;
	while(z->parent->color){
		//cout<<"loop"<<endl;
		if(z->parent->parent->left==z->parent){
			node * y = z->parent->parent->right;
			if(y->color){
				//cout<<"now"<<endl;
				z->parent->color = false;
				y->color = false;
				z->parent->parent->color = true;
				z = z->parent->parent;
			}
			else{
				if(z->parent->right==z){
					z = z->parent;
					leftrotate(head,z,tnil);
				}
				z->parent->color=false;
				//cout<<"there"<<endl;
				z->parent->parent->color=true;
				rightrotate(head,z->parent->parent,tnil);
			}
		}
		else{
			//cout<<"hey"<<endl;
			node * y = z->parent->parent->left;
			if(y->color){
				z->parent->color = false;
				y->color = false;
				z->parent->parent->color = true;
				z = z->parent->parent;
			}
			else{
				if(z->parent->left==z){
					z = z->parent;
					rightrotate(head,z,tnil);
				}
				z->parent->color=false;
				z->parent->parent->color=true;
				leftrotate(head,z->parent->parent,tnil);
			}
		}
	}
	(*head)->color = false;
}

void insert(node ** head,int data,node * tnil){
	node * x = (*head), *y = tnil;
	while(x!=tnil){
		y = x;
		if((x->key)>data){x = x->left;}
		else{x = x->right;}
	}
	node * z = new node;
	z->key = data;
	z->left = tnil;
	z->right = tnil;
	z->color = true; //red
	z->parent = y;
	if(y==tnil){*head = z;}
	else if((y->key)>data){y->left = z;}
	else{y->right = z;}
	insert_fixup(head,z,tnil);
	//cout<<"hey"<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    struct node * tnil = new node;
	tnil->color = false;   //black
	tnil->left = NULL;
	tnil->right = NULL;
	tnil->parent = NULL;
	tnil->key = -11111;
    node * head = new node;
    head->key = 21;
    head->parent = tnil;
    head->color = false;
    head->left = tnil;
	head->right = tnil;
    insert(&head,9,tnil);
    insert(&head,6,tnil);
    insert(&head,1,tnil);
    insert(&head,66,tnil);
    insert(&head,5,tnil);
    insert(&head,10,tnil);
    insert(&head,61,tnil);
    insert(&head,170,tnil);
    insert(&head,8,tnil);
    print_inorder(head,tnil,0);
    //cout<<head->right->right->left->key<<endl;
    cout<<endl;
}