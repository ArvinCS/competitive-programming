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
		ll n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		vector<ll> v;
		ll cnt = 1;
		for(int x=1;x<n;x++){
			if(data[x-1] != data[x]){
			 	v.push_back(cnt);
				cnt = 0;
			}
			cnt++;
		}
		v.push_back(cnt);
		
		sort(v.rbegin(), v.rend());
		
		priority_queue<ll> pq;
		for(int x=0;x<v.size();x++){
			pq.push(v[x]);
		}
		
		ll ans = 0;
		
		while(pq.size() > 1){
			ll p1 = pq.top();
			pq.pop();
			ll p2 = pq.top();
			pq.pop();
			
			if(p1 > 1) pq.push(p1-1);
			if(p2 > 1) pq.push(p2-1);
			ans += 2;
		}
		
		cout << max(n-ans, 0ll) << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

