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

const int maxN = 1e4 + 5;

bool prime[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(prime, prime+maxN, true);
	
	prime[1] = false;
	for(int x=2;x*x<maxN;x++){
		if(prime[x]){
			for(int y=x+x;y<maxN;y+=x){
				prime[y] = false;
			}
		}
	}
	
	us t;
	cin >> t;
	
	while(t--){
		string s;
		int k;
		cin >> k >> s;
		
		ll a[k];		
		for(int x=0;x<k;x++){
			a[x] = (s[x] - '0');
		}
		
		ll ans = inf_ll;
		for(int x=0;x<k;x++){
			ll num = a[x];
			
			if(!prime[num]){
				ans = min(ans, num);
			}
			
			for(int y=x+1;y<k;y++){
				num *= 10;
				num += a[y];
				
				if(!prime[num]){
					ans = min(ans, num);
				}
				
				num /= 10;
			}
		}
		
		if(ans >= 10){
			cout << 2 << "\n";
		} else {
			cout << 1 << "\n";
		}
		cout << ans << "\n";
	}
	
    return 0;
}

