#include <bits/stdc++.h>
#include <stack>  
using namespace std;

void print_stack(stack <int> &s){
	int temp = s.top();
	s.pop();
	if(s.empty()==0){
		print_stack(s);
		cout<<temp<<" ";
		s.push(temp);
	}
	else{
		cout<<temp<<" ";
		s.push(temp);
	}
}

void put_down(stack <int> &s,int t){
	if(s.empty()){
		s.push(t);
	}
	else{
		int temp = s.top();
		s.pop();
		if(t<=temp){
			s.push(temp);
			s.push(t);
		}
		else{
			put_down(s,t);
			s.push(temp);
		}
	}
}

void rec_sta(stack <int> &s){
	int temp = s.top();
	//cout<<"yes"<<endl;
	s.pop();
	//cout<<temp<<endl;
	if(s.empty()==0){
		rec_sta(s);
		put_down(s,temp);
	}
	else{
		s.push(temp);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	stack <int> s;
	int n,j;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>j;
		s.push(j);
	}
	print_stack(s);
	cout<<endl;
	rec_sta(s);
	print_stack(s);
	cout<<endl;
}