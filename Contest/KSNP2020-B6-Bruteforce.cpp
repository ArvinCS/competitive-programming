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

int n, m, k;

int solve(int idx, int a[]){
	if(idx == n){
		int prv = 0, cnt = 0;
		int ans = 0;
		for(int x=0;x<n;x++){
			if(prv == a[x]){
				cnt++;
				ans = max(ans, cnt);
			} else {
				prv = a[x];
				cnt = 1;
				ans = max(ans, cnt);
			}
		}
		
		if(ans >= k){
			for(int x=0;x<n;x++) cout << a[x] << " ";
			cout << "\n";
			return 1;
		} else {
			return 0;
		}
	}
	
	int ans = 0;
	for(int x=1;x<=m;x++){
		a[idx] = x;
		ans += solve(idx+1, a); 
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m >> k;
	
	int a[n];
	cout << solve(0, a) << "\n";

    return 0;
}

