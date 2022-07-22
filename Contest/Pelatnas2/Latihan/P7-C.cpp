#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll orientation(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
    ll val = (p2.second - p1.second) * (p3.first - p2.first) -
              (p2.first - p1.first) * (p3.second - p2.second);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	int q;
	cin >> q;
	
	for(int x=0;x<q;x++){
		ll posX, posY;
		cin >> posX >> posY;
		
		bool valid = false;
		for(int x=0;x<n;x++){
			if(orientation(p[x], p[(x+1)%n], {posX, posY}) == 2){
				cout << x << "\n";
				int mx = (n/2)-1;
				if(orientation(p[(x+mx)%n], p[(x+mx+1)%n], {posX, posY}) == 1){
					valid = true;
					break;
				}
			}
		}
		
		cout << (valid ? "YES" : "NO") << "\n";
	}
    return 0;
}

