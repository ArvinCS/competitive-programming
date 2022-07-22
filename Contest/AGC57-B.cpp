#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for(int x=0;x<n;x++) pq.push(a[x]);
	
	ll ans = a[n-1]-a[0];
	ll mx = a[n-1];
	for(int x=1;x<=50000;x++){
		mx = max(mx, 2*pq.top()+)
	}
	
	cout << ans << "\n";
    return 0;
}

