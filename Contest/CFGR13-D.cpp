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

	int q;
	cin >> q;
	
	while(q--){
		ull a, b;
		cin >> a >> b;
		
		if(a > b){
			cout << "NO\n";
			continue;
		}
		
		int cnt = 0;
		bool possible = true;
		for(ull x=1;x<=30;x++){
			ull bit = 1 << (x-1);
			if(a < bit && b < bit) break;
			
			if((a&bit) == bit) cnt++;
			if((b&bit) == bit) cnt--;
			
			if(cnt < 0) possible = false;
		}

		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

