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

void maxsum(int arr[],int n){
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
	cout<<"The max sum is "<<maxv<<endl;
	cout<<"It starts from "<<maxi+1<<" to "<<maxf+1<<endl;
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
	maxsum(arr,n);
	printarrrray(arr,n);
	return 0;
}