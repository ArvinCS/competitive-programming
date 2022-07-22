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

const int maxN = 2e5 + 5;

int n, k;
pair<ll, int> a[maxN];
ll c[maxN], prefix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].second = x;
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	for(int x=0;x<n;x++){
		prefix[x] = c[x] + (x > 0 ? prefix[x-1] : 0);	
	}
	
	sort(a, a+n);
	
	ll ans = 0;
	priority_queue<pair<ll, int>> pq, pq2;
	for(int x=0;x<n;x++){
		pq.push({a[x].first - (a[x].second > 0 ? prefix[a[x].second-1] : 0), x}); // kiri
		pq2.push({a[x].first + prefix[a[x].second], x}); // kanan
		
		while(!pq.empty() && abs(a[x].first-a[pq.top().second].first) > k){
			pq.pop();
		}
		while(!pq2.empty() && abs(a[x].first-a[pq2.top().second].first) > k){
			pq2.pop();
		}
		
		ans = max(ans, max(k - a[x].first + prefix[a[x].second] + pq.top().first, k + pq2.top().first - a[x].first - (a[x].second > 0 ? prefix[a[x].second-1] : 0)));
	}
	
	cout << ans << "\n";
	
    return 0;
}

