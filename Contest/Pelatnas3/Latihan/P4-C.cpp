#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int inf = 1e6 + 1;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	// notice that each duck walks can interpreted as a concave function
	// if concave function merged with concave function, it would still be a concave function.
	// concave function? ternary search!
	
	array<int, 3> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x][0] >> p[x][1] >> p[x][2];
	}
	
	auto solve = [&](ll s) -> ll {
		ll cnt = 0;
		for(int x=0;x<n;x++){
			if(s-p[x][2] <= p[x][0] && p[x][0] <= s+p[x][2]) continue;
			
			if(p[x][0] <= s){
				cnt += (s-p[x][2]-p[x][0]) * 1ll * p[x][1];
			} else {
				cnt += (p[x][0]-s-p[x][2]) * 1ll * p[x][1];
			}
		}
		return cnt;
	};
	
	ll ans = 1e18;
	ll left = 1, right = 1e9-1;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll cur = solve(mid), nxt = solve(mid+1);
		ans = min(ans, min(cur, nxt));
		if(cur >= nxt){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

