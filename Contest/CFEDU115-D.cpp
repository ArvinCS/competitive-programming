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

const int maxN = 2e5 + 5;

pair<int, int> p[maxN];
vector<int> t[maxN], d[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int q;
	cin >> q;
	
	while(q--){
		ll n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
			p[x].first--; p[x].second--;
		}
		
		for(int x=0;x<n;x++){
			t[x].clear();
			d[x].clear();
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			t[p[x].first].push_back(p[x].second);
			d[p[x].second].push_back(p[x].first);
		}
		
		for(int x=0;x<n;x++){
			for(auto val : t[x]){
				ll sz = t[x].size();
				ll sz2 = d[val].size();
				
				ans += (sz-1) * (sz2-1);
			}
			for(auto val : d[x]){
				ll sz = d[x].size();
				ll sz2 = t[val].size();
				
				ans += (sz-1) * (sz2-1);
			}
			
//			cout << x << " -> " << ans << "\n";
		}
		
		ans /= 2;
		ans = n*(n-1)*(n-2)/6 - ans;
		cout << ans << "\n";
	}
	
    return 0;
}

