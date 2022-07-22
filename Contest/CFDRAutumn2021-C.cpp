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

const int maxA = 1e6 + 5;

bool prime[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(prime, prime+maxA, true);
	
	for(int x=2;x*x<maxA;x++){
		if(prime[x]){
			for(int y=2*x;y<maxA;y+=x){
				prime[y] = false;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		vector<int> v[m];
		for(int x=0;x<n;x++){
			if(a[x] == 1) continue;
			
			v[x%m].push_back(x);
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			auto it = lower_bound(v[x%m].begin(), v[x%m].end(), x+1);
			
			if(it != v[x%m].end()){
				if(a[x] == 1){
					if(prime[a[*it]]){
						int prv = *it;
						
						it++;
						
						int nxt = (it == v[x%m].end() ? n+m-1 : *it);
						ans += (nxt-prv) / m;
					}
				} else {
					if(prime[a[x]]) ans += (*it - x) / m - 1;	
				}
			} else {
				if(a[x] > 1 && prime[a[x]]) ans += max(0, (n+m-1 - x) / m - 1);
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

