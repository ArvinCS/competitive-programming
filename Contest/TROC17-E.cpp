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

const int maxN = 1e5 + 5;

int n;
ll data[maxN], tree[2*maxN];

void build(){
	for(int x=0;x<n;x++){
		tree[n+x] = data[x];
	}
	for(int x=n-1;x>0;x--){
		tree[x] = (tree[x<<1] * tree[x<<1|1]) % smod;
	}
}

void update(int pos, int val){
	pos += n;
	tree[pos] |= val;
	
	for(int x=pos;x>1;x>>=1){
		tree[x>>1] = (tree[x] * tree[x^1]) % smod;
	}
}

ll query(int left, int right){ // [left, right)
	ll ans = 1;
	for(left += n, right += n; left < right; left>>=1, right>>=1){
		if(left&1) ans *= tree[left++];
		ans %= smod;
		if(right&1) ans *= tree[--right];
		ans %= smod;
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
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	build();
	
	ll ans = 1;
	int pos[32];
	fill(pos, pos+32, -1);
	
	for(int x=0;x<n;x++){
		for(int i=0;i<32;i++){
			int bit = (1 << i);
			if(data[x]&bit){
				for(int y=pos[i]+1;y<=x;y++){
					update(y, bit);
				}
				pos[i] = x;
			}
		}
		ans *= query(0, x+1);
		ans %= smod;
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

