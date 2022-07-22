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
		
		int cnt[n];
		fill(cnt, cnt+n, 0);
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			cnt[a[x]-1]++;
		}
		
		int ans = 0;
		vector<int> v;
		vector<pair<int, int>> w;
		for(int x=0;x<n;x++){
			if(x > 0 && a[x-1] == a[x]){
				v.push_back(a[x]);
			} else {
				w.push_back({x, a[x]});
			}
		}
		
		for(int x=0;x+1<w.size();x++){
//			cout << w[x+1].first << " " << w[x].first << "\n";
			if(w[x+1].first-w[x].first > 1){
				ans++;
			}
		}
		
		sort(v.begin(), v.end());
		
		int cnt2 = 1;
		int last = 0;
		for(int x=0;x<v.size();x++){
			if(v[last] != v[x]){
				int cnt = x-last;
				ans += cnt;
				last = x;
				cnt2++;
			}
		}
		{
			int cnt = v.size()-last;
			ans += cnt;
			cnt2++;
		}
		
 		for(int x=0;x<n;x++){
			if(cnt[x] > (n-cnt[x])+1){
				ans = 1e9;
				break;
			}
		}
		
		if(ans == 1e9){
			cout << -1 << "\n";
		} else {
			cout << ans << "\n";
		}
	}
	
    return 0;
}

