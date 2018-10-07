#include<bits/stdc++.h>

using namespace std;
//innsertion sort
//optimised merge sort
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

void reinsert(int arr[],int n){
	int j;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			for(j=i-1;j>=0;j--){
				if(arr[j]<0){
					break;
				}
			}
			int temp = arr[i];
			for(int k=i;k>j+1;k--){
				arr[k] = arr[k-1];
			}
			arr[j+1] = temp;
		}
	}
}



void merge(int arr[],int p, int r, int q){
	int n1 = r-p+1;
	int n2 = q-r;
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++){
		arr1[i] = arr[p+i];
	}
	for(int i=0;i<n2;i++){
		arr1[i] = arr[r+1+i];
	}
	int count=0,i,j;
	for(i=0;i<n1;i++){
		if(arr1[i]<0){
			arr[count++] = arr1[i];
		}
		else{break;}
	}
	for(j=0;j<n2;j++){
		if(arr2[j]<0){
			arr[count++] = arr2[j];
		}
		else{break;}
	}
	for(i=i;i<n1;i++){
		if(arr1[i]>=0){
			arr[count++] = arr1[i];
		}
	}
	for(j=j;j<n2;j++){
		if(arr2[j]>=0){
			arr[count++] = arr2[j];
		}
	}
}

void mergesort(int arr[],int p,int q){
	if(q>p){
		int r = (p+q)/2;
		mergesort(arr,p,r);
		mergesort(arr,r+1,q);
		merge(arr,p,r,q);
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
	mergesort(arr,0,n-1);
	printarrrray(arr,n);
	return 0;
}