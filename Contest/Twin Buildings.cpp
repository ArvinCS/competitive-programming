#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	pair<ull, ull> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		if(p[x].second < p[x].first) swap(p[x].second, p[x].first);
	}
	
	ull ans = 0, rem = 0;
	
	sort(p, p+n);
	reverse(p, p+n);
	
	ull mx = p[0].second;
	for(int x=1;x<n;x++){
		ull a = p[x].first, b = p[x].second;
		ans = max(ans, a*min(b,mx));
		mx = max(mx, b);
	}
	
	for(int x=0;x<n;x++){
		if(2*ans < p[x].first*p[x].second){
			ans = p[x].first*p[x].second / 2;
			rem = (p[x].first*p[x].second) % 2;
		}
	}
	
	cout << fixed << setprecision(1) << ans;
	if(rem){
		cout << ".5\n";
	} else {
		cout << ".0\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

