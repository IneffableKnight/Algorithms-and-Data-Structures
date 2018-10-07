#include <bits/stdc++.h>
using namespace std;

class que{
private:
	int arr[100];
	int top;
	int bot;
public:
	que(){
		top=99;
		bot=99;
	}
	void enq(int x);
	int deq();
	int ele();
	void prin();
};

void que::enq(int x){
	if(bot>0){
		arr[bot] = x;
		bot--;
	}
	else{
		cout<<"overflow"<<endl;
	}
}

int que::deq(){
	if(top>bot){
		top--;
		return arr[top+1];
	}
	else{
		cout<<"underflow"<<endl;
		return -1;
	}
}

int que::ele(){
	return (top-bot);
}

void que::prin(){
	for(int i=bot+1;i<=top;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

class sq: public que{
public:
	int peq();
};

int sq::peq(){
	int temp = que::ele();
	int r;
	while(temp>1){
		//cout<<"yes"<<endl;
		temp--;
		r = que::deq();
		//cout<<r<<endl;
		que::enq(r);
		//prin(); 
	}
	return que::deq();
}

int main(){
	struct sq q;
	q.enq(10);
	//q.prin();
	q.enq(9);
	//q.prin();
	//cout<<q.deq()<<endl;
	q.enq(8);
	//q.prin();
	q.enq(7);
	//q.prin();
	cout<<q.peq()<<endl;
	//q.prin();
	//q.prin();
	cout<<q.peq()<<endl;
	//q.prin();
	cout<<q.peq()<<endl;
	//q.prin();
	cout<<q.peq()<<endl;
	//q.prin();
}