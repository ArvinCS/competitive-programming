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

	int n;
	cin >> n;
	
	int ans[n+1];
	fill(ans, ans+n+1, -1);
	
	ans[1] = 1;
	for(int x=2;x<=n;x++){
		if(ans[x] == -1){
			ans[x] = 2;
		}
		
		int cur = ans[x]+1;
		for(int y=x+x;y<=n;y+=x){
			ans[y] = max(ans[y], cur);
		}
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

