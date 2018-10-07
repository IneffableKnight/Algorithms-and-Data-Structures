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

int recur(int arr1[],int arr2[] ,int n, int ind){
	if(ind>=2*n){
		return 0;
	}
	else{
		/////////////////////////////////////
		int i,j,a,b;
		for(i=0;i<2*n;i++){
			if(arr1[i]==arr2[ind]){
				if(i%2==0){
					for(j=0;j<2*n;j++){
						if(arr1[i+1]==arr2[j]){
							if(j==ind+1){return 0;}
							swap(&arr2[ind+1],&arr2[j]);
							a = recur(arr1,arr2,n,ind+2);
							break;
						}
					}
					swap(&arr2[ind+1],&arr2[j]);
				}
				else{
					for(j=0;j<2*n;j++){
						if(arr1[i-1]==arr2[j]){
							if(j==ind+1){return 0;}
							swap(&arr2[ind+1],&arr2[j]);
							a = recur(arr1,arr2,n,ind+2);
							break;
						}
					}
					swap(&arr2[ind+1],&arr2[j]);
				}
			}
		}
		/////////////////////////////////
		for(i=0;i<2*n;i++){
			if(arr1[i]==arr2[ind+1]){
				if(i%2==0){
					for(j=0;j<2*n;j++){
						if(arr1[i+1]==arr2[j]){
							if(j==ind){return 0;}
							swap(&arr2[ind],&arr2[j]);
							b = recur(arr1,arr2,n,ind+2);
							break;
						}
					}
					swap(&arr2[ind],&arr2[j]);
				}
				else{
					for(j=0;j<2*n;j++){
						if(arr1[i-1]==arr2[j]){
							if(j==ind){return 0;}
							swap(&arr2[ind],&arr2[j]);
							b = recur(arr1,arr2,n,ind+2);
							break;
						}
					}
					swap(&arr2[ind],&arr2[j]);
				}
			}
		}
		////////////////////////////////
		ind = ind+2;
		/////return the min value+1
		if(a<=b){
			return (a+1);
		}
		else{
			return (b+1);
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
	int arr1[2*n],arr2[2*n];
	for(int i=0;i<2*n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<2*n;i++){
		cin>>arr2[i];
	}
	int ans = recur(arr1,arr2,n,0);
	cout<<ans<<endl;
	return 0;
}