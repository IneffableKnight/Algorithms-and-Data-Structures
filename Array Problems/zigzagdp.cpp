#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    if(n==1){return 1;}
    if(n==2){return 2;}
    vector<int> seq(n);
    vector<int> last(n);
    vector<int> lastid(n);
    seq[0] = 1;lastid[0]=0;
    for(int i=1;i<n;i++){
    	if(arr[i]!=arr[0]){
    		seq[i]=2;last[i]=arr[0];lastid[i]=0;
    	}
    	else{
    		seq[i] = 1;last[i] = arr[i];lastid[i]=i;
    	}
    }
    for(int i=2;i<n;i++){
    	for(int j=i;j>0;j--){
    		if(arr[j]==arr[i]){continue;}
    		if(arr[j]>arr[i]){
    			if((last[j]<arr[j])&&(seq[j]+1>seq[i])){seq[i] = seq[j]+1;last[i] = arr[j];lastid[i]=j;}
    		}
    		if(arr[j]<arr[i]){
    			if((last[j]>arr[j])&&(seq[j]+1>seq[i])){seq[i] = seq[j]+1;last[i] = arr[j];lastid[i]=j;}
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	cout<<seq[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
    	cout<<last[i]<<"  ";
    }
    for(int i=0;i<n;i++){
    	cout<<lastid[i]<<"  ";
    }
    cout<<endl;
    int max=0,id=0;
    for(int i=0;i<n;i++){
    	if(max<seq[i]){max=seq[i];id=i;}
    }
    cout<<id<<endl;
    while(id!=lastid[id]){
    	cout<<arr[id]<<" ";
    	id  = lastid[id];
    }
    cout<<arr[id]<<" ";
    cout<<endl;
}