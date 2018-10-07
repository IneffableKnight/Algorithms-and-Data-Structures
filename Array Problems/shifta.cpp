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

void shifta(int arr1[],int arr2[],int n){
	int s =n,k=0,temp1=arr1[0],temp2,k_prev;
	int b = 15;
	while((s)&&(b>0)){
		b--;
		//cout<<b<<endl;
		if(arr2[k]>-1){
			temp2 = arr1[arr2[k]];
			arr1[arr2[k]] = temp1;
			temp1 = temp2;
			k_prev = k;
			k = arr2[k];
			arr2[k_prev] = -1;
			s--;
		}
		else{
			for(int i=k;i<n;i++){
				if(arr2[i]>-1){
					k = i;
					temp1 = arr1[k];
					break;
				}
			}
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
	int arr1[n],arr2[n];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	printarrrray(arr1,n);
	printarrrray(arr2,n);
	shifta(arr1,arr2,n);
	printarrrray(arr1,n);
	printarrrray(arr2,n);
	return 0;
}