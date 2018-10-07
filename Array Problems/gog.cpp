#include <bits/stdc++.h>
using namespace std;

bool fun1(int a){
	return !(a&(a-1));
}
int fun2(int b){
	int val = b;
	int count=0;
	while(val){
		val = val&(val-1);
		count++;
	}
	return count;
}
bool fun3(int c){
	return (ceil(log2(c)))==(floor(log2(c)));
}

int diff(int arr[],int n){
	int count=0,temp;
	for(int i=0;i<32;i++){
		temp=0;
		for(int j=0;j<n;j++){
			if(arr[j]&(1<<i)){
				temp++;
			}
		}
		//cout<<temp<<endl;
		count += (n-temp)*temp*2;
	}
	return count;
}

int swap(int x){
	return (x & 0x0F)<<4 | (x & 0xF0)>>4;
}

void perm(char s[],int r,int l){
	if(r==l-1){
		cout<<s<<endl;
	}
	char temp;
	for(int i=r;i<l;i++){
		temp = s[i];
		s[i] = s[r];
		s[r] = temp;
		perm(s,r+1,l);
		temp = s[i];
		s[i] = s[r];
		s[r] = temp;
	}
}

void nex(string s){
	int b = s.length()-1;
	while(b>0&&s[b-1]>=s[b]){
		b--;
	}
	if(b==0){
		reverse(s.begin(),s.end());
	}
	else{
		char temp = s[s.length()-1];
		s[s.length()-1] = s[b-1];
		s[b-1] = temp;
		reverse(s.begin()+b,s.end());
	}
	cout<<s<<endl;
}
 
int sum(int p){
	bool prim[p+1];
	memset(prim,false,p+1);
	int s = 0;
	for(int i=2;i<=p;i++){
		if(!prim[i]){
			int k = i+i;
			while(k<=p){ 
				prim[k] = true; //composite
				k += i;
			}
			s += i;
		}
	}
	return s;
}

int max2(int arr[],int n){
	int temp[n];
	memset(temp,0,n);
	int m,ans=0;
	m = arr[n-1];
	for(int i=n-2;i>-1;i--){
		if(arr[i]>m){m=arr[i];}
		temp[i] = max(temp[i+1],m-arr[i]);
	}
	m = arr[0];
	ans = temp[0];
	for(int i=1;i<n;i++){
		if(arr[i]<m){m=arr[i];}
		temp[i] = max(temp[i-1],temp[i]+arr[i]-m);
		ans = max(ans,temp[i]);
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cout<<fun2(8)<<endl;
	cout<<fun2(16)<<endl;
	cout<<fun2(5)<<endl;
	int arr[3] = {2,8,1};
	sort(arr,arr+3);
	cout<<arr[0]<<arr[1]<<arr[2]<<endl;
	cout<<diff(arr,3)<<endl;
	int x = 100;
	cout<<swap(x)<<endl;
	char arr1[] = "ABC";
	perm(arr1,0,strlen(arr1));
	string num = "534976";
	nex(num);
	int p = 10;
	cout<<sum(11)<<endl;
	int arrs[6] = {10,22,5,75,65,80};
	cout<<max2(arrs,6);
	return 0;
}