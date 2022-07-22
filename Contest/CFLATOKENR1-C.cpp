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

const int maxN = 4e5 + 5;

int parrent[maxN], sz[maxN];

int getParrent(int x){
	if(parrent[x] == x) return parrent[x];
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[b] > sz[a]){
			swap(a, b);
		}
		
		parrent[b] = a;
		sz[a] += sz[b];
	}
}

bool check(int x, int y){
	return getParrent(x) != getParrent(y);
}

ll modpow(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		for(int x=0;x<=n;x++){
			parrent[x] = x;
			sz[x] = 1;
		}
		
		int cnt = n;
		for(int x=0;x<n;x++){
			if(check(a[x], b[x])){
				merge(a[x], b[x]);
				cnt--;
			}
		}
		
		cout << modpow(2ll, cnt) << "\n";
	}

    return 0;
}

