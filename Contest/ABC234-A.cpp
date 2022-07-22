#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll val = n*n + 2*n + 3;
	ll val2 = val*val + 2*val + 3;
	ll val3 = (val+n)*(val+n) + 2*(val+n) + 3;
	ll ans = (val3+val2)*(val3+val2) + 2*(val3+val2) + 3;
	
	cout << ans << "\n";
	
    return 0;
}

