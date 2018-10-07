#include <bits/stdc++.h>
using namespace std;
const int alpha = 26;

struct trienode{
	bool endw;
	struct trienode *arr[alpha];
};

trienode* newnode(){
	trienode * node = new trienode;
	node->endw = false;
	for(int i=0;i<alpha;i++){
		node->arr[i] = NULL;
	}
	return node;
}
//prone to null root !
void insert(trienode* root,string s){
	trienode * temp = root;
	for(int i=0;i<s.length();i++){
		int t = s[i]-'a';
		if(temp->arr[t]==NULL){
			temp->arr[t] = newnode();
		}
		temp = temp->arr[t];
	}
	temp->endw = true;
}

bool search(trienode* root,string s){
	trienode * temp = root;
	if(root==NULL){return false;}
	for(int i=0;i<s.size();i++){
		temp = temp->arr[s[i]-'a'];
		if(temp==NULL){return false;}
	}
	return (temp->endw);
}

bool isleaf(trienode* t){
	return (t->endw);
}

bool isempt(trienode* t){
	for(int i=0;i<alpha;i++){
		if(t->arr[i]!=NULL){
			return false;
		}
	}
	return true;
}

bool remov(trienode* t,string s,int i){
	if(t==NULL){
		return false;
	}
	else{
		if(i==s.length()){
			if(t->endw){
				t->endw = false;
				if(isempt(t)){
					return true;
				}
				return false;
			}
		}
		else{
			if(remov(t->arr[s[i]-'a'],s,i+1)){
				delete(t->arr[s[i]-'a']);
				t->arr[s[i]-'a'] = NULL;
				//very crucial step !
				return (isempt(t)&&!isleaf(t));
			}
		}
	}
}

void delet(trienode* root,string s){
	if(s.length()>0&&root!=NULL){
		remov(root,s,0);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string key[] = {"chill","cool","dawg","coolish","sexy"};
    int siz = sizeof(key)/sizeof(key[0]);
    trienode* node = newnode();
    for(int i=0;i<siz;i++){
    	insert(node,key[i]);
    }
    cout<<search(node,"chill")<<endl;
    cout<<search(node,"sexy")<<endl;
    string s = "sexy";
    delet(node,s);
    cout<<search(node,s)<<endl;
    return 0;
}