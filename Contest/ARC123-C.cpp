#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll a[20];
		for(int x=0;x<20;x++){
			a[x] = n%10;
			n /= 10;
		}
		
		bool found = false;
		ll ans = 1e18;
		while(!found){
			ll cur = 0;
			found = true;
			
			for(int x=19;x>=0;x--){
				if(a[x] < cur){
					a[x] += 10;
					a[x+1]--;
					found = false;
					break;
				}
				cur = max(cur, (a[x]+2)/3);
			}
			
			if(found){
				ans = cur;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

