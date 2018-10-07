#include <bits/stdc++.h>
#include <string> 
using namespace std;

int main(){
	/*string a ="33";
	string b ="34";
	bool s = a<b;
	//cout<<s;
	string ss= "raja";
	bool p = (ss[2]=='a');*/
	//cout<<p;
	/*double dbl;
	string test = "25.23";
	dbl = stod(test);
	cout<<dbl;*/
	/*vector<vector<int> > ssss(3);
	ssss[0].push_back(1);
	ssss[0].push_back(2);
	ssss[0].push_back(13);
	ssss[0].push_back(14);
	ssss[0].push_back(15);
	ssss[1].push_back(16);
	cout<<ssss[1][0];*/
	/*#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MyComparator
{
    const vector<int> & value_vector;

    MyComparator(const vector<int> & val_vec):
        value_vector(val_vec) {}

    bool operator()(int i1, int i2)
    {
        return value_vector[i1] < value_vector[i2];
    }
};

void print(const vector<int> & v, const char * msg)
{
    int size = v.size();

    for (int i = 0; i < size; ++i)
        cout << v[i] << " ";

    cout << msg << endl;
}

int main()
{
    srand(time(0));

    vector<int> A(5), B(5);

    for (int i = 0; i < 5; ++i)
    {
        A[i] = rand() % 10;
        B[i] = i;
    }

    print(A, "<- A");
    print(B, "<- B");

    sort(B.begin(), B.end(), MyComparator(A));

    print(B, "<- B (sorted)");

    cout << "\n(hit enter to quit)";
    cin.get();

    return 0;
}
*/
	/*int k= INT_MAX;
	int t =  2222234;
	long long tt = INT_MAX;
	cout<<k;
	long long u = LLONG_MAX;
	long long o = tt*tt;
	cout<<endl<<LLONG_MAX<<endl;
	cout<<(o);*/
	char s[] = "abc";
	sort(s,s+strlen(s));
	do{
		cout<<s<<endl;
	}
	while(next_permutation(s,s+strlen(s)));
}