//1999999999999999999
#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long a,b;
	cin >> a >> b;
	
	cout << (a+b) % 1000000007 << "\n";
    return 0;
}
