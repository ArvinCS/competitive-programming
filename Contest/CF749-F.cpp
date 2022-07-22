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

const int maxN = 1e3 + 5;

int n, k, mx = 1;
int edge[maxN][maxN];

void solve(int l, int r, bool used[]){
	if(l >= r) return;
	int length = r-l+1;
	int sz = (length+k-1)/k;
	
	int c = -1;
	for(int x=1;x<=n;x++){
		if(!used[x]){
			c = x;
			break;
		}
	}
	used[c] = true;
	
	for(int x=l;x<=r;x++){
		for(int y=x+1;y<=r;y++){
			if((x-l)/sz != (y-l)/sz){
				edge[x][y] = c;
				mx = max(mx, c);
			}
		}
	}
	
	for(int x=l;x<=r;x+=sz){
		solve(x, min(x+sz-1, r), used);
	}
	used[c] = false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> k;
	
	bool used[n+1];
	fill(edge[0], edge[maxN], 0);
	fill(used, used+n+1, false);
	
	solve(0, n-1, used);
	
	cout << mx << "\n";
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(x > 0 || y > 1) cout << " ";
			cout << edge[x][y];
		}
	}
	cout << "\n";
    return 0;
}

