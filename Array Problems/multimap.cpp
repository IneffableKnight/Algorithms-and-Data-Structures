#include<bits/stdc++.h>

using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarrrray(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void sor(int arr[],int n,int ab){
	multimap<int, int> ma;
	for(int i=0;i<n;i++){
		ma.insert(make_pair(abs(arr[i]-ab),arr[i]));
	}
	int i = 0 ;
	for(auto it = ma.begin;it!=ma.end;it++){
		arr[i++] = (*it).second;
	}
}

int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n,i,ab;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>ab;
	printarrrray(arr,n);
	sor(arr,n,ab);
	printarrrray(arr,n);
	return 0;
}