#include <iostream>

using namespace std;

unsigned long long mod = 1000000007;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long a, b;
	cin >> a >> b;
	
	a %= mod;
	b %= mod;
	
	unsigned long long body = ((b-a+1)) * ((b+a));
	unsigned long long ans = (body) / 2;
	
	cout << ans % mod << "\n";
    return 0;
}
// 1999999999999999999
