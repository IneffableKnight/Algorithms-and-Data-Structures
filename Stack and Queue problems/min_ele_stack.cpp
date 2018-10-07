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
public:
	int minele;
	void push(int x);
	int pop();
};



void specialstack::push(int x){
	if(isEmpty()){
		Stack::push(x);
		minele = x;
	}
	else{
		if(minele<=x){
			Stack::push(x);
		}
		else{
			Stack::push(2*x-minele);
			minele = x;
		}
	}
}

int specialstack::pop(){
	int x = Stack::pop();
	if(minele<=x){
		//cout<<minele<<"true"<<x<<endl;
		return minele;
	}
	else{
		//cout<<minele<<"fa"<<x<<endl;
		int temp = minele;
		minele = 2*minele-x;
		return temp;
	}
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct specialstack s;
	s.push(10);
	cout<<s.minele<<endl;
	s.push(20);
	cout<<s.minele<<endl;
	s.push(5);
	cout<<s.minele<<endl;
	s.push(30);
	cout<<s.minele<<endl;
	s.push(2);
	cout<<s.minele<<endl;
	cout<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
}
