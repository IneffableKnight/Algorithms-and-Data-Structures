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
	void prin(){
		for(int i=0;i<=top;i++){
			cout<<arr[i]<<" ";
		}
	}
};

int Stack::pop(){
	if(top>=0){
		return arr[top--];
	}
	else{
		cout<<"underflow"<<endl;
		return -1;
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
public:
	void push(int x);
	int pop();
};

void que::push(int x){
	if(isEmpty()){
		Stack::push(x);
		//cout<<"yes1"<<endl;
	}
	else{
		int k = Stack::pop();
		if(isEmpty()){
			//cout<<"yes2"<<endl;
			Stack::push(x);
			Stack::push(k);
		}
		else{
			//cout<<"yes3"<<endl;
			push(x);
			Stack::push(k);
		}
	}
}

int que::pop(){
	Stack::pop();
}



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	struct que s;
	s.push(10);
	//s.prin();
	//cout<<endl;
	s.push(20);
	cout<<s.pop()<<endl;
	//s.prin();
	//cout<<endl;
	//cout<<s.pop()<<endl;
	s.push(5);
	//s.prin();
	//cout<<endl;
	s.push(23);
	//s.prin();
	cout<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.isEmpty()<<endl;
}
