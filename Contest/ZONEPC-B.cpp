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
	
	ll n, d, h;
	cin >> n >> d >> h;
	
	pair<ll, ll> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	d *= 1000;
	h *= 1000;
	
	sort(data, data+n);
	
	int idx = 0;
	for(ll x=0;x<=1000*1000;x++){
		while(idx < n){
			double slope = (h-x)*1.0/d;
			if(slope*data[idx].first*1000 + x > data[idx].second*1000){
				idx++;
			} else {
				break;
			}
		}
		if(idx == n){
			cout << fixed << setprecision(3) << x*1.0/1000 << "\n";
			return 0;
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

