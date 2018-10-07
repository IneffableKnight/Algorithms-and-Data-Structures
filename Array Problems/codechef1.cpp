#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[4] = {1,2,3,4};
	int k = 10;
	int ans = 0,cur=0,pro=1;
	for(int i=0;i<4;i++){
		pro *= arr[i];
		if(pro>=k){
			while(pro>=k){
				pro /= arr[cur];
				cur++;
			}
		}
		cout<<i-cur+1<<endl;
		ans += i-cur+1;
	}
	cout<<ans<<endl;
	return ans;
}