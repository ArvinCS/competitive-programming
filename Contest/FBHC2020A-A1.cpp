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

const int maxN = 1e6 + 5;

int tree[maxN];
ll l[maxN], h[maxN], cur[maxN];

int query(int pos){
	pos++;
	
	int ans = 0;
	while(pos > 0){
		ans += tree[pos];
		ans %= mod;
		
		pos -= pos&(-pos);		
	}
	return ans;
}

void update(int pos, int val){
	pos++;
	
	while(pos < maxN){
		tree[pos] += val;
		tree[pos] %= mod;
		
		pos += pos&(-pos);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, k, w;
		cin >> n >> k >> w;
		
		for(int x=1;x<=k;x++){
			cin >> l[x];
		}
		
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		for(int x=k+1;x<=n;x++){
			l[x] = ((a*l[x-2] + b*l[x-1] + c) % d) + 1;
		}
		
		for(int x=1;x<=k;x++){
			cin >> h[x];
		}
		
		cin >> a >> b >> c >> d;
		
		for(int x=k+1;x<=n;x++){
			h[x] = ((a*h[x-2] + b*h[x-1] + c) % d) + 1;
		}
		
		fill(cnt, cur+n+1, 0);
		
		ll ans = 1;
		for(int x=1;x<=n;x++){ // O(N)
			int pos = x;
			for(int y=x;y<=n;y++){ // O(W)
				if(l[x]+w < l[y]){
					break;
				}
				
				if(cnt[y] < h[x]){
					
				}
			}
			
			
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

