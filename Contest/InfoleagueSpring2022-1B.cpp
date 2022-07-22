#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll mod;
	cin >> mod;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int cnt[m+1];
	fill(cnt, cnt+m+1, 0);
	
	for(int x=0;x<n;x++){
		cnt[a[x]]++;
	}
	
	ll pw[n+1];
	pw[0] = 1;
	for(int x=1;x<=n;x++){
		pw[x] = (2 * pw[x-1]) % mod;
	}
	
	ll ways = pw[n] - n - 1;
	ll cur = 0;
	ll ans = 0;
	for(int y=0;y<=m;y++){
		for(int x=0;x<n;x++){
			if(a[x] > (a[x]^y)) continue;
			if((a[x]^y) > m) continue;
			
			if((a[x]^y) == a[x]){
				ll val = (ways - (pw[cnt[a[x]^y]-1] + mod) % mod;
				
				cout << x << ": " << a[x] << "^" << (a[x]^y) << " " << y << " -> " << val << " " << ways << "\n";
				
				ans += val;
				ways -= val;
			} else {
				ll val = pw[cnt[a[x]^y]] * ways % mod;
				
				cur += cnt[a[x]^y];
				cout << x << ": " << a[x] << "^" << (a[x]^y) << " " << y << " -> " << val << " " << ways << "\n";
				ans += val;
				ways -= val;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

