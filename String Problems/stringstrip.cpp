#include <bits/stdc++.h>
using namespace std;


int compareVersion(string A, string B) {
    //copy into char[]
    //keep using tokens till null
    //remove front zero
    //compare length and if equal string comparison
    //if both null at the end the 0
    //if one equals null check other for zero
    char * prev1, *prev2;
    char * arr1 = new char[A.length()+1];
    strcpy(arr1,A.c_str());
    char * arr2 = new char[B.length()+1];
    strcpy(arr2,B.c_str());
    char * atok = strtok_r(arr1,".",&prev1);
    char * btok = strtok_r(arr2,".",&prev2);
    int res;
    while((atok!=NULL)&&(btok!=NULL)){
        /*cout<<atok<<endl;
        cout<<btok<<endl;
        cout<<endl;*/
        while((strlen(atok))&&(*atok=='0')){
            atok++;
        }
        while((strlen(btok))&&(*btok=='0')){
            btok++;
        }
        if(strlen(atok)>strlen(btok)){
            res = 1;
        }
        else if(strlen(atok)<strlen(btok)){
            res = -1;
        }
        else{
            res = strcmp(atok,btok);
        }
        //cout<<res<<endl;
        if(!res){
            atok = strtok_r(NULL,".",&prev1);
            btok = strtok_r(NULL,".",&prev2);
        }
        else{
            //delete[] arr1;
            //delete[] arr2;
            if(res<0){return -1;}
            else{return 1;}
        }
    }
    //delete[] arr1;
    //delete[] arr2;
    if((atok==NULL)&&(btok==NULL)){return 0;}
    if(!atok){
        //cout<<"yes";
        while((strlen(btok))&&(*btok=='0')){
            btok++;
        }
        if(!strlen(btok)){
            return 0;
        }
        else{
            return -1;
        }
    }
    if(!btok){
        //cout<<strlen(atok);
        while((strlen(atok))&&(*atok=='0')){
            atok++;
        }
        if(!strlen(atok)){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string a = "22";
    string b = "122";
    cout<<compareVersion(a,b);
    return 0;
}