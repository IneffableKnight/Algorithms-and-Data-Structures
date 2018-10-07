#include <bits/stdc++.h>
using namespace std;

void swap(int ** a,int** b){
	int * t = *a;
	*a = *b;
	*b = t;
}

int main(){
	int * arr = new int[3];
	int * brr = new int[3];
	arr[0]=3,arr[1]=4,arr[2]=5;
	brr[0]=-3,brr[1]=-4,brr[2]=-5;
	/*int ** temp,**temp1 ;
	temp = &arr;
	temp1 = &brr;
	int * t;
	t = *temp;
	*temp = *temp1;
	*temp1 = t;
	cout<<arr[0];*/
	/*int * temp ;
	temp = arr;
	arr = brr;
	brr = temp;*/
	swap(&arr,&brr);
	cout<<arr[0]<<endl;
}