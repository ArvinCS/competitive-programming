#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[k];
	for(int x=0;x<k;x++){
		cin >> a[x];
		a[x]--;
	}
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ll mn = 1e18;
		for(int y=0;y<k;y++){
			ll distX = abs(p[x].first-p[a[y]].first);
			ll distY = abs(p[x].second-p[a[y]].second);
			
			ll dist = distX*distX + distY*distY;
			mn = min(mn, dist);
		}
		
		ans = max(ans, mn);
	}
	
	double val = sqrt(ans);
	cout << fixed << setprecision(6) << val << "\n";
    return 0;
}

