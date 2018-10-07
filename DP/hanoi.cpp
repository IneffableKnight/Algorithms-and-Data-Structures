#include <bits/stdc++.h>
using namespace std;

void recur(int n, int a, int b,int c){
	if(n>1){
		recur(n-1,a,c,b);
		cout<<n<<" from "<<a<<" to "<<c<<endl;
		recur(n-1,b,a,c);
	}
	else{
		cout<<n<<" from "<<a<<" to "<<c<<endl;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n =2;
	recur(n,1,2,3);
}
