#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxP = 39;

ll pw[maxP];
ll prefix[maxP];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	prefix[0] = 1;
	for(int x=1;x<maxP;x++){
		pw[x] = (3ll * pw[x-1]);
		prefix[x] = prefix[x-1] + pw[x];
	}
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll ans = 0;
		for(int x=maxP-1;x>=0;x--){
			if((x > 0 ? prefix[x-1] : 0) >= n){
				continue;
			}
			
			n -= pw[x];
			ans += pw[x];
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

