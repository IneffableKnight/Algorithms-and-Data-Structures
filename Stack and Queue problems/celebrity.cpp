#include <bits/stdc++.h>
using namespace std;



int main(){
	bool mat[5][5] = {{0, 1 ,0, 0, 0},{1, 0, 0, 1, 1},
	{1, 0, 0, 0, 0},{1, 1, 0, 0 ,0},{1, 1, 1 ,0, 0}};
	int n=5;
	stack <int> s;
	for(int i=0;i<n;i++){
		s.push(i);
	}
	int in = n;
	int a1,a2;
	while(in>1){
		a1 = s.top();
		s.pop();
		a2 = s.top();
		s.pop();
		cout<<a1<<" "<<a2<<endl;
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
			else{
				in = in-2;
			}
		}
	}
	if(in==0){
		cout<<"no one is  celebrity"<<endl;
	}
	if(in==1){
		int l = s.top();
		int flag = 1;
		for(int i=0;i<n;i++){
			if(mat[l][i]==1){
				flag = 0;
				break;
			}
			if(mat[i][l]==0){
				if(i!=l){
					flag = 0;
					break;
				}
			}
		}
		if(flag){
			cout<<l<<endl;
		}
		else{
			cout<<"no one is  celebrity"<<endl;
		}
	}
}
