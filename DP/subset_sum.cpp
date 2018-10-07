#include <bits/stdc++.h>
using namespace std;

int dp(int arr[],int n,int dparr[],int sum,bool pre[]){
	cout<<sum<<endl;
	int temp;
	if(dparr[sum]!=-1){return dparr[sum];}
	if(sum==0){return 1;}
	for(int i=0;i<n;i++){
		if((pre[i])&&(sum>=arr[i])){
			pre[i] = false;
			temp = dp(arr,n,dparr,sum-arr[i],pre);
			if(temp==1){
				dparr[sum] = 1;
				return dparr[sum];
			}
			pre[i] = true;
		}
	}
	dparr[sum] = 0;
	return 0;
}

int dp1(int arr[])

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	int arr[n];
	int sum;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>sum;
	bool pre[n];
	for(int i=0;i<n;i++){
		pre[i] = true;
	}
	int dparr[1000];
	for(int i=0;i<1000;i++){
		dparr[i] = -1;
	}
	int ans  = dp(arr,n,dparr,sum,pre);
	cout<<ans<<endl;
	/*for(int i=0;i<10;i++){
		cout<<i<<" "<<dparr[i]<<endl;
	}*/
	return 0;
}