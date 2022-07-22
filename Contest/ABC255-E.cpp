#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll s[n];
	s[0] = 0;
	for(int x=1;x<n;x++){
		cin >> s[x];
		s[x] -= s[x-1];
	}
	
	ll l[m];
	for(int x=0;x<m;x++){
		cin >> l[x];
	}
	
	map<ll, int> mp;
	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++){
			if(y % 2 == 0){
				mp[l[x]-s[y]]++;
			} else {
				mp[s[y]-l[x]]++;
			}
		}
	}
	
	int ans = 0;
	for(auto p : mp){
		ans = max(ans, p.second);
	}
	
	cout << ans << "\n";
    return 0;
}

