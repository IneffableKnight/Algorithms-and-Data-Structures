#include <bits/stdc++.h>
using namespace std;


void spush(int arr[],int prev[],int stck[],int a,int b,int* ind){
	if(stck[a]==-1){
		stck[a] = *ind;
		prev[*ind] = -1;
		arr[*ind] = b;
		*ind += 1;
	}
	else{
		int k = stck[a];
		stck[a] = *ind;
		prev[*ind] = k;
		arr[*ind] = b;
		*ind += 1;
	}
}

int spop(int arr[],int prev[],int stck[],int a){
	if(stck[a]==-1){
		cout<<"Underflow"<<endl;
		return -1;
	}
	else{
		int k = stck[a];
		int l = prev[k];
		stck[a] = l;
		return arr[k];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int i,sn,t,a,b,ind=0;
	int arr[100];
	int prev[100];
	int stck[50];
	//////////////////////
	for(int i=0;i<100;i++){
		arr[i] = -1;
		prev[i] = -1;
	}
	for(int i=0;i<50;i++){
		stck[i] = -1;
	}
	/////////////////////
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>a>>b;
		spush(arr,prev,stck,a,b,&ind);
	}
	/////////////////////
	for(int j=0;j<t;j++){
		cout<<arr[j]<<endl;
	}
	cout<<endl;
	//////////////////////
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>a;
		cout<<spop(arr,prev,stck,a)<<endl;
	}
}