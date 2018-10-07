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

void parti(int arr[],int n,int hi, int low){
	int j=-1,k=-1,l=0;
	for(l=0;l<n;l++){
		if(arr[l]>=hi){
			continue;
		}
		else{
			if(arr[l]>=low){
				k++;
				swap(&arr[k],&arr[l]);
			}
			else{
				k++;
				swap(&arr[k],&arr[l]);
				j++;
				swap(&arr[k],&arr[j]);
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
	int n,i,hi,lo;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>hi;
	cin>>lo;
	printarrrray(arr,n);
	parti(arr,n,hi,lo);
	//sor(arr,n);
	printarrrray(arr,n);
	return 0;
}