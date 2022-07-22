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

const int maxLength = 15;
const int maxM = 1e6 + 5;

vector<ll> v;

ll n;
bool done[maxM];

ll length(ll n){
	ll ans = 0;
	while(n > 0){
		ans++;
		n /= 10;
	}
	return ans;
}

ll dp(int i, ll cur, bool zero, bool less){
	ll ans = 0;
	if(zero && !done[cur] && cur*pow(10, length(cur))+cur <= n){
		done[cur] = true;
		ans++;
	}
	if(i < v.size()/2){
		int mx = (less ? 9 : v[i]);
		for(int x=0;x<=mx;x++){
			ans += dp(i+1, cur*10 + x, zero || x > 0, less || x < v[i]);
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	fill(done, done+maxM, false);
	
	ll tmp = n;
	while(tmp > 0){
		v.push_back(tmp % 10);
		tmp /= 10;
	}
	reverse(v.begin(), v.end());
	
	if(v.size() % 2 == 1){
		v.pop_back();
		for(int i=0;i<v.size();i++){
			v[i] = 9;
		}
	}
	
	cout << dp(0, 0, false, false) << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

