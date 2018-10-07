#include <bits/stdc++.h>
using namespace std;
double intlog(double base, double x) {
    return (log(x) / log(base));
}

int main(){
	int f=10;
	int n=100;
	int temp,carry=0,siz=0,i,j;
	vector<int> ans(n,0);
	ans[0] = 1;
	for(i=2;i<f+1;i++){
		carry = 0;
		for(j=0;j<=siz;j++){
			temp = ans[j]*i + carry;
			//cout<<ans[j]<<" "<<i<<endl;
			ans[j] = temp%10;
			carry = temp/10;
		}
		if(carry>0){
			ans[j] = carry;
			siz++;
		}
	}
	for(i=siz;i>-1;i--){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	cout<<intlog(3,10);
	double ssss = 2.0959;
	if(ssss==intlog(3,10));{
		cout<<"yes";
	}
	//cout<<INT_MAX*3<<endl;
}