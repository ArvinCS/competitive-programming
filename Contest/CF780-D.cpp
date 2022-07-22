#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int prefix[n], s[n];
		for(int x=0;x<n;x++){
			if(x > 0){
				prefix[x] = prefix[x-1];
				s[x] = s[x-1];
			} else {
				prefix[x] = 0;
				s[x] = 1;
			}
			
			if(a[x] == 0){
				prefix[x] = 0;
				s[x] = 1;
			} else {
				prefix[x] += abs(a[x])-1;
			}
			if(a[x] < 0){
				s[x] *= -1;
			}
		}
		
		array<ll, 3> ans = {0, n, n-1};
		pair<ll, int> neg = {1e9, 1e9}, pos = {0, -1};
		for(int x=0;x<n;x++){
			if(a[x] == 0){
				neg = {1e9, 1e9};
				pos = {0, x};
				continue;
			}
			if(s[x] == -1){
				if(neg.second < x) ans = max(ans, {prefix[x]-neg.first, neg.second+1, x});
				neg = min(neg, {prefix[x], x});
			} else {
				if(pos.second < x) ans = max(ans, {prefix[x]-pos.first, pos.second+1, x});
				pos = min(pos, {prefix[x], x});
			}
		}
		
		cout << ans[1] << " " << n-ans[2]-1 << "\n";
	}
	
    return 0;
}

