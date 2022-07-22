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

const int maxN = 5e5 + 5;

map<set<int>, ll> mp;
ll c[maxN];
set<int> st[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		mp.clear();
		for(int x=0;x<n;x++){
			cin >> c[x];
			st[x].clear();
		}
		
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			st[b].insert(a);
		}
		
		for(int x=0;x<n;x++){
			if(st[x].size() > 0){
				mp[st[x]] += c[x];
			}
		}
		
		ll ans = 0;
		for(auto p : mp){
			if(ans == 0){
				ans = p.second;
			}
			ans = __gcd(ans, p.second);
		}
		
		cout << ans << "\n";
//		cout << total << " -\n";
	}

    return 0;
}

