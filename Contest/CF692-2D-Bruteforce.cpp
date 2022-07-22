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

int n;
ll best = inf_ll;
string s;
ll a, b;

void solve(int idx, string state, ll ans, ll zero, ll one){
	if(idx == n){
		cout << state << ": " << ans << "\n";
		best = min(ans, best);
		return;
	}
	
	if(state[idx] == '0'){
		solve(idx+1, state, ans+one*b, zero+1, one);
	} else if(state[idx] == '1'){
		solve(idx+1, state, ans+zero*a, zero, one+1);
	} else {
		state[idx] = '0';
		solve(idx+1, state, ans+one*b, zero+1, one);
		state[idx] = '1';
		solve(idx+1, state, ans+zero*a, zero, one+1);
		state[idx] = '?';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> s >> a >> b;
	
	n = s.length();
	
	solve(0, s, 0, 0, 0);
	
	cout << "Best: " << best << "\n";
    return 0;
}

