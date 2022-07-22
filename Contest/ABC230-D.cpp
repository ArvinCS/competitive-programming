#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll d;
	cin >> n >> d;
	
	vector<pair<ll, int>> v;
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		v.push_back({p[x].first, x});
		v.push_back({p[x].second, x});
	}
	
	sort(v.begin(), v.end());
	
	set<int> st;
	
	int ans = 0, mx = 0;
	for(int x=0;x<v.size();x++){
		if(st.count(v[x].second)){
			ans++;
			mx = v[x].first+d-1;
			st.clear();
		} else {
			if(p[v[x].second].first > mx){
				st.insert(v[x].second);
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

