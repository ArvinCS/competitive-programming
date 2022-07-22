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
		
		pair<int, int> p[n+1];
		vector<pair<int, int>> v;
		for(int x=1;x<=n;x++){
			cin >> p[x].first >> p[x].second;
			v.push_back({p[x].first, x});
			v.push_back({p[x].second+1, -x});
		}
		
		sort(v.begin(), v.end());
		
		int cnt[n+1];
		fill(cnt, cnt+n+1, 0);
		
		set<int> st;
		int cur = 0, comp = 0;
		for(int x=0;x<v.size();x++){
			int idx = v[x].second;
			if(idx > 0){
				cur++;
				st.insert(idx);
			} else {
				cur--;
				st.erase(-idx);
				
				if(cur == 1 && v[x+1].second > 0){
					if(x+2 < v.size()) cnt[*(st.begin())]++;
				}
				if(cur == 0){
					comp++;
				}
			}
		}
		
		int ans = 0;
		for(int x=1;x<=n;x++){
			ans = max(ans, cnt[x]);
		}
		if(comp == n) comp--;
		
		ans += comp;
		
		cout << ans << "\n";
	}

    return 0;
}

