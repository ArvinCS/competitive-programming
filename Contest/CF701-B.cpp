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
	
	int n, q, k;
	cin >> n >> q >> k;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	pair<int, int> query[q];
	for(int x=0;x<q;x++){
		cin >> query[x].first >> query[x].second;
		query[x].first--; query[x].second--;
	}
	
	ll pos[n], prefix[n];
	pos[0] = (n > 1 ? pos[1]-pos[0]-1+data[0]-1 : k-1);
	pos[n-1] = (n > 1 ? pos[n-1]-pos[n-2]-1+k-data[n-1] : k-1);
	for(int x=1;x<n-1;x++){
		pos[x] = (data[x]-data[x-1]-1) + (data[x+1]-data[x]-1);
	}
	
	prefix[0] = pos[0];
	for(int x=1;x<n;x++){
		prefix[x] = prefix[x-1] + pos[x];
	}
	
	for(int x=0;x<q;x++){
		pair<int, int> p = query[x];
		ll ans = data[p.first] - 1 + k - data[p.second];
		if(p.second-p.first+1 > 1){
			ans += data[p.first+1]-data[p.first]-1 + data[p.second]-data[p.second-1]-1;
		}
		if(p.second-p.first+1 > 2){
			ans += prefix[p.second-1] - prefix[p.first];
		}
		cout << ans << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

