#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ask(ll x){
	cout << x << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a[3];
	for(int x=0;x<3;x++){
		cin >> a[x];
	}
	
	cout << "First" << endl;
	pair<ll, int> p[3];
	for(int x=0;x<3;x++){
		p[x] = {a[x], x};
	}
	
	sort(p, p+3);
	
	ll val = 2*p[2].first-p[1].first-p[0].first;
	
	ll res = ask(val);
	
	if(res-1 == p[2].second){
		for(int x=0;x<3;x++){
			if(p[x].second == res-1) p[x].first += val;
		}
		
		sort(p, p+3);
		
		ll val = 2*p[2].first-p[1].first-p[0].first;
		int res = ask(val);

		for(int x=0;x<3;x++){
			if(p[x].second == res-1) p[x].first += val;
		}
		
		sort(p, p+3);
		
		ask(p[1].first-p[0].first);
	} else {
		for(int x=0;x<3;x++){
			if(p[x].second == res-1) p[x].first += val;
		}
		
		sort(p, p+3);
		
		ask(p[1].first-p[0].first);
	}
    return 0;
}

