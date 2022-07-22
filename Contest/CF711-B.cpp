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

ll p[21];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	p[0] = 1;
	p[1] = 2;
	for(int x=2;x<=20;x++){
		p[x] = 2ll * p[x-1];
	}
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, w;
		cin >> n >> w;
		
		ll data[n], cnt[25];
		fill(cnt, cnt+25, 0);
		
		for(int x=0;x<n;x++){
			cin >> data[x];
			ll base = log2(data[x]);
			cnt[base]++;
		}
		
		ll row = 1, col = 0;
		ll rec = n;
		while(rec > 0){
			for(ll x=22;x>=0;x--){
				while(cnt[x] > 0 && col+p[x] <= w){
					cnt[x]--;
					col += p[x];
					rec--;
				}
			}
			if(rec <= 0) break;
			row++;
			col = 0;
		}
		cout << row << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

