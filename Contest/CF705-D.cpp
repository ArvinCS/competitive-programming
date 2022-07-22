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

map<int, int> mp[maxN], p[maxN];
int prime[maxN], cntP[maxN];
vector<int> primes;
vector<int> used;

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= mod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

ll mulmod(ll x, ll y){
	ll ans = 0;
	x %= mod;
	
	while(y > 0){
		if(y&1) ans = (ans + x) % mod;
		
		y >>= 1;
		x = (x*2) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxN;x++) prime[x] = x;
	for(int x=2;x<maxN;x++){
		if(prime[x] == x){
			primes.push_back(x);
			for(int y=x+x;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	int n, m;
	cin >> n >> m;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	for(int x=0;x<n;x++){
		int cur = data[x];
		while(cur > 1){
			int div = prime[cur], cnt = 0;
			while(cur % div == 0){
				cnt++;
				cur /= div;
			}
			p[div][cnt]++;
			if(cntP[div] == n){
				used.push_back(div);
			}
			mp[x][div] += cnt;
			cntP[div]++;
		}
	}
	
	ll ans = 1;
	for(auto i : primes){
		if(cntP[i] == n) ans = mulmod(ans, powmod(i, (*p[i].begin()).first));
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--;
		
		int cur = b;
		while(cur > 1){
			int div = prime[cur], cnt = 0;
			while(cur % div == 0){
				cnt++;
				cur /= div;
			}
			
			int prv = (*p[div].begin()).first;
			bool change1 = false, change2 = false;
			if(mp[a][div] == 0){
				cntP[div]++;
				if(cntP[div] == n){
					change1 = true;
				}
			} else {
				p[div][mp[a][div]]--;
				if(p[div][mp[a][div]] == 0){
					change2 = true;
					p[div].erase(mp[a][div]);
				}
			}
			
//			cout << a << "(" << div << ") == " << mp[a][div] << "\n";
//			cout << x << " - " << cntP[div] << " " << div << " -- " << change << " " << (*p[div].begin()).first << " " << prv << "\n";
			mp[a][div] += cnt;
			p[div][mp[a][div]]++;
			
			if(change1){
				ans = mulmod(ans, powmod(div, (*p[div].begin()).first));
			} else if(change2){
				if(cntP[div] == n) ans = mulmod(ans, powmod(div, (*p[div].begin()).first-prv));
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

