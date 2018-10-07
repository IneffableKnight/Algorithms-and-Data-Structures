#include <bits/stdc++.h>

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

void sor(int arr[], int n){
	sort(arr,arr+n);
}

void opele(int arr[],int n){
	int prev,temp;
	prev = arr[0];
	arr[0] = arr[0]*arr[1];
	for(int i=1;i<n-1;i++){
		temp = prev*arr[i+1];
		prev = arr[i];
		arr[i] = temp;
	}
	arr[n-1] = arr[n-1]*prev;
}

int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n,sum=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printarrrray(arr,n);
	opele(arr,n);
	printarrrray(arr,n);
	return 0;
}