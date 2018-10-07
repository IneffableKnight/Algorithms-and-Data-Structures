#include <bits/stdc++.h>
using namespace std;

//construct the list of  vertices _/
//construct a pririty queue from stl c++ _/
//perform the algorithm

struct vertex{
	int id;
	int key;
	int parent;
};

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
    priority_queue<vertex *,vector<vertex *>, mycomparator > priority;
    int v = 9;
    for(int i=0;i<v;i++){
        vertex* temp = new vertex;
        temp->key = (4-i)*(4-i);
        temp->id = i;
    	priority.push(temp);
    }
    vertex *s;
    while(!priority.empty()){
    	s = priority.top();
    	priority.pop();
    	cout<<s->key<<endl;
    }
}
