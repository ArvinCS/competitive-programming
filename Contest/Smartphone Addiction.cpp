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
	
	ll n, m, t, maxN;
	cin >> n >> m >> t;
	
	pair<ll, ll> cafe[m];
	for(int i=0;i<m;i++){
		cin >> cafe[i].first >> cafe[i].second;
	}
	
	maxN = n;
	
	ll lastSecond = 0;
	bool valid = true;
	for(int i=0;i<m;i++){
		n -= cafe[i].first - lastSecond;
		if(n <= 0){
			valid = false;
			break;
		}
		
		n = min(n + cafe[i].second - cafe[i].first, maxN);
		lastSecond = cafe[i].second;
	}
	
	if(valid){
		n -= t-lastSecond;
		if(n <= 0){
			valid = false;
		}
	}
	
	if(valid) cout << "Yes\n";
	else cout << "No\n";
	
    return 0;
}

