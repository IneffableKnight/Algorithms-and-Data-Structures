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

void ispart(int arr[],int n){
	bool a1[2*n+1];
	int a2[2*n+1];
	for(int i=0;i<2*n+1;i++){
		a1[i] = false;
	}
	int max=0;
	int indf;
	for(int j=0;j<n;j++){
		if(a1[arr[j]]){
			if(max<(j-a2[arr[j]])){
				max = j-a2[arr[j]];
				indf = j;
			}
		}
		else{
			a1[arr[j]] = true;
			a2[arr[j]] = j;
		}

	}
	cout<<max<<endl;
	cout<<a2[arr[indf]]<<" to "<<indf<<endl;
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
	int sum[n];
	if(arr[0]==1){sum[0] = 1;}
	else{sum[0] = -1;}
	for(int i=1;i<n;i++){
		if(arr[i]==0){sum[i]=sum[i-1]-1;}
		if(arr[i]==1){sum[i]=sum[i-1]+1;}
	}
	printarrrray(sum,n);
	ispart(sum,n);
	return 0;
}