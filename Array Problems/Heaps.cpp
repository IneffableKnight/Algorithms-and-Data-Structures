//this code contains basic functions
//for heapsort
//min_heap
#include <iostream>
#include <stdio.h>
using namespace std;

int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}

void printarray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swap(int* a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minheapify(int arr[],int i,int n){
	int smallest = i;
	int l = left(i);
	int r = right(i);
	if((arr[l]<arr[smallest])&&(l<n)){smallest = l;}
	if((arr[r]<arr[smallest])&&(r<n)){smallest = r;}
	if(smallest!=i){
		swap(&arr[smallest],&arr[i]);
		minheapify(arr,smallest,n);
	}
}

void buildminheap(int arr[],int n){
	for(int i = n/2; i>=0; i--){
		minheapify(arr,i,n);
	}
}

void heapsort(int arr[],int n){
	for(int i=n-1;i>0;i--){
		buildminheap(arr,(i+1));
		swap(&arr[0],&arr[i]);
	}
}

int heapmin(int arr[],int n){
	return arr[0];
}

int extractmin(int arr[],int *n){
	int s = arr[0];
	swap(&arr[0],&arr[*n-1]);
	*n = (*n)-1;
	buildminheap(arr,*n);
	return s;
}

void heapdecreasekey(int arr[],int i,int key){
	if(key>arr[i]){cout<<"key is larger"<<endl;}
	else{
		arr[i] = key;
		while((key<arr[parent(i)])&&(i>0)){
			swap(&arr[i],&arr[parent(i)]);
			i = parent(i);
		}
	}
}

void insertkey(int arr[],int key,int * n){
	*n = (*n)+1;
	arr[(*n)-1] = 10000;
	heapdecreasekey(arr,(*n)-1,key);
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int heapsize = 10;
    int arr[14] = {2,4,5,1,44,21,34,6,66,3,0,0,0,0};
    printarray(arr,heapsize);
    //heapsort(arr,heapsize);
    buildminheap(arr,heapsize);
    printarray(arr,heapsize);
    //cout<<extractmax(arr,&heapsize);
    //heapincreasekey(arr,3,10);
    //cout<<heapmax(arr,heapsize);
    //heapincreasekey(arr,3,70);
    //insertkey(arr,32,&heapsize);
    //printarray(arr,heapsize);
}
