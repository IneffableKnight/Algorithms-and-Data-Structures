#include <bits/stdc++.h>
using namespace std;

void print_path(int parent[],int i, int j,int n){
	if(i==j){
		cout<<i<<" ";
	}
	else if(parent[i*n+j]==-1){
		cout<<"no path exist from "<<i<<" to "<<j<<" exits";
	}
	else{
		print_path(parent,i,parent[i*n+j],n);
		cout<<j<<" ";
	}
}

void swap(int ** a,int ** b){
	int * t = *a;
	*a = *b;
	*b = t;
}

void print_mat(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[n*i+j]<<" ";
		}
		cout<<endl;
	}
}

void shortest_path(int parent[],int parent_temp[],int temp[],int temp1[],int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				temp1[i*n+j] = temp[i*n+j];
				//parent_temp[i*n+j] = parent[i*n+j];
				if(temp[i*n+j]>(temp[i*n+k]+temp[k*n+j])){
					temp1[i*n+j] = temp[i*n+k]+temp[k*n+j];
					parent[i*n+j] = parent[k*n+j];///casuality may happen
					//I am dynamicaly changing the parent matrix against the algorithm
				}
			}
		}
	//swap(&parent_temp,&parent);
	swap(&temp,&temp1);
	}
	print_mat(temp,n);
	cout<<"============"<<endl;
	print_mat(parent,n);
	cout<<"============"<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int n,tt;
	cin>>n;
	int *weight = new int[n*n];
	int *parent = new int[n*n];
	int *parent_temp = new int[n*n];
	int *temp = new int[n*n];
	int *temp1 = new int[n*n];
	for(int i=0;i<n*n;i++){
		cin>>tt;
		weight[i] = tt;
		temp[i] = tt;
		parent[i] = i/n;
		if(tt==-1){
			weight[i] = 1000;
			temp[i] = 1000;
			parent[i] = -1;
		}
	}
	for(int i=0;i<n;i++){
		parent[i*n+i] = -1;
	}
	shortest_path(parent,parent_temp,temp,temp1,n);
	print_path(parent,0,1,n);
	delete [] temp1;
	return 0;
}