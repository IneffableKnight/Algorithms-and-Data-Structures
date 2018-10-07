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

void sor(int arr[], int n){
	sort(arr,arr+n);
}

int z_to_o(int arr[],int n){
	int max = 0,sum=0,temp=0,index=0,imax=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			sum++;
		}
		else{
			temp += sum;
			if(temp>max){
				max = temp;
				imax = index;
			}
			temp = sum;
			sum = 0;
			index = i;
		}
	}
	temp += sum;
	if(temp>=max){
		max = temp;
		imax = index;
	}
	return imax;
}

int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n,i,hi,lo;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>hi;
	cin>>lo;
	printarrrray(arr,n);
	int ans = z_to_o(arr,n);
	cout<<ans<<endl;
	//printarrrray(arr,n);
	return 0;
}