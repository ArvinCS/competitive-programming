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

	ll n, k;
	cin >> n >> k;
	
	ll a[n], length[n], cnt = n, ans = 0;
	priority_queue<pair<ll, int>> pq;
	for(int x=0;x<n;x++){
		cin >> a[x];
		length[x] = 1;
		ans += pow(a[x], 2);
	}
	
	for(int x=0;x<n;x++){
		ll remain = a[x]%2;
		
		ll nxt = pow(a[x]/2 + 1, 2)*remain + pow(a[x]/2, 2)*(2-remain);
		
		pq.push(make_pair(pow(a[x], 2)-nxt, x));
	}
	
	while(cnt < k){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		ans -= p.first;
		
		ll idx = p.second;
		if(a[idx] == length[idx]) continue;
		
		length[idx]++;
		cnt++;
		
		ll remain1 = a[idx]%length[idx];
		ll cur = pow(a[idx]/length[idx] + 1, 2)*remain1 + pow(a[idx]/length[idx], 2)*(length[idx]-remain1);		
		
		ll remain2 = a[idx]%(length[idx]+1);
		ll nxt = pow(a[idx]/(length[idx]+1) + 1, 2)*remain2 + pow(a[idx]/(length[idx]+1), 2)*((length[idx]+1)-remain2);
		
		pq.push(make_pair(cur-nxt, idx));
	}
	
	cout << ans << "\n";
    return 0;
}
