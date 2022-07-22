#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n, greater<int>());
	
	int cnt[30][2], ops[30];
	fill(cnt[0], cnt[30], 0);
	fill(ops, ops+30, 0);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans += a[x];
		for(int y=0;y<30;y++){
			int bit = (1 << y);
			
			cnt[y][(a[x]&bit) != 0]++;
		}
	}
	
	for(int x=0;x<n;x++){
		ll diff = 0;
		
		for(int y=0;y<30;y++){
			int bit = (1 << y);
			
			if(((a[x]&bit) != 0) != (ops[y]&1)){
				diff += cnt[y][0]*1ll*bit;
				diff -= cnt[y][1]*1ll*bit;
			}
		}
		
		if(diff > 0){
			ans += diff;
			
			for(int y=0;y<30;y++){
				int bit = (1 << y);
				
				if(((a[x]&bit) != 0) != (ops[y]&1)){
					ops[y]++;
					swap(cnt[y][0], cnt[y][1]);
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}
