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

const int maxA = 1e6 + 5;

int prime[maxA], l, r;

int solve(int i, ll cur, ll origin, vector<int> &v){
	if(cur > r) return 0;
	if(i == v.size()){
		cout << cur << "\n";
		return (cur >= l && cur != 1 && origin % cur != 0 ? 1 : 0);
	}
	
	return solve(i+1, cur*v[i], origin, v) + solve(i+1, cur, origin, v);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxA;x++) prime[x] = x;
	for(int x=2;x*x<maxA;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxA;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	cin >> l >> r;
	
	ll ans = 0;
	for(int x=l;x<=r;x++){
		vector<int> v;
		
		int cur = x;
		while(cur > 1){
			int div = prime[cur];
			
			while(cur % div == 0){
				cur /= div;
				v.push_back(div);
			}
		}
		
		cout << x << ":\n";
		ans += solve(0, 1, x, v)*2ll;
	}
	
	for(int x=l;x<=r;x++){
		for(int y=x;y<=r;y++){
			int gc = __gcd(x,y);
			if(gc != 1 && x/gc != 1 && y/gc != 1){
				cout << x << " " << y << "\n";
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

