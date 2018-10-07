#include <bits/stdc++.h>
#include <stack>  
using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	stack <int> s;
	int n,j,l;
	cin>>n;
	int arr[n],dat[n];
	for(int j=0;j<n;j++){
		cin>>arr[j];
	}
	s.push(0);
	dat[0] = 1;
	for(int i=1;i<n;i++){
		while((s.empty()==0)&&(arr[s.top()]<=arr[i])){
			s.pop();
		}
		if(s.empty()){
			dat[i] = i+1;
		}
		else{
			dat[i] = i-s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<dat[i]<<" ";
	}
	cout<<endl;
}