#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	ll l = 0, r = 1e18;
	for(int x=0;x<n;x++){
		l = max(l, p[x].first);
		r = min(r, p[x].second);
		
		if(l <= r){
			cout << "0\n";
		} else {
			ll x1 = (r+l)/2, x2 = (r+l+1)/2;
			
			cout << min(max(abs(x1-r), abs(x1-l)), max(abs(x2-r), abs(x2-l))) << "\n";
		}
	}
    return 0;
}

