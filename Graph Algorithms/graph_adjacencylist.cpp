#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

class graph{
private:
	int v;
	vector<int> *list;
public:
	graph(int v){
		this->v = v;
		list = new vector<int>[v];
	}
	void insert_edge(int a,int b){
		list[a].push_back(b);
		list[b].push_back(a);
	}
	void print_adj(int a){
		cout<<"the adjacent vertices of "<<a<<" are:"<<endl;
		vector<int>::iterator it;
		for(it = list[a].begin();it!=list[a].end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    graph g(5);
    g.insert_edge(0,1);
    g.insert_edge(0,4);
    g.insert_edge(4,1);
    g.insert_edge(3,1);
    g.insert_edge(2,1);
    g.insert_edge(2,3);
    g.insert_edge(4,3);
    g.print_adj(0);
    g.print_adj(1);
    g.print_adj(4);
}