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

const int maxN = 2e6 + 5;

ll tree[maxN];

ll query(int pos){
	if(pos < 0) return 0;
	
	pos++;
	
	ll ans = 0;
	while(pos > 0){
		ans += tree[pos];
		ans %= mod;
		
		pos -= pos & (-pos);		
	}
	return ans;
}

void update(int pos, ll val){
	if(pos < 0) return;
	
	pos++;
	val %= mod;
	
	while(pos < maxN){
		tree[pos] += val;
		tree[pos] %= mod;
		
		pos += pos & (-pos);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	ll table[n+m+1];
	fill(table, table+n+m+1, 0);
	
	update(0, 1);
	for(int x=1;x<n+m;x++){
		int bound = x;
		int left = 0, right = min(x, m);
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if((x-mid) > mid+k){
				left = mid+1;
			} else {
				bound = mid;
				right = mid-1;
			}
		}
		
		int batas = min(n-1, x-bound-1);
		int tmp = query(x-bound), tmp2 = query(batas), tmp3 = query(batas-1), tmp4 = query(x-1-m);
		
		table[x] += tmp2;
		table[x] += (tmp-tmp4+mod) % mod;
		
		cout << x << " " << table[x] << " " << bound << " | " << tmp << " " << tmp2 << " " << tmp3 << " " << tmp4 << "\n";
		update(batas, tmp3);
		update(batas+1, (tmp2-tmp3+2*mod)%mod);
	}
	
	table[n+m] = query(n);
	cout << table[n+m] << "\n";
    return 0;
}

