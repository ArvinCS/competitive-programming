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
		
		vector<ll> v[n];
		for(int x=0;x<n;x++){
			int k;
			cin >> k;
			
			for(int y=0;y<k;y++){
				ll tmp;
				cin >> tmp;
				
				v[x].push_back(tmp);
			}
		}
		
		vector<pair<ll, ll>> w;
		for(int x=0;x<n;x++){
			ll mx = 0;
			for(int y=0;y<v[x].size();y++){
				mx = max(mx, v[x][y]+1-y);
			}
			
			ll sz = v[x].size();
			w.push_back({mx, -sz});
		}
		
		sort(w.begin(), w.end());
		
		ll ans = 0, sum = 0;
		for(int x=0;x<w.size();x++){
			if(w[x].first > ans+sum){
				ans += w[x].first-(ans+sum);
			}
			sum += (-w[x].second);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

