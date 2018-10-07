#include <bits/stdc++.h>
using namespace std;



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	bool mat[5][5] = {{1 0 0 0 0},{1 1 0 1 1},
	{1 0 1 0 0},{1 1 0 1 0},{1 1 1 0 1}};
	int n=5;
	stack <int> s;
	for(int i=0;i<n;i++){
		s.push(i);
	}
	int in = n;
	int a1,a2;
	while(in>0){
		a1 = s.top();
		s.pop();
		a2 = s.top();
		s.pop();
		if(mat[a1][a2]){
			if(mat[a2][a1]){
				in = in-2;
			}
			else{
				s.push(a2);
				in--;
			}
		}
		else{
			if(mat[a2][a1]){
				s.push(a1);
				in--;
			}
		}
	}
}
