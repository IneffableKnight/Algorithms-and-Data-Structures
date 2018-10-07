#include <bits/stdc++.h>
using namespace std;


void lps(int arr[],string pat){
	int k = -1; //intitial index of the prefix
	arr[0] = -1;
	for(int i=1;i<pat.length();i++){
		while((k>-1)&&(pat[k+1]!=pat[i])){
			k = arr[k];
		}
		if(pat[k+1]==pat[i]){
			k++;
		}
		arr[i] = k;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string palin;
	cin>>palin;
	int m = palin.length();
	int arr[m];
	lps(arr,palin);
	for(int i=0;i<m;i++){
		cout<<arr[i]<<" ";
	}
}