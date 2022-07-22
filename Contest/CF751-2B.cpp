#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], cnt[n+1];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int q;
		cin >> q;
		
		int ans[q], pos[q], turn[q];
		vector<pair<int, int>> v;
		for(int i=0;i<q;i++){
			cin >> pos[i] >> turn[i];
			
			pos[i]--;
			v.push_back({turn[i], i});
		}
		
		sort(v.begin(), v.end());
		
		bool cycle = false;
		int cur = 0;
		for(int x=0;x<v.size();x++){
			while(cur < v[x].first){
				if(cycle){
					cur = v[x].first;
				} else {
					int b[n];
					fill(cnt, cnt+n+1, 0);
					
					for(int y=0;y<n;y++){
						cnt[a[y]]++;
					}
					for(int y=0;y<n;y++){
						b[y] = cnt[a[y]];
					}
					
					bool same = true;
					for(int y=0;y<n;y++){
						if(b[y] != a[y]){
							same = false;
							break;
						}
					}
					
					cycle |= same;
					cur++;
					
					for(int y=0;y<n;y++){
						a[y] = b[y];
					}
				}
			}
			
			ans[v[x].second] = a[pos[v[x].second]];
		}
		
		for(int x=0;x<q;x++){
			cout << ans[x] << "\n";
		}
	}

    return 0;
}

