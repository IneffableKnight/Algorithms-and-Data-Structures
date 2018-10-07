#include <bits/stdc++.h>
using namespace std;

long long int powe(long long int a,long long int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	if(b%2==0){
		int s = powe(a,b/2);
		return s*s;
	}
	else{
		int s = powe(a,b/2);
		return s*s*a;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long long int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	long long int p = powe(a,b*c);
	cout<<p<<endl;
}