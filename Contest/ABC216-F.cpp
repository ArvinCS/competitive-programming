#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 5e3 + 5;

vector<int> v[maxN];
ll table[maxN];
int a[maxN], b[maxN], n;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(table, table+maxN, 0);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	for(int x=0;x<n;x++){
		v[a[x]].push_back(x);
	}
	
	
	ll ans = 0;
	table[0] = 1;
	for(int x=1;x<maxN;x++){
		for(auto idx : v[x]){
			for(int y=maxN-1;y>=0;y--){
				if(y+b[idx] <= 5000 && table[y] > 0){
					table[y+b[idx]] += table[y];
					table[y+b[idx]] %= mod;
					
					if(y+b[idx] <= x){
						ans += table[y];
						ans %= mod;
					}
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

