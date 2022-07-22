#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 2e5 + 5;

ll fac[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = 0;
	fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1])%mod;
	} 
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n, greater<int>());
		
		ll ans = 1;
		ll cnt = 0, cnt2 = 0;
		for(int x=1;x<n;x++){
			if(a[x] == a[0]){
				cnt2++;
				cnt2 %= mod;
			} else if(a[x]+1 == a[0]){
				cnt++;
				cnt %= mod;
			} else if(a[x]+1 < a[0]){
				ans *= (x+1);
				ans %= mod;
			}
		}
		
		if(cnt2 > 0){
			cout << fac[n] << "\n";
			continue;
		}
		if(cnt == 0){
			cout << "0\n";
			continue;
		}
		
		cout << (fac[n]-((fac[cnt]*ans)%mod)+mod) % mod << "\n";
	}
	
    return 0;
}

