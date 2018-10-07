#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

//this is for directed grah;

class graph{
private:
	int v;
	vector<int> *list;
	vector<int> *listT;
	vector<int> parent;
	vector<int> timein;
	vector<int> timeout;
	vector<int> visited; //0=white,1=gray,2=black//
	vector<int> parent1;
	vector<int> timein1;
	vector<int> timeout1;
	vector<int> visited1;
	queue<int> qu;
	map<int,int,greater<int> > mymap;
	int time;
	int time1;
public:
	graph(int v);
	void insert_edge(int a,int b);
	void print_adj1(int a);
	void print_adj2(int a);
	void dfs1();
	void dfs2();
	void dfs_visit1(int s);
	void dfs_visit2(int s);
	void print_all1();
	void print_all2();
};

graph::graph(int v){
	this->v = v;
	list = new vector<int>[v];
	listT = new vector<int>[v];
}

void graph::insert_edge(int a,int b){
	list[a].push_back(b);
	listT[b].push_back(a);
}

void graph::print_adj1(int a){
	cout<<"the adjacent vertices of G"<<a<<" are:"<<endl;
	vector<int>::iterator it;
	for(it = list[a].begin();it!=list[a].end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void graph::print_adj2(int a){
	cout<<"the adjacent vertices of G.T"<<a<<" are:"<<endl;
	vector<int>::iterator it;
	for(it = listT[a].begin();it!=listT[a].end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void graph::dfs1(){
	for(int i=0;i<v;i++){
		parent.push_back(-1);
		timeout.push_back(0);
		timein.push_back(0);
		visited.push_back(0);
	}
	time = 0;
	for(int i=0;i<v;i++){
		if(visited[i]==0){
			dfs_visit1(i);
		}
	}
}

void graph::dfs2(){
	for(int i=0;i<v;i++){
		parent1.push_back(-1);
		timeout1.push_back(0);
		timein1.push_back(0);
		visited1.push_back(0);
	}
	time1 = 0;
	map<int,int,greater<int> >::iterator it;
	for(it = mymap.begin();it!=mymap.end();it++){
		if(visited1[it->second]==0){
			dfs_visit2(it->second);
			cout<<"next strongly connected components are :"<<endl;
			while(!qu.empty()){
				cout<<qu.front()<<" ";
				qu.pop();
			}
			cout<<endl;
		}
	}
}

void graph::dfs_visit1(int s){
	time++;
	timein[s] = time;
	visited[s] = 1;
	vector<int>::iterator it;
	for(it = list[s].begin();it!=list[s].end();it++){
		if(visited[*it]==0){
			parent[*it] = s;
			dfs_visit1(*it);
		}
	}
	visited[s] = 2;
	time++;
	mymap[time] = s;
	timeout[s] = time;
}

void graph::dfs_visit2(int s){
	qu.push(s);
	time1++;
	timein1[s] = time1;
	visited1[s] = 1;
	vector<int>::iterator it;
	for(it = listT[s].begin();it!=listT[s].end();it++){
		if(visited1[*it]==0){
			parent1[*it] = s;
			dfs_visit2(*it);
		}
	}
	visited1[s] = 2;
	time1++;
	timeout1[s] = time1;
}

void graph::print_all1(){
	for(int i=0;i<v;i++){
		cout<<parent[i]<<" "<<timein[i]<<" "<<timeout[i]<<endl;
	}
}

void graph::print_all2(){
	for(int i=0;i<v;i++){
		cout<<parent1[i]<<" "<<timein1[i]<<" "<<timeout1[i]<<endl;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    graph g(8);
    g.insert_edge(0,1);
    g.insert_edge(1,4);
    g.insert_edge(4,0);
    g.insert_edge(1,5);
    g.insert_edge(4,5);
    g.insert_edge(1,2);
    g.insert_edge(5,6);
    g.insert_edge(6,5);
    g.insert_edge(2,6);
    g.insert_edge(2,3);
    g.insert_edge(3,2);
    g.insert_edge(6,7);
    g.insert_edge(3,7);
    g.insert_edge(7,7);
    g.dfs1();
    g.dfs2();
    g.print_all1();
    cout<<endl;
    g.print_all1();
}