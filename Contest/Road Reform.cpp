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

const int maxN = 5 * 1e5;
int dsu[maxN];

ll getParrent(int a){
	if(dsu[a] == a) return a;
	return dsu[a] = getParrent(dsu[a]);
}

bool check(int a, int b){
	return getParrent(a) == getParrent(b);
}

void join(int a, int b){
	dsu[getParrent(a)] = getParrent(b);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		ll k;
		cin >> n >> m >> k;
		
		for(int x=0;x<=n+1;x++){
			dsu[x] = x;
		}
		
		vector<tuple<ll, int, int>> less, great;
		for(int x=0;x<m;x++){
			int a, b;
			ll c;
			cin >> a >> b >> c;
			
			if(c > k) great.push_back(make_tuple(c, a, b));
			else less.push_back(make_tuple(c, a, b));
		}
		
		if(less.size() > 0) sort(less.begin(), less.end());
		if(great.size() > 0) sort(great.begin(), great.end());
		
		ll ans = 0, cnt = 0;
		for(int x=less.size()-1;x>=0;x--){
			int a = get<1>(less[x]), b = get<2>(less[x]);
			ll c = get<0>(less[x]);
			if(!check(a, b)){
				join(a, b);
				cnt++;
			}
			if(cnt == n-1) break;
		}
		
		if(cnt < n-1){
			ans = 0;
			for(int x=0;x<great.size();x++){
				int a = get<1>(great[x]), b = get<2>(great[x]);
				ll c = get<0>(great[x]);
				if(!check(a,b)){
					join(a, b);
					ans += c-k;
					cnt++;
				}
				if(cnt == n-1) break;
			}
		} else {
			ans = k-get<0>(less.back());
			if(great.size() > 0) ans = min(ans, get<0>(great.front())-k);
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

