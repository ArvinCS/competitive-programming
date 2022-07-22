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

ll n, k;
ll data[maxN], up[maxN];

ll solve(ll level, ll day, ll sum){
	ll need = (k-sum+data[level]-1)/data[level];
	ll need2 = (up[level+1]-sum+data[level]-1)/data[level];
	
	ll best = inf_ll;
	if(level < n-1 && need2 < need){
		best = min(best, solve(level+1, day+need2+1, (sum+data[level]*need2) - up[level+1]));
	}
	
	day += need;
	
	best = min(best, day);
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		up[0] = inf_int;
		for(int x=1;x<n;x++){
			cin >> up[x];
		}
		
		cout << solve(0, 0, 0) << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

