#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[2*n];
	for(int x=0;x<2*n;x++){
		cin >> a[x];
	}
	
	pair<ll, ll> p = {1e18, 1e18};
	for(int x=0;x<n;x++){
		p = min(p, {a[x], a[n+x]});
	}
	
	if(p.first >= p.second){
		cout << p.first << " " << p.second << "\n";
		return 0;
	}
	
	vector<ll> l, r;
	ll mn = -1;
	for(int x=0;x<n;x++){
		if(mn == -1){
			if(a[x] == p.first){
				l.push_back(a[x]);
				r.push_back(a[n+x]);
				mn = a[n+x];
			}
		} else {
			if(a[x] <= mn){
				l.push_back(a[x]);
				r.push_back(a[n+x]);
			}
		}
	}
	
	for(int x=0;x<r.size();x++){
		l.push_back(r[x]);
	}
	for(int x=0;x<l.size();x++){
		if(x > 0) cout << " ";
		cout << l[x];
	}
	cout << "\n";
    return 0;
}

