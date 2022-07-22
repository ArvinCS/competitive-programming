#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int t[n];
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	ll mx = 0;
	for(int x=0;x<n;x++){
		ll cur = (1ll << t[x]);
		
		if(mx >= cur){
			cur = mx;
			cur |= (1ll << (t[x]+1))-1;
			cur ^= (1ll << t[x])-1;
			
			if(mx >= cur){
				cur = mx+(1ll << (t[x]+1));
				cur |= (1ll << (t[x]+1))-1;
				cur ^= (1ll << t[x])-1;
			}
		}
		
		mx = max(mx, cur);
	}
	
	cout << mx << "\n";
    return 0;
}

