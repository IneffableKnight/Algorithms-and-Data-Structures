#include <bits/stdc++.h>

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

void shiftarray(int arr[],int n){
	int ind=0,ipast,vpresent,vpast = arr[0];
	int cou = n;
	int limit = 25;
	while((cou>0)&&(limit>0)){
		limit --;
		//cout<<"---"<<vpast<<"---"<<endl;
		if(arr[vpast]>=n){
			for(int i=1;i<n;i++){
				//cout<<"---"<<i<<"---"<<endl;
				//cout<<"---"<<arr[ipast+i]<<"---"<<endl;
				if(arr[ipast+i]<n){
					//cout<<"yes"<<endl;
					ipast += i;
					ind = ipast;
					vpast = arr[ind];
					//cout<<ind<<endl;
					break;
				}
			}
		}
		else{
			vpresent = arr[vpast];
			arr[vpast] = ind+n;
			ind = vpast;
			vpast = vpresent;
			ipast = ind;
			cou--;
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
	int n,sum=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	printarrrray(arr,n);
	shiftarray(arr,n);
	for(int i=0;i<n;i++){
		arr[i] -= n;
	}
	printarrrray(arr,n);
	return 0;
}