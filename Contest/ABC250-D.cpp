#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxP = 1e6 + 5;

bool prime[maxP];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(prime, prime+maxP, true);
	for(int x=2;x*x<maxP;x++){
		if(prime[x]){
			for(int y=2*x;y<maxP;y+=x){
				prime[y] = false;
			}
		}
	}
	
	ll n;
	cin >> n;
	
	ll ans = 0;
	for(int x=1;x*1ll*x*x<=n;x++){
		if(prime[x]){
			for(int y=2;y*1ll*x*x*x<=n&&y<x;y++){
				if(prime[y]){
					ans++;
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

