#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int a[n];
	fill(a, a+n, 0);
	
	int suffix[n], cnt = 0;
	for(int x=n-1;x>=0;x--){
		if(s[x] == '0'){
			cnt = 0;
		} else {
			cnt++;
		}
		
		suffix[x] = cnt;
	}
	
	int nxt[n+1];
	nxt[n] = n;
	for(int x=n-1;x>=0;x--){
		if(s[x] == '0'){
			nxt[x] = x;
		} else {
			nxt[x] = nxt[x+1];
		}
	}
	
	vector<pair<int, int>> v;
	v.push_back({0, n});
	
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		int mn = suffix[x];
		while(!v.empty() && v.back().first <= mn){
			v.pop_back();
		}
		v.push_back({mn, max(x, nxt[x]-1)});
		
		int prv = 0;
		for(int y=v.size()-1;y>=0;y--){
			int cur = v[y].first;
			int pos = v[y].second;
			int nxtpos = (y > 0 ? v[y-1].second-max(0, v[y-1].first-v[y].first) : n-1);
			
			ans += (nxtpos-pos+1)*1ll*cur;
			if(prv < cur){
				ans += cur*1ll*(cur-1)/2 - prv*1ll*(prv+1)/2;
			}
			prv = cur;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

