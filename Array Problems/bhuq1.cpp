#include <bits/stdc++.h>
using namespace std;


int rec(int i,string a,string b,vector<int> &tt){
	if(i==a.length()){return 0;}
	if(a[i]==b[i]){return rec(i+1,a,b,tt);}
	if(i==a.length()-1){return 1;}
	if(tt[i]!=-1){return tt[i];}
	int a1=INT_MAX,a2=INT_MAX,temp;
	a1 = 1+rec(i+1,a,b,tt);
	if(b[i]==a[i+1]){
		temp = a[i+1];
		a[i+1] = a[i];
		a2 = 1+rec(i+1,a,b,tt);
		a[i+1] = temp;
	}
	if(a2<a1){tt[i] = a2;}
	else{tt[i] = a1;}
	return tt[i];
}

int main(){
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<int> tt(n+1,-1);
	cout<<rec(0,a,b,tt);
	return 0;
}