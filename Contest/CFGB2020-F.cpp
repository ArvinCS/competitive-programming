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

const int maxN = 5e5 + 5;

int parrent[maxN], sz[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}	
	return ans;
}

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void join(int x, int y){
	int a = getParrent(x);
	int b = getParrent(y);
	
	if(a != b){
		if(sz[a] < sz[b]){
			swap(a, b);
		}
		
		sz[a] += sz[b];
		parrent[b] = a;
	}
}

bool check(int x, int y){
	return getParrent(x) != getParrent(y);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<=m+1;x++){
		parrent[x] = x;
		sz[x] = 1;
	}
	
	vector<int> ans;
	for(int x=0;x<n;x++){
		int k;
		cin >> k;
		
		int a, b = m+1;
		
		cin >> a;
		if(k > 1) cin >> b;
		
		if(check(a, b)){
			join(a, b);
			ans.push_back(x);
		}
	}
	
	cout << powmod(2, ans.size()) << " " << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

