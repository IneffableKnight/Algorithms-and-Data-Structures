#include <bits/stdc++.h>
#include <time.h>

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


void perm(int arr[],int n){
	srand(time(NULL));
	for(int i=n-1;i>0;i--){
		int s = rand()%(i+1);
		swap(&arr[s],&arr[i]);
	}
}


int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printarrrray(arr,n);
	perm(arr,n);
	printarrrray(arr,n);
	return 0;
}