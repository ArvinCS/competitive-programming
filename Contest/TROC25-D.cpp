#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	bool existA[k+1], existB[k+1];
	fill(existA, existA+k+1, false);
	fill(existB, existB+k+1, false);
	
	int cnt = 0;
	for(int x=n-1;x>=0;x--){
		cnt += a[x];
		
		if(x+k < n){
			cnt -= a[x+k];
		}
		
		if(x+k <= n) existA[cnt] = true;
	}
	
	cnt = 0;
	for(int x=m-1;x>=0;x--){
		cnt += b[x];
		
		if(x+k < m){
			cnt -= b[x+k];
		}
		
		if(x+k <= m) existB[cnt] = true;
	}
	
	int mx = -1, mn = 1e9;
	for(int x=0;x<=k;x++){
		if(existB[x]){
			mx = max(mx, x);
			mn = min(mn, x);
		}
	}
	
	ll ans = 0;
	for(int x=0;x<=k;x++){
		if(existA[x]){
			if(x >= (k-x)){
				ans = max(ans, x*1ll*(k-mn)+(k-x)*1ll*mn);
			} else {
				ans = max(ans, x*1ll*(k-mx)+(k-x)*1ll*mx);
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

