#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 1e6 + 5;
const ll div2 = 500000004;

ll f[11][maxN], pw2[maxN];

void chadd(ll &a, ll b){
	if(b >= mod) b -= mod;
	
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	f[0][0] = 0;
	pw2[0] = 1;
	for(int x=1;x<maxN;x++){
		f[0][x] = 0;
		pw2[x] = (2 * pw2[x-1]) % mod;
	}
	for(int x=2;x<maxN;x++){
		if(f[0][x] == 0){
			for(int y=2*x;y<maxN;y+=x){
				f[0][y]++;
			}
		}
	}
	
	f[0][1] = 1;
	for(int x=2;x<maxN;x++){
		if(f[0][x] == 0){
			f[0][x] = pw2[1];
		} else {
			f[0][x] = pw2[f[0][x]];
		}
	}
	
	// only for subtask 6
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		int d, n;
		cin >> d >> n;
		
		int cnt[n+1];
		fill(cnt, cnt+n+1, 0);
		
		queue<pair<int, int>> q;
		q.push({d, n});
		
		while(!q.empty()){	
			pair<int, int> p = q.front();
			q.pop();
			
			if(p.first == 0){
				cnt[p.second]++;
				continue;
			}
			
			for(int x=1;x*x<=p.second;x++){
				if(p.second%x == 0){
					q.push({p.first-1, x});
					if(p.second/x != x) q.push({p.first-1, p.second/x});
				}
			}
		}
		
		ll ans = 0;
		for(int x=1;x<=n;x++){
			chadd(ans, cnt[x]*f[0][x] % mod);
		}
		
		cout << ans << "\n";
	}
    return 0;
}

