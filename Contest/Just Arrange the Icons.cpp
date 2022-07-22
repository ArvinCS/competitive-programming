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

const int maxN = 2 * 1e6 + 10;

int cnt[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		fill(cnt, cnt+n+1, 0);
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			cnt[tmp]++;
		}
				
		vector<pair<int, int>> v;
		for(int x=1;x<=n;x++){
			if(cnt[x] == 0) continue;
			v.push_back(make_pair(cnt[x], x));
		}
		
		sort(v.begin(), v.end());
		
		int ans = inf_int;
		for(int x=v[0].first+1;x>=1;x--){
			int best = 0;
			for(int y=0;y<v.size();y++){
				if(v[y].first % x == 0){
					best += (v[y].first+x-1)/x;
				} else {
					ll need = x - (v[y].first % x);
					if(need <= v[y].first/x){
						best += (v[y].first+x-1)/x;
					} else if(v[y].first % (x-1) == 0){
						best += v[y].first / (x-1);
					} else {
						best = -1;
						break;
					}
				}
			}
			if(best == -1) continue;
//			cout << x << " -> " << best << "\n";
			ans = min(ans, best);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

