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

const int maxN = 1e6;
int n;

ll tree[2*maxN];

ll mul(ll a, ll b){
	ll ans = 0;
	a %= smod;
	
	while(b > 0){
		if(b & 1) ans = (ans+a) % smod;
		
		a = (2*a) % smod;
		b >>= 1;
	}
	
	return ans % smod;
}

ll query(int left, int right){
	ll ans = 0;
	
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
		if(left&1) ans |= tree[left++];
		if(right&1) ans |= tree[--right];
	}	
	
	return ans % smod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	
	for(int x=0;x<n;x++) cin >> tree[n+x];
	for(int x=n-1;x>0;--x){
		tree[x] = tree[x<<1]|tree[x<<1|1];
	}

	ll ans = 1;
	for(int x=0;x<n;x++){
		for(int y=x;y<n;y++){
			ans = ((ans%smod) * (query(x,y+1) %smod)) % smod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

