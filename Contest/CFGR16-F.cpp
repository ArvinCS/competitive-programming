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
		int n, m;
		cin >> n >> m;
		
		vector<tuple<ll, int, int>> v;
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			v.push_back(make_tuple(a[x], 1, x));
		}
		
		pair<ll, ll> s[m];
		for(int x=0;x<m;x++){
			cin >> s[x].first >> s[x].second;
			v.push_back(make_tuple(s[x].first, 0, x+1));
			v.push_back(make_tuple(s[x].second+1, 0, -(x+1)));
		}
		
		sort(v.begin(), v.end());
		
		bool bef[m], done[m];
		fill(bef, bef+m, false);
		
		set<int> st;
		for(int x=0;x<v.size();x++){
			ll pos = get<0>(v[x]);
			int state = get<1>(v[x]), idx = get<2>(v[x]);
			
			if(state == 1){
				for(auto y : st){
					bef[y-1] = true;
				}
				st.clear();
			} else {
				if(idx > 0){
					st.insert(idx);
				} else {
					auto it = st.find(abs(idx));
					
					if(it != st.end()) st.erase(it);
				}
			}
		}
		
		v.clear();
		
		ll ans = 0, ans2 = 0;
		for(int x=0;x<n;x++){
			v.push_back(make_tuple(a[x], 1, x));
		}
		for(int x=0;x<m;x++){
			if(!bef[x]){
				v.push_back(make_tuple(s[x].first, 0, x+1));
				v.push_back(make_tuple(s[x].second+1, 0, -(x+1)));
				done[x] = false;
			} else {
				done[x] = true;
			}
		}
		
		sort(v.begin(), v.end());
		
		vector<pair<ll, int>> w;
		for(int x=0;x<v.size();x++){
			ll pos = get<0>(v[x]);
			int state = get<1>(v[x]), idx = get<2>(v[x]);
			
//			cout << pos << " " << state << " " << idx << "\n";
			if(state == 1){
				w.push_back({pos, idx});
			} else {
				if(idx > 0 && !w.empty()){
					ans += abs(pos-w.back().first);
					w.back().first = pos;
					done[idx-1] = true;
				}
			}
		}
		
		v.clear();
		
		for(int x=0;x<w.size();x++){
			v.push_back(make_tuple(w[x].first, 1, w[x].second));
		}
		for(int x=0;x<m;x++){
			if(!done[x]){
				v.push_back(make_tuple(s[x].first-1, 0, -(x+1)));
				v.push_back(make_tuple(s[x].second, 0, (x+1)));
			}
		}
		
		sort(v.begin(), v.end());
		
		w.clear();
		
		for(int x=v.size()-1;x>=0;x--){
			ll pos = get<0>(v[x]);
			int state = get<1>(v[x]), idx = get<2>(v[x]);
			
			if(state == 1){
				w.push_back({pos, idx});
			} else {
				if(idx > 0 && !w.empty()){
					ans += abs(pos-w.back().first);
					w.back().first = pos;
					done[idx-1] = true;
				}
			}
		}
		
		// move left then right
		v.clear();
		w.clear();
		for(int x=0;x<n;x++){
			v.push_back(make_tuple(a[x], 1, x));
		}
		for(int x=0;x<m;x++){
			if(!bef[x]){
				v.push_back(make_tuple(s[x].first-1, 0, -(x+1)));
				v.push_back(make_tuple(s[x].second, 0, (x+1)));
				done[x] = false;
			} else {
				done[x] = true;
			}
		}
		
		sort(v.begin(), v.end());
		
		for(int x=v.size()-1;x>=0;x--){
			ll pos = get<0>(v[x]);
			int state = get<1>(v[x]), idx = get<2>(v[x]);
			
//			cout << pos << " " << state << " " << idx << "\n";
			if(state == 1){
				w.push_back({pos, idx});
			} else {
				if(idx > 0 && !w.empty()){
					ans2 += abs(pos-w.back().first);
					w.back().first = pos;
					done[idx-1] = true;
				}
			}
		}
		
		v.clear();
		
		for(int x=0;x<w.size();x++){
			v.push_back(make_tuple(w[x].first, 1, w[x].second));
		}
		for(int x=0;x<m;x++){
			if(!done[x]){
				v.push_back(make_tuple(s[x].first, 0, (x+1)));
				v.push_back(make_tuple(s[x].second+1, 0, -(x+1)));
			}
		}
		
		sort(v.begin(), v.end());
		
		w.clear();
		
		for(int x=0;x<v.size();x++){
			ll pos = get<0>(v[x]);
			int state = get<1>(v[x]), idx = get<2>(v[x]);
			
			if(state == 1){
				w.push_back({pos, idx});
			} else {
				if(idx > 0 && !w.empty()){
					ans2 += abs(pos-w.back().first);
					w.back().first = pos;
					done[idx-1] = true;
				}
			}
		}
		
		cout << min(ans, ans2) << "\n";
	}

    return 0;
}

