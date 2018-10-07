#include <bits/stdc++.h>
#include <string>

using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarrrray(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void sor(int arr[], int n){
	sort(arr,arr+n);
}

int dig(int a){
	int i = 0;
	int j = a;
	while(j){
		j = j/10;
		i++;
	}
	return i;
}

bool comp(int a, int b){
	long long int c=a,d=b;
	int n1,n2;
	n1 = dig(a);
	n2 = dig(b);
	while(n2){
		c = c*10;
		n2--;
	}
	c += b;
	while(n1){
		d = d*10;
		n1--;
	}
	d += a;
	if(c>d){
		return true;
	}
	else{
		return false;
	}
}

void insort(int arr[],int n){
	for(int i=1;i<n;i++){
		if(comp(arr[i],arr[i-1])){
			int j = i-1;
			while((comp(arr[j+1],arr[j]))&&(j>=0)){
				swap(&arr[j+1],&arr[j]);
				j--;
			}
		}
	}
}


int main(){
	///////////////////////////
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//////////////////////////
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	string a = "5489";
	string b = "548";
	string c=a,d=b;
	c.append(b);
	d.append(a);
	bool ans = (c).compare(d);
	cout<<c<<"   "<<ans<<"  "<<d<<endl;
	printarrrray(arr,n);
	//insort(arr,n);
	sort(arr,arr+n,comp);
	printarrrray(arr,n);
	return 0;
}