#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	long long n,m,a;
	cin >> n >> m >> a;

	long long ans = ((n + a - 1)/a) * ((m + a - 1)/a);
	cout << ans << "\n";
	
    return 0;
}
