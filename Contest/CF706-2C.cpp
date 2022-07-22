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
		
		vector<ll> miner, diamond;
		for(int x=0;x<2*n;x++){
			ll a, b;
			cin >> a >> b;
			
			if(a == 0){
				miner.push_back(abs(b));
			} else {
				diamond.push_back(abs(a));
			}
		}
		
		sort(miner.begin(), miner.end());
		sort(diamond.begin(), diamond.end());
		
		double ans = 0.0;
		for(int x=0;x<n;x++){
			double dist = sqrt(diamond[x] * diamond[x] + miner[x] * miner[x]);
			ans += dist;
		}
		
		cout << fixed << setprecision(12) << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

