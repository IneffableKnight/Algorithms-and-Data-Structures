#include <bits/stdc++.h>
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
    int n,id;
    cin>>n;
    node arr[n];
    //node *arr = new node[n];
    int e;
    cin>>e;
    multimap<int,int> mymap;
    int source[e],dest[e],weight[e];
    //*******vertex starts from 1 in input not zero***//
    for(int j=0;j<e;j++){
    	cin>>source[j]>>dest[j]>>weight[j];
    	mymap.insert(pair<int,int>(weight[j],j));
    }
    ////ALGORITHM/////
    vector<int> edges;
    for(int i=0;i<n;i++){
    	makeset(&arr[i],i+1);
    }
    int sum = 0;
    multimap<int,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++){
    	cout<<source[it->second]<<"--->"<<dest[it->second]<<endl;
    	node * a = findset(&arr[source[it->second]-1]);
    	node * b = findset(&arr[dest[it->second]-1]);
    	if(a!=b){
    		sum += weight[it->second];
    		edges.push_back(weight[it->second]);
    		Union(&arr[source[it->second]-1],&arr[dest[it->second]-1]);
    	}
    }
    for(int i=0;i<edges.size();i++){
    	cout<<edges[i]<<" ";
    }
    cout<<endl<<sum;
}