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

const int maxN = 100;

pair<ll, ll> p[maxN];
int table[maxN][505];

int solve(int n, int idx, vector<int> v, int sum){
	if(idx == n){
		return sum == 0;
	}
	if(table[idx][sum] != -1) return table[idx][sum];
	
	if(p[idx].second == 0){
		return table[idx][sum] = solve(n, idx+1, v, sum);
	}
	bool ans = solve(n, idx+1, v, sum);
	
	for(int x=1;x<=p[idx].second;x++){
		if(x*p[idx].first > sum) break;
		
		ans = (ans || solve(idx))
	}
	return table[idx][sum] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
			sum += p[x].first*p[x].second;
		}
		
		ll ans = 0;
		for(int x=0;x<m;x++){
			for(int y=x+1;y<m;y++){
				
			}
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

