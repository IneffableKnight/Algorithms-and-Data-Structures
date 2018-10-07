#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
	int arr[100];
	int top;
	Stack(){top = -1;}
	int pop();
	bool push(int x);
	bool isEmpty();
};

int Stack::pop(){
	if(top>=0){
		return arr[top--];
	}
	else{
		cout<<"underflow"<<endl;
	}
}
bool Stack::push(int x){
	if(top<99){
		arr[++top] = x;
		return true;
	}
	else{
		cout<<"overflow"<<endl;
		return false;
	}
}
bool Stack::isEmpty(){
	return (top<0);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct Stack s;
	cout<<s.push(10)<<endl;
	cout<<s.push(20)<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
}
