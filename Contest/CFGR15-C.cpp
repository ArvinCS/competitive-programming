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
		int n, k;
		cin >> n >> k;
		
		bool pick[2*n];
		fill(pick, pick+2*n, true);
		
		vector<pair<int, int>> v;
		for(int x=0;x<k;x++){
			int a, b;
			cin >> a >> b;
			
			if(a > b) swap(a, b);
			
			a--; b--;
			pick[a] = pick[b] = false;
			v.push_back({a, b});
		}
		
		vector<int> w;
		for(int x=0;x<2*n;x++){
			if(pick[x]){
				w.push_back(x);
			}
		}
		
		for(int x=0;x<w.size()/2;x++){
			v.push_back({w[x], w[w.size()/2 + x]});
		}
		
		ll ans = 0;
		for(int x=0;x<v.size();x++){
			for(int y=x+1;y<v.size();y++){
				if(v[x].first <= v[y].first && v[y].first <= v[x].second && v[x].second <= v[y].second){
					ans++;
				} else if(v[y].first <= v[x].first && v[x].first <= v[y].second && v[y].second <= v[x].second){
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

