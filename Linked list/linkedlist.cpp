#include <stdio.h>
#include <stdlib.h>

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

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d",&n);
	struct node* prev;
	struct node* start = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&m);
	start->data = m;
	prev = start;
	while(n>1){
		n--;
		scanf("%d",&m);
		struct node* ele = (struct node*)malloc(sizeof(struct node));
		ele->data = m;
		prev->next = ele;
		prev = ele;
	}
	printlist(start);
}