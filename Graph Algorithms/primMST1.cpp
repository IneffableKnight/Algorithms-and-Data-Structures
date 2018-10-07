#include <bits/stdc++.h>
using namespace std;

///I guess this will not work because if we directly change the value of elements
//in the priority queue then it will not be able work properly, as there is no
//decrease key operation supported by c++ priority queue implementation.


//construct the list of  vertices _/
//construct a pririty queue from stl c++ _/
//perform the algorithm

struct vertex{
	int id;
	int key;
	int parent;
	vector<vertex *> adj;
	vector<int> weight;
};

//we cannot overload the < operator inside the struct as it will be called only when
//instance of struct is called not it's pointer. so overload it seperately outside.

struct mycomparator{
    bool operator()(vertex * arg1,vertex * arg2){
        return (arg1->key)>(arg2->key);
    }
};

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
    	temp->id = i;
    	temp->key = 1000;
    	temp->parent = -1;
    	arr[i] = temp;
    }
    //undirected graph implementation
    for(int i=0;i<e;i++){
    	cin>>ss>>d>>w;
    	arr[ss-1]->adj.push_back(arr[d-1]);
    	arr[ss-1]->weight.push_back(w);
    	arr[d-1]->adj.push_back(arr[ss-1]);
    	arr[d-1]->weight.push_back(w);
    }
    arr[0]->key = 0; ///source
    vector<bool> mem(v,true);
    priority_queue<vertex*,vector<vertex*>, mycomparator > priority;
    for(int i=0;i<v;i++){
    	priority.push(arr[i]);
    }
    vertex * s;
    /*while(!priority.empty()){
    	s = priority.top();
    	priority.pop();
    	cout<<s->key<<endl;
    }*/
    vector<vertex *>::iterator it;
    vector<int>::iterator it1;
    while(!priority.empty()){
    	for(int i=0;i<v;i++){
    		cout<<mem[i]<<" ";
    	}
    	cout<<endl;
    	for(int i=0;i<v;i++){
    		cout<<arr[i]->key<<" ";
    	}
    	cout<<endl;
    	s = priority.top();
    	priority.pop();
    	mem[s->id] = false;
    	cout<<s->id<<endl;
    	//cout<<s->key<<endl;
    	it = s->adj.begin();
    	it1 = s->weight.begin();
    	for(;it!=s->adj.end();it++,it1++){
    		//cout<<(*it)->id<<" ";
    		//cout<<(*it)->key<<" ";
    		if(mem[(*it)->id]){
    			if(((*it)->key)>(*it1)){
    				((*it)->key) = (*it1);
    				((*it)->parent) = s->id;
    			}
    		}
    		//cout<<(*it)->key<<" ";
    	}
    	cout<<endl;
    }
}
