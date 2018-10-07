#include<bits/stdc++.h>

using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n,i,st=-1,en,temp;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	////make  partition to seperate + and -
	for(en=0;en<n;en++){
		if(arr[en]<0){
			st++;
			swap(&arr[st],&arr[en]);
			//temp = arr[st];
			//arr[st]= arr[en];
			//arr[en] = temp;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	////no alteernatively swap 
	int count =0 ;
	for(i=0;i<n;i++){
		if(arr[i]<0){
			count++;}
	}
	int counta = 1, countb = count,countc=0;
	while((countc<count)&&(countb<n)){
		swap(&arr[counta],&arr[countb]);
		//temp = arr[counta];
		//arr[counta] = arr[countb];
		//arr[countb] = temp;
		counta += 2;
		countb++;
		countc++;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}