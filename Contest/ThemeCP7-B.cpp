#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxM = 1e6 + 5;

ll table[maxM];

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int m;
		cin >> m;
		
		string s;
		cin >> s;
		
		int n = s.length();
		
		for(int x=0;x<n;x++){
			table[x] = (s[x] - '0');
		}
		
		ll ans = n, cur = n;
		ll pos = n;
		for(int x=0;x<m;x++){
			if(pos >= m) break;
			ll len = pos-x-1;
			for(int i=1;i<table[x];i++){
				if(pos >= m) break;
				
				for(int y=0;y<len;y++){
					if(pos >= m) break;
					assert(x+1+y < pos);
					table[pos] = table[x+1+y];
					pos++;
				}
			}
		}
		
		for(int x=0;x<m;x++){
			chadd(cur, -1);
			
			chadd(ans, (table[x]-1)*1ll*cur % mod);
			chadd(cur, (table[x]-1)*1ll*cur % mod);
		}
		
		cout << ans % mod << "\n";
	}
	
    return 0;
}

