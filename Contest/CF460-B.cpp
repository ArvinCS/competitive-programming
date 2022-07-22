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

vector<ll> v;

void solve(int pos, ll num, int sum){
	if(pos == 10){
		if(sum == 10) v.push_back(num);
		return;
	}
	if(sum > 10) return;
	
	for(ll x=0;x<=9;x++){
		solve(pos+1, num * 10 + x, sum+x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	solve(0, 0, 0);
	
//	sort(v.begin(), v.end());
	
	cout << v[n-1] << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

