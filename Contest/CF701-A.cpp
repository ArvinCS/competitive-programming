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
	
	us t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		int ans = inf_int;
		for(int x=0;x<=max(a-b+2, 0);x++){
			if(b+x == 1) continue;
			int tmp = a;
			int cnt = x;
			while(tmp > 0){
				tmp /= (b+x);
				cnt++;
			}
			if(ans < cnt) break;
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

