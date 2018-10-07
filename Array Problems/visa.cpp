#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int c;
	cin>>c;
	vector<string> nam(c);
	vector<int> xc(c);
	vector<int> yc(c);
	for(int i=0;i<c;i++){
		cin>>nam[i]>>xc[i]>>yc[i];
	}
	unordered_map<int,vector<int> > xq;
	unordered_map<int,vector<int> > yq;
	for(int i=0;i<c;i++){
		if(xq.find(xc[i])!=xq.end()){
			xq[xc[i]].push_back(yc[i]);
		}
		else{
			vector<int> temp;
			temp.push_back(yc[i]);
			xq[xc[i]] = temp;
		}
		if(yq.find(yc[i])!=yq.end()){
			yq[yc[i]].push_back(xc[i]);
		}
		else{
			vector<int> temp;
			temp.push_back(xc[i]);
			yq[yc[i]] = temp;
		}
	}
	for(auto it=xq.begin();it!=xq.end();it++){
		sort((it->second).begin(),(it->second).end());
	}
	for(auto it=yq.begin();it!=yq.end();it++){
		sort((it->second).begin(),(it->second).end());
	}
	for(int i=0;i<c;i++){
		int fx = xc[i];int fy = yc[i];
		vector<int>::iterator it1,it2,it3,it4;
		it1 = upper_bound(xq[fx].begin(),xq[fx].end(),fy);
		it2 = lower_bound(xq[fx].begin(),xq[fx].end(),fy);
		it3 = upper_bound(yq[fy].begin(),yq[fy].end(),fx);
		it4 = lower_bound(yq[fy].begin(),yq[fy].end(),fx);
		int xa1,xa2,ya1,ya2;
		if(abs(fy-*it1)<abs(fy-*it2)){
			xa1 = fx;ya1 = *it1;
		}
		else{
			xa1 = fx;ya1 = *it2;
		}
		if(abs(fy-*it3)<abs(fy-*it4)){
			xa2 = *it3;ya2 = fy;
		}
		else{
			xa2 = *it4;ya2 = fy;
		}
		if(abs(ya1-fy)<(xa2-fx)){
			cout<<xa1<<" "<<ya1<<endl;
		}
		else{
			cout<<xa2<<" "<<ya2<<endl;
		}
	}
}