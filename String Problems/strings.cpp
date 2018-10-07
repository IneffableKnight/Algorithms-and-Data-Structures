//this file contains basic string code and 
//syntax with it.
#include <iostream>
#include <stdio.h>
#include<string>
using namespace std;

void mode(string s){
	char ss = s[5];
	cout<<ss<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string s ="hey there";
    string y = "how you doin";
    cout<<s.insert(9," girl")<<endl;
    //mode(s);
    //vector<bool> mark(26,false);
    /*string str = "how you doin??";
    string str2 = "how you doinqsq??";*/
    //getline(cin,str);
    //cout<<"the string is : ";
    //cout<<str<<endl;
    //str.push_back('n');
    //cin>>str;
    //str.resize(5);
    /*cout<<str<<endl;*/
    //cout<<str.capacity()<<endl;
    /*string::iterator it,itt;
    for(it = str.begin();it!=str.end();it++){
    	cout<<*it;
    }*/
    //char s[10] = "sojfinr";
    //cout<<s;
    /*str2.swap(str);
    cout<<str2;
    cout<<str;*/
}


