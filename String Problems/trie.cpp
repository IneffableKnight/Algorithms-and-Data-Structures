#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

//  this file contains Trie data structure in a class form 
//  with insert, search, and delete as the available functions

struct node{
	map<char,node *> dict;
	bool end;
};


class trie{
public:
	trie(){
		root = new node;
	}
	void Insert(string key);
	bool Search(string key); ///for complete search of a word
	bool Delet(string key,int i,node *cur);
	node *root;
};

void trie::Insert(string key){
	map<char,node *>::iterator it;
	node * cur  = root;
	for(int i=0;i<key.length();i++){
		it  = (cur->dict).find(key[i]);
		if(it==(cur->dict).end()){
			node * n = new node;
			n->end = false;
			(cur->dict).insert(pair<char,node*>(key[i],n));
			cur = n;
		}
		else{
			cur = it->second;
		}
	}
	cur->end = true;
}

bool trie::	Search(string key){
	node * cur = root;
	map<char,node *>::iterator it;
	for(int i=0;i<key.length();i++){
		it  = (cur->dict).find(key[i]);
		if(it==(cur->dict).end()){return false;}
		else{
			cur = it->second;
		}
	}
	if(cur->end){return true;}
	else{return false;}
}

bool trie::Delet(string key,int i,node * cur){
	if(i==(key.length())){
		if(!(cur->end)){
			cout<<"no such element"<<endl;
			return false;
		}
		if(!(cur->dict).empty()){
			cur->end = false;
			return false;
		}
		if((cur->end)&&((cur->dict).empty())){
			delete(cur);
			return true;
		}
	}
	map<char,node *>::iterator it;
	it  = (cur->dict).find(key[i]);
	if(it==(cur->dict).end()){
		cout<<"no such element"<<endl;
		return false;
	}
	if(i<(key.length())){
		bool p = Delet(key,i+1,(it->second));
		if(p){
			(cur->dict).erase(it);
			if((cur->dict).empty()){
				if(cur->end){
					return false;
				}
				else{
					delete(cur);
					return true;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    trie d;
    d.Insert("hey");
    d.Insert("hero");
    d.Insert("girly");
    d.Insert("girls");
    cout<<d.Search("ryu")<<endl;
    cout<<d.Search("hey")<<endl;
    cout<<d.Search("hero")<<endl;
    cout<<d.Search("girls")<<endl;
    bool k = d.Delet("girly",0,d.root);
    cout<<d.Search("girls")<<endl;
}
