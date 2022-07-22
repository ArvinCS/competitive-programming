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

const int maxN = 1e6 + 5;

ll cnt[maxN];
ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(table, table+maxN, 0);
	fill(cnt, cnt+maxN, 0);
	
	for(int x=1;x<maxN;x++){
		for(int y=x;y<maxN;y+=x){
			cnt[y]++;
		}
	}
		
	int n;
	cin >> n;
	
	ll sum = 0;
	for(ll x=1;x<=n;x++){
		table[x] = (sum + cnt[x]) % smod;
		sum = (sum + table[x]) % smod;
	}
	cout << table[n] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

