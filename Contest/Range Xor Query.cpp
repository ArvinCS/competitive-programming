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

const int maxN = 300005;
int n;

ll tree[2*maxN];

int query(int left, int right){
	int ans = -1;
	
//	cout << left << " -- " << right << "\n"; 
	for(left += n, right += n; left < right; left >>= 1, right >>= 1){
//		cout << left << " - " << right << "\n"; 
		if(left&1){
			if(ans == -1) ans = tree[left++];
			else ans ^= tree[left++];
		}
		if(right&1){
			if(ans == -1) ans = tree[--right];
			else ans ^= tree[--right];
		}
	}	
	
	return ans;
}

void update(int index, int val){
	index += n;
	
	tree[index] ^= val;
	for(int x=index;x>1;x>>=1){
		tree[x>>1] = tree[x]^tree[x^1];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		cin >> tree[n+x];
	}
	
	for(int x=n-1;x>0;--x){
		tree[x] = ((x<<1|1) > 2*n ? tree[x<<1] : tree[x<<1]^tree[x<<1|1]);
	}
	
//	for(int x=1;x<=2*n;x++){
//		cout << "--" << tree[x] << "\n";
//	}
	
	for(int x=0;x<q;x++){
		int t, a, b;
		cin >> t >> a >> b;
		
		if(t == 1){
			update(a-1, b);
		} else {
			cout << query(a-1, b) << "\n";
		}
	}
	
    return 0;
}

