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

class que: public Stack{
private:
	Stack left;
	Stack right;
public:
	void push(int x);
	int pop();
};

int que::pop(){
	int k;
	if(left.isEmpty()==1){
		while(right.isEmpty()==0){
			k = right.pop();
			left.push(k);
		}
		left.pop();
	}
	else{
		left.pop();
	}
}

void que::push(int x){
		right.push(x);
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct que s;
	s.push(10);
	s.push(20);
	cout<<s.pop()<<endl;
	s.push(5);
	s.push(23);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
}
