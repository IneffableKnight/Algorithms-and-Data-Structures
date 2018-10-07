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

void funinc(int arr[],int inc[],int n){
	inc[0] = 1;
	for(int i=1;i<n;i++){
	//search for maximum element smaller or equal to ith update (inc[num]+1)
		int index = 0;
		for(int j=0;j<i;j++){
			if((arr[j]<=arr[i])&&(inc[j]>=inc[index])){
				index = j;
				inc[i] = inc[index] + 1;
			}
		}
	}
}

void fundec(int arr[],int dec[],int n){
	dec[n-1] = 1;
	for(int i=n-1;i>=0;i--){
	//search for maximum element smaller or equal to ith update (inc[num]+1)
		int index = n-1;
		for(int j=n-1;j>i;j--){
			if((arr[j]<=arr[i])&&(dec[j]>=dec[index])){
				index = j;
				dec[i] = dec[index] + 1;
			}
		}
	}
}

void finele(int arr[],int inc[],int dec[],int ele[],int n,int index,int siz){
	int tem1[inc[index]-1];
	int tem2[dec[index]-1];
	int are = arr[index];
	int val = inc[index];
	int t=0;
	for(int i=index-1;((i>=0)&&(t<inc[index]-1));i--){
		if((arr[i]<=are)&&(val-1==inc[i])){
			are = arr[i];
			val--;
			tem1[t++] = are;
		}
	}
	are = arr[index];
	val = dec[index];
	t=0;
	for(int i=index+1;((i<n)&&(t<dec[index]-1));i++){
		if((arr[i]<=are)&&(val-1==dec[i])){
			are = arr[i];
			val--;
			tem2[t++] = are;
		}
	}
	//printarrrray(tem1,inc[index]-1);
	//printarrrray(tem2,dec[index]-1);
	t = inc[index]-1;
	int u=0;
	while(t>0){
		ele[u++] = tem1[t-1];
		t--;
	}
	ele[u++] = arr[index];
	t = dec[index]-1;
	int uu =0;
	while(t>0){
		ele[u++] = tem2[uu++];
		t--;
	}
	printarrrray(ele,siz);
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
	int inc[n];
	int dec[n];
	for(int y=0;y<n;y++){
		inc[y] = 1;
		dec[y] = 1;
	}
	funinc(arr,inc,n);
	fundec(arr,dec,n);
	int sum = 0;
	int index;
	for(int i=0;i<n;i++){
		if(sum<=(inc[i]+dec[i])){
			sum = inc[i]+dec[i];
			index = i;
		}
	}
	//cout<<index<<endl;
	//cout<<sum-1<<endl;
	int ele[sum-1];
	finele(arr,inc,dec,ele,n,index,sum-1);
	//printarrrray(inc,n);
	//printarrrray(dec,n);
	printarrrray(ele,sum-1);
	return 0;
}