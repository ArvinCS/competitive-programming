#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	ll q[m];
	for(int x=0;x<m;x++){
		cin >> q[x];
	}
	
	sort(q, q+m);
	
	vector<pair<ll, ll>> v;
	int pos = 0;
	for(int x=0;x<n;x++){
		while(pos+1 < m && q[pos+1] <= x*100ll){
			pos++;
		}
		
		ll mn = min(abs(x*100ll-q[pos]), (pos+1 < m ? abs(q[pos+1]-x*100ll) : inf));
		v.push_back({(x*100ll-mn)*10+1, p[x]});
		v.push_back({(x*100ll+mn)*10-1, -p[x]});	
	}
	
	sort(v.begin(), v.end());
	
	ll cur = 0, ans = 0;
	for(int x=0;x<v.size();x++){
		cur += v[x].second;
		
		if(x+1 < v.size() && v[x].first == v[x+1].first) continue;
		ans = max(ans, cur);
	}
	
	cout << ans << "\n";
    return 0;
}

