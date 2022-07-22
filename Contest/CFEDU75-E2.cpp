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
		int n;
		cin >> n;
		
		pair<ll, ll> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		sort(p, p+n);
		
		vector<ll> w;
		for(int x=0;x<n;x++){
			w.push_back(p[x].first);
		}
		w.erase(unique(w.begin(), w.end()), w.end());
		
		tree.reset(n, p);
		
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		vector<ll> z;
		ll ans = 0;
		for(int x=n-1;x>=0;x--){
			pq.push(p[x].second);
			while(pq.size()+p[x].first-1 > w.back()){
				z.push_back(pq.top());
				pq.pop();
			}
		}
		
		sort(z.begin(), z.end());
		
		int cnt = 0;
		int pos = 0;
		ll cur = 0;
		for(int x=0;x<n;x++){
			if(cur < p[x].first){
				for(int y=cur;y<p[x].first;y++){
					ans += z[pos++];
				}
			}
			cur = max(p[x].first+1, cur+1);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

