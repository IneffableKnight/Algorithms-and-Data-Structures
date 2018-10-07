#include <bits/stdc++.h>
using namespace std;

string zer(int a){
    string sol="";
    while(a>0){
        sol = sol+"0";
        a--;
    }
    return sol;
}
string multiply(string A, string B) {
    int n = B.length();
    int m = A.length();
    string pre,prev;
    int temp = m+1,carry=0,sum=0,count=n-1,num,cm1,cm2,temadd;
    char in;
    while(temp>0){
        prev = prev+"0";
        temp--;
    }
    while(count>=0){
        //multiply and reverse using carry
        pre = "";
        for(int i=m-1;i>-1;i--){
            sum = ((int)(A[i]-'0'))*((int)(B[count]-'0')) + carry;
            carry = sum/10;
            in = '0' + sum%10;
            //cout<<in<<endl;
            pre.push_back(in);
        }
        if(carry>0){
            in = '0' + carry;
            pre.push_back(in);
        }
        reverse(pre.begin(),pre.end());
        num = n-count-1;
        while(num>0){
           pre.push_back('0'); 
           num--;
        }
        //insert zero and add prev
        cm1 = pre.length(); cm2 = prev.length();
        if(cm1>cm2){
            prev = zer(cm1-cm2)+prev;
        }
        else if(cm1<cm2){
            pre = zer(cm2-cm1)+pre;
        }
        //add
        cm1 = max(cm1,cm2);
        carry = 0;
        for(int i=cm1-1;i>-1;i--){
            temadd = (int)(pre[i]-'0') + (int)(prev[i]-'0') + carry;
            carry = temadd/10;
            pre[i] = '0' + temadd%10;
        }
        if(carry>0){
            pre = "0" + pre;
            pre[0] = '0' + carry;
        }
        //update prev
        //cout<<pre<<endl;
        //cout<<prev<<endl;
        prev = pre;
        count--;
    }
    int ind = 0;
    int len = prev.length();
    while((ind<len-1)&&(prev[ind]=='0')){
    	ind++;
    }
    return prev.substr(ind,len-ind);
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string d;
	string a = "5131848155574784703269632922904933776792735241197982102373370";
	string b = "56675688419586288442134264892419611145485574406534291250836";
	string c = "290851027081985078955918627261751688832742312387314888842460711865148550965912482730570750031304678344564428861596637320";
	d = multiply(a,b);
	cout<<d<<endl;
	cout<<c<<endl;
	if(d==c){cout<<"yes";}
	return 0;
}