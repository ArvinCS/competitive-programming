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

int n, tree[maxN], a[maxN];

int query(int pos){
	pos++;
	
	pos = (n+3)-pos-1;
	
	int ans = 0;
	while(pos > 0){
		ans += tree[pos];
		pos -= pos&(-pos);
	}
	return ans;
}

void update(int pos, int val){
	pos++;
	
	pos = (n+3)-pos-1;
	
	while(pos < n+3){
		tree[pos] += val;
		pos += pos&(-pos);
	}
}

int solve(int x, int y){
	int pos[2], b[n];
	pos[0] = x;
	pos[1] = y;
	
	for(int x=0;x<n;x++){
		b[x] = pos[a[x]];
		pos[a[x]] += 2;
	}
	
	fill(tree, tree+n+3, 0);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		ans += query(b[x]);
		update(b[x], 1);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		int one = 0, zero = 0;
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x] %= 2;
			
			if(a[x] == 1){
				one++;
			} else {
				zero++;
			}
		}
		
		if(abs(zero-one) > 1){
			cout << "-1\n";
			continue;
		}
		
		if(one == zero){
			cout << min(solve(1, 2), solve(2, 1)) << "\n";
		} else if(one > zero){
			cout << solve(2, 1) << "\n";
		} else {
			cout << solve(1, 2) << "\n";
		}
	}
	
    return 0;
}

