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

const int maxN = 1e5 + 5;

vector<ll> v;
ll h[maxN], prefix[maxN], a, r, m;
int n;

ll calc(ll x){
	int less = lower_bound(v.begin(), v.end(), x) - v.begin();
	int great = lower_bound(v.begin(), v.end(), x+1) - v.begin();
	
	ll need1 = less*x - (less-1 >= 0 ? prefix[less-1] : 0);
	ll need2 = (prefix[n-1] - (great-1 >= 0 ? prefix[great-1] : 0)) - (n-great)*x;
	ll ans = need1 * a + need2 * r;
	
	if(need1 <= need2){
		ans = min(ans, (need2-need1)*r + need1 * m);
	} else {
		ans = min(ans, (need1-need2)*a + need2 * m);
	}
	
	return ans;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> a >> r >> m;
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		cin >> h[x];
		sum += h[x];
		v.push_back(h[x]);
	}
	
	sort(v.begin(), v.end());
	
	ll ans = inf_ll;
	if((sum%n)*r <= (n-(sum%n))*a){
		ans = (sum%n)*r;
		sum -= (sum%n);
	} else {
		ans = (n-(sum%n))*a;
		sum += n-(sum%n);
	}
	
	for(int x=0;x<n;x++){
		if(h[x] > sum/n) ans += (h[x]-sum/n) * m;
	}
	
	for(int x=0;x<n;x++){
		prefix[x] = v[x] + (x-1 >= 0 ? prefix[x-1] : 0);
	}
	
	int left = 0, right = inf_int;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		ll tmp1 = calc(mid), tmp2 = calc(mid+1);
		ans = min(ans, tmp1);
		if(tmp1 > tmp2){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

