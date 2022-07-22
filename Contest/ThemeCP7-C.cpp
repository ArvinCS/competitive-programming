#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int cnt[k];
	fill(cnt, cnt+k, 0);
	
	for(int x=0;x<n;x++){
		int t;
		cin >> t;
		
		cnt[t-1]++;
	}
	
	sort(cnt, cnt+k);
	
	auto solve = [&](int c) -> int {
		int ans = 0;
		int l = 0, r = k-1;
		while(l < r){
			if(cnt[l]+cnt[r] <= c){
				ans++;
				l++;
				r--;
				continue;
			} else {
				ans++;
				r--;
				continue;
			}
		}
		if(l == r) ans++;
		return ans;
	};
	
	ll ans = 1e18;
	int c = cnt[k-1];
	while(c <= 2*cnt[k-1]){
		int cur = solve(c);
		
		int last = c;
		int left = c, right = 2*cnt[k-1];
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(solve(mid) == cur){
				last = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		ans = min(ans, c*1ll*cur);
		c = last+1;
	}
	
	cout << ans << "\n";
    return 0;
}

