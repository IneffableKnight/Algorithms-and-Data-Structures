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

void wave(int arr[],int n){
	for(int i=0;i<n;i=i+2){
		if(i==0){
			if(arr[i]<arr[i+1]){swap(&arr[i],&arr[i+1]);}
		}
		else if(i==n-1){
			if(arr[i-1]>arr[i]){swap(&arr[i],&arr[i-1]);}
		}
		else {
			if(arr[i]<arr[i-1]){swap(&arr[i],&arr[i-1]);}
			if(arr[i]<arr[i+1]){swap(&arr[i],&arr[i+1]);}
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
	int n,i,st=-1,en,temp;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	printarrrray(arr,n);
	wave(arr,n);
	printarrrray(arr,n);
	return 0;
}