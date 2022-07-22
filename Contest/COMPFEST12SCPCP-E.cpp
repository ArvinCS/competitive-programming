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

pair<int, int> a[maxN], d[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].second = x;
	}
	for(int x=0;x<n;x++){
		cin >> d[x].first;
		d[x].second = x;
	}
	
	sort(d, d+n);
	
	ll ans = 0;
	
	if(k == 0){
		ll sum = 0;
		for(int x=n-1;x>=0;x--){
			sum += a[x].first;
			
			ans = max(ans, sum-a[x].second);
		}
	} else if(k == 1){
		
	} else {
		
	}
	
	cout << ans << "\n";
    return 0;
}

