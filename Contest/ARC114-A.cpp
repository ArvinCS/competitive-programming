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

vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int arr[50];
int n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	for(int x=0;x<n;x++){
		cin >> arr[x];
	}
	
	ll ans = inf_ll;
	for(int i=1;i<(1<<15);i++){
		ll cnt = 1;
		for(int x=0;x<primes.size();x++){
			if(i&(1<<x)) cnt *= primes[x];
		}
		
		bool valid = true;
		for(int x=0;x<n;x++){
			if(__gcd(arr[x]*1ll, cnt) == 1){
				valid = false;
				break;
			}
		}
		
		if(valid) ans = min(ans, cnt);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
