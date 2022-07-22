#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxM = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	ll d;
	cin >> n >> m >> d;
	
	ll r[m+1];
	ll s[m+1];
	for(int x=0;x<=m;x++){
		cin >> r[x];
	}
	for(int x=0;x<m;x++){
		cin >> s[x];
	}
	s[m] = 0;
	
	ll ans = 0;
	for(int x=0;x<=(d+1)/2;x++){
		ll sum = s[(lower_bound(r, r+m+1, x+1) - r)-1];
		ll p = x-d, q = x+d;
		
		for(int y=1;y<n;y++){
			ll left = s[lower_bound(r, r+m+1, abs(p)) - r - 1];
			ll right = s[lower_bound(r, r+m+1, abs(q)) - r - 1];
			
//			cout << x << " " << y << " -> " << p << "(" << left << ") " << q << " " << (lower_bound(r, r+m+1, abs(q)) - r) << "(" << right << ")\n";
			sum += max(left, right);
			if(left >= right){
				p -= d;
			} else {
				q += d;
			}
		}
		
		ans = max(ans, sum);
	}
	
	cout << ans << "\n";
    return 0;
}

