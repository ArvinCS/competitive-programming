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

const int maxN = 2e7 + 5;

int c, d, m;
int prime[maxN], table[maxN];

int solve(int g){
	if((m/g + d) % c != 0) return 0;
	
	int ans = 1;
	int cur = ((m/g)+d)/c;
	int origin = cur;
	
	if(table[cur] != -1) return table[cur];
	
	while(cur > 1){
		int div = prime[cur];
		int cnt = 0;
		
		while(cur % div == 0){
			cur /= div;
			cnt++;	
		}
		
		ans *= 2;
	}
	return table[origin] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxN;x++){
		prime[x] = x;
		table[x] = -1;
	}
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxN;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	us t;
	cin >> t;
	
	while(t--){
		cin >> c >> d >> m;
		
		ll ans = 0;
		for(int i=1;i*i<=m;i++){
			if(m%i == 0){
				ans += solve(i);
				if(m/i != i) ans += solve(m/i);
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

