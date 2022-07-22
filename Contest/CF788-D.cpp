#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	vector<pair<ll, int>> v;
	
	for(ll x=1;x<=1e5;x++){
		ll cnt2 = 2*x;
		ll cur = 2*x*x;
		
		v.push_back({cur, cnt2});
		
		cur += x*4;
		cnt2++;
		
		v.push_back({cur, cnt2});
	}
	
	sort(v.begin(), v.end());
	
	int mn = 1e9;
	vector<pair<ll, int>> w;
	for(int x=v.size()-1;x>=0;x--){
		if(x > 0 && v[x-1].first == v[x].first) continue;
		if(v[x].second <= mn){
			w.push_back(v[x]);
			mn = v[x].second;
		}
	}
	
	reverse(w.begin(), w.end());
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		cout << (*(lower_bound(w.begin(), w.end(), make_pair(n, -1)))).second << "\n";
	}
	
    return 0;
}

