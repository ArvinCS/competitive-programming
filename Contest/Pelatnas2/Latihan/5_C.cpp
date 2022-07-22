#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k, d;
	cin >> n >> k >> d;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	pair<int, ll> p[d];
	for(int x=0;x<d;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	priority_queue<pair<ll, int>> pq;
	ll ans = 0;
	
	for(int x=0;x<n;x++){
		while(!pq.empty() && x-pq.top().second+1 > k){
			pq.pop();
		}
		
		if(!pq.empty()) ans = max(ans, a[x]+pq.top().first);
		
		pq.push({a[x], x});
	}
	
	cout << ans << "\n";
    return 0;
}

