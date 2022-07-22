#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 1e3 + 5;

int n, a[maxN];
ll table[maxN][11][(1 << 10)];

ll solve(int idx, int last, int mask){
	if(idx == n) return 1;
	if(table[idx][last][mask] != -1) return table[idx][last][mask];
	
	ll ans = 0;
	if(last == a[idx]){
		ans += solve(idx+1, last, mask|(1 << a[idx]));
		ans %= mod;
	}
	if(last != a[idx] && !(mask&(1 << a[idx]))){
		ans += solve(idx+1, a[idx], mask|(1 << a[idx]));
		ans %= mod;
	}
	
	ans += solve(idx+1, last, mask);
	ans %= mod;
	
	return table[idx][last][mask] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		char c;
		cin >> c;
		
		a[x] = (c - 'A');
	}
	
	fill(*table[0], *table[maxN], -1);
	cout << (solve(0, 10, 0) + mod - 1) % mod << "\n";
    return 0;
}

