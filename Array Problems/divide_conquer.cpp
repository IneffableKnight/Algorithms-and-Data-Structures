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

int max_sum(int arr[],int p, int q){
	if(q==p){return arr[q];}
	int r = (p+q)/2;
	int suml = max_sum(arr,p,r);
	int sumr = max_sum(arr,r+1,q);
	int sum1=0,sum2=0,max1=0,max2=0;
	for(int i=r+1;i<=q;i++){
		sum1 += arr[i];
		if(max1<sum1){max1 =sum1;}
	}
	for(int i=r;i>=p;i--){
		sum2 += arr[i];
		if(max2<sum2){max2 =sum2;}
	}
	if(((max1+max2)>=suml)&&((max1+max2)>=sumr)){return (max1+max2);}
	if((suml>=sumr)&&(suml>=(max1+max2))){return suml;}
	if((suml<=sumr)&&(sumr>=(max1+max2))){return sumr;}
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
	int ans = max_sum(arr,0,n-1);
	cout<<ans<<endl;
	//printarrrray(arr,n);
	return 0;
}