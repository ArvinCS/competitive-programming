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

const int maxN = 1e5+5;

stack<ll> v[maxN];
ll n;

int gcdExtended(ll a, ll b, ll* x, ll* y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 	
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	for(ll x=2;x<=n;x++){
		v[x].push(x);
	}
	
	vector<ll> ans;
	ans.push_back(1);
	
	vector<ll> tmp;
	for(ll x=2;x<=n;x++){
		ll a, b;
		ll g = gcdExtended(x, n, &a, &b);
		if(g != 1) continue;
		
		ll left = x, right = (a+n)%n;
		
		if(right == 1){
			while(!v[left].empty()){
				ans.push_back(v[left].top());
				v[left].pop();
			}
			continue;
		}
		
		if(left == right){						
			while(!v[left].empty()){
				tmp.push_back(v[left].top());
				v[left].pop();
			}
			continue;
		}
		
		int sz = min(v[left].size(), v[right].size());
		
		int cnt = sz;
		while(cnt--){
			ans.push_back(v[left].top());
			v[left].pop();
		}
		
		cnt = sz;
		while(cnt--){
			ans.push_back(v[right].top());
			v[right].pop();
		}
	}
	
	if(tmp.size() > 0 && tmp.size() % 2 == 0) tmp.pop_back();
	if(tmp.size() > 1) for(auto e : tmp) ans.push_back(e);
	
	sort(ans.begin(), ans.end());
	
	ll prod = 1;
	for(int x=0;x<ans.size();x++){
		prod = (prod * ans[x]) % n;
	}
	
	if(prod != 1){
		cout << "1\n1\n";
		return 0;
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

