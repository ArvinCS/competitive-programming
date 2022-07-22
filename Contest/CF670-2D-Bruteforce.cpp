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

int n, a[5000], best = inf_int;

void solve(int idx, int b[], int c[]){
	if(idx == n){
		int mx = -inf_int;
		for(int x=0;x<n;x++){
			mx = max(mx, b[x]);
			mx = max(mx, c[x]);
		}		
		
		if(mx > best || mx > 10) return;
		
		best = min(best, mx);
		
		cout << mx << ": \n";
		for(int x=0;x<n;x++){
			cout << b[x] << " ";
		}
		cout << "\n";
		for(int x=0;x<n;x++){
			cout << c[x] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int x=-15;x<=15;x++){
		if((idx > 0 ? b[idx-1] : -inf_int) <= x && a[idx]-x <= (idx > 0 ? c[idx-1] : inf_int)){
			b[idx] = x;
			c[idx] = (a[idx]-x);
			solve(idx+1, b, c);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int b[n], c[n];
	solve(0, b, c);
		
	cout << "Best: " << best << "\n";
    return 0;
}

