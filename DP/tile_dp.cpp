#include <bits/stdc++.h>
using namespace std;

int dp(int arr[],int n){
	if(arr[n]!=-1){return arr[n];}
	else if(n==2){arr[n] = 3;return arr[n];}
	else if(n<2){arr[n] = 1;return arr[n];}
	else{
		arr[n] = 3*dp(arr,n-2);
		int temp = n-4;
		while(temp>=0){
			arr[n] += 2*dp(arr,temp);
			temp -= 2;
		}
		return arr[n];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	n = 12;
	int arr[100];
	memset(arr,-1,sizeof(arr));
	cout<<dp(arr,n);
	return 0;
}