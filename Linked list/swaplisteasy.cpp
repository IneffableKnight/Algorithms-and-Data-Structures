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

void swapy(struct node** head,int a,int b){
	struct node* t = *head,*prev = NULL;
	while((t->next!=NULL)&&(t->data!=a)){
		prev = t;
		t = t->next;
	}
	if(t->data!=a){
		printf("element not present in the list\n");
		return;
	}
	struct node* t1 = *head,*prev1 = NULL;
	while((t1->next!=NULL)&&(t1->data!=b)){
		prev1 = t1;
		t1 = t1->next;
	}
	if(t1->data!=b){
		printf("element not present in the list\n");
		return;
	}
	if(t==t1){
		printf("they are same element in the list\n");
	}
	if(prev==NULL){
		*head = t1;
	}
	else{
		prev->next = t1;
	}
	if(prev1==NULL){
		*head = t;
	}
	else{
		prev1->next = t;
	}
/////////////////////next pointer will be taken care now
	struct node* s;
	s = t->next;
	t->next = t1->next;
	t1->next = s;
	//binary casing leads to 8 line sequential casing leads to 4 line
	// things which are common can be seperated out
	// the adjacent case was handelled pretty well
}

void swapp(struct node*& a,struct node*& b){
	struct node* temp = a;
	a = b;
	b = temp; 
}

/*void swap(Node*& a, Node*& b)
{
 
    Node* temp = a;
    a = b;
    b = temp;
}
 
void swapNodes(Node** head, int x, int y)
{
    if (x == y)
        return;
 
    Node **a = NULL, **b = NULL;
    while (*head_ref) {
 
        if ((*head_ref)->data == x) {
            a = head_ref;
        }
 
        else if ((*head_ref)->data == y) {
            b = head_ref;
        }
 
        head_ref = &((*head_ref)->next);
    }
    if (a && b) {
 
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}
*/
void swappp(struct node** head,int a,int b){
	if(a==b){return;}
	struct node** t1=NULL;
	struct node** t2=NULL;
	while((*head)){
		if((*head)->data==a){
			t1 = head;
		}
		if((*head)->data==b){
			t2 = head;
		}
		(*head) = (*head)->next;
	}
	if(t1 && t2){
		swapp(*t1,*t2);
		swapp(((*t1)->next),((*t2)->next));
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
	swappp(&head,3,6);
	printf("\n");
	//std::cout<<5;
	printlist(head);
}