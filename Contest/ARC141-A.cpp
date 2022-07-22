#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll pw[18];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<18;x++) pw[x] = 10 * pw[x-1];
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<ll> v;
		ll cur = n;
		while(cur > 0){
			v.push_back(cur%10);
			cur /= 10;
		}
		
		reverse(v.begin(), v.end());
		
		auto len = [&](ll val) -> int {
			int ans = 0;
			while(val > 0){
				ans++;
				val /= 10;
			}
			return ans;
		};
		
		ll ans = 0;
		for(int x=1;x<=v.size();x++){
			for(int y=1;y<x;y++){
				if(x%y == 0){
					ll left = pw[y-1], right = pw[y]-1;
					while(left <= right){
						ll mid = (left+right) >> 1;
						
						bool valid = false;
						int length = len(mid);
						int cnt = 0;
						ll val = 0;
						while(cnt+length <= x){
							val *= pw[y];
							val += mid;
							cnt += length;
							if(cnt > length && val <= n) ans = max(ans, val);
						}
					
						if(val <= n){
							valid = true;
						}
										
						if(valid){
							left = mid+1;
						} else {
							right = mid-1;
						}
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

