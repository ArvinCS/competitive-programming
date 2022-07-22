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

const int maxN = 2e5 + 5;
const int maxM = 65;

int n, m, p, mx;
ll person[maxN];
bool like[maxN][maxM];
map<ll, vector<int>> mp;
ll ans = 0, cntAns = 0;

void solve(int idx, ll state, int cnt, vector<int> v){
	if(cntAns == mx) return;
	if(idx == m || cnt > p){
		if(cnt > cntAns){
//			cout << state << " " << cnt << " " << v.size() << "\n";
			cntAns = cnt;
			ans = state;
		}
		return;
	}
	
	ll bit = state;
	bit |= (1ll << idx);
	
	vector<int> tmp;
	for(int x=0;x<v.size();x++){
		if((person[v[x]]&bit) == bit) tmp.push_back(v[x]);
	}
	
	if(tmp.size() >= (n+1)/2) solve(idx+1, bit, cnt+1, tmp);
	solve(idx+1, state, cnt, v);
}

int dp(ll state, int i){
	if(i == -1){
		
		return 0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m >> p;
	
	for(int x=0;x<n;x++){
		ll bit = 0;
		int cnt = 0;
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			like[x][y] = (c == '1');
			
			if(like[x][y]){
				v[y].push_back(x);
				bit |= (1ll << y);
				cnt++;
			}
		}
				
		mx = max(mx, cnt);
		person[x] = bit;
	}
	
	for(int x=0;x<m;x++){
		ll bit = (1ll << x);
		
		vector<int> v;
		for(int y=0;y<n;y++){
			if((person[y]&bit) == bit){
				v.push_back(y);
			}
		}
		
		if(v.size() >= (n+1)/2) solve(x+1, bit, 1, v);
	}
	
	for(int x=0;x<m;x++){
		if(ans&(1ll << x)) cout << "1";
		else cout << "0";
	}
	cout << "\n";
    return 0;
}

