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

ll memo[maxN][maxN];

int a, b;
ll k;
string ans;

ll combin(ll x, ll y){
	if(y == x) return 1;
	if(y == 1) return x;
	if(x <= 0 || y <= 0 || y > x) return 0;
	if(memo[x][y] != -1) return memo[x][y];
	return memo[x][y] = (combin(x-1, y) + combin(x-1, y-1));
}

void solve(int i, ll cur, int pos[]){
	if(i == b-1){
		pos[i] = a+b-cur;
		
		int idx = 0;
		for(int x=0;x<a+b;x++){
			ans.push_back('a');
		}
		for(int x=0;x<=i;x++){
			ans[pos[x]] = 'b';
		}
		return;
	}
	
	ll cnt = 0;
	int length = a+b, limit = (i > 0 ? pos[i-1]+1 : 0);
	for(int x=length-(b-i);x>=limit;x--){
		ll tmp = combin(length-x-1, b-i-1);
		if((cnt < cur && cnt+tmp >= cur) || x == limit){
			pos[i] = x;
			solve(i+1, cur-cnt, pos);
			return;
		}
		cnt += tmp;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> a >> b >> k;
	
	fill(memo[0], memo[maxN], -1);
	
//	cout << combin(5, 3) << "\n";
	int pos[b];
	solve(0, k, pos);

	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

