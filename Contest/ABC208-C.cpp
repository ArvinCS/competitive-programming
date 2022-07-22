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

	ll n, k;
	cin >> n >> k;
	
	bool bonus[n];
	vector<pair<int, int>> v;
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back({a[x], x});
		bonus[x] = false;
	}
	
	sort(v.begin(), v.end());
	
	ll remain = k%n;
	for(int x=0;x<remain;x++){
		bonus[v[x].second] = true;
	}
	
	for(int x=0;x<n;x++){
		cout << (k/n + bonus[x]) << "\n";
	}
    return 0;
}

