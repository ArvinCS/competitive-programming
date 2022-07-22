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

const int maxK = 2e5 + 5;

ll cnt[maxK], table[maxK];
bool exist[maxK];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	ll a[n];
	ll sum = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
		sum %= k;
	}
	
	fill(cnt, cnt+maxK, 0);
	fill(exist, exist+maxK, false);
	fill(table, table+maxK, 0);
	
	cnt[0]++;
	exist[0] = true;
	for(ll x=1;x<=m-2;x++){
		cnt[(sum*x)%k]++;
		exist[(sum*x)%k] = true;
	}
	exist[sum*(m-1)%k] = true;
	
	ll b[2*n];
	for(int x=0;x<n;x++){
		b[n+x] = b[x] = a[x];
	}
	
	ll ans = (sum*m % k == 0);
//	for(int x=0;x<n;x++){
//		ll tmp = 0;
//		
//		for(int i=0;i<n;i++){
//			int y = x+i;
//			
//			if(m == 1 && y%n == (x-1+n)%n) continue;
//			
//			tmp += b[y];
//			
//			ll need = (k-(tmp%k))%k;
//			
//			ans += cnt[need] * m % mod;
////			if(cnt[need] > 0) cout << x << " " << y << " " << cnt[need] << " " << (cnt[need] * m) << "\n";
////			if(y < n){
////				if(need == (sum*(m-1))%k){
////					ans += m;
////				}
////			}
//			if(m > 1 && y-x+1 < n){ // if almost use all m pieces
//				if(need == sum*(m-1) % k){
////					cout << x << " " << y << "--\n";
//					ans += m;
//				}
//			}
//			ans %= mod;
//			
////			cout << x << " " << y << " -> " << need << " " << cnt[need] << "\n";
//		}
//	}
	
	ll prefix[2*n];
	vector<int> v;
	for(int x=0;x<=k;x++){
		if(exist[x]) v.push_back(x);
	}
	
//	deque<int> w[k+1];
	queue<pair<ll, int>> q;
	ll cur = 0;
	
	q.push({cur, -1});
//	w[0].push_back(-1);
	table[cur]++;
	
	for(int x=0;x<2*n-1;x++){
		cur += b[x];
		cur %= k;
		prefix[x] = cur;
		
		while(!q.empty() && x-q.front().second > n-(m == 1)){
//			w[q.front().first].pop_front();
			table[q.front().first]--;
//			cout << "popped " << q.front().second << "\n";
			q.pop();
		}
		
//		cout << x << " " << "bef: " << ans << " " << q.size() << "\n";
		for(int y=0;y<v.size();y++){
			ll rem = (cur+v[y]+k) % k;
			ans += cnt[v[y]] * m % mod * table[rem] % mod;
			ans %= mod;
			
//			cout << v[y] << " -> " << ans << " " << cnt[v[y]] << "\n";
			if(m > 1 && v[y] == sum*(m-1) % k){
				ans += m * (table[rem]-(x >= n ? prefix[x-n] == rem : (x-n == -1 ? rem == 0 : 0))) % mod;
				ans %= mod;
			}
//			for(auto a : w[rem]) cout << a << " =\n";
			cout << v[y] << " -> " << ans << " " << rem << " " << table[rem] << "\n";
		}
		cout << "now: " << ans << "\n";
		
		if(x < n-1){
//			cout << "aaaaaaaaaaaaaaaaaa\n";
			table[cur]++;
			q.push({cur, x});
//			w[cur].push_back(x);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

