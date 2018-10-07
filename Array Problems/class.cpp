#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int arr[7] = {100,180,260,310,40,535,695};
	int n = 7;
	int i=0,j=0,sum=0;
	while(i<n&&j<n){
		while(i<n-1&&arr[i]>=arr[i+1]){
			i++;
		}
		if(i==n-1){
			cout<<sum<<endl;
			return sum;
		}
		j = i+1;
		while(j<n&&arr[j-1]<=arr[j]){
			j++;
		}
		sum += arr[j-1]-arr[i];
		cout<<sum<<endl;
		if(j==n){
			cout<<sum<<endl;
			return sum;
		}
		i = j;

	}
	cout<<sum<<endl;
	return sum;
}