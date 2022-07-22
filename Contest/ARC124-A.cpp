#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int cnt[n];
	fill(cnt, cnt+n, k);
	
	for(int x=0;x<k;x++){
		char c;
		cin >> c;
		
		int p;
		cin >> p;
		
		p--;
		cnt[p] = 1;
		
		if(c == 'L'){
			for(int y=0;y<p;y++){
				cnt[y]--;
				if(cnt[y] <= 0) cnt[y] = 1;
			}
		} else {
			for(int y=p+1;y<n;y++){
				cnt[y]--;
				if(cnt[y] <= 0) cnt[y] = 1;
			}
		}
	}
	
	ll ans = cnt[0];
	for(int x=1;x<n;x++){
		ans *= cnt[x] % mod;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

