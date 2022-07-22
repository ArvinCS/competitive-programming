#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const ll div2 = 500000004;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	assert(n == 1);
	
	cout << a[0] % mod << " " << a[0]*(a[0]-1) % mod * div2 % mod << "\n";
	
    return 0;
}

