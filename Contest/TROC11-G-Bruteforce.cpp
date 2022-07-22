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

int m;

int solve(int n, int idx, int c[]){
	if(idx == n){
		bool valid = true;
		for(int x=0;x<n;x++){
			int nxt1 = (x+1)%n, nxt2 = (x+2)%n;
			
			if(c[x] == c[nxt1] || c[x] == c[nxt2] || c[nxt1] == c[nxt2]){
				valid = false;
				break;
			}
		}
		return valid;
	}
	
	int ans = 0;
	for(int x=0;x<m;x++){
		if(idx > 0 && c[idx-1] == x) continue;
		c[idx] = x;
		ans += solve(n, idx+1, c);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n >> m;
	
	int c[n];
	for(int x=1;x<=n;x++){
		cout << x << " -> " << solve(x, 0, c) << "\n";
	}

    return 0;
}

