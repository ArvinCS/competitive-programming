#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, w;
	cin >> n >> w;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+n);
	
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		int mn = min(w, p[x].second);
		
		w -= mn;
		p[x].second -= mn;
		
		ans += mn*1ll*p[x].first;
	}
	
	cout << ans << "\n";
    return 0;
}

