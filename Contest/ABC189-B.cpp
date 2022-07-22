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

bool customSort(pair<ull, ull> a, pair<ull, ull> b){
	return ((a.first/100.0) * 1.0 * a.second) > ((b.second/100.0) * 1.0 * b.second);
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull n, m;
	cin >> n >> m;
	
	m *= 100;
	pair<ull, ull> l[n];
	ull cnt = 0;
	for(ull x=0;x<n;x++){
		cin >> l[x].first >> l[x].second;
	}
		
	for(ull x=0;x<n;x++){
		ull v = l[x].first, p = l[x].second;
		if(p > 0 && v > 0) cnt += (v * 1.0 * p);
		
		if(cnt > m){
			cout << x+1 << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

