#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree <pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>

const ll maxA = 1e16;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	ll s, c;
	cin >> n >> m >> s >> c;
		
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	int q;
	cin >> q;
	
	ll ans[q];
	fill(ans, ans+q, 0);
	
	vector<pair<int, int>> pendingQ[2005];
	for(int x=0;x<q;x++){
		int pos;
		ll t;
		cin >> pos >> t;
		
		pos--;
//		assert(t > 0);
		pendingQ[t].push_back({pos, x});
	}
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	set<ll> st;
	for(int x=0;x<m;x++) st.insert(b[x]);
	
	vector<int> pendingU[2005];
	for(int t=1;t<2005;t++){
		for(auto val : pendingU[t]){
			st.insert(val);
		}
		
		for(int x=0;x<n;x++){
			if(st.count((a[x]+t)%s)){
				st.erase((a[x]+t)%s);
				cnt[x]++;
				if(x == 11) cout << t << " " << (a[x]+t)%s << " -\n";
				if(t+c < 2005) pendingU[t+c].push_back((a[x]+t)%s);
			}
		}
		
		for(auto p : pendingQ[t]){
			ans[p.second] = cnt[p.first];
		}
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

