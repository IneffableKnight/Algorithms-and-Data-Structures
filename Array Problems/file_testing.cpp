/*#include<bits/stdc++.h>

using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	#endif
	int a,b;
	cin>>a>>b;
	cout<<(a*b);
	return 0;
}
*/
#include <unordered_set>
#include <iostream>

int main() {

    int a[] = { 1, 9, 4, 5, 8, 3, 1, 3, 5 };
    const size_t len = sizeof(a) / sizeof(a[0]);

    std::unordered_set<int> s(a, a + len);

    std::cout << s.size() << std::endl;
    return EXIT_SUCCESS;

}