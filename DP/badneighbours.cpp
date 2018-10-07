#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;j--;
    }
}

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
    if(n==2){
        if(arr[0]>arr[1])
            {return arr[0];}
        else
            {return arr[1];}
    }
    vector<int> sum(n-1);
    sum[0] = arr[0];
    sum[1] = arr[1];
    for(int i =2;i<n-1;i++){
        if(arr[i]+sum[i-2]>sum[i-1]){
            sum[i] = arr[i]+sum[i-2];
        }
        else{
            sum[i] = sum[i-1];
        }
    }
    int max=0;
    for(int i=0;i<n-1;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        if(max<sum[i]){max = sum[i];}
    }
    cout<<max<<endl;
    reverse(arr,n);
    sum[0] = arr[0];
    sum[1] = arr[1];
    for(int i =2;i<n-1;i++){
        if(arr[i]+sum[i-2]>sum[i-1]){
            sum[i] = arr[i]+sum[i-2];
        }
        else{
            sum[i] = sum[i-1];
        }
    }
    max=0;
    for(int i=0;i<n-1;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        if(max<sum[i]){max = sum[i];}
    }
    cout<<max<<endl;
}