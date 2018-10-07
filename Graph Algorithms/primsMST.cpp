//the code doesn't works
#include <bits/stdc++.h>
using namespace std;

int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}

void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swap(int* a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minheapify(int arr[],int id[],int i,int n){
	int smallest = i;
	int l = left(i);
	int r = right(i);
	if((arr[l]<arr[smallest])&&(l<n)){smallest = l;}
	if((arr[r]<arr[smallest])&&(r<n)){smallest = r;}
	if(smallest!=i){
		swap(&arr[smallest],&arr[i]);
		swap(&id[smallest],&id[i]);
		minheapify(arr,id,smallest,n);
	}
}

void buildminheap(int arr[],int id[],int n){
	for(int i = n/2; i>=0; i--){
		minheapify(arr,id,i,n);
	}
}


void extractmin(int arr[],int id[],int *n){
	swap(&arr[0],&arr[*n-1]);
	swap(&id[0],&id[*n-1]);
	*n = (*n)-1;
	buildminheap(arr,id,*n);
}

void heapdecreasekey(int arr[],int id[],int i,int key){
	if(key>arr[i]){cout<<"key is greater"<<endl;}
	else{
		arr[i] = key;
		while((key<arr[parent(i)])&&(i>0)){
			swap(&arr[i],&arr[parent(i)]);
			swap(&id[i],&id[parent(i)]);
			i = parent(i);
		}
	}
}

////althrough you can make a binary heap node and that willbe better

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        ///vertices starts from 0 to n-1***
    ///undirected graph
    ///////////////////////////////
    int n,e,s,d,w;
    cin>>n;
    cin>>e;
    vector<int> adj[n];
    vector<int> weight[n];
    for(int i=0;i<e;i++){
    	cin>>s>>d>>w;
    	s--;
    	d--;
    	adj[s].push_back(d);
    	adj[d].push_back(s);
    	weight[s].push_back(w);
    	weight[d].push_back(w);
    }
    ////////////////////////////////
    int par[n];
    int ver_wei[n];
    int key[n];
    int id[n];
    bool mem[n];
    for(int i=0;i<n;i++){mem[i] = true;}
    ///////////////////////////////initialize
    for(int i=0;i<n;i++){
    	par[i] = -1;
    	key[i] = 100000;
    	id[i] = i;
    	ver_wei[i] = 100000;
    }
    heapsize = n;
    key[0] = 0;
    int ek,ei;
    while(heapsize>0){
    	ek = key[0];
    	ei = id[0];
    	extractmin(key,id,&heapsize);
    	mem[ei] = false;
    	vector<int>::iterator it;
    	for(it=adj[ei].begin(),it1=weight[ei].begin();it!=adj[ei].end();it++,it1++){
    		if((mem[*it])&&(*it1<ver_wei[ei])){
    			par[*it] = ei;
    			ver_wei[*it] = *it1;
    			heapdecreasekey(key,id,*it,*it1);
    		}
    	}
    }
}
