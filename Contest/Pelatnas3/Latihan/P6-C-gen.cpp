#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 100;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	ll s = 2 + rng() % inf;
	ll c = 1 + rng() % inf;
	int n = 1 + rng() % min(s-2, 15ll);
	int m = 1 + rng() % (min(s-2, 15ll)-n-1);
	
	cout << n << " " << m << " " << s << " " << c << "\n";
	
	vector<ll> a, b;
	set<int> st;
	for(int x=0;x<n;x++){
		ll pos = rng() % s;
		while(st.count(pos)){
			pos = rng() % s;
		}
		
		a.push_back(pos);
		st.insert(pos);
	}
	
	sort(a.begin(), a.end());
	for(int x=0;x<a.size();x++){
		if(x > 0) cout << " ";
		cout << a[x];
	}
	cout << "\n";
	
	for(int x=0;x<m;x++){
		ll pos = rng() % s;
		while(st.count(pos)){
			pos = rng() % s;
		}
		
		b.push_back(pos);
		st.insert(pos);
	}
	
	sort(b.begin(), b.end());
	for(int x=0;x<b.size();x++){
		if(x > 0) cout << " ";
		cout << b[x];
	}
	cout << "\n";
	
	int q = 1000 + rng() % 1001;
	cout << q << "\n";
	
	while(q--){
		cout << rng() % n + 1 << " " << rng() % 1001 << "\n";
	}
    return 0;
}

