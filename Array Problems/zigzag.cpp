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

void zigzag(int arr[],int n){
	for(int i=0;i<n;i++){
		if(i%2==1){
			if(arr[i-1]>arr[i]){swap(&arr[i-1],&arr[i]);}
			if(arr[i+1]>arr[i]){swap(&arr[i+1],&arr[i]);}
		}
	}
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
	zigzag(arr,n);
	printarrrray(arr,n);
	return 0;
}