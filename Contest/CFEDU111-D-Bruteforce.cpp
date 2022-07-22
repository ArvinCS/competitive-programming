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

int n, l, r;
map<int, vector<int>> mp;
int ans = 0, ans2 = 0;
void solve(int idx, int a[]){
	if(idx == n){
		int cnt = 0;
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				if(a[x]+a[y] == (x+y+2)){
					cnt++;
				}
			}
		}
		
		if(cnt == 0) return;
		if(ans < cnt) ans2 = 1;
		if(ans == cnt) ans2++;
		ans = max(ans, cnt);
		if(ans == cnt){
			cout << cnt << " ->";
			for(int x=0;x<n;x++){
				cout << " " << a[x];
			}
			cout << "(" << ans2 << ")" << "\n";
		}
		return;
	}
	
	for(int x=l;x<=r;x++){
		if(idx+1 == x) continue;
		
		a[idx] = x;
		solve(idx+1, a);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> l >> r;
	
	int a[n];
	solve(0, a);

	cout << "max: " << ans << "\n";
    return 0;
}

