#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
/*class graph{
private:
	int * parent;
	int * weight;
	int n;
	int * temp;
	int * tempu; //delete it finally;
	//check if we simultaneouly update weights instead at the end
	//will it work??
public:
	graph(int n);
	void print_graph();
	void update_path();
	void recall();
};*/

/*graph::graph(int n){
	int **parent = new int*[n];
	for(int i = 0; i < n; ++i) {
	    parent[i] = new int[n];
	}
	for(int i = 0; i < n; ++i) {
    	delete [] parent[i];
	}
	delete [] parent;
	//intialise pointer of pointer array allocate in memoery
	//using a loop at each element strore newly allocated memory's address
	//similary delete in backward direction :)
	//this is lenthy so we will use alternative
	this->n = n;
	parent = new int[n*n];
	weight = new int[n*n];
	temp = new int[n*n];
	tempu = new int[n*n];
	//use parent[i*n+j]
}*/


//////////////////////////////////////////////////////////////////////////////

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

void shortest_path(int weight[],int parent[],int temp[],int temp1[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp1[n*i+j] = 1000;
			for(int k=0;k<n;k++){
				if(temp1[n*i+j]>(temp[n*i+k]+weight[n*k+j])){
					temp1[n*i+j]=(temp[n*i+k]+weight[n*k+j]);
				}
			}
		}
	}
	//swap(&temp,&temp1);
	//swap is not working here
}

void iter(int weight[],int parent[],int temp[],int temp1[],int n){
	for(int i=0;i<n-2;i++){
		shortest_path(weight,parent,temp,temp1,n);
		swap(&temp,&temp1);
		print_mat(temp,n);
		cout<<"----------"<<endl;
	}
}

void fast_iter(int weight[],int parent[],int temp[],int temp1[],int n){
	int m = 1;
	while(m<n-1){
		m = 2*m;
		shortest_path(temp,parent,temp,temp1,n);
		swap(&temp,&temp1);
	}
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
	int *temp = new int[n*n];
	int *temp1 = new int[n*n];
	for(int i=0;i<n*n;i++){
		cin>>tt;
		weight[i] = tt;
		temp[i] = tt;
		if(tt==-1){
			weight[i] = 1000;
			temp[i] = 1000;
		}
	}
	iter(weight,parent,temp,temp1,n);
	//fast_iter(weight,parent,temp,temp1,n);
	//print_mat(temp,n);
	delete [] temp1;
	return 0;
}