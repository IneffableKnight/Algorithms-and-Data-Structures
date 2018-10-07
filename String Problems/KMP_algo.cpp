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

void KMP(string text,string pat){
	int m = pat.length();
	int n = text.length();
	int arr[m];
	lps(arr,pat);
	int q=-1;   //i till which pattern matched
	for(int i=0;i<n;i++){
		while((q>-1)&&(text[i]!=pat[q+1])){
			q = arr[q];
		}
		if(text[i]==pat[q+1]){
			q++;
		}
		if(q==m-1){
			cout<<"pattern exists "<<i-m+1<<" to "<<i<<endl;
			q = arr[q];
		}
	}
	for(int i=0;i<m;i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string text;
	string pattern;
	getline(cin,text);
	getline(cin,pattern);
	KMP(text,pattern);
}