#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pair<ll, ll> p[3];
	for(int x=0;x<3;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+3);
	
	vector<array<ll, 4>> ans;
	ans.push_back({p[1].first, p[1].second, p[1].first, p[2].second});
	ans.push_back({p[1].first, p[2].second, p[2].first, p[2].second});
	
	ll mnY = min(p[1].second, p[2].second), mxY = max(p[1].second, p[2].second);
	if(mnY <= p[0].second && p[0].second <= mxY){
		ans.push_back({p[0].first, p[0].second, p[1].first, p[0].second});
	} else {
		ans.push_back({p[0].first, p[0].second, p[1].first, p[0].second});
		ans.push_back({p[1].first, p[0].second, p[1].first, (p[0].second < mnY ? mnY : mxY)});
	}
	
	vector<array<ll, 4>> v;
	for(auto a : ans){
		if(a[0] == a[2] && a[1] == a[3]){
			continue;
		}
		v.push_back(a);
	}
	
	swap(ans, v);
	
	cout << ans.size() << "\n";
	for(auto a : ans){
		for(int y=0;y<4;y++){
			if(y > 0) cout << " ";
			cout << a[y];
		}
		cout << "\n";
	}
    return 0;
}

