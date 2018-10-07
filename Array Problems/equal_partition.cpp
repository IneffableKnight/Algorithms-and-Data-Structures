//Recursion
//See if even
//See if the present left or unleft works or not
//Pass: Array/no. of undecided elements/sum left
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

void printmat(bool arr[][7],int m,int n){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


void sor(int arr[], int n){
	sort(arr,arr+n);
}

bool ispart(int arr[],int n,int sum){
	if(n==0){
		if(sum==0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(sum==0){
			return true;
		}
		else{
			return((ispart(arr,n-1,sum-arr[n-1]))||(ispart(arr,n-1,sum)));
		}
	}
}

bool ispartdp(int arr[],int n,int sum){
	bool mem[sum+1][7];
	for(int i=0;i<=sum;i++){
		mem[i][0] = false;
	}
	for(int i=0;i<=n;i++){
		mem[0][i] = true;
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			mem[i][j] = mem[i][j-1];
			if(i>=arr[j-1]){
				mem[i][j] = ((mem[i][j])||(mem[i-arr[j-1]][j-1]));
			}

		}
	}
	printmat(mem,sum,n);
	return mem[sum][n];
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
	int sum = 0;
	for(int j=0;j<n;j++){
		sum += arr[j];
	}
	bool ans;
	if(sum%2!=0){
		ans = false;
	}
	else{
		ans = ispartdp(arr,n,sum/2);
	}
	cout<<ans<<endl;
	return 0;
}