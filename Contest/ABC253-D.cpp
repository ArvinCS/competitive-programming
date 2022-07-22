#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, a, b;
	cin >> n >> a >> b;
	
	ll lcm = a * b / __gcd(a,b);
	ll cntA = n/a;
	ll cntB = n/b;
	ll cntC = n/lcm;
	
	cout << n*(n+1)/2 - cntA * (2*a + (cntA-1)*a) / 2 - cntB * (2*b + (cntB-1)*b) / 2 + cntC * (2*lcm + (cntC-1)*lcm) / 2 << "\n";
    return 0;
}

