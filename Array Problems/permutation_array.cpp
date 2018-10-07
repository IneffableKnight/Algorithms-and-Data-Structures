#include <bits/stdc++.h>
using namespace std;

/*void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

void prin(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void permutate(int arr[],int n,int i){
	if(n-1==i){
		prin(arr,n);
		return;
	}
	sort(arr+i,arr+n);
	permutate(arr,n,i+1);
	for(int j=i+1;j<n;j++){
		swap(arr[i],arr[j]);
		permutate(arr,n,i+1);
		swap(arr[j],arr[i]);
	}
}

int main(){
	int arr[5] = {1,2,3};
	permutate(arr,3,0);
}*/

void swap(char &a,char &b){
	char temp = a;
	a = b;
	b = temp;
}

void prin(char arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	cout<<endl;
}

/*void permutate(char arr[],int n,int i){
	if(n-1==i){
		cout<<arr<<endl;
		return;
	}
	//sort(arr+i,arr+n);
	for(int j=i;j<n;j++){
		swap(arr[i],arr[j]);
		permutate(arr,n,i+1);
		swap(arr[j],arr[i]);
	}
}*/

void permutate(char arr[],int n,int i){
	if(n-1==i){
		cout<<arr<<endl;
		return;
	}
	//sort(arr+i,arr+n);
	for(int j=i;j<n;j++){
		swap(arr[i],arr[j]);
		permutate(arr,n,i+1);
		swap(arr[j],arr[i]);
	}
}


int main(){
	char arr[] = "ABC";
	sort(arr,arr+strlen(arr));
	permutate(arr,strlen(arr),0);
	string aa = "www";
	string bb = aa;
	bb[0] = 'e';
	cout<<bb<<endl;
}

/*#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void permute(string& list, int level, vector<string>& v){
    if(level == list.size()){
        v.push_back(list);
        return;
    }
    for(int i=level;list[i];++i){
        swap(list[level], list[i]);
        permute(list, level + 1, v);
        swap(list[level], list[i]);
    }
}

int main(){
    string anagrama;
    vector<string> v;
    cout << "input character set >";
    cin >> anagrama;
    permute(anagrama, 0, v);
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}*/