#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

//this is for directed grah;

class graph{
private:
	int v;
	vector<int> *list;
	vector<int> parent;
	vector<int> distance;
	vector<int> visited;
	int flagb;

public:
	graph(int v);
	void insert_edge(int a,int b);
	void print_adj(int a);
	void bfs(int s);
	int dist(int s,int q);
	void path(int s,int q);
	void call_print(int s,int q);
};

graph::graph(int v){
	this->v = v;
	this->flagb = 0;
	list = new vector<int>[v];
}

void graph::insert_edge(int a,int b){
	list[a].push_back(b);
	list[b].push_back(a);
}

void graph::print_adj(int a){
	cout<<"the adjacent vertices of "<<a<<" are:"<<endl;
	vector<int>::iterator it;
	for(it = list[a].begin();it!=list[a].end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void graph::bfs(int s){
	flagb = 1;
	queue<int> q;
	for(int i=0;i<v;i++){
		parent.push_back(-2);
		distance.push_back(-1);
		visited.push_back(0);
	}
	q.push(s);
	parent[s] = -1;
	distance[s] = 0;
	visited[s] = 1;
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		visited[cur] = 2;
		/*for(int i=0;i<v;i++){
			cout<<visited[i]<<" ";
		}
		cout<<endl;*/
		vector<int>::iterator it;
		for(it = list[cur].begin();it!=list[cur].end();it++){
			if(visited[*it]==1){cout<<"cycle_detected"<<endl;}
			if(visited[*it]==0){
				q.push(*it);
				parent[*it] = cur;
				distance[*it] = distance[cur]+1;
				visited[*it] = 1;
			}
		}
	}
	for(int i=0;i<v;i++){
		cout<<parent[i]<<distance[i]<<visited[i]<<endl;
	}
}
int graph::dist(int s,int q){
	if((flagb)&&(distance[s]==0)){
		return (distance[q]);
	}
	else{
		bfs(s);
		return (distance[q]);
	}
}
void graph::path(int s,int q){
	if((flagb)&&(distance[s]==0)){
		call_print(s,q);
	}
	else{
		bfs(s);
		call_print(q,s);
	}
}
void graph::call_print(int s,int q){
	if(q==s){
		cout<<s<<" ";
	}
	else{
		if(q<0){
			cout<<"no such path exist"<<endl;
		}
		else{
			call_print(s,parent[q]);
			cout<<q<<" ";
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    //input the ID of vertices starting from 0 to n-1
    //source can be anything
    //be careful with the meaning of the input paramrters
    graph g(8);
    g.insert_edge(0,1);
    g.insert_edge(1,2);
    g.insert_edge(2,3);
    g.insert_edge(3,4);
    g.insert_edge(3,5);
    g.insert_edge(4,5);
    g.insert_edge(5,6);
    g.insert_edge(6,7);
    g.insert_edge(4,7);
    g.insert_edge(4,6);
    g.bfs(2);
    cout<<g.dist(2,7)<<endl;
    g.path(2,7);
}