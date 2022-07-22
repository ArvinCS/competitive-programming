#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m = pow(2, n)-1;
	ll c[m+1];
	for(int x=1;x<=m;x++){
		cin >> c[x];
	}
	
	ll ans = c[1];
	for(int x=1;x<n;x++){
		ans += min(c[(1 << x)], c[(1 << (x+1))-1]);
	}
	
	cout << ans << "\n";
    return 0;
}

