#include <iostream>
#include <stdio.h>
using namespace std;

//we need to find minimum of an array elements in a 
//given interval

void build_tree(int arr[],int tree[],int low,int high,int pos){
	if(low==high){
		tree[pos] = arr[low];
		return;
	}
	int mid = (low+high)/2;
	build_tree(arr,tree,low,mid,2*pos+1);
	build_tree(arr,tree,mid+1,high,2*pos+2);
	if(tree[2*pos+1]<=tree[2*pos+2]){tree[pos] =tree[2*pos+1];}
	else{tree[pos] = tree[2*pos+2];}
}

int query_min(int tree[],int qlow,int qhigh,int low,int high,int pos){
	if((low>qhigh)||(qlow>high)){return 11111;}
	if((low>=qlow)&&(qhigh>=high)){return tree[pos];}
	int mid = (low+high)/2;
	int a = query_min(tree,qlow,qhigh,low,mid,2*pos+1); 
	int b = query_min(tree,qlow,qhigh,mid+1,high,2*pos+2);
	if(a<=b){return a;}
	else{return b;}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int arr[4] = {-1,2,4,0};
    int tree[2*4-1];
    build_tree(arr,tree,0,3,0);
    for(int i = 0;i<(2*4-1);i++){
    	cout<<tree[i]<<" ";
    }
    cout<<endl<<query_min(tree,0,3,0,3,0);
}