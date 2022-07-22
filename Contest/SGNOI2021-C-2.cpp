#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 1e18;
const int maxN = 4e5 + 5;
const int maxSN = 100;

ll dp[2][maxSN], prefix[maxSN], suffix[maxSN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	ll d[n];
	for(int x=0;x<n;x++){
		d[x] = (p[x]-a[x]+k+1)%(k+1);
	}
	
	if(k == 0){
		cout << "0\n";
		return 0;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans += d[x];
		if(x > 0 && d[x-1] >= d[x]) pq.push(k+1-d[x-1]);
		else if(x > 0) pq.push(k+1-2*d[x]);
	}
	for(int x=0;x<n;x++){
		if(pq.empty()) break;
		cout << ans << " - " << pq.top() << "\n";
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
    return 0;
}

