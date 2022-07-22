#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m[n];
	for(int x=0;x<n;x++){
		cin >> m[x];
	}
	
	pair<ll, int> best = {-1, -1};
	for(int x=0;x<n;x++){
		ll val = m[x];
		int cur = m[x];
		for(int l=x-1;l>=0;l--){
			cur = min(cur, m[l]);
			val += cur;
		}
		
		cur = m[x];
		for(int r=x+1;r<n;r++){
			cur = min(cur, m[r]);
			val += cur;
		}
		
		best = max(best, {val, x});
	}
	
	ll ans[n];
	int cur = m[best.second];
	for(int l=best.second;l>=0;l--){
		cur = min(cur, m[l]);
		ans[l] = cur;
	}
		
	cur = m[best.second];
	for(int r=best.second+1;r<n;r++){
		cur = min(cur, m[r]);
		ans[r] = cur;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

