#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

//this is for directed grah;

class graph{
private:
	int v;
	vector<int> *list;
	vector<int> parent;
	vector<int> timein;
	vector<int> timeout;
	vector<int> visited; //0=white,1=gray,2=black//
	vector<int> topsort;
	int time;
public:
	graph(int v);
	void insert_edge(int a,int b);
	void print_adj(int a);
	void dfs();
	void dfs_visit(int s);
	void print_all();
};

graph::graph(int v){
	this->v = v;
	list = new vector<int>[v];
}

void graph::insert_edge(int a,int b){
	list[a].push_back(b);
}

void graph::print_adj(int a){
	cout<<"the adjacent vertices of "<<a<<" are:"<<endl;
	vector<int>::iterator it;
	for(it = list[a].begin();it!=list[a].end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void graph::dfs(){
	for(int i=0;i<v;i++){
		parent.push_back(-1);
		timeout.push_back(0);
		timein.push_back(0);
		visited.push_back(0);
	}
	time = 0;
	for(int i=0;i<v;i++){
		if(visited[i]==0){
			dfs_visit(i);
		}
	}
}

void graph::dfs_visit(int s){
	cout<<s<<"<---------visited"<<endl;
	time++;
	timein[s] = time;
	visited[s] = 1;
	vector<int>::iterator it;
	for(it = list[s].begin();it!=list[s].end();it++){
		if(visited[*it]==0){
			parent[*it] = s;
			dfs_visit(*it);
		}
		else{
			if(visited[*it]==1){
				cout<<"the graph is detected"<<endl;
			}
		}
	}
	visited[s] = 2;
	time++;
	timeout[s] = time;
	topsort.push_back(s);
}

void graph::print_all(){
	for(int i=0;i<v;i++){
		cout<<parent[i]<<" "<<timein[i]<<" "<<timeout[i]<<endl;
	}
	cout<<endl;
	for(int i=0;i<v;i++){
		cout<<topsort[v-1-i]<<" ";
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    //check if it is bidirectional or not
    //input the ID of vertices starting from 0 to n-1
    //source can be anything
    //be careful with the meaning of the input paramrters
    graph g(6);
    g.insert_edge(0,2);
    g.insert_edge(0,1);
    g.insert_edge(1,2);
    g.insert_edge(2,3);
    g.insert_edge(3,1);
    g.insert_edge(4,3);
    g.insert_edge(4,5);
    g.insert_edge(5,5);
    g.dfs();
    g.print_all();
}