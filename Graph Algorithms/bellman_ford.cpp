#include <bits/stdc++.h>
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int v,e,s,d,w;
    cin>>v>>e;
    int source[e],dest[e],weight[e];
    for(int i=0;i<e;i++){
    	cin>>source[i]>>dest[i]>>weight[i];
    }
    int p[v],key[v];
    for(int i=0;i<v;i++){
    	p[i] = -1;
    	key[i] = INT_MAX/2;
    }
    key[0] = 0; //source
    for(int i=0;i<v-1;i++){
    	for(int j=0;j<e;j++){
    		if(key[dest[j]]>(key[source[j]]+weight[j])){
    			//cout<<key[source[j]]<<endl;
    			p[dest[j]] = source[j];
    			key[dest[j]] = key[source[j]]+weight[j];
    		}
    	}
    }
    for(int j=0;j<e;j++){
		if(key[dest[j]]>(key[source[j]]+weight[j])){
			cout<<"there is a negative cycle"<<endl;
		}
    }
    for(int j=0;j<v;j++){
    	cout<<key[j]<<" ";
    }
}