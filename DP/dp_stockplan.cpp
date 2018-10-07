#include <bits/stdc++.h>
using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,sum,temp;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s[n];
	s[0] = 1;
	for(int i=1;i<n;i++){
		sum = 1;
		if(arr[i-1]>arr[i]){
			s[i] = sum;
		}
		else{
			sum = 1;
			temp = i-1;
			while((arr[temp]<=arr[i])&&(temp>=0)){
				sum += s[temp];
				temp = temp-s[temp];
			}
			s[i] = sum;
		}
	}
	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
}
