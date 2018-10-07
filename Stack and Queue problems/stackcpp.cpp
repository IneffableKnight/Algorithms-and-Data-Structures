#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
	int arr[100];
	int top;
public:
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

class specialstack: public Stack{
private:
	Stack min;
public:
	int getmin();
	void push(int x);
	int pop();
};

int specialstack::pop(){
	min.pop();
	int x = Stack::pop();
	return x;
}

void specialstack::push(int x){
	if(isEmpty()){
		min.push(x);
		Stack::push(x);
	}
	else{
		Stack::push(x);
		int m = min.pop();
		min.push(m);
		if(m<x){
			min.push(m);
		}
		else{
			min.push(x);
		}
	}
}

int specialstack::getmin(){
	int x = min.pop();
	min.push(x);
	return x;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct specialstack s;
	s.push(10);
	cout<<s.getmin()<<endl;
	s.push(20);
	s.push(5);
	cout<<s.getmin()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.getmin()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
}
