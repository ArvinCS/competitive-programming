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
	return 2*a.first+a.second > 2*b.first+b.second;
}
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll cur = 0;
	pair<ull, ull> town[n];
	for(int x=0;x<n;x++){
		cin >> town[x].first >> town[x].second;
		
		cur -= town[x].first;
	}
	
	sort(town, town+n, customSort);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		if(cur > 0) break;
		
		cur += 2*town[x].first+town[x].second;
		ans++;
	}
	
	cout << ans << "\n"; 
    return 0;
}
 
// Santai
// Pikirin dengan benar-benar
