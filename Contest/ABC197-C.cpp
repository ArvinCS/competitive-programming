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

ll arr[25];
int n;

ll solve(int index, vector<ll> v, ll cur){
	if(index == n){
		ll ans = cur;
		for(int x=0;x<v.size();x++){
			ans ^= v[x];
		}
		
		return ans;
	}
	
	ll best = solve(index+1, v, cur|arr[index]);
	v.push_back(cur);
	cur = arr[index];
	best = min(best, solve(index+1, v, cur));
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> arr[x];
	}

	vector<ll> tmp;
	cout << solve(1, tmp, arr[0]) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

