#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct DSU {
	int parrent[maxN], sz[maxN];
	ll mn[maxN], mx[maxN];
	
	void reset(int n, ll t[]){
		for(int x=0;x<n;x++){
			parrent[x] = x;
			sz[x] = 1;
			mn[x] = mx[x] = t[x];
		}
	}
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]){
				swap(a, b);
			}
			
			parrent[b] = a;
			sz[a] += sz[b];
			mn[a] = min(mn[a], mn[b]);
			mx[a] = max(mx[a], mx[b]);
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int tc;
	cin >> tc;
	
	while(tc--){
		int n;
		ll k;
		cin >> n >> k;
		
		pair<int, int> p[n];
		ll t[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second >> t[x];
		}
		
		vector<tuple<int, int, int>> vR, vC;
		for(int x=0;x<n;x++){
			vR.push_back(make_tuple(p[x].first, p[x].second, x));
			vC.push_back(make_tuple(p[x].second, p[x].first, x));
		}
		
		sort(vR.begin(), vR.end());
		sort(vC.begin(), vC.end());
		
		dsu.reset(n, t);
		
		for(int x=1;x<n;x++){
			if(get<0>(vR[x]) == get<0>(vR[x-1]) && get<1>(vR[x]) - get<1>(vR[x-1]) <= k){
				dsu.merge(get<2>(vR[x]), get<2>(vR[x-1]));
			}
			if(get<0>(vC[x]) == get<0>(vC[x-1]) && get<1>(vC[x]) - get<1>(vC[x-1]) <= k){
				dsu.merge(get<2>(vC[x]), get<2>(vC[x-1]));
			}
		}
		
		vector<int> w;
		for(int x=0;x<n;x++){
			if(dsu.getParrent(x) == x){
				w.push_back(dsu.mn[x]);
			}
		}
		
		sort(w.rbegin(), w.rend());
		
		int ans = -1;
		for(int x=0;x<w.size();x++){
			if(ans+1 <= w[x]){
				ans++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

