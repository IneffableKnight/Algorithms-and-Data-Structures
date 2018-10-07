#include <iostream>
#include <stdio.h>
using namespace std;

//this file contain the disjoint set data with path compression and union
//by rank

struct node{
	int rank;
	node * p;
	int n;
};

void makeset(node * x,int a){
	x->n = a;
	x->p = x;
	x->rank = 0;
}

node * findset(node * x){
	if(x!=(x->p)){
		x->p = findset(x->p);
	}
	return x->p;
}

void Union(node *a, node *b){
	node * x = findset(a);
	node * y = findset(b);
	if((x->rank)>(y->rank)){y->p = x;}
	else{
		x->p = y;
		if((x->rank)==(y->rank)){
			y->rank = y->rank+1;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    makeset(a,1);
    makeset(b,2);
    makeset(c,3);
    makeset(d,4);
    makeset(e,5);
    Union(a,b);
    cout<<findset(a)->n<<endl;
    cout<<findset(b)->n<<endl;
    cout<<findset(c)->n<<endl;
    cout<<findset(d)->n<<endl;
    cout<<findset(e)->n<<endl;
    cout<<endl;
    Union(a,c);
    cout<<findset(a)->n<<endl;
    cout<<findset(b)->n<<endl;
    cout<<findset(c)->n<<endl;
    cout<<findset(d)->n<<endl;
    cout<<findset(e)->n<<endl;
    cout<<endl;
    Union(d,e);
    cout<<findset(a)->n<<endl;
    cout<<findset(b)->n<<endl;
    cout<<findset(c)->n<<endl;
    cout<<findset(d)->n<<endl;
    cout<<findset(e)->n<<endl;
    cout<<endl;
    Union(a,d);
    cout<<findset(a)->n<<endl;
    cout<<findset(b)->n<<endl;
    cout<<findset(c)->n<<endl;
    cout<<findset(d)->n<<endl;
    cout<<findset(e)->n<<endl;
    cout<<endl;
}