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
		ll n, m, p, q;
		cin >> n >> m >> p >> q;
		
		bool found = false;
		int res = n-p;
		for(int x=0;x<=1000;x++){
			for(int y=0;y<=1000;y++){
				if(res == (p+q)*x - (n+m)*2*y){
					cout << x << " " << y << "\n";
					cout << (p+q)*x + p << " " << (n+m)*2*y+n << "\n";
					cout << max((p+q)*x + p, (n+m)*2*y+n) << "\n";
					found = true;
					break;
				}
			}
			if(found) break;
		}
		
		if(!found) cout << "infinity\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

