#include <bits/stdc++.h>
using namespace std;

//construct the list of  vertices _/
//construct a pririty queue from stl c++ _/
//perform the algorithm

struct vertex{
    int add;
	int id;
	int key;
	int parent;
	vector<vertex *> adj;
	vector<int> weight;
};

/////////////////Binary heap//////////////////////

//using array for heap with additional address variable .
//binary heap would be better

int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}

void printarray(vertex* arr[],int n){
    for(int i=0;i<n;i++){
        cout<<(arr[i]->key)<<" ";
    }
    cout<<endl;
}

void swap(vertex** a,vertex** b){
    vertex* temp = *a;
    *a = *b;
    *b = temp;
    int temp1 = (*a)->add;
    (*a)->add = (*b)->add;
    (*b)->add = temp1;
}

void minheapify(vertex* arr[],int i,int n){
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if(((arr[l]->key)<(arr[smallest]->key))&&(l<n)){smallest = l;}
    if(((arr[r]->key)<(arr[smallest]->key))&&(r<n)){smallest = r;}
    if(smallest!=i){
        swap(&arr[smallest],&arr[i]);
        minheapify(arr,smallest,n);
    }
}

void buildminheap(vertex* arr[],int n){
    for(int i = n/2; i>=0; i--){
        minheapify(arr,i,n);
    }
}

vertex * heapmin(vertex* arr[],int n){
    return arr[0];
}

vertex * extractmin(vertex* arr[],int *n){
    vertex* s = arr[0];
    swap(&arr[0],&arr[*n-1]);
    *n = (*n)-1;
    buildminheap(arr,*n);
    return s;
}

void heapdecreasekey(vertex* arr[],vertex * ii,int key1){
    if(key1>(ii->key)){cout<<"key is larger"<<endl;}
    else{
        ii->key = key1;
        int i = ii->add;
        while((key1<(arr[parent(i)]->key))&&(i>0)){
            swap(&arr[i],&arr[parent(i)]);
            i = parent(i);
        }
    }
}

///////////////////END///////////////////////////

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int v,e,ss,d,w;
    cin>>v>>e;
    vertex * arr[v];
    for(int i=0;i<v;i++){
    	vertex * temp = new vertex;
        temp->add = i;
    	temp->id = i;
    	temp->key = 1000;
    	temp->parent = -1;
    	arr[i] = temp;
    }
    //undirected graph implementation
    for(int i=0;i<e;i++){
    	cin>>ss>>d>>w;
    	(arr[ss]->adj).push_back(arr[d]);
    	(arr[ss]->weight).push_back(w);
    }
    arr[0]->key = 0; ///source
    vector<bool> mem(v,true);
    buildminheap(arr,v);
    vertex * s;
    int heapsize = v;
    int sum = 0;
    cout<<"vertices---->"<<"their distance from the source"<<endl;
    while(heapsize>0){
        s = extractmin(arr,&heapsize);
    	mem[s->id] = false;
        sum += s->key;
    	cout<<s->id<<"----------------->"<<s->key<<endl;
        vector<vertex *>::iterator it;
        vector<int>::iterator it1;
    	it = s->adj.begin();
    	it1 = s->weight.begin();
    	for(;it!=s->adj.end();it++,it1++){
    		if(mem[(*it)->id]){
    			if(((*it)->key)>((s->key)+*it1)){
                    heapdecreasekey(arr,*it,((s->key)+*it1));
    				((*it)->parent) = s->id;
    			}
    		}
    	}
    }
    cout<<"the total sum of spanning tree is "<<sum;
}
