#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	string subsoal;
	cin >> subsoal;
	
	ll a, b, q;
	cin >> a >> b >> q;
	
	ll l[q], r[q];
	vector<int> ans[q];
	vector<pair<ll, int>> w;
	for(int x=0;x<q;x++){
		cin >> l[x] >> r[x];
		
		w.push_back({r[x], x});
	}
	
	sort(w.begin(), w.end());
	
	vector<pair<ll, int>> v;
	while(a >= 1 && b > 0){
		ll oldA = a, oldB = b;
		
		v.push_back({a/(b+1), 1});
		
		a %= (b+1);
		
		if(a == 0) break;
		
		v.push_back({b/a, 0});
		
		b %= a;
		
		if(a == oldA && b == oldB){
			break;
		}
	}
	
	if(a == 0 || b != 0){
		cout << "TIDAK MUNGKIN\n";
		return 0;
	}
	if(a > 0) v.push_back({a, 1});
	
	reverse(v.begin(), v.end());
	
	ll pos = 0;
	ll cur = 0;
	for(int x=0;x<q;x++){
		while(pos < v.size() & cur+v[pos].first-1 < w[x].first){
			cur += v[pos].first;
			pos++;
		}
				
		if(pos >= v.size()){
			ans[w[x].second].push_back(-1);
			continue;
		}
		
		ll need = w[x].first-l[w[x].second]+1;
		for(ll y=0;y<w[x].first-max(l[w[x].second], cur)+1;y++){
			ans[w[x].second].push_back(v[pos].second);
			need--;
		}
		
		for(int y=pos-1;y>=0;y--){
			if(need == 0) break;
			
			ll cnt = min(need, v[y].first);
			while(cnt > 0){
				ans[w[x].second].push_back(v[y].second);
				cnt--;
				need--;
			}
		}
		
		if(need != 0){
			ans[w[x].second].clear();
			ans[w[x].second].push_back(-1);
			continue;
		}		
	}
	
	cout << "MUNGKIN\n";
	for(int x=0;x<q;x++){
		if(ans[x][0] == -1){
			cout << "DI LUAR BATAS\n";
			continue;
		}
		
		for(int y=ans[x].size()-1;y>=0;y--){
			cout << ans[x][y];
		}
		cout << "\n";
	}
    return 0;
}

