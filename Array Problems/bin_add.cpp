#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B) {
    int m = A.length();
    int n = B.length();
    int i = m-1,j = n-1;
    int sum=0,carry=0;
    string sol = "";
    while(i>-1&&j>-1){
        sum = ( (int)(A[i]-'0') + (int)(B[j]-'0') +carry );
        carry = sum/2;
        if(sum%2){sol.push_back('1');}
        else{sol.push_back('0');}
        cout<<A[i]<<" "<<B[j]<<endl;
        i--;j--;
    }
    if((i==-1)&&(j!=-1)){
        while(j>-1){
            sum = ( (int)(B[j]-'0') +carry );
            carry = sum/2;
            if(sum%2){sol.push_back('1');}
            else{sol.push_back('0');}
            j--;
        }
    }
    else if((j==-1)&&(i!=-1)){
        while(i>-1){
            sum = ( (int)(A[i]-'0') +carry );
            carry = sum/2;
            if(sum%2){sol.push_back('1');}
            else{sol.push_back('0');}
            i--;
        }
    }
    if(carry){sol.push_back('1');}
    else{sol.push_back('0');}
    return sol;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a = "10100" ;
    string b = "1100110" ;
    string c = addBinary(a,b) ;
    reverse(c.begin(),c.end());
    cout<<c<<endl;
    return 0;
}
