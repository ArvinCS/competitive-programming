#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	vector<ll> ans;
	ll cur = 0, cnt = 0, mx = 0;
	for(int x=0;x<n;x++){
		cnt += a[x];
		cur += cnt;
		
		mx = max(mx, a[x]);
		
		ans.push_back(cur+(x+1)*mx);
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

