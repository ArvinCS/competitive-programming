#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll m = n;
	
	vector<array<ll, 3>> ans;
	
	auto reduce = [&](ll &n) -> void {
		ll val = n;
		
		ans.push_back({n, n, 0});
		n += val;
		
		ans.push_back({val, n, 1});
		n ^= val;
		
		ans.push_back({val, n, 0});
		n += val;
	};
	
	reduce(n);
	
	while(__builtin_popcountll(n) > 1){
		vector<int> v;
		for(int x=0;x<63;x++){
			ll bit = (1ll << x);
			
			if(n&bit){
				v.push_back(x);
			}
		}
		
		ll res = n;
		for(int x=0;x<v[1]-v[0]-1;x++){
			ans.push_back({n, n, 0});
			n += n;
			
			ans.push_back({res, n, 1});
			res ^= n;
		}
		
		n = res;
		reduce(n);
	}
	
	int mn = 0, mx = 0;
	for(int x=1;x<63;x++){
		ll bit = (1ll << x);
		if(n&bit){
			mn = x;
		}
		if(m&bit){
			mx = x;
		}
	}
	
	for(int x=mn+1;x<63;x++){
		ans.push_back({n, n, 0});
		n *= 2;
	}
	
	ans.push_back({2*m, m, 1});
	
	m = (2*m)^m;
	
	ans.push_back({m, m, 0});
	ll cur = 2*m;
	
	for(int x=1;x<63;x++){
		ll bit = (1ll << x);
		if(m&bit){
			ans.push_back({m, cur, 1});
			m ^= cur;
		}
		for(int y=mn;y<63;y++){
			ll bit2 = (1ll << y);
			if(m&bit2){
				ans.push_back({m, bit2, 1});
				m ^= bit2;
			}
			if(cur&bit2){
				ans.push_back({cur, bit2, 1});
				cur ^= bit2;
			}
		}
		if(m == 1) break;
		
		ans.push_back({cur, cur, 0});
		cur *= 2;
	}
	
	cout << ans.size() << "\n";
	for(auto a : ans){
		cout << a[0] << " " << (a[2] ? "^" : "+") << " " << a[1] << "\n";
	}
    return 0;
}

