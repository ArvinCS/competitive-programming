#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
		
	ll c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	sort(c, c+n);
	
	ll ways = 1, cur = 0;
	for(int x=0;x<n;x++){
		cur += c[x]-(x > 0 ? c[x-1] : 0);
		
		ways *= cur;
		ways %= mod;
		cur--;
	}
	
	cout << ways << "\n";
    return 0;
}

