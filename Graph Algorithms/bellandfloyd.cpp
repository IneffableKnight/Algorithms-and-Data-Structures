//#include <bits/stdc++.h>
#include <stdio.h>
//#include <iostream>

using namespace std;

#define inf 10000
#define v 5
#define e 8
#define V 4

int main(){
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
	int mat[4][4] = {
		{0,5,inf,10},
		{inf,0,3,inf},
		{inf,inf,0,1},
		{inf,inf,inf,0}
	};
	/*int src[8] = {0,0,1,1,1,3,3,4};
	int des[8] = {1,2,2,3,4,2,1,3};
	int we[8] = {-1,4,3,2,2,5,1,-3};
	int dist[5] = {0,inf,inf,inf,inf};
	for(int i=1;i<=v-1;i++){
		for(int j=0;j<e;j++){
			if(dist[des[j]]>dist[src[j]]+we[j]){
				dist[des[j]] = dist[src[j]]+we[j];
			}
		}
	}
	for(int j=0;j<e;j++){
		if(dist[des[j]]>dist[src[j]]+we[j]){
			cout<<"cycle bad";
		}
	}
	for(int i=0;i<v;i++){
		cout<<dist[i]<<" ";
	}*/

	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(mat[i][k]!=inf && mat[k][j]!=inf && mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j] = mat[i][k]+mat[k][j];
				}
			}
		}
	}

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			printf("%d ",mat[i][j]);
			//cout<<mat[i][j]<<" ";
		}
		printf("\n");
		//cout<<endl;
	}
	return 0;
}