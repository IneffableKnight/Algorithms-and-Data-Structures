#include <bits/stdc++.h>
#include <time.h>

using namespace std;
///Logic: compare maximum non circular subarray sum with entire sum - minimum sum of 
/// subarray this will help to find the two extreme max with both end points included 
///as it is a circular case

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

int maxsum(int arr[],int n){
	int maxi=0,maxf=0,maxv=0,ini=0,sum=0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum>0){
			if(sum>maxv){
				maxv = sum;
				maxf = i;
				maxi = ini;
			}
		}
		else{
			sum = 0;
			ini = i+1;
		}
	}
	//cout<<"The max sum is "<<maxv<<endl;
	//cout<<"It starts from "<<maxi+1<<" to "<<maxf+1<<endl;
	return maxv;
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
	int a1 = maxsum(arr,n);
	for(int i=0;i<n;i++){
		sum += arr[i];
		arr[i] = arr[i]*(-1);
	}
	int a2 = maxsum(arr,n);
	int a3 = sum+a2;
	if(a3<=a1){
		cout<<a1<<endl;
	}
	else{
		cout<<a3<<endl;
	}
	//printarrrray(arr,n);
	return 0;
}