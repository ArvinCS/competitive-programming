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

const int maxN = 2*(2e5 + 50);

int tree[2*maxN], a[maxN];
int n;

int query(int left, int right){ // [l, r)
	int ans = -1;
	
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
		if(left&1){
			if(ans == -1) ans = tree[left++];
			else ans = __gcd(ans, tree[left++]);
		}
		if(right&1){
			if(ans == -1) ans = tree[--right];
			else ans = __gcd(ans, tree[--right]);
		}
	}
	return ans;
}

void build(){
	for(int x=0;x<n;x++){
		tree[n+x] = a[x];
	}
	for(int x=n-1;x>0;x--){
		tree[x] = __gcd(tree[x<<1], tree[(x<<1) | 1]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			a[n+x] = a[x];
		}
		
		int sz = n;
		n *= 2;
		build();
		
		int ans = inf_int;
		int left = 0, right = n;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool ok = true;
			int cur = query(0,mid+1);
			for(int x=1;x<sz;x++){
				if(cur != query(x, x+mid+1)){
					ok = false;
					break;
				}
			}
			
			if(ok){
				ans = min(ans, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

