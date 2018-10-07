#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

//this is for directed grah;

class graph{
private:
	int v;
	vector<int> *list;
	vector<int> *weight;  ////use a pair <int,int>
	vector<int> parent;
	vector<int> timein;
	vector<int> timeout;
	vector<int> visited; //0=white,1=gray,2=black//
	vector<int> topsort; //basically you want stack so use it
	///make space for distance of each vertices;
	int time;
public:
	graph(int v);
	void insert_edge(int a,int b);
	void insert_weight(int a,int b);
	void print_adj(int a);
	void dfs();
	void dfs_visit(int s);
	void print_all();
	void dag(int s);
};

graph::graph(int v){
	this->v = v;
	list = new vector<int>[v];
	weight = new vector<int>[v];
}

void graph::insert_edge(int a,int b){
	list[a].push_back(b);
}

void graph::insert_weight(int a,int b){
	weight[a].push_back(b);
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

void graph::dag(int s){
	int key[v];
	int p[v];
	for(int j=0;j<v;j++){
		key[j] = 10000;  ///large number but not  so large that on 
		//adding somwthing it goes out of the range of integer. :)
		p[j] = -1;
	}
	key[s] = 0; ////////source is vertices 1
	for(int i=v-1;i>=0;i--){
		vector<int>::iterator it,it1;
		int a = topsort[i];
		for(it=list[a].begin(),it1=weight[a].begin();it!=list[a].end();it++,it1++){
			//relax for *it
			if((key[topsort[i]]+*it1)<(key[*it])){
				key[*it] = (key[topsort[i]]+*it1);
				p[*it] = topsort[i];
			}
		}
	}
	for(int i=0;i<v;i++){
		cout<<key[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
}

void graph::print_all(){
	for(int i=0;i<v;i++){
		cout<<parent[i]<<" "<<timein[i]<<" "<<timeout[i]<<endl;
	}
	cout<<endl;
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,e,s,d,w;
    cin>>n>>e;
    graph g(n);
    for(int i=0;i<e;i++){
    	cin>>s>>d>>w;
    	g.insert_edge(s,d);
    	g.insert_weight(s,w);
    }
    g.dfs();
    g.print_all();
    g.dag(1);
}