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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int ans[n+1];
		if(n % 2 == 0){
			for(int x=1;x<=n;x++){
				ans[x] = ((x+1)%2 == 0 ? x+1 : x-1);
			}
		} else {
			for(int x=1;x<=n-1;x++){
				ans[x] = ((x+1)%2 == 0 ? x+1 : x-1);
			}
			ans[n] = n;
			swap(ans[n-1], ans[n]);
		}
		
		for(int x=1;x<=n;x++){
			if(x > 1) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

