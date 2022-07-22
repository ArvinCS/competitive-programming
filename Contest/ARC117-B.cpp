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
	
	int n;
	cin >> n;
	
	unordered_set<ll> st;
	vector<ll> v;
	for(int x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		
		if(!st.count(tmp)){
			v.push_back(tmp);
			st.insert(tmp);
		}
	}
	
	sort(v.begin(), v.end());
	
	ll ans = 1, cur = 0;
	for(int x=0;x<v.size();x++){
		ans = (ans * max(v[x]-cur+1, 1ll)) % mod;
		
		if(x+1 < v.size()) cur = v[x];
	}
	
	cout << ans % mod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

