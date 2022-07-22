#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool customSort(pair<ll, ll> a, pair<ll, ll> b){
	return a.first-a.second < b.first-b.second;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].second;
	}
	for(int x=0;x<n;x++){
		cin >> p[x].first;
	}
	
	sort(p, p+n, customSort);
	
	ll table[n+1];
	fill(table, table+n+1, 1e18);
	
	table[0] = 0;
	for(int x=0;x<n;x++){
		for(int y=n-1;y>=0;y--){
			if(table[y] == 1e18) continue;
			if(table[y] <= p[x].first){
				table[y+1] = min(table[y+1], table[y]+p[x].second);
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<=n;x++){
		if(table[x] != 1e18){
			ans = x;
		}
	}
	cout << ans << "\n";
	return 0;
}
